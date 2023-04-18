#include "vector2.h"
#include "image.h"
#include "circle.h"
#include "math.h"
#include "draw.h"

void	draw_x_line(t_img *img, t_vector2 start, int length, int color, int thickness);
// void	draw_block(unsigned int *pixel_ptr, int chunk_size, int color);


// void draw_filled_circle_bresenham(t_img *img, t_circle circle) {
// 	int x = 0;
// 	int y = circle.radius;
// 	int d = 3 - 2 * circle.radius;

// 	unsigned int *center_pixel_ptr = (unsigned int *)(img->addr + (circle.center.y * img->line_len + circle.center.x * (img->bpp / 8)));
// 	int line_step = img->line_len / (img->bpp / 8);

// 	while (x <= y) {
// 		draw_horizontal_line(center_pixel_ptr - x - y * line_step, 2 * x + 1, circle.color);
// 		draw_horizontal_line(center_pixel_ptr - x + y * line_step, 2 * x + 1, circle.color);
// 		draw_horizontal_line(center_pixel_ptr - y - x * line_step, 2 * y + 1, circle.color);
// 		draw_horizontal_line(center_pixel_ptr - y + x * line_step, 2 * y + 1, circle.color);

// 		x++;
// 		if (d <= 0) {
// 			d += 4 * x + 6;
// 		} else {
// 			d += 4 * (x - y) + 10;
// 			y--;
// 		}

// 	}
// }

// void draw_horizontal_line(unsigned int *pixel_ptr, int length, unsigned int color) {
// 	// Draw the chunk
// 	int chunk_size = length - (length % 12);
// 	draw_block(pixel_ptr, chunk_size, color);

// 	// Draw the remaining pixels
// 	for (int x = chunk_size; x < length; x++) {
// 		pixel_ptr[x] = color;
// 	}
// }



// algo from (https://stackoverflow.com/a/59211338s)
// __attribute__ ((optimize(1))) // needed?
void	draw_filled_circle(t_img *img, t_circle circle)
{
	int	radius = circle.radius;
	int	radius_sqr = radius * radius;
	int	color = circle.color;

	// --------------  210 FPS -------------- //
	for (int y = -radius; y < radius; y++)
	{
		int ww = (int)sqrt(radius_sqr - y * y);
		int ry = circle.center.y + y;
		int pw = circle.center.x + ww;
		// engine_draw_rect(img, (t_rect){(t_vector2){circle.center.x - ww, ry}, (t_vector2){pw-(circle.center.x-ww), 1}}, color);

		draw_x_line(img, (t_vector2){circle.center.x - ww, ry}, pw-(circle.center.x-ww), color, 1);
	}


	// -------------- 240 FPS -------------- //
	// for (int y = -radius; y <= radius; y++) {
	// 	int ww = (int)sqrt(radius_sqr - y * y);
	// 	int ry = circle.center.y + y;
	// 	int x_start = circle.center.x - ww;
	// 	int x_end = circle.center.x + ww;
	// 	int length = x_end - x_start + 1;

	// 	unsigned int *pixel_ptr = (unsigned int *)(img->addr + (ry * img->line_len + x_start * (img->bpp / 8)));

	// 	// Draw the chunk
	// 	int chunk_size = length - (length % 12);
	// 	draw_block(pixel_ptr, chunk_size, color);

	// 	// Draw the remaining pixels
	// 	for (int x = chunk_size; x < length; x++) {
	// 		pixel_ptr[x] = color;
	// 	}
	// }


	// --------------  260 FPS -------------- //
	// draw_filled_circle_bresenham(img, circle);



	// for (int x = -radius; x < radius ; x++)
	// {
	// 	int hh = (int)sqrt(radius_sqr - x * x);
	// 	int rx = circle.center.x + x;
	// 	int ph = circle.center.y + hh;
	// 	for (int y = circle.center.y-hh; y < ph; y++)
	// 		engine_draw_pixel(img, (t_vector2){rx, y}, color);
	// }
}

// void draw_filled_circle(t_img *img, t_circle circle) {
//     int radius = circle.radius;
//     int radius_sqr = radius * radius;

//     int cx = circle.center.x;
//     int cy = circle.center.y;

//     for (int y = -radius; y <= radius; y++) {
//         for (int x = -radius; x <= radius; x++) {
//             int dist_sqr = x * x + y * y;
//             if (dist_sqr <= radius_sqr) {
//                 // engine_draw_pixel(img, (t_vector2){cx + x, cy + y}, circle.color);
//             }
//         }
//     }
// }

// void draw_filled_circle(t_img *img, t_circle circle)
// {
//     int x = 0;
//     int y = circle.radius;
//     int p = 3 - 2 * circle.radius;

//     void draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
//     {
//         for (int x = x1; x <= x2; x++)
//         {
//             engine_draw_pixel(img, (t_vector2){x, y1}, color);
//             engine_draw_pixel(img, (t_vector2){x, y2}, color);
//         }
//     }

//     while (x <= y)
//     {
//         draw_line(img, circle.center.x - x, circle.center.y + y, circle.center.x + x, circle.center.y + y, circle.color);
//         draw_line(img, circle.center.x - x, circle.center.y - y, circle.center.x + x, circle.center.y - y, circle.color);
//         draw_line(img, circle.center.x - y, circle.center.y + x, circle.center.x + y, circle.center.y + x, circle.color);
//         draw_line(img, circle.center.x - y, circle.center.y - x, circle.center.x + y, circle.center.y - x, circle.color);

//         if (p < 0)
//         {
//             p = p + 4 * x + 6;
//         }
//         else
//         {
//             p = p + 4 * (x - y) + 10;
//             y--;
//         }
//         x++;
//     }
// }
// void draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
//     {
//         for (int x = x1; x <= x2; x++)
//         {
//             engine_draw_pixel(img, (t_vector2){x, y1}, color);
//             engine_draw_pixel(img, (t_vector2){x, y2}, color);
//         }
//     }
// void draw_filled_circle(t_img *img, t_circle circle)
// {
//     int x = 0;
//     int y = circle.radius;
//     int d = 3 - 2 * circle.radius;



//     while (y >= x)
//     {
//         draw_line(img, circle.center.x - x, circle.center.y + y, circle.center.x + x, circle.center.y + y, circle.color);
//         draw_line(img, circle.center.x - x, circle.center.y - y, circle.center.x + x, circle.center.y - y, circle.color);
//         draw_line(img, circle.center.x - y, circle.center.y + x, circle.center.x + y, circle.center.y + x, circle.color);
//         draw_line(img, circle.center.x - y, circle.center.y - x, circle.center.x + y, circle.center.y - x, circle.color);

//         x++;

//         if (d > 0)
//         {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         else
//         {
//             d = d + 4 * x + 6;
//         }
//     }
// }
