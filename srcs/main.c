/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:01:37 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 00:30:08 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Questions :
	- how to close the window when user press on ESC or close button
	- text ??  https://lvgl.io/tools/font_conv_v5_3 ?
*/

#include "engine.h"
#include <stdlib.h>

BALL_NB = 100;

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
		balls[i] = create_ball(100, COLOR_ALICEBLUE, (t_fvector2){500, 500}, random_velocity(-4.0f, 4.0f));
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

int	on_update(t_engine *engine)
{
	engine_draw_background(&engine->img, COLOR_BLACK);

	update_balls(engine->data, BALL_NB, engine);

	engine_frame_update(engine);


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
