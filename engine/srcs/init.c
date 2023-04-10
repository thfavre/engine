#include "engine.h"

/*
 * Closes the engine, destroys the window, and releases the memory resources
 *
 * @param engine: pointer to the engine structure containing data about
 *                the window and mlx
*/
void	engine_init(void *data, int (*on_update)(t_engine *engine),
						int (*on_close)(t_engine *engine))
{
	t_engine	engine;
	engine.mlx = mlx_init(); // test is null
	engine.win = mlx_new_window(engine.mlx, 1920, 1080, "Hello World!");
	engine.img.img = mlx_new_image(engine.mlx, 1920, 1080);
	engine.img.size = (t_vector2){1920, 1080};
	engine.img.addr = mlx_get_data_addr(engine.img.img, &engine.img.bpp,
		&engine.img.line_len, &engine.img.endian);
	engine.data = data;
	keys_init(engine.key_pressed);
	mlx_hook(engine.win, KeyPress, KeyPressMask, on_keypressed, &engine.key_pressed);
	mlx_hook(engine.win, KeyRelease, KeyReleaseMask, on_keyreleased, &engine.key_pressed);

	mlx_hook(engine.win, DestroyNotify, NoEventMask, on_close, &engine); // add a struct to pass the engine and the user callback?
	mlx_loop_hook(engine.mlx, on_update, &engine);
	mlx_loop(engine.mlx);

}

// TODO to close the window.
/*
void engine_init(void *data,
                 int (*on_update)(t_engine *engine),
                 int (*user_on_close)(t_engine *engine))
{
    // ... other initialization code

    // Pass the user-defined callback to engine_close
    mlx_hook(engine.win, DestroyNotify, NoEventMask, engine_close, &(t_engine_close_callback){&engine, user_on_close});
}

typedef struct s_engine_close_callback
{
    t_engine *engine;
    int (*user_on_close)(t_engine *engine);
} t_engine_close_callback;


int engine_close(void *param)
{
    t_engine_close_callback *callback = (t_engine_close_callback *)param;
    t_engine *engine = callback->engine;

    printf("on_close\n");

    // Call user-defined callback function to free user-specific resources
    if (callback->user_on_close)
    {
        callback->user_on_close(engine);
    }

    // Add any necessary clean-up code for your engine here

    return (0);
}

*/
