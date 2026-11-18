NAME        = so_long

CC          = gcc

FLAG        = -Wall -Wextra -Werror

LIBFT_PATH  = ./libft/

LIBFT_FILE  = libft.a

MLX_FILE    = libmlx.a

LIBFT_LIB   = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG    = -lX11 -lXext

MLX_PATH    = ./minilibx-linux/

MLX_LIB     = $(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX      = $(MLX_LIB) $(MLX_FLAG)

C_FILE      = handle_map.c             \
              map_checker.c     \
              handle_rendering.c          \
              renderMoves.c     \
              set.c             \
              so_long.c         \
              utils.c           \
			  collect_handling.c			\

SRC_DIR     = ./srcs/

INC_DIR     = ./inc/

OBJ_DIR     = ./obj/

SRC         = $(addprefix $(SRC_DIR),$(C_FILE))

OBJ         = $(addprefix $(OBJ_DIR),$(C_FILE:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@

all: lib mlx $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object files...\n"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable...\n"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re lib mlx
