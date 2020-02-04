SRCS = ./SRCS/main.c

NAME = ft_wolf

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MINLIB = minilibx_macos

MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@echo "\x1B[32making libft.."
	@make -C $(LIBFT)
	@echo "\x1B[32mmaking minilibx.."
	@make -C $(MINLIB)
	@echo "\x1B[32mmaking ft_wolf.."
	@make ft_wolf

ft_wolf:
	@gcc $(SRCS) $(FLAGS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf *.dSYM

re: fclean all

debug:
	@gcc $(SRCS) $(FLAGS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address
