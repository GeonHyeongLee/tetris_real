#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>
#include "colors.h"

typedef struct _cursor_info_t {
    uint32_t x;
    uint32_t y;
    bool is_hide;
} cursor_info_t;

typedef struct _windows_console_t {
    uint32_t cols;
    uint32_t rows;

    color_t fore_color;
    color_t back_color;

    cursor_info_t cursor_info;
} windows_console_t;

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);

void console_clear(windows_console_t* console);

void console_set_cursor(windows_console_t* console, uint32_t x, uint32_t y, bool value);

bool get_cursor_visibility(void);

void console_set_size(windows_console_t* console, uint32_t cols, uint32_t rows);

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);

void console_display_info(const windows_console_t* console);

void console_init(windows_console_t* console);
