//
//  Entities.h
//  Find The Kitten
//
//  Created by Ilya Noskov on 4/27/17.
//  Copyright © 2017 Ilya Noskov. All rights reserved.
//

#ifndef Entities_h
#define Entities_h
#include <algorithm>
#include <iostream>
#include "Locations.h"
#include "utilities.h"

using namespace std;

class Entity {
   public:
    char symbol = '2';
    string name;
    string message;
    pair<int, int> position;

    Entity() {}

    void place_randomly() {
        int x = random_x_location(eng);
        int y = random_y_location(eng);
        this->position = make_pair(x, y);
    }

    void assign_random_symbol() {
        char c;
        c = random_symbol(eng);
        this->symbol = c;
    }

    char get_symbol() { return symbol; }
    pair<int, int> get_self_position() { return this->position; }

    string say() { return this->message; }
};

class Friend : public Entity {
   public:
    Friend() {
        place_randomly();
        assign_random_symbol();
    }
};

// Funny
// Encouraging
// Helpful

class Enemy : public Entity {
   public:
    Enemy() {
        place_randomly();
        assign_random_symbol();
    }
};
// Mean
// Stupid
// silent

// the Player
class Robot : public Entity {
   public:
    bool found_kitten;
    Robot() {
        found_kitten = false;
        // set the moving symbols
        v.push_back('O');
        v.push_back('o');

        // initial position
        y = 1;
        x = 1;
        position = make_pair(x, y);

        // initialize empty text field
        clear_text_field();
    }

    void moveUp() {
        y++;
        position = make_pair(y, x);
    }
    void moveDown() {
        y--;
        position = make_pair(y, x);
    }
    void moveLeft() {
        x--;
        position = make_pair(y, x);
    }
    void moveRight() {
        x++;
        position = make_pair(y, x);
    }

    void checkLocation() {}
    char get_symbol() {
        reverse(v.begin(), v.end());
        return v[0];
    }

    void play(char game_field[30][80], pair<int, int> old_location,
              pair<int, int> new_location) {
        // inspect current location, hashmap look-up

        // delete the Robot symbol from the board
        game_field[old_location.first][old_location.second] = ' ';
        // delete the entity from the hash map

        // place the new Robot symbol on the board
        game_field[new_location.first][new_location.second] =
            this->get_symbol();

        print_text_field();
    }

   private:
    vector<char> v;
    int x;
    int y;
    void readMessage(Entity) { cout << Entity::say(); };
    char text_field[5][80];

    void clear_text_field() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 80; j++) {
                if (i == 0 || i == 4) {
                    text_field[i][j] = '-';
                } else {
                    if (j == 0 || j == 79) {
                        text_field[i][j] = '|';
                    } else {
                        text_field[i][j] = ' ';
                    }
                }
            }
        }
    }

    void print_text_field() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 80; j++) {
                cout << text_field[i][j];
            }
            cout << "\n";
        }
    }
};

#endif /* Entities_h */
