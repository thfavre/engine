#include "engine.h"

/*
 * Closes the engine, destroys the window, and releases the memory resources
 *
 * @param engine: pointer to the engine structure containing data about the
 *                window and mlx
*/
void	engine_close(t_engine *engine)
{
	// mlx_do_key_autorepeaton(engine->mlx);
	// mlx_destroy_window(engine->mlx, engine->win);
	free(engine->mlx);
	exit(0);
}
