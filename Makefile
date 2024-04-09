NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

CFILES = main.c \
		map_parser/map_parse.c \
		map_parser/check_file.c \
		map_parser/check_line.c \
		map_parser/fill_map.c \
		map_parser/floodfill.c \
		utils/utils.c \
		utils/utils2.c \
		view/load_textures.c \
		view/init_view.c \
		view/display_map.c \
		view/get_texture.c \

OFILES = $(CFILES:.c=.o)

MLX_DIR = MLX42/
MLX_LIB = MLX42/build/libmlx42.a

$(NAME): $(MLX_LIB) $(OFILES)
	$(CC) $(CFLAGS) -IMLX42/include -LMLX42/build $(OFILES) -o $(NAME) -ldl -lglfw -pthread -lmlx42 -lm

all: $(NAME) clean

.c.o:
	$(CC) $(CFLAGS) -IMLX42/include -c $< -o ${<:.c=.o}

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git

$(MLX_LIB): $(MLX_DIR)
	cd MLX42 && cmake -B build && cd build && make

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)
	# make -C MLX42/build clean

re: fclean $(NAME)

norm:
	norminette -R CheckDefine $(CFILES) so_long.h

.PHONY:  all clean fclean re norm