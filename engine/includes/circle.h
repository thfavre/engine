#ifndef CIRCLE_H
# define CIRCLE_H

# include "vector2.h"

typedef struct s_circle
{
	t_vector2		center;
	unsigned int	radius;
	unsigned int	thickness; // 0 = filled
	int				color;
} t_circle;

#endif
