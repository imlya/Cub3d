NAME= cub3d
SRC=
OBJS= $(SRC:.c=.o)
CC= cc
CFLAGS= -Wall -Wextra -Werror
LIBFT= ./libft/libft.a
MLX= ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -g
GCL= git clone
MlX_URL= https://github.com/42Paris/minilibx-linux.git

all: minilibx-linux $(NAME)

minilibx-linux:
	$(GCL) $(MLX_URL)
	make -C $@

$(NAME) : $(LIBFT) $(OBJS) minilibx-linux/libmlx_Linux.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -rf minilibx-linux
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re