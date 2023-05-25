#ifndef ENGINE_H
# define ENGINE_H

# include <stdio.h> // TODO delete
# include <stdbool.h>
# include <stdlib.h>

# include "mlx.h" // put in envey file that uses mlx to make it invisible to the user?
# include "image.h"
# include "keycodes.h"
# include "vector2.h"
# include "draw.h"
# include "color.h"
# include "rect.h"
# include "circle.h"

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_img		img;
	void		*data;
	bool		key_pressed[MAX_KEYS];
	t_vector2	mouse_pos;
	float		dt;
}	t_engine;


// typedef struct {
//     int id;
//     char* name;
// } t_employee;

// #define EMPLOYEE(...) ((t_employee) { .id = 13, .name = "none", __VA_ARGS__ })


void	engine_init(void *data, int (*on_update)(t_engine *engine),
			int (*on_close)(t_engine *engine));
void	engine_update(t_engine *engine);
void	engine_close(t_engine *engine);


#endif
