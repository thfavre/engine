#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

# define COLOR_BLACK	0x000000
# define COLOR_WHITE	0xFFFFFF
# define COLOR_RED		0xFF0000
# define COLOR_GREEN	0x00FF00
# define COLOR_BLUE		0x0000FF
# define COLOR_YELLOW	0xFFFF00
# define COLOR_MAGENTA	0xFF00FF
# define COLOR_CYAN		0x00FFFF

int	engine_rgb(uint8_t red, uint8_t green, uint8_t blue);
int	engine_add_color(int color, int to_add_color);

#endif
