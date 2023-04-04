
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
int	rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
