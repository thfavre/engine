/*
Questions :
	- how to close the window when user press on ESC or close button
	- text ??  https://lvgl.io/tools/font_conv_v5_3 ?
*/

#include "engine.h"
#include <stdlib.h>

int BALL_NB = 1000;

typedef struct s_ball
{
	int 		radius;
	int 		color;
	t_fvector2	pos;
	t_fvector2	vel;
} t_ball;


t_ball create_ball(int radius, int color, t_fvector2 pos, t_fvector2 vel)
{
	t_ball ball;

	ball.radius = radius;
	ball.color = color;
	ball.pos = pos;
	ball.vel = vel;
	return (ball);
}

t_fvector2 random_velocity(float min, float max)
{
    t_fvector2 vel;
    float range = max - min;

    vel.x = min + (float) rand() / (RAND_MAX / range);
    vel.y = min + (float) rand() / (RAND_MAX / range);

    return vel;
}

t_ball	*create_balls(int nb)
{
	t_ball		*balls;
	int			i;

	balls = malloc(sizeof(t_ball) * nb);
	i = 0;
	while (i < nb)
	{
		balls[i] = create_ball(50, COLOR_ALICEBLUE, (t_fvector2){500, 500}, random_velocity(-4.0f, 4.0f));
		i++;
	}
	return (balls);
}

void	update_ball(t_ball *ball, t_engine *engine)
{
	ball->pos.x += ball->vel.x; // * engine->dt;
	ball->pos.y += ball->vel.y; // * engine->dt;
	if (ball->pos.x + ball->radius >= engine->img.size.x)
	{
		ball->pos.x = engine->img.size.x - ball->radius;
		ball->vel.x *= -1;
	}
	if (ball->pos.x - ball->radius <= 0)
	{
		ball->pos.x = ball->radius;
		ball->vel.x *= -1;
	}
	if (ball->pos.y + ball->radius >= engine->img.size.y)
	{
		ball->pos.y = engine->img.size.y - ball->radius;
		ball->vel.y *= -1;
	}
	if (ball->pos.y - ball->radius <= 0)
	{
		ball->pos.y = ball->radius;
		ball->vel.y *= -1;
	}
	engine_draw_circle(&engine->img, (t_circle){
		.center = (t_vector2){ball->pos.x, ball->pos.y},
		.radius = ball->radius,
		.thickness = 0,
		.color = ball->color});
}

void	update_balls(t_ball *balls, int nb, t_engine *engine)
{
	int i;

	i = 0;
	while (i < nb)
		update_ball(&balls[i++], engine);
}


int	on_close(t_engine *engine)
{
	printf("on_close\n");
	engine_close(engine);
	return (0);
}
float X = 0;
float Y = 0;
int color = COLOR_RED;
int	on_update(t_engine *engine)
{
	engine_draw_background(&engine->img, COLOR_BLACK);

	// Circles tests
	// update_balls(engine->data, BALL_NB, engine);
	// for (int x=100; x<1850; x+=100)
	// 	for (int y=100; y<1060; y+=100)
	// 	{
	// 		// if (x % 200 == 0 && y % 200 == 0)
	// 			engine_draw_circle(&engine->img, (t_circle){(t_vector2){x, y}, 70, 1, COLOR_YELLOW});
	// 		engine_draw_circle(&engine->img, (t_circle){(t_vector2){x, y}, 48, 1, COLOR_FIREBRICK4});
	// 		engine_draw_circle(&engine->img, (t_circle){(t_vector2){x, y}, 40, 1, COLOR_DEEPSKYBLUE3});
	// 		engine_draw_circle(&engine->img, (t_circle){(t_vector2){x, y}, 33, 1, COLOR_PALEGREEN4});
	// 	}

	//Lines tests
	// for (int x=12; x<1900; x+=12)
	// 	for (int y=12; y<1000; y+=35)
	// 	engine_draw_line(&engine->img, (t_vector2){x, y}, (t_vector2){x, y+30}, COLOR_YELLOW4, 4);

	// Polygons tests
	t_vector2 points[5] = {{400, 100}, {600, 150}, {700, 250}, {600, 400}, {300+X , 20+Y}};
	// t_vector2 points[5] = {{22, 22}, {900, 66}, {1801, 222}, {1890, 1011}, {300+X , 20+Y}};
	engine_draw_polygon(&engine->img, points, 5, COLOR_DEEPSKYBLUE3);
	for (int i=0; i < 5; i++)
	{
		if (color == COLOR_GREEN && i == 4)
			engine_draw_circle(&engine->img, (t_circle){points[i], 10, 0, COLOR_GREEN});
		else
			engine_draw_circle(&engine->img, (t_circle){points[i], 10, 0, COLOR_RED3});
	}
	color = COLOR_RED3;
	float move_speed = 0.4;
	engine_frame_update(engine);
	if (engine->key_pressed[K_D])
		{X += move_speed;color=COLOR_GREEN;}
	if (engine->key_pressed[K_A])
		{X -= move_speed;color=COLOR_GREEN;}
	if (engine->key_pressed[K_W])
		{Y -= move_speed;color=COLOR_GREEN;}
	if (engine->key_pressed[K_S])
		{Y += move_speed;color=COLOR_GREEN;}



	if (engine->key_pressed[K_ESC])
		on_close(engine);
	return (0);
}

int	main(void)
{
	t_ball	*balls = create_balls(BALL_NB);
// 	int test(void)
// 	{
// 	printf("test\n");
// 	return (0);
// }
// test();
engine_init(balls, &on_update, &on_close);
}
