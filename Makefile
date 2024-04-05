NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

CFILES = main.c \
		map_parser/map_parse.c \
		map_parser/check_file.c \
		map_parser/check_line.c \
		map_parser/fill_map.c \
		utils/utils.c

OFILES = $(CFILES:.c=.o)

MLX_DIR = MLX42/
MLX_LIB = MLX42/build/libmlx42.a

$(NAME): $(MLX_LIB) $(OFILES)
	$(CC) $(CFLAGS) -IMLX42/include -LMLX42/build $(OFILES) -o $(NAME) -ldl -lglfw -pthread -lmlx42

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

re: fclean $(NAME)

n:
	norminette -R CheckDefine $(CFILES) so_long.h

.PHONY:  all clean fclean re