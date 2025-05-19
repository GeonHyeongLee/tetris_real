#include "colors.h"

char* color_strings[16] = {
    "black", // 검정
    "blue", // 파랑
    "green", // 초록
    "cyan", // 청록
    "red", // 빨강
    "purple", // 자주
    "yellow", // 노랑
    "white", // 흰색
    "gray", // 회색
    "light blue", // 밝은 파랑
    "light green", // 밝은 회색
    "light cyan", // 밝은 청록
    "light red", // 밝은 빨강
    "light purple", // 밝은 자주
    "light yellow", // 밝은 노랑
    "light white" // 밝은 흰색
};

char* get_color_string(color_t color) {
    if (color >= BLACK && color <= LIGHT_WHITE) {
        return color_strings[color]; // 유효한 색상 값이면 해당 문자열 반환
    }
    else {
        return "unknown"; // 유효하지 않은 값이면 기본값 반환
    }
}
