#define WIDTH  800
#define HEIGHT 600
#include<stdio.h>
#include "graphics.h"
#include "game.h"
#include "menu.h"
int main(void) {
    initwindow(WIDTH, HEIGHT, "Chamber of Secrets", 124, 84);//создание окна
    show_splash_screen();
    show_menu();
    closegraph();
    return 0;
}