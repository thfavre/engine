# Compiler and flags
CC = gcc
CFLAGS = -fsanitize=address #-Wall -Wextra -Werror

# Project source files and object files
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)

# Name of the output binary
BIN = project

# Engine folder and library
ENGINE_DIR = engine
ENGINE_LIB = $(ENGINE_DIR)/libengine.a

# mlx folder and library
MLX_DIR = $(ENGINE_DIR)/mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

# X11 libraries
X11_LIBS = -lXext -lX11

# Default rule
all: $(ENGINE_LIB) $(MLX_LIB) $(BIN)

# Compile project source files
%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

# Compile the project code and link with the engine, mlx, and X11 libraries
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -Iincludes -o $@ $^ -L$(ENGINE_DIR) -lengine -L$(MLX_DIR) -lmlx $(X11_LIBS)

# Call the engine and mlx Makefiles
$(ENGINE_LIB):
	$(MAKE) -C $(ENGINE_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Clean rule
clean:
	$(MAKE) -C $(ENGINE_DIR) clean
	rm -f $(OBJS)

# Clean all rule
fclean: clean
	$(MAKE) -C $(ENGINE_DIR) fclean
	rm -f $(BIN)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re
