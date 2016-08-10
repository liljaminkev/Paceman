#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH 40
#define HEIGHT 10

//function used to render window with choices
void print_menu(WINDOW *, int);

//get name and welcome user
void getName();

int mainMenu();
#endif
