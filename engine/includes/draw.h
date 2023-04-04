#ifndef DRAW_H
# define DRAW_H

# include "vector2.h"
# include "image.h"

void	draw_pixel(t_img *img, t_vector2 pos, int color);
void	draw_rect(t_img *img, t_vector2 pos, t_vector2 size, int color);

#endif
