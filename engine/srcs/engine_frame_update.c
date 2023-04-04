#include "engine.h"

/*
 * Updates the engine's window by drawing the current image to the window
 *
 * @param engine: pointer to the engine structure containing data about
 *                the window and image
*/
void	engine_frame_update(t_engine *engine)
{
	mlx_put_image_to_window(engine->mlx, engine->win, \
		engine->img.img, 0, 0);
}
