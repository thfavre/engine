# include "engine.h"
#include <math.h>
double	CHANGE_ANGLE = M_PI/6;
double	REDUCE_SIZE = 1.25;
double	START_SIZE = 100;


void	draw_tree(t_engine *engine, float size, double angle, t_vector2 start_pos, int color, int thickness)
{
	t_vector2	end_pos;

	end_pos.x = start_pos.x + sin(angle) * size;
	end_pos.y = start_pos.y + cos(angle) * size;

	engine_draw_line(&engine->img, start_pos, end_pos, color, thickness);

	size /= REDUCE_SIZE;
	if (size > 10)
	{
			thickness -= 6;
		if (thickness <= 1)
			thickness = 1;
		draw_tree(engine, size, angle + CHANGE_ANGLE, end_pos, engine_add_color(color, engine_rgb(0, 18, 1)), thickness);
		draw_tree(engine, size, angle - CHANGE_ANGLE, end_pos, engine_add_color(color, engine_rgb(0, 18, 1)), thickness);
	}
}


int	on_update(t_engine *engine)
{
	// keys
	if (engine->key_pressed[K_UP])
		{START_SIZE += 1; printf("START_SIZE: %d\n", (int)START_SIZE);}
	if (engine->key_pressed[K_DOWN])
		{START_SIZE -= 1; if (START_SIZE < 0)START_SIZE=0; printf("START_SIZE: %d\n", (int)START_SIZE);}
	if (engine->key_pressed[K_RIGHT])
		{REDUCE_SIZE -= 0.001; printf("REDUCE_SIZE: %.2f\n", REDUCE_SIZE);}
	if (engine->key_pressed[K_LEFT])
		{REDUCE_SIZE += 0.001; printf("REDUCE_SIZE: %.2f\n", REDUCE_SIZE);}
	if (engine->key_pressed[K_D])
		{CHANGE_ANGLE -= 0.01; printf("CHANGE_ANGLE: %.2f\n", CHANGE_ANGLE);}
	if (engine->key_pressed[K_A])
		{CHANGE_ANGLE += 0.01; printf("CHANGE_ANGLE: %.2f\n", CHANGE_ANGLE);}
	// draw
	engine_draw_background(&engine->img, engine_rgb(10, 10, 10));
	draw_tree(engine, START_SIZE, M_PI, (t_vector2){1920/2, 1000}, engine_rgb(102, 51, 0), 35);
	// close
	if (engine->key_pressed[K_ESCAPE])
		engine_close(engine);
	// update
	engine_frame_update(engine);
	return (0);
}


int main(){
	engine_init(NULL, &on_update, NULL);
}
