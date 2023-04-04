#ifndef ENGINE_H
# define ENGINE_H

# include <stdio.h> // TODO delete
# include <stdbool.h>
# include <stdlib.h>

# include "../mlx/mlx.h"
# include "image.h"
# include "events.h"
# include "key.h"
# include "vector2.h"
# include "draw.h"
# include "color.h"

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	t_img	img;
	void	*data;
	bool	key_pressed[MAX_KEYS];
}	t_engine;

void	engine_init(void *data, int (*on_update)(t_engine *engine));
void	engine_frame_update(t_engine *engine);
void	engine_close(t_engine *engine);


#endif
