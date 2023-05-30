#include "engine.h"

void	engine_draw_background(t_img *img, int color)
{
	engine_draw_rect(img, (t_rect){0, 0, img->size.x, img->size.y}, color);
}
