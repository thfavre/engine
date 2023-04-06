# include "engine.h"

/*
 * Closes the engine, destroys the window, and releases the memory resources
 *
 * @param engine: pointer to the engine structure containing data about
 *                the window and mlx
*/
void	engine_init(void *data, int (*on_update)(t_engine *engine))
{
	t_engine	engine;
	engine.mlx = mlx_init(); // test is null
	engine.win = mlx_new_window(engine.mlx, 1920, 1080, "Hello World!");
	engine.img.img = mlx_new_image(engine.mlx, 1920, 1080);
	engine.img.size = (t_vector2){1920, 1080};
	engine.img.addr = mlx_get_data_addr(engine.img.img, &engine.img.bpp,
		&engine.img.line_len, &engine.img.endian);
	engine.data = data;

	// engine.img.size = (t_vector2){1920, 1080};
	// for (int i = 0; i < 1000; i++)
		// mlx_hook(engine.win, i, 0, &on_keypress, &engine);
		// mlx_hook(engine.win, KeyPress, 0, &on_keypress, &engine);
		// engine.img.addr[i] = 0;

	keys_init(engine.key_pressed);

	// hooks
		// keys
	// mlx_do_key_autorepeaton(engine.mlx);
	// mlx_do_key_autorepeatoff(engine.mlx);
	mlx_hook(engine.win, KeyPress, KeyPressMask, &on_keypressed, &engine.key_pressed);
	mlx_hook(engine.win, KeyRelease, KeyReleaseMask, &on_keyreleased, &engine.key_pressed);
		// loop
	mlx_loop_hook(engine.mlx, on_update, &engine);
	mlx_loop(engine.mlx);

}
