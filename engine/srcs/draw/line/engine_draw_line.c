#include <stdbool.h>
#include "vector2.h"
#include "image.h"
#include "draw.h"
#include <stdlib.h>



void engine_draw_pixel(t_img *img, t_vector2 pos, int color);
void engine_draw_rect(t_img *img, t_rect rect, int color); // TODO remove

void draw_line_step(t_img *img, t_vector2 *pos, t_vector2 *d, t_vector2 *s, int *err, int color, int thickness) {
	t_rect rect = {{pos->x - thickness / 2, pos->y - thickness / 2}, {thickness, thickness}};
	engine_draw_rect(img, rect, color);

	int e2 = 2 * *err;
	if (e2 > -d->y) {
		*err -= d->y;
		pos->x += s->x;
	}
	if (e2 < d->x) {
		*err += d->x;
		pos->y += s->y;
	}
}

void engine_draw_line(t_img *img, t_vector2 start_pos, t_vector2 end_pos, int color, int thickness) {
	t_vector2 d = {abs(end_pos.x - start_pos.x), abs(end_pos.y - start_pos.y)};
	t_vector2 s = {(start_pos.x < end_pos.x) ? 1 : -1, (start_pos.y < end_pos.y) ? 1 : -1};
	t_vector2 pos = start_pos;
	int err = d.x - d.y;

	while (true) {
		draw_line_step(img, &pos, &d, &s, &err, color, thickness);
		if (pos.x == end_pos.x && pos.y == end_pos.y) break;
	}
}

// old algorithm
// void	swap(int *a, int *b)
// {
// 	int	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// typedef struct s_v
// {
// 	bool		steep;
// 	t_vector2	start_pos;
// 	t_vector2	end_pos;
// 	t_vector2	xy;
// 	t_vector2	d;
// 	t_vector2	error;
// }	t_v;

// void	draw_line_1px(t_img img, t_v v, int color)
// {
// 	if (v.start_pos.x > v.end_pos.x)
// 		swap(&v.start_pos.y, &v.end_pos.y);
// 	if (v.start_pos.x > v.end_pos.x)
// 		swap(&v.start_pos.x, &v.end_pos.x);
// 	v.d = (t_vector2){v.end_pos.x - v.start_pos.x, v.end_pos.y - v.start_pos.y};
// 	v.error = (t_vector2){abs(v.d.y) * 2, 0};
// 	v.xy = (t_vector2){v.start_pos.x - 1, v.start_pos.y - 1};
// 	while (++v.xy.x <= v.end_pos.x)
// 	{
// 		if (v.steep)
// 			engine_draw_pixel(&img, (t_vector2){v.xy.y, v.xy.x}, color);
// 		else
// 			engine_draw_pixel(&img, (t_vector2){v.xy.x, v.xy.y}, color);
// 		v.error.y += v.error.x;
// 		if (v.error.y > v.d.x)
// 		{
// 			if (v.end_pos.y > v.start_pos.y)
// 				v.xy.y += 1;
// 			else
// 				v.xy.y -= 1;
// 			v.error.y -= v.d.x * 2;
// 		}
// 	}
// }

// void	engine_draw_line(t_img *img, t_vector2 start_pos, t_vector2 end_pos, int color, int thickness)
// {
// 	int	i;
// 	t_v	v;

// 	i = -thickness / 2;
// 	while (i <= thickness / 2)
// 	{
// 		v.start_pos = (t_vector2){start_pos.x + i, start_pos.y};
// 		v.end_pos = (t_vector2){end_pos.x + i, end_pos.y};
// 		v.steep = abs(v.start_pos.x - v.end_pos.x) < \
// 			abs(v.start_pos.y - v.end_pos.y);
// 		if (v.steep)
// 			swap(&v.start_pos.x, &v.start_pos.y);
// 		if (v.steep)
// 			swap(&v.end_pos.x, &v.end_pos.y);
// 		draw_line_1px(*img, v, color);
// 		i++;
// 	}

// }
