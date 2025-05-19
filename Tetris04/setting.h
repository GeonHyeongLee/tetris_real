#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdbool.h>

//
// 색상 타입 (콘솔 색상용)
//
typedef enum _color_t {
    BLACK = 0,
    BLUE,
    GREEN,
    CYAN,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_PURBPLE,
    LIGHT_YELLOW,
    LIGHT_WHITE
} color_t;

//
// 셀 속성 (보드 내의 상태)
//
typedef enum {
    W, // Wall
    E, // Empty
    N  // Normal block
} cell_attributes_t;

//
// 좌표 정보
//
typedef struct _point_t {
    uint32_t x;
    uint32_t y;
} point_t;

//
// 셀 구조체 (보드의 단위 요소)
//
typedef struct _cell_t {
    point_t point;             // 셀 위치
    color_t color;             // 셀 색상
    cell_attributes_t att;     // 셀 속성
} cell_t;

//
// 콘솔 커서 정보
//
typedef struct _cursor_info_t {
    uint32_t x;
    uint32_t y;
    bool is_hide;
} cursor_info_t;

//
// 콘솔 정보 구조체
//
typedef struct _windows_console_t {
    uint32_t cols;
    uint32_t rows;

    color_t fore_color;
    color_t back_color;

    cursor_info_t cursor_info;
} windows_console_t;

#endif // COMMON_H
