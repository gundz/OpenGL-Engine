#include <Noise.class.hpp>

Noise::Layer::Layer(const int size, const float persistence, const int maxHeight) : s(size), p(persistence), maxHeight(maxHeight)
{
	t = new int*[s];
	for (int i = 0; i < s; i++)
	{
		t[i] = new int[s];
		for (int j = 0; j < s; j++)
			t[i][j] = 0;
	}
	return ;
}

Noise::Layer::~Layer(void)
{
	// for (int i = 0; i < s; i++)
	// 	delete [] t[i];
	// delete [] t;
	return ;
}

int
Noise::Layer::rnd(const int max)
{
	return (rand() % max);
}

void
Noise::Layer::randomizeLayer(void)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
			t[i][j] = rnd(maxHeight);
	}
}

Noise::Noise(const int size, const int frequence, const int octaves, const float persistence, const int lissage) : _s(size), _f(frequence), _o(octaves), _p(persistence), _l(lissage), _maxHeight(256)
{
	srand(time(NULL));
	return ;
}

Noise::Noise(Noise const &src)
{
	*this = src;
	return ;
}

Noise::~Noise(void)
{
	return ;
}

Noise &
Noise::operator = (Noise const &rhs)
{
	if (this != &rhs)
	{
		// copy members here
	}
	return (*this);
}

void
Noise::genPerlin(void)
{
	std::vector<Layer>				layers;

	Layer				random(_s, _p, _maxHeight);
	random.randomizeLayer();
	Layer				ret(_s, _p, _maxHeight);

	for (int i = 0; i < _o; i++)
	{
		Layer			layer(_s, _p, _maxHeight);
		layer.randomizeLayer();
		layers.push_back(layer);
	}

	int current_f = _f;
	for (int n = 0; n < _o; n++)
	{
		for (int y = 0; y < _s; y++)
		{
			for (int x = 0; x < _s; x++)
			{
				layers[n].t[y][x] = interpolateValues(y, x, current_f, random);
			}
		}
		current_f *= _f;
	}

	float sum_persistances = 0;
	for (int i = 0; i < _o; i++)
		sum_persistances += layers[i].p;

	// ajout des calques successifs
	for (int i=0; i < _s; i++)
	{
		for (int j=0; j < _s; j++){
			for (int n=0; n < _o; n++)
				ret.t[i][j] += layers[n].t[i][j] * layers[n].p;

			// normalisation
			ret.t[i][j] =  ret.t[i][j] / sum_persistances;
		}
	}

	// lissage
	Layer			lisse(_s, _p, _maxHeight);

	int l, k;
	for (int x = 0; x < _s; x++)
	{
		for (int y = 0; y < _s; y++)
		{
			int a=0;
			int n=0;
			for (k= x - _l; k <= x + _l; k++)
			{
				for (l= y - _l; l<= y + _l; l++)
					if ((k >= 0) && (k < _s) && (l >= 0) && (l < _s))
					{
						n++;
						a += ret.t[k][l];
					}
			}
			lisse.t[x][y] = (float)a/n;
		}
	}
	std::cout << lisse;
}

int
Noise::interpolate(const int y1, const int y2, const int n, const int d)
{
	// interpolation non linéaire
	if (n == 0)
		return (y1);
	if (n == 1)
		return (y2);

	float a = (float)d/n;

	float fac1 = 3 * pow(1 - a, 2) - 2 * pow(1 - a,3);
	float fac2 = 3 * pow(a, 2) - 2 * pow(a, 3);

	return (y1 * fac1 + y2 * fac2);

	//////////////////////////////////////////////

	// interpolation linéaire
	/*if (n!=0)
		return y1+delta*((float)y2-(float)y1)/(float)n;
	else
		return y1;*/
}

int
Noise::interpolateValues(const int i, const int j, const int f, Layer layer)
{
	// valeurs des bornes
	int borne1x, borne1y, borne2x, borne2y, q;
	float pas;
	pas = (float)layer.s / f;

	q = (float)i / pas;
	borne1x = q * pas;
	borne2x = (q + 1) * pas;

	if(borne2x >= layer.s)
		borne2x = layer.s - 1;

	q = (float)j / pas;
	borne1y = q * pas;
	borne2y = (q + 1) * pas;

	if(borne2y >= layer.s)
		borne2y = layer.s - 1;

	int b00,b01,b10,b11;
	b00 = layer.t[borne1x][borne1y];
	b01 = layer.t[borne1x][borne2y];
	b10 = layer.t[borne2x][borne1y];
	b11 = layer.t[borne2x][borne2y];

	int v1 = interpolate(b00, b01, borne2y-borne1y, j-borne1y);
	int v2 = interpolate(b10, b11, borne2y-borne1y, j-borne1y);
	int fin = interpolate(v1, v2, borne2x-borne1x , i-borne1x);

	return fin;
}

void
Noise::setMaxHeight(const int max)
{
	_maxHeight = max;
}

int
Noise::getSize(void) const
{
	return (_s);
}

std::ostream &
operator << (std::ostream &o, Noise const &i)
{
	o	<< "Noise: " << &i;
	return (o);
}

std::ostream &
operator << (std::ostream &o, Noise::Layer const &i)
{
	o	<< "Layer: " << std::endl;
	for (int y = 0; y < i.s; y++)
	{
		for (int x = 0; x < i.s; x++)
			o << i.t[y][x] << " ";
		o << std::endl;
	}
	o << std::endl;
	return (o);
}