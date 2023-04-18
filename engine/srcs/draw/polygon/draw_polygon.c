#include <limits.h>
#include "image.h"
#include "vector2.h"

void	draw_x_line(t_img *img, t_vector2 start, int length, int color, int thickness);

#include <float.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

void swap_float(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort_intersections(float *intersections, int num_intersections) {
    for (int i = 0; i < num_intersections - 1; i++) {
        for (int j = i + 1; j < num_intersections; j++) {
            if (intersections[i] > intersections[j]) {
                swap_float(&intersections[i], &intersections[j]);
            }
        }
    }
}

void engine_draw_polygon(t_img *img, t_vector2 *vertices, int num_vertices, int color) {
    if (img == NULL || vertices == NULL || num_vertices <= 2) {
        fprintf(stderr, "Invalid input parameters\n");
        return;
    }

    int min_y = INT_MAX;
    int max_y = INT_MIN;
    int i;

    for (i = 0; i < num_vertices; i++) {
        if (vertices[i].y < min_y) {
            min_y = vertices[i].y;
        }
        if (vertices[i].y > max_y) {
            max_y = vertices[i].y;
        }
    }

    for (int y = min_y; y <= max_y; y++) {
        int num_intersections = 0;
        float intersections[num_vertices];

        for (i = 0; i < num_vertices; i++) {
            int j = (i + 1) % num_vertices;
            if (fabs(vertices[j].y - vertices[i].y) > FLT_EPSILON) {
                if ((vertices[i].y <= y && y < vertices[j].y) || (vertices[j].y <= y && y < vertices[i].y)) {
                    float x = (y - vertices[i].y) * (vertices[j].x - vertices[i].x) / (vertices[j].y - vertices[i].y) + vertices[i].x;
                    intersections[num_intersections++] = x;
                }
            }
        }

        sort_intersections(intersections, num_intersections);

        for (i = 0; i < num_intersections - 1; i += 2) {
            int length = (int) (intersections[i + 1] - intersections[i] + 0.5);
            draw_x_line(img, (t_vector2){intersections[i], y}, length, color, 1);
        }
    }
}
