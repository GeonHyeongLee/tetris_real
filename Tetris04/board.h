#ifndef BOARD_H
#define BOARD_H

#include "block.h"         // block_t 타입 사용
#include "console_util.h"  // windows_console_t, cell_t 사용

#define BOARD_WIDTH  (10 + 2)   // 양 옆 벽 포함
#define BOARD_HEIGHT (20 + 1)   // 바닥 포함

#define BOARD_START_X 4
#define BOARD_START_Y 4

// 방향 enum (가독성 개선)
typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} move_dir_t;

// 외부에서 사용할 함수들
void board_init(const cell_attributes_t data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);

void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);
void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);

void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, move_dir_t dir);

void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // 디버깅용
void board_rotate_block(block_t* block); // TODO: 구현 예정

#endif
