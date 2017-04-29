//
//  Board.h
//  Find The Kitten
//
//  Created by Ilya Noskov on 4/27/17.
//  Copyright © 2017 Ilya Noskov. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <termios.h>
#include <iostream>
#include <vector>
#include "Entities.h"
#include "utilities.h"

using namespace std;

class Board {
   public:
    int x;
    int y;
    char game_field[30][80];

    Board() {
        // initialize the game field, create borders
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 80; j++) {
                if (i == 0 || i == 29) {
                    game_field[i][j] = '-';
                } else if (j == 0 || j == 79) {
                    game_field[i][j] = '|';
                } else {
                    game_field[i][j] = ' ';
                }
            }
        }

        // get Entities' symbols and put them on the field
        for (int i = 0; i < 15; i++) {
            game_field[friends[i].get_self_position().second]
                      [friends[i].get_self_position().first] =
                          friends[i].symbol;
        }
        // put the robot on the board
        game_field[player.get_self_position().first]
                  [player.get_self_position().second] = player.get_symbol();
        y = player.get_self_position().first;
        x = player.get_self_position().second;
    }

    // MAIN GAME FUNCTION
    void findTheKitten() {
        // print the board
        // walk the Robot
        while (!player.found_kitten) {
            square();
        }

        clear_screen();
        cout << "GAME OVER";
    }

    void square() {
        // get char input
        int a = getch();
        if (a == 49) player.found_kitten = true;

        pair<int, int> old_location = player.get_self_position();
        // walk the robot
        if (a == 65 && y - 1 > 0) {
            y -= 1;
            player.moveDown();
        }
        if (a == 66 && y + 1 < 29) {
            y += 1;
            player.moveUp();
        }
        if (a == 68 && x - 1 > 0) {
            x -= 1;
            player.moveLeft();
        }
        if (a == 67 && x + 1 < 79) {
            x += 1;
            player.moveRight();
        }

        pair<int, int> new_location = player.get_self_position();

        clear_screen();
        player.play(game_field, old_location, new_location);
        print_square(game_field);
        cout << "press 1 to Quit";
    }

    void print_square(char v[30][80]) {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 80; j++) {
                cout << v[i][j];
            }
            cout << "\n";
        }
    }

    void clear_screen() { cout << "\x1B[2J\x1B[H"; }

   private:
    Friend friends[15];
    Enemy enemies[15];
    Robot player;
};

#endif /* Board_h */
