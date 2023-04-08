#include "engine.h"


#include <time.h>
double get_elapsed_time() // DEBUG stuff
{
    static clock_t start_time = 0;
    // if (start_time == 0) {
    //     start_time = clock();
    //     return 0.0;
    // } else {
        clock_t current_time = clock();
        double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
		start_time = clock();
        return elapsed_time;
    // }
}


/*
 * Updates the engine's window by drawing the current image to the window
 *
 * @param engine: pointer to the engine structure containing data about
 *                the window and image
*/
void	engine_frame_update(t_engine *engine)
{
	static	int all_fps;
	static	int frame_count;

	mlx_put_image_to_window(engine->mlx, engine->win, \
		engine->img.img, 0, 0);
	// DEBUG stuff
	double dt = get_elapsed_time();
	double fps = 1.0 / dt;
	all_fps += fps;
	frame_count++;
	if (frame_count == 100)
	{
		printf("average fps: %d  (dt: %f)\n", all_fps / frame_count, dt);
		all_fps = 0;
		frame_count = 0;
	}
}

