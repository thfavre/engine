# include "engine.h"
#include <math.h>
double	CHANGE_ANGLE = M_PI/6;
double	REDUCE_SIZE = 1.25 - 0.07;
double	START_SIZE = 150;
void	draw_x_line(t_img *img, t_vector2 start, int length, int color, int thickness);

int NB_LINES = 0;
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

float COLOR_OFFSET = 0;

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

	t_rect rect;
	rect.size.x = 8;
	rect.size.y = rect.size.x;
	int mx, my;
	mlx_mouse_get_pos(engine->mlx, engine->win, &mx, &my);

	for (int x=0, i=0; x < engine->img.size.x; x+=rect.size.x, i++)
	{
		for (int y=0, j=0; y < engine->img.size.y; y+=rect.size.y, j++)
		{
			rect.pos.x = x;
			rect.pos.y = y;
			engine_draw_rect(&engine->img, rect, engine_rgb(mx+i, my+j, (i*1.5 + j)/1000)); //0x119000 + i/2 + j*1.4 + COLOR_OFFSET
		}
	}
	// COLOR_OFFSET += 0.052;
	// int total_rect = 0;
	// for (int y = 10; y < 200*5; y+=200)
	// 	for (int x = 10; x < 200*9; x+=200, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){180, 180}}, engine_rgb(77, 55, 1));
	// for (int y = 15; y < 200*5; y+=200)
	// 	for (int x = 15; x < 200*9; x+=200, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){144, 144}}, engine_rgb(77, 55, 122));
	// for (int y = 50; y < 200*5; y+=100)
	// 	for (int x = 50; x < 200*9; x+=100, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){80, 80}}, engine_rgb(66, 88, 44));
	// for (int y = 75; y < 50*20; y+=50)
	// 	for (int x = 75; x < 50*30; x+=50, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){40, 40}}, engine_rgb(200, 122, 122));
	// for (int y = 100; y < 990; y+=20)
	// 	for (int x = 75; x < 1000; x+=20, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){12, 12}}, engine_rgb(200, 222, 122));
	// for (int y = 100; y < 990; y+=10)
	// 	for (int x = 1100; x < 1860; x+=30, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){20, 5}}, engine_rgb(200, 222, 222));
	// for (int y = 130; y < 900; y+=25)
	// 	for (int x = 1130; x < 1800; x+=8, total_rect++)
	// 		engine_draw_rect(&engine->img, (t_rect){(t_vector2){x, y}, (t_vector2){4, 20}}, engine_rgb(11, 11, 233));
	// printf("TOTAL_RECT: %d\n", total_rect); // 7854



	// draw_x_line(&engine->img, (t_vector2){200, 200}, 400, engine_rgb(102, 51, 0), 40);
	// engine_draw_line(&engine->img, (t_vector2){200, 400}, (t_vector2){600, 400}, engine_rgb(102, 51, 0), 40);
	// draw_tree(engine, START_SIZE, M_PI, (t_vector2){1920/2, 970}, engine_rgb(102, 51, 0), 40);
	// printf("NB_LINES: %d\n", NB_LINES);
	NB_LINES = 0;
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
