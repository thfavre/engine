#include "engine.h"

/*
 * Closes the engine, destroys the window, and releases the memory resources
 *
 * @param engine: pointer to the engine structure containing data about the
 *                window and mlx
*/
void	engine_close(t_engine *engine)
{
	free(engine->mlx);
	exit(0);
}
