//
//  Entities.h
//  Find The Kitten
//
//  Created by Ilya Noskov on 4/27/17.
//  Copyright © 2017 Ilya Noskov. All rights reserved.
//

#ifndef Entities_h
#define Entities_h
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
        y = 80;
        x = 0;
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

   private:
    vector<char> v;
    int x;
    int y;
    void readMessage(Entity) { cout << Entity::say(); };
};

#endif /* Entities_h */
