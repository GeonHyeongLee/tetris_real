#include "console.h"
#include "point.h"

typedef struct _cell_t {
    point_t point; // cell의 위치
    color_t color; // cell의 색상
    cell_attributes_t att; // cell의 속성
} cell_t;
