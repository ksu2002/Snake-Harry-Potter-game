#ifndef MENU_H
#define MENU_H
#include<stdio.h>
#include "graphics.h"
typedef struct button {//структура кнопки
   int posX;
   int posY;
   int sizeX;
   int sizeY;
   IMAGE *image;
} button;

button create_button(int posX, int posY, int sizeX,
                     int sizeY, IMAGE *image
                    );//конструктор создания кнопки
void drawn_button(button butt); //функция отрисовки кнопки
int is_click_button(button butt);
int select_button(button butt);//функция проверки нажатия кнопки
int play_snake_game(void);
void game_over(int points);
void show_splash_screen(void);//заставка
void show_record(void);//окно «рекорд»
void show_rules(void);//окно «как играть»
void show_about(void);//окно «об игре»
void exit(void);//выход
void show_splash_screen(void);
void play_game(void);
void show_menu(void);

#endif