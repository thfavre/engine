/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:01:37 by thomas            #+#    #+#             */
/*   Updated: 2023/04/10 21:16:36 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Questions :
	- how to close the window when user press on ESC or close button
	- text ??  https://lvgl.io/tools/font_conv_v5_3 ?
*/

#include "engine.h"

int	on_close(t_engine *engine)
{
	printf("on_close\n");
	engine_close(engine);
	return (0);
}

int	on_update(t_engine *engine)
{
	engine_draw_background(&engine->img, COLOR_BLACK);
	engine_draw_circle(&engine->img, (t_circle){
		.center = (t_vector2){500, 500},
		.radius = 100, // You don't see that little norminette ;)
		.thickness = 12,
		.color = COLOR_RED});
	engine_draw_pixel(&engine->img, (t_vector2){800, 500}, COLOR_RED);

    mlx_string_put(engine->mlx, &engine->win, 100, 100, COLOR_AQUA, "HEY!");

	engine_frame_update(engine);


	if (engine->key_pressed[K_ESC])
		on_close(engine);
	return (0);
}

int	main(void)
{
// 	int test(void)
// 	{
// 	printf("test\n");
// 	return (0);
// }
// test();
engine_init(NULL, &on_update, &on_close);
}
