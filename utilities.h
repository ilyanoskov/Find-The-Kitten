//
//  utilities.h
//  Find The Kitten
//
//  Created by Ilya Noskov on 4/27/17.
//  Copyright © 2017 Ilya Noskov. All rights reserved.
//

#ifndef utilities_h
#define utilities_h
#include <termios.h>
#include <iostream>
#include <random>
static struct termios old, newtt;

/* Initialize newtt terminal i/o settings */
void initTermios(int echo) {
    tcgetattr(0, &old);       /* grab old terminal i/o settings */
    newtt = old;              /* make newtt settings same as old settings */
    newtt.c_lflag &= ~ICANON; /* disable buffered i/o */
    newtt.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW,
              &newtt); /* use these newtt terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) { tcsetattr(0, TCSANOW, &old); }

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void) { return getch_(0); }

//Random number generator in a range


std::random_device rd; // obtain a random number from hardware
std::mt19937 eng(rd()); // seed the generator
std::uniform_int_distribution<> random_x_location(1, 79); // define the range
std::uniform_int_distribution<> random_y_location(1, 28); // define the range
std::uniform_int_distribution<> random_symbol(33, 65); // define the range


#endif /* utilities_h */
