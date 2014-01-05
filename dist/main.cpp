/*
 *  main.cpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

// #define __CPP_DEBUG__ // If you are debugging. (Currently, this changes very little.)

/**
 * @todo Add Castle button.
 * @todo Add background music.
 * @todo Add undo move button.
 */

#include "main.hpp"

ChessMain() {
    File.SetPath("/Users/usandfriends/Documents/Ronak\'s Folder/Programming/C++/My Programs/SimpleChess/SimpleChess/");
    Textures.Initialize();
    Sounds.Initialize();
    
    while(true) {
        if(StartPage.Main()) {
            GameWindow.Main();
        } else {
            Reader.Main();
        }
    }
    
    EndMain();
}
