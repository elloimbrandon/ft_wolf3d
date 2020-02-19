NAME = ft_wolf

SRCS = 		./srcs/main.c \
					./srcs/init_env.c \
					./srcs/helpers.c \
					./srcs/calculate_rays.c \
					./srcs/draw_rays.c \
					./srcs/movement.c \
					./srcs/map.c \
					./srcs/mini_map.c

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MINILIB = minilibx_macos

MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@echo "\x1B[34mBuilding Library Files"
	@make -C $(LIBFT) ||:
	@echo "\x1B[34mBuilding MiniLibX Files"
	@make -C $(MINILIB)
	@echo "\x1B[32mLibrary Files Built!"
	@echo "\x1B[34mBuilding Wolf3D Executable"
	@make wolf
	@echo "\n\n\n"
	@echo "\x1B[32mExecutable built! Please follow these instructions:\n"
	@echo "\x1B[32m 1. Run the executable with the map provided: ./ft_wolf map.txt"
	@echo "\x1B[32m 2. If you want to edit your own map there is a few rules you have to follow:"
	@echo "\x1B[32m\t • Create a filename.txt and open it  (vim/emacs/nano)."
	@echo "\x1B[32m\t • The file HAS to be 24 integers long and 24 integers wide. (No spaces)"
	@echo "\x1B[32m\t • The file must contain numbers ranging from 1-5 for the walls/textures -"
	@echo "\x1B[32m\t    9 for hidden doors and 0's for walkable space."
	@echo "\x1B[32m\t • The file parser will check to see if you gave it right inputs."
	@echo "\x1B[32m 3. It is much easier to edit the file provided (trust us!!!)"



wolf:
	@gcc $(SRCS) $(FLAGS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIB)

fclean: clean
	@echo "\033[0;31mCleaning Library Files."
	@make fclean -C $(LIBFT)
	@echo "\033[0;31mCleaning MiniLibX Files."
	@make clean -C $(MINILIB)
	@echo "\033[0;31mCleaning Wolf3D Files."
	@rm -rf *.dSYM

re: fclean all

debug:
	@gcc $(SRCS) $(FLAGS) $(MINILIBX) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address
