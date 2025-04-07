CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g3 -MMD
LIBFLAGS = -L./libft/ -lft
MLXFLAGS = -Lmlx -lm -lX11 -lXext -lXrandr -lXi
MLXLIB = minilibx-linux/libmlx_Linux.a

SRC = $(wildcard src/*.c src/parsing/*c src/exec/*c)

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

NAME = cub3D
NAME_BONUS = cub3D_bonus
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(MLXLIB):
	make -j4 -C mlx

$(NAME): $(OBJ) $(MLXLIB) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(MLXLIB) $(LIBFLAGS)

$(LIBFT):
	$(MAKE) -j4 -C $(LIBFT_PATH) 

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_PATH) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re