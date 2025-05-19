//추가적으로 밝은 색상은 해당 값에 8을 더한 값으로 표현됩니다(예: 밝은 파랑은 9).
typedef enum _color_t {
    BLACK, //0
    BLUE, // 1
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
    LIGHT_WHITE,
} color_t;

char* get_color_string(color_t color);
