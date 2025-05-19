#include "cell.h"

void cell_init(cell_t* cell, int x, int y, cell_attributes_t att, color_t color) {
    cell->point.x = x;
    cell->point.y = y;
    cell->att = att;
    cell->color = color;
}
