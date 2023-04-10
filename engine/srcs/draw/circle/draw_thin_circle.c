#include "vector2.h"
#include "image.h"
#include "circle.h"
#include "draw.h"

void draw_circle_octant_points(t_img *img, t_vector2 center, t_vector2 pos, int color)
{
	engine_draw_pixel(img, (t_vector2){center.x+pos.x, center.y+pos.y}, color);
	engine_draw_pixel(img, (t_vector2){center.x-pos.x, center.y+pos.y}, color);
	engine_draw_pixel(img, (t_vector2){center.x+pos.x, center.y-pos.y}, color);
	engine_draw_pixel(img, (t_vector2){center.x-pos.x, center.y-pos.y}, color);
	engine_draw_pixel(img, (t_vector2){center.x+pos.y, center.y+pos.x}, color);
	engine_draw_pixel(img, (t_vector2){center.x-pos.y, center.y+pos.x}, color);
	engine_draw_pixel(img, (t_vector2){center.x+pos.y, center.y-pos.x}, color);
	engine_draw_pixel(img, (t_vector2){center.x-pos.y, center.y-pos.x}, color);
}

// Function for circle-generation with one px thickness
// using Bresenham's algorithm
void draw_thin_circle(t_img *img, t_circle circle)
{
	t_vector2	pos;
	int			d;

	pos.x = 0;
	pos.y = circle.radius;
	d = 3 - 2 * circle.radius;
	draw_circle_octant_points(img, circle.center, pos, circle.color);
	while (pos.y >= pos.x)
	{
		pos.x++;
		if (d > 0)
		{
			pos.y--;
			d = d + 4 * (pos.x - pos.y) + 10;
		}
		else
			d = d + 4 * pos.x + 6;
		draw_circle_octant_points(img, circle.center, pos, circle.color);
	}
}
