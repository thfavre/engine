# Compiler and flags
CC = gcc
CFLAGS = #-Wall -Wextra -Werror

# Engine source files and object files
SRCS =	srcs/draw/draw_rect.c \
		srcs/draw/draw_line.c \
		srcs/draw/draw_pixel.c \
		srcs/draw/color.c \
		srcs/key/on_keyreleased.c \
		srcs/key/on_keypressed.c \
		srcs/key/keys_init.c \
		srcs/engine_init.c \
		srcs/engine_frame_update.c \
		srcs/engine_close.c


OBJS = $(SRCS:.c=.o)

# Name of the output static library
LIB = libengine.a

# mlx folder and library
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
# commands to be executed on Linux
	MLX_DIR = mlx/mlx_linux
else ifeq ($(UNAME), Darwin)
# commands to be executed on macOS
	MLX_DIR = mlx/mlx_mac
else
	$(error Unsupported operating system: $(UNAME))
endif

MLX_LIB = mlx/libmlx.a

# Default rule
all: $(MLX_LIB) $(LIB)

# Compile engine source files
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -Iincludes -c $< -o $@

# Create the engine static library
$(LIB): $(OBJS)
	ar rcs $@ $^
	ranlib $@

# Call the mlx Makefile
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Clean rule
clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

# Clean all rule
fclean: clean
	$(MAKE) -C $(MLX_DIR) fclean
	rm -f $(LIB)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re
