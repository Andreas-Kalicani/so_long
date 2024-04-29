NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = so_long.c

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
		@echo $(Y)Compiling [$<]...$(X)
		@$(CC) $(CFLAGS) -Imlx -c $< -o $@



subsystems:
		@echo $(B)
		make -C $(MLX_PATH) all
		@echo Compiling subsystem

$(NAME): $(OBJECTS)
		@echo $(Y) Compiling [$(CFILES)...$(X)]
		@echo $(G) Finished [$(CFILES)]$(X)
		@echo
		@echo $(Y)Compiling [$(NAME)]
		@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) -o $(NAME)
		@echo $(G)Finished [$NAME]$(X)

clean:
	@make -C $(MLX_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(MLX_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean