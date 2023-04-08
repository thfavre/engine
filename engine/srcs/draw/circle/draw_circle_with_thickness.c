#include "vector2.h"
#include "image.h"
#include "circle.h"

void xLine(t_img *img, int x1, int x2, int y, int colour)
{
	while (x1 <= x2) engine_draw_pixel(img, (t_vector2){x1++, y}, colour);
}

void yLine(t_img *img, t_vector2 pos, int y2, int colour)
{
	while (pos.y <= y2)
	{
		pos.y++;
		engine_draw_pixel(img, pos, colour);
	}
}

void draw_circle_with_thickness(t_img *img, t_circle circle)
{
	int xo = circle.radius;
	int xi = circle.radius - circle.thickness;
	int y = 0;
	int erro = 1 - xo;
	int erri = 1 - xi;

	while(xo >= y) {
		xLine(img, circle.center.x + xi, circle.center.x + xo, circle.center.y + y,  circle.color);
		yLine(img, (t_vector2){circle.center.x + y,  circle.center.y + xi}, circle.center.y + xo, circle.color);
		xLine(img, circle.center.x - xo, circle.center.x - xi, circle.center.y + y,  circle.color);
		yLine(img, (t_vector2){circle.center.x - y,  circle.center.y + xi}, circle.center.y + xo, circle.color);
		xLine(img, circle.center.x - xo, circle.center.x - xi, circle.center.y - y,  circle.color);
		yLine(img, (t_vector2){circle.center.x - y,  circle.center.y - xo}, circle.center.y - xi, circle.color);
		xLine(img, circle.center.x + xi, circle.center.x + xo, circle.center.y - y,  circle.color);
		yLine(img, (t_vector2){circle.center.x + y,  circle.center.y - xo}, circle.center.y - xi, circle.color);
		y++;
		if (erro < 0) {
			erro += 2 * y + 1;
		} else {
			xo--;
			erro += 2 * (y - xo + 1);
		}
		if (y > circle.radius - circle.thickness) {
			xi = y;
		} else {
			if (erri < 0) {
				erri += 2 * y + 1;
			} else {
				xi--;
				erri += 2 * (y - xi + 1);
			}
		}
	}
}
