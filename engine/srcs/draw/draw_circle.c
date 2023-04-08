# include "draw.h"
# include "circle.h"

void	draw_filled_circle(t_img *img, t_circle circle);
void	draw_thin_circle(t_img *img, t_circle circle);
void	draw_circle_with_thickness(t_img *img, t_circle circle);

/*
 * Draws a circle on the given surface.
 *
 * @param img: pointer to the image structure containing data about the image
 * @param circle: t_circle struct containing the (x, y) coordinates of the center,
 *                radius, thickness, and color of the circle.
 *                A thickness of 0: filled circle
*/
void	engine_draw_circle(t_img *img, t_circle circle)
{
	if (circle.thickness == 0 || circle.thickness == circle.radius)
		draw_filled_circle(img, circle);
	else if (circle.thickness == 1)
		draw_thin_circle(img, circle);
	else
		draw_circle_with_thickness(img, circle);
}

