#include <stdio.h>
#include <assert.h>

typedef struct Point {
    float x;
    float y;
} Point;

typedef struct Rectangle {
    struct Point bottom_left;
    struct Point upper_right;
} Rectangle;

float get_area(struct Rectangle rect) {
    return (rect.upper_right.y - rect.bottom_left.y) *
           (rect.upper_right.x - rect.bottom_left.x);
}

int is_in_rect(struct Rectangle rect, struct Point p) {
    if (p.y > rect.upper_right.y || p.y < rect.bottom_left.y) {
        return 0;
    } else if (p.x > rect.upper_right.x || p.x < rect.bottom_left.x) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char** argv) {
    struct Point bl = {0, 0};
    struct Point ur = {2, 3};
    struct Rectangle rect = {bl, ur};
    struct Point check = {1, 1};
    struct Point check1 = {4, 4};
    struct Point check2 = {2, 4};
    struct Point check3 = {4, 3};
    assert(get_area(rect) == 6);
    assert(is_in_rect(rect, check) == 1);
    assert(is_in_rect(rect, check1) == 0);
    assert(is_in_rect(rect, check2) == 0);
    assert(is_in_rect(rect, check3) == 0);
    printf("success");
    return 0;
}