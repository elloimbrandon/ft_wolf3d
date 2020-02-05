SRCS = ./SRCS/main.c

NAME = ft_wolf

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MINILIB = minilibx_macos

MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@echo "\x1B[34mMaking Libft.."
	@make -C $(LIBFT)
	@echo "\x1B[34mMaking Minilibx.."
	@make -C $(MINILIB)
	@echo "\x1B[34mMaking Ft_Wolf.."
	@make wolf
	@echo "\x1B[32mFt_Wolf made!"

wolf:
	@gcc $(SRCS) $(FLAGS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIB)

fclean: clean
	@echo "\x1B[33mcleaning Libft.."
	@make fclean -C $(LIBFT)
	@echo "\x1B[33mcleaning Minilib.."
	@make clean -C $(MINILIB)
	@echo "\x1B[33mcleaning Ft_Wolf.."
	@rm -rf *.dSYM

re: fclean all

debug:
	@gcc $(SRCS) $(FLAGS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address
