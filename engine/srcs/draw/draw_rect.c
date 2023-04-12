#include "image.h"
#include "rect.h"
#include "draw.h"
#include "color.h"

static void	adjust_rect_in_image(t_rect *rect, t_img *img);
static void	draw_block(unsigned int *pixel_ptr, int chunk_size, int color);

/*
 * Draws a rectangle on an image at the specified (x, y) position, given by
 * a t_vector2 struct, with the provided size and color
 *
 * @param img: pointer to the image structure containing data about the image
 * @param pos: t_vector2 struct containing the (x, y) coordinates of the top-left corner
 * @param size: t_vector2 struct containing the width and height of the rectangle
 * @param color: color value of the rectangle to be drawn
*/
void	engine_draw_rect(t_img *img, t_rect rect, int color)
{
	int				x;
	int				y;
	unsigned int	*pixel_ptr;
	int				chunk_size;

	adjust_rect_in_image(&rect, img);
	chunk_size = rect.size.x - rect.size.x % 12;
	y = 0;
	while (y < rect.size.y)
	{
		pixel_ptr = (unsigned int *)(img->addr + ((y + rect.pos.y) * img->line_len + rect.pos.x * (img->bpp / 8)));
		draw_block(pixel_ptr, chunk_size, color);
		x = chunk_size;
		while (x < rect.size.x)
			*(pixel_ptr + x++) = color;
		y++;
	}
}

static void	adjust_rect_in_image(t_rect *rect, t_img *img)
{
	if (rect->pos.x < 0)
	{
		rect->size.x -= -rect->pos.x;
		rect->pos.x = 0;
	}
	if (rect->pos.y < 0)
	{
		rect->size.y -= -rect->pos.y;
		rect->pos.y = 0;
	}
	if (rect->pos.x + rect->size.x > img->size.x)
		rect->size.x = img->size.x - rect->pos.x;
	if (rect->pos.y + rect->size.y > img->size.y)
		rect->size.y = img->size.y - rect->pos.y;
}

static void	draw_block(unsigned int *pixel_ptr, int chunk_size, int color)
{
	int	x;
	// int	offset;

	x = 0;
	while (x < chunk_size)
	{
		// offset = 0;
		// while (offset < PIXELS_PER_BLOCK)
		// 	*(pixel_ptr + x + offset++) = color;
		// x += 12;
		*(pixel_ptr + x) = color;
		*(pixel_ptr + x + 1) = color;
		*(pixel_ptr + x + 2) = color;
		*(pixel_ptr + x + 3) = color;
		*(pixel_ptr + x + 4) = color;
		*(pixel_ptr + x + 5) = color;
		*(pixel_ptr + x + 6) = color;
		*(pixel_ptr + x + 7) = color;
		*(pixel_ptr + x + 8) = color;
		*(pixel_ptr + x + 9) = color;
		*(pixel_ptr + x + 10) = color;
		*(pixel_ptr + x + 11) = color;
		x += 12;
	}
}
