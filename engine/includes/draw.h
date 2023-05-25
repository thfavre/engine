#ifndef DRAW_H
# define DRAW_H

# include "vector2.h"
# include "image.h"
# include "rect.h"
# include "circle.h"
# include "line.h"

void	engine_draw_pixel(t_img *img, t_vector2 pos, int color);
void	engine_draw_polygon(t_img *img, t_vector2 *vertices, int num_vertices, int color);
void	engine_draw_background(t_img *img, int color);

#endif
