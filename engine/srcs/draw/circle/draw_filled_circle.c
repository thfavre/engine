#include "vector2.h"
#include "image.h"
#include "circle.h"
#include "math.h"
#include "draw.h"

// algo from (https://stackoverflow.com/a/59211338s)
void	draw_filled_circle(t_img *img, t_circle circle)
{
	int	radius = circle.radius;
	int	radius_sqr = radius * radius;

	for (int x = -radius; x < radius ; x++)
	{
		int hh = (int)sqrt(radius_sqr - x * x);
		int rx = circle.center.x + x;
		int ph = circle.center.y + hh;
		for (int y = circle.center.y-hh; y < ph; y++)
			engine_draw_pixel(img, (t_vector2){rx, y}, circle.color);
	}
}


