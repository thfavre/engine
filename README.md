(Work in progress)
# Description
- 2d graphical engine 
- Made in C with the MinilibX
- Is at 42 norme
- Works on Mac and Linux

# Structure
```
your_project_folder/
├── Makefile
└── engine/
    ├── Makefile
    ├── srcs/
    ├── includes/
    └── mlx/
        ├── mlx_linux/
        │   ├── Makefile
        │   └── srcs
        └── mlx_mac/
            ├── Makefile
            └── srcs

```

# Examples
## Ideas
- https://www.cis.upenn.edu/~cis110/13su/hw/hw03/gallery.shtml
- https://www.cs.princeton.edu/courses/archive/spr15/cos126/art/index.php

## Fractal canopy
<details>
    <summary><b>Code</b></summary>
    <p>
    
  ```C
  #include "engine.h"
   
  void	draw_tree(t_engine *engine, float size, double angle, t_vector2 start_pos, int color, int thickness)
  {
	t_vector2	end_pos;

	end_pos.x = start_pos.x + sin(angle) * size;
	end_pos.y = start_pos.y + cos(angle) * size;
	engine_draw_line(&engine->img, start_pos, end_pos, color, thickness);
	size /= REDUCE_SIZE;
	if (size > 10)
	{
		thickness -= 6;
		if (thickness < 1)
			thickness = 1;
		draw_tree(engine, size, angle + CHANGE_ANGLE, end_pos, engine_add_color(color, engine_rgb(0, 18, 1)), thickness);
		draw_tree(engine, size, angle - CHANGE_ANGLE, end_pos, engine_add_color(color, engine_rgb(0, 18, 1)), thickness);
	}
  }

  int	on_update(t_engine *engine)
  {
	// keys
	if (engine->key_pressed[K_UP])
		START_SIZE += 1; 
	if (engine->key_pressed[K_DOWN])
		START_SIZE -= 1; 
	// draw
	engine_draw_rect(&engine->img, (t_vector2){0, 0}, (t_vector2){1920, 1080}, engine_rgb(10, 10, 10));
	draw_tree(engine, START_SIZE, M_PI, (t_vector2){1920/2, 920}, engine_rgb(102, 51, 0), 35);
	// update
	engine_frame_update(engine);
	return (0);
  }
  
  
  int main()
  {
	engine_init(NULL, &on_update);
  }
 
  ```
  
  </p>
  </summary>
</details>
<details>
  <summary><b>Result</b></summary>
    <p>
    
   [![Watch the video]fractal_canopy.mp4)]
   
   <img src="fractal_canopy.mp4" width="500" height="500" />
    
  </p>
  </summary>
</details>
