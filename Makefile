CC = gcc
CFLAGS = -g3 -fsanitize=address #-Wall -Wextra -Werror
TARGET = project
SRC = srcs/main.c
OBJ = $(SRC:.c=.o)
INCLUDES = includes

LIBS = -Lengine -lengine -Lengine/mlx/mlx_linux -lmlx -lXext -lX11 -lm


all: $(TARGET)

$(TARGET): $(OBJ)
	$(MAKE) -C engine
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES) -Iengine/mlx/mlx_linux -Iengine/includes

clean:
	$(MAKE) -C engine clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C engine fclean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
