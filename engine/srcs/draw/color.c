
#include <stdint.h>

/*
 * Converts a red, green, blue values to a single 32-bit integer
 *
 * @param red: red value
 * @param green: green value
 * @param blue: blue value
 *
 * @return 32-bit integer containing red, green, blue values
*/
int	engine_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int engine_add_color(int color, int to_add_color)
{
	int	red;
	int	green;
	int	blue;

	red = (color >> 16) + (to_add_color >> 16);
	green = ((color >> 8) & 0xFF) + ((to_add_color >> 8) & 0xFF);
	blue = (color & 0xFF) + (to_add_color & 0xFF);

	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return (engine_rgb(red, green, blue));
}
