#define WIDTH  800
#define HEIGHT 600
#include<stdio.h>
#include "graphics.h"
#include "game.h"
#include "menu.h"
button create_button(int posX, int posY, int sizeX, int sizeY, IMAGE *image) {//конструктор создания кнопки
   button buf;
   buf.posX = posX;
   buf.posY = posY;
   buf.sizeX = sizeX;
   buf.sizeY = sizeY;
   buf.image = image;
   return buf;
}

void drawn_button(button butt) { //функция отрисовки кнопки
   putimage(butt.posX, butt.posY, butt.image, COPY_PUT);
}

int is_click_button(button butt)//Проверка нажатия на данную кнопку
{
   int x, y;
   x = mousex();
   y = mousey();
   if (x >= butt.posX &&
         x <= butt.posX + butt.sizeX &&
         y > butt.posY &&
         y <= butt.posY + butt.sizeY) return 1;
   return 0;
}
int select_button(button butt) {//функция проверки нажатия кнопки
   if (mousebuttons() == 1) {
      return is_click_button(butt);
   }
   return 0;
}

void show_splash_screen() {
   IMAGE *image;
   image = loadBMP("window_start.bmp");
   putimage(0, 0, image, COPY_PUT);
   freeimage(image);
   getch();
}

void play_game(void) {
   int points;
   points = play_snake_game();
   closegraph();
   game_over(points);
}

void show_menu(void) {
   IMAGE *gameimage = loadBMP("button_game.bmp");
   button buttonnewgame = create_button(300, 100, 200, 50, gameimage);
   IMAGE *rec = loadBMP("button_record.bmp");
   button buttonrecord = create_button(300, 200, 200, 50, rec);
   IMAGE *rul = loadBMP("button_rules.bmp");
   button buttonrules = create_button(300, 300, 200, 50, rul);
   IMAGE *ab = loadBMP("button_about.bmp");
   button buttonabout = create_button(300, 400, 200, 50, ab);
   IMAGE *ex = loadBMP("button_exit.bmp");
   button buttonexit = create_button(300, 500, 200, 50, ex);
   IMAGE *image_menu;
   image_menu = loadBMP("enter.bmp");
   putimage(0, 0, image_menu, COPY_PUT);
   drawn_button(buttonnewgame);
   drawn_button(buttonrecord);
   drawn_button(buttonrules);
   drawn_button(buttonabout);
   drawn_button(buttonexit);
   while (1) {
      if (select_button(buttonnewgame) == 1)
      {
         play_game();
         return;
      }
      if (select_button(buttonrecord) == 1) {
         show_record();
         return;
      }
      if (select_button(buttonrules) == 1) {
         show_rules();
         return;
      }
      if (select_button(buttonabout) == 1) {
         show_about();
         return;
      }
      if (select_button(buttonexit) == 1) {
         exit();
         return;
      }
   }
   freeimage(gameimage);
   freeimage(rec);
   freeimage(rul);
   freeimage(ab);
   freeimage(ex);
   freeimage(image_menu);
   getch();
}

void show_record(void) {
   IMAGE *image_record;
   image_record = loadBMP("enter.bmp");
   IMAGE *menuimage = loadBMP("button_menu.bmp");
   button buttonmenu = create_button(550, 500, 200, 50, menuimage);
   putimage(0, 0, image_record, COPY_PUT);
   drawn_button(buttonmenu);
   FILE *record;
   record = fopen("record.txt", "r");
   int rec;
   char bufferrec[100];
   fscanf(record, "%d", &rec);
   rec = snprintf(bufferrec, 100, " %d", rec);
   settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
   outtextxy(450, 300, bufferrec);
   outtextxy(260, 300, "Рекорд:");
   while (1) {
      if (select_button(buttonmenu) == 1)
      {

         show_menu();
         return;
      }
   }
   fclose(record);
   freeimage(menuimage);
   freeimage(image_record);
   getchar();
   return;
}

void show_rules(void) {
   IMAGE *image_rules;
   image_rules = loadBMP("rules.bmp");
   IMAGE *menu2image = loadBMP("button_menu2.bmp");
   button buttonmenu2 = create_button(550, 500, 200, 50, menu2image);
   putimage(0, 0, image_rules, COPY_PUT);
   drawn_button(buttonmenu2);
   while (1) {
      if (select_button(buttonmenu2) == 1) {
         show_menu();
         return;
      }
   }
   freeimage(image_rules);
   freeimage(menu2image);
   getchar();
   return;
}

void show_about(void) {
   IMAGE *image_about;
   image_about = loadBMP("about.bmp");
   IMAGE *menuimage = loadBMP("button_menu.bmp");
   button buttonmenu = create_button(570, 540, 200, 50, menuimage);
   putimage(0, 0, image_about, COPY_PUT);
   drawn_button(buttonmenu);
   while (1) {
      if (select_button(buttonmenu) == 1) {
         show_menu();
         return;
      }
   }
   freeimage(image_about);
   freeimage(menuimage);
   getch();
}

void exit(void) {
   closegraph();
}

void game_over(int points) {//функция отрисовки окна при окончании игры
   initwindow(WIDTH, HEIGHT, " ", 124, 84);//создание окна);
   IMAGE *loose = loadBMP("death.bmp");
   putimage(0, 0, loose, COPY_PUT);
   IMAGE *menuimage = loadBMP("button_menu.bmp");//создание кнопок
   button buttonmenu = create_button(300, 540, 200, 50, menuimage);
   IMAGE *newgameimage = loadBMP("button_game.bmp");
   button buttonnewgame = create_button(300, 470, 200, 50, newgameimage);
   drawn_button(buttonmenu);
   drawn_button(buttonnewgame);

   int score = points;// вывод набранных очков
   char buffer[100];
   score = snprintf(buffer, 100, " %d", score);
   outtextxy(410, 430, buffer);
   outtextxy(365, 430, "Счёт:");

   int rec;//вывод рекорда
   char bufferrec[100];
   FILE *record;
   record = fopen("record.txt", "r");
   fscanf(record, "%d", &rec);
   fclose(record);
   if (rec < points) {//обновление рекорда
      rec = points;
      record = fopen("record.txt", "w+");
      fprintf(record, "%d", rec);
      fclose(record);
   }
   rec = snprintf(bufferrec, 100, " %d", rec);
   outtextxy(430, 450, bufferrec);
   outtextxy(365, 450, "Рекорд:");
   while (1) {
      if (select_button(buttonmenu) == 1) {//выход в главное меню
         show_menu();
         closegraph();
         return;
      }
      if (select_button(buttonnewgame) == 1) {//начать новую игру
         play_game();
         closegraph();
         return;
      }
   }
   freeimage(menuimage);
   freeimage(newgameimage);
   freeimage(loose);
   getch();
}
