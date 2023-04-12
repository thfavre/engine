#include "image.h"
#include "draw.h"

void	draw_x_line(t_img *img, t_vector2 start, int length, int color, int thickness)
{
	t_rect line_rect;

	line_rect.pos = (t_vector2){start.x, start.y - thickness / 2};
	line_rect.size = (t_vector2){length, thickness};
	engine_draw_rect(img,  line_rect, color);
}
