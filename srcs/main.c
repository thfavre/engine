# include "project.h"


void	close(t_engine *engine)
{
	printf("Close\n");
	engine_close(engine);
}

#include <math.h>
double	CHANGE_ANGLE = M_PI/6;
double	REDUCE_SIZE = 1.25;
double	START_SIZE = 150;

void	draw(t_engine *engine, float size, double angle, t_vector2 start_pos, int color, int thickness)
{
	t_vector2	end_pos;
	float		new_size;

	end_pos.x = start_pos.x + sin(angle) * size;
	end_pos.y = start_pos.y + cos(angle) * size;

	draw_line(&engine->img, start_pos, end_pos, color, thickness);

	new_size = size / REDUCE_SIZE;
	if (new_size > 10)
	{
			thickness -= 5;
		if (thickness <= 2)
			thickness = 2;
		draw(engine, new_size, angle + CHANGE_ANGLE, end_pos, color+11, thickness);
		draw(engine, new_size, angle - CHANGE_ANGLE, end_pos, color+11, thickness);
	}
}


int	on_update(t_engine *engine)
{
	if (engine->key_pressed[K_UP])
		{START_SIZE += 1; printf("START_SIZE: %d\n", (int)START_SIZE);}
	if (engine->key_pressed[K_DOWN])
		{START_SIZE -= 1; printf("START_SIZE: %d\n", (int)START_SIZE);}
	if (engine->key_pressed[K_RIGHT])
		{REDUCE_SIZE -= 0.001; printf("REDUCE_SIZE: %d\n", (int)REDUCE_SIZE);}
	if (engine->key_pressed[K_LEFT])
		{REDUCE_SIZE += 0.001; printf("REDUCE_SIZE: %d\n", (int)REDUCE_SIZE);}
	// CHANGE_ANGLE += 0.01;
	// char *pixel;
	// pixel = engine->img.addr + (100 * engine->img.line_len + 100 * (engine->img.bpp / 8));
	// *(unsigned int *)pixel = 0x5be838;
	// draw_pixel(&engine->img, (t_vector2){10, 10}, COLOR_GREEN);
	draw_rect(&engine->img, (t_vector2){0, 0}, (t_vector2){1920, 1080}, rgb(10, 10, 10));

	// draw_line(&engine->img, (t_vector2){112, 112}, (t_vector2){325, 400}, rgb(22, 222, 20), 22);

	draw(engine, START_SIZE, M_PI, (t_vector2){1920/2, 920}, rgb(44, 200, 20), 20);

	if (engine->key_pressed[K_ESCAPE])
		close(engine);
	engine_frame_update(engine);
	return (0);
}


typedef struct s_data
{
	int		x;
	int		y;
}	t_data;

int main(){
	t_data	data;
	data.x = 100;
	data.y = 100;

	engine_init(&data, &on_update);
	return 0;
}
