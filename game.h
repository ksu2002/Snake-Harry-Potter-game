#ifndef GAME_H
#define GAME_H
#include<stdio.h>
#include "graphics.h"

typedef struct cell_snake {//структура клетки змеи
	int i, j;
	int value;
} cell_snake;

enum snake_head_direction {//направления движения змеи
	RIGHT,
	LEFT,
	UP,
	DOWN,
};

enum cell_type {
	FOOD = -1,
	FIELD,
	WALL,
	HEAD_SNAKE,
};

IMAGE* createmask(IMAGE* p);
void drawimage(int x, int y, IMAGE* m, IMAGE* p);
int** create_game_field(int widht, int height);//создание игрового поля и заполнение 0 и 1
cell_snake* create_snake(int max_widht, int max_height);//создание змейки
void init_snake(int xhead, int yhead, cell_snake* snake, int** game_field);//инициализация змейки
void draw_game_field(int field_widht, int field_height, int** game_field);//отрисовка игрового поля
void draw_record(int windowheigth);//вывод рекорда на экран
void draw_points(int points, int windowheigth);// вывод текущего счёта на экран
void move_snake(int xhead, int yhead, cell_snake* snake, int snake_size, int** game_field);// расположение змеи
int change_direction(int* xhead, int* yhead, int* direction);//смена направления движения змеи
void draw_snake_tail(int xxtemp, int xtemp, int yytemp, int ytemp);//отрисовка хвоста змеи
void draw_snake_head(int direction, int xhead, int yhead);//отрисовка головы змеи
void draw_snake(cell_snake* snake, int direction);// отрисовка змеи
int create_food(
	int* food_x,
	int* food_y,
	int is_food_eaten,
	int field_widht,
	int field_height,
	int** game_field
);// функция создания еды
int check_game_over(
	int** game_field,
	cell_snake* snake,
	int is_game_over,
	int xhead,
	int yhead
);
int  check_food_eaten(int **game_field, int is_food_eaten, int xhead, int yhead, int *snake_size, int *points); //проверка на собирание еды

#endif