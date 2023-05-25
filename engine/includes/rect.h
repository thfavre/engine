#ifndef RECT_H
# define RECT_H

# include "image.h"
# include "vector2.h"

typedef struct s_rect
{
	t_vector2	pos;
	t_vector2	size;
} t_rect;

void	engine_draw_rect(t_img *img, t_rect rect, int color);

#endif
