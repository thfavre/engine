CC = gcc
AR = ar
CFLAGS = #-Wall -Wextra -Werror
NAME = libengine.a
SRC = srcs/draw/draw_rect.c \
		srcs/draw/line/draw_line.c \
		srcs/draw/line/draw_x_line.c \
		srcs/draw/draw_pixel.c \
		srcs/draw/circle/draw_circle.c \
		srcs/draw/circle/draw_filled_circle.c \
		srcs/draw/circle/draw_thin_circle.c \
		srcs/draw/circle/draw_circle_with_thickness.c \
		srcs/draw/draw_background.c \
		srcs/draw/color.c \
		srcs/key/on_keyreleased.c \
		srcs/key/on_keypressed.c \
		srcs/key/keys_init.c \
		srcs/init.c \
		srcs/frame_update.c \
		srcs/close.c
OBJ = $(SRC:.c=.o)
INCLUDES = includes

# Platform detection
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  LIBS = -lmlx -lXext -lX11 -lm
  MLX_DIR = mlx/mlx_linux
else
  LIBS = -lmlx -framework OpenGL -framework AppKit
  MLX_DIR = mlx/mlx_mac
endif


all: $(NAME)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(AR) rcs $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(MLX_DIR) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  -I$(INCLUDES) -I$(MLX_DIR)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
