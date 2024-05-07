NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

#SANITIZER = -g3 -fsanitize=address

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

LIBFT_LIB = ./libft/libft.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = so_long.c parse_map.c error.c character_moves.c

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
		@echo $(Y)Compiling [$<]...$(X)
		@$(CC) $(CFLAGS) -Imlx -c $< -o $@



subsystems:
		@echo $(B)
		make -C $(MLX_PATH) all
		make -C libft
		@echo Compiling subsystem

$(NAME): $(OBJECTS)
		@echo $(Y) Compiling [$(CFILES)...$(X)]
		@echo $(G) Finished [$(CFILES)]$(X)
		@echo
		@echo $(Y)Compiling [$(NAME)]
		@$(CC) $(CFLAGS) $(SANITIZER) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
		@echo $(G)Finished [$NAME]$(X)

clean:
	@make -C $(MLX_PATH) clean
	@make -s $@ -C libft 
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(MLX_PATH) fclean
	@make -s $@ -C libft
	@rm -rf $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean