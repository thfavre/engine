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
void	frame_update(t_engine *engine)
{
	static	int all_fps;
	static	int frame_count;
	static	int total_frame_count;
	static	int total_fps_count;

	mlx_put_image_to_window(engine->mlx, engine->win, \
		engine->img.img, 0, 0);
	// DEBUG stuff
	engine->dt = get_elapsed_time();
	double fps = 1.0 / engine->dt;
	all_fps += fps;
	frame_count++;
	total_frame_count++;
	if (frame_count == 100)
	{
		total_fps_count += all_fps;
		printf("last %d frames avrage fps: %d\t(total: %d)\t(dt: %f)\n", frame_count, all_fps / frame_count, total_fps_count / total_frame_count, engine->dt);
		all_fps = 0;
		frame_count = 0;
	}
}

