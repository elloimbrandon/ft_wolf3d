SRCS = ./SRCS/main.c

NAME = ft_wolf

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MINLIB = minilibx_macos

MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@make -C $(MINLIB)
	@gcc $(SRCS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

debug:
	@gcc $(SRCS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address
