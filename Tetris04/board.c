#include "board.h"
#include <stdio.h>

// 전역 보드 선언 (여기서만 사용하게 제한)
cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0 };

// 보드 초기 상태
extern cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH];

void board_init(const cell_attributes_t data[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            gboard[i][j].point.x = BOARD_START_X + j;
            gboard[i][j].point.y = BOARD_START_Y + i;
            gboard[i][j].att = data[i][j];
            gboard[i][j].color = YELLOW;
        }
    }
}

void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            switch (board[i][j].att) {
            case W:
                console_set_fore_color(console, GREEN);
                break;
            case N:
                console_set_fore_color(console, RED);
                break;
            case E:
            default:
                console_set_fore_color(console, WHITE);
                break;
            }
            cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
            console_set_default_color(console);
        }
    }
}

void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j].att != W) {
                board[i][j].att = E;
            }
        }
    }
}

void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y) {
    block->x = block_x;
    block->y = block_y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            if (block->att[block->rotation_index][i][j] == N) {
                board[block_y + i][block_x + j].att = N;
            }
        }
    }
}

void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y) {
    cell->point.x = cell_x;
    cell->point.y = cell_y;
    board[cell->point.y][cell->point.x].att = cell->att;
}

void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, move_dir_t dir) {
    board_clear_data(board);

    switch (dir) {
    case DIR_UP:    block->y -= 1; break;
    case DIR_DOWN:  block->y += 1; break;
    case DIR_LEFT:  block->x -= 1; break;
    case DIR_RIGHT: block->x += 1; break;
    }

    board_insert_block(board, block, block->x, block->y);
    board_draw(console, board);
}

void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("(%d,%d) ", board[i][j].point.x, board[i][j].point.y);
        }
        printf("\n");
    }
}

void board_rotate_block(block_t* block) {
    // 아직 미구현
}
