/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:01:37 by thomas            #+#    #+#             */
/*   Updated: 2023/04/08 17:05:41 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	on_update(t_engine *engine)
{
	engine_draw_background(&engine->img, COLOR_BLACK);
	engine_draw_circle(&engine->img, (t_circle){
		.center = (t_vector2){500, 500},
		.radius = 100, // You don't see that little norminette ;)
		.thickness = 12,
		.color = COLOR_RED});
	engine_frame_update(engine);
	return (0);
}

int	main(void)
{
	engine_init(NULL, &on_update);
}
