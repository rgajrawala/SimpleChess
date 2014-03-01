/*
 *  main.cpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#define __CPP_DEBUG__ // If you are debugging. (Currently, this changes very little.)

/**
 * @todo Add Castle button.
 * @todo Add background music.
 * @todo Add undo move button.
 */

#include "main.hpp"

ChessMain() {
    // Make sure the config folder (and its contents) and the log folder (and its contents) are in this directory.
    SimpleChess::File::SetPath("SET_THIS");
    
    SimpleChess::Textures::Initialize();
    SimpleChess::Sounds::Initialize();
    
    while(true) {
        if(SimpleChess::StartPage::Main()) {
            SimpleChess::GameWindow::Main();
        } else {
            SimpleChess::Reader::Main();
        }
    }
    
    SimpleChess::EndChessMain();
}
