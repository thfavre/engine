# include "../../includes/engine.h"

/*
 * Draws a rectangle on an image at the specified (x, y) position, given by
 * a t_vector2 struct, with the provided size and color
 *
 * @param img: pointer to the image structure containing data about the image
 * @param pos: t_vector2 struct containing the (x, y) coordinates of the top-left corner
 * @param size: t_vector2 struct containing the width and height of the rectangle
 * @param color: color value of the rectangle to be drawn
*/
void	draw_rect(t_img *img, t_vector2 pos, t_vector2 size, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			// printf("x: %d, y: %d\n", pos.x + x, pos.y + y);
			draw_pixel(img, (t_vector2){pos.x + x, pos.y + y}, color);
			y++;
		}
		x++;
	}
}
