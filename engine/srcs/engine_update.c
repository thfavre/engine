
#include "engine.h"

void	frame_update(t_engine *engine);

void	engine_update(t_engine *engine)
{
	#if __APPLE__
		mlx_mouse_get_pos(engine->win, &engine->mouse_pos.x, &engine->mouse_pos.y);
	# else
		mlx_mouse_get_pos(engine->mlx, engine->win, &engine->mouse_pos.x, &engine->mouse_pos.y);
	#endif
	frame_update(engine);
}
