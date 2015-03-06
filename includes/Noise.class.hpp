#ifndef		NOISE_CLASS_HPP
# define	NOISE_CLASS_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <vector>
# include <cmath>

class Noise
{
	public:

		class Layer
		{
			public:
				
				Layer(void);
				Layer(const int size, const float p, const int maxHeight);
				~Layer(void);

				void		init(const int size, const float p, const int maxHeight);
				int			rnd(const int max);
				void		randomizeLayer(void);

				int			**t;
				int			s;
				float		p;
				int			maxHeight;
		};

		Layer			retNoise;

		Noise(const int size, const int frequence, const int octaves, const float persistence, const int lissage);
		Noise(Noise const &src);
		~Noise(void);

		Noise			&operator = (Noise const &rhs);

		void			genPerlin(void);
		int				interpolate(const int y1, const int y2, const int n, const int d);
		int				interpolateValues(const int i, const int j, const int f, Layer layer);
		void			setMaxHeight(const int max);
		int				getSize(void) const;

	protected:

		int				_s; //size
		int				_f; //frequence
		int				_o; // octaves
		float			_p; //persistences
		int				_l; //lissage
		int				_maxHeight;
};

std::ostream			&operator << (std::ostream &o, Noise const &i);

std::ostream			&operator << (std::ostream &o, Noise::Layer const &i);

#endif