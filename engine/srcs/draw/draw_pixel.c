#include "engine.h"

/*
 * Draws a pixel on an image at the specified (x, y) coordinates, given by
 * a t_vector2 struct, with the provided color
 *
 * @param img: pointer to the image structure containing data about the image
 * @param pos: t_vector2 struct containing the (x, y) coordinates of the pixel
 * @param color: color value of the pixel to be drawn
 */
void	engine_draw_pixel(t_img *img, t_vector2 pos, int color)
{
	char	*pixel;

	if (pos.x >= 0 && pos.x < img->size.x && pos.y >= 0 && pos.y < img->size.y)
	{
		pixel = img->addr + (pos.y * img->line_len + pos.x * (img->bpp / 8));
		*((unsigned int *)pixel) = color;
	}
}
