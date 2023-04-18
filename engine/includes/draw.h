#ifndef DRAW_H
# define DRAW_H

# include "vector2.h"
# include "image.h"
# include "rect.h"
# include "circle.h"

void	engine_draw_pixel(t_img *img, t_vector2 pos, int color);
void	engine_draw_pixel_xy(t_img *img, int x, int y, int color);
// void	engine_draw_pixel_xy(t_img *img, int x, int y, int color);
void	engine_draw_rect(t_img *img, t_rect rect, int color);
void	engine_draw_line(t_img *img, t_vector2 start_pos, t_vector2 end_pos, int color, int thickness);
// void	engine_draw_circle(t_img *img, t_vector2 center, int radius, int color);
void	engine_draw_circle(t_img *img, t_circle circle);
void engine_draw_polygon(t_img *img, t_vector2 *vertices, int num_vertices, int color);
void	engine_draw_background(t_img *img, int color);

#endif
