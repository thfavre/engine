# include "project.h"

void	close(t_engine *engine)
{
	printf("Close\n");
	engine_close(engine);
}

int	on_update(t_engine *engine)
{
	char *pixel;
	pixel = engine->img.addr + (100 * engine->img.line_len + 100 * (engine->img.bpp / 8));
	*(unsigned int *)pixel = 0x5be838;
	// draw_pixel(&engine->img, (t_vector2){10, 10}, COLOR_GREEN);
	// draw_rect(&engine->img, (t_vector2){100, 100}, (t_vector2){120, 100}, rgb(200, 10, 20));
	if (engine->key_pressed[K_ESCAPE])
		close(engine);
	// engine_frame_update(engine);
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
