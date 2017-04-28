//
//  main.cpp
//  Find The Kitten
//
//  Created by Ilya Noskov on 4/27/17.
//  Copyright © 2017 Ilya Noskov. All rights reserved.
//

#include <iostream>
#include "Board.h"
#include "utilities.h"

using namespace std;

int main() {
    Board Universe = *new Board();
    Universe.findTheKitten();
    return 0;
}
