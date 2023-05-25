/*
Questions :
	- how to close the window when user press on ESC or close button
	- text ??  https://lvgl.io/tools/font_conv_v5_3 ?
*/

#include "engine.h"
#include <stdlib.h>



int	on_close(t_engine *engine)
{
	printf("on_close\n");
	engine_close(engine);
	return (0);
}



int	on_update(t_engine *engine)
{
	engine_draw_background(&engine->img, COLOR_BLACK);
	for (int i =0; i<188; i+=1)
		for (int j =0; j<100; j+=1)
			engine_draw_rect(&engine->img, (t_rect){i*10, j*10, 9, 9}, COLOR_WHITE+i*engine->mouse_pos.x/2+j*engine->mouse_pos.y);

	// engine_draw_line(&engine->img, (t_vector2){0, 0}, (t_vector2){engine->img.size.x, engine->img.size.y}, COLOR_WHITE, 5);

	engine_update(engine);

	if (engine->key_pressed[K_ESC])
		on_close(engine);
	return (0);
}

enum e_tile_type
{
	EMPTY,
	WALL,
	PLAYER
};

struct s_data
{
	enum e_tile_type	map[10][10];
	t_vector2			player_pos;
};

int	main(void)
{
	struct s_data data;
	// data.map = {
	// 	{WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
	// 	{WALL, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL}
	// };
	engine_init(NULL, &on_update, &on_close);
}
