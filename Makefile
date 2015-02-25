NAME = Project

CC =  g++
#CFLAGS = -Wall -Wextra -Werror -O3 -lm
CFLAGS = -g -lm
CFLAGS += `sdl2-config --cflags` -framework OpenGL -framework GLUT -framework Cocoa -framework OpenCL

LFLAGS += `sdl2-config --libs` -framework OpenGL -framework GLUT -framework Cocoa -framework OpenCL

#CFLAGS += -I /usr/include/SDL2
#LFLAGS += -lSDL2_image

PATH_INC = includes/
PATH_OBJ = obj
PATH_SRC = srcs/

SRC =		\


SRC +=	main.cpp \
		Engine.class.cpp \

OBJ = $(patsubst %.cpp, $(PATH_OBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): namemes $(OBJ)
	@ $(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -I $(PATH_INC) -o $(NAME)
	@ echo " \033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/, %.cpp)
	@ echo -n .
	@ mkdir -p $(PATH_OBJ)
	@ $(CC) -c $^ -I $(PATH_INC) $(CFLAGS) $(LFGLAGS) -o $@


clean:
	@ rm -rf $(PATH_OBJ)
	@ echo "Cleaning $(NAME) \
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "Fcleaning $(NAME) \
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

namemes :
	@ echo -n Compiling $(NAME)

re: fclean all

.PHONY: clean fclean re
