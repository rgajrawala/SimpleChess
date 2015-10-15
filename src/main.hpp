/*
 *  main.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_main_hpp
#define SimpleChess_main_hpp

#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cassert>

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <fstream>

#include "SFML/Audio.hpp"
#include "SFML/Config.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/OpenGL.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#define is ==
#define ChessMain int main(void) {
#define ChessMainH ChessMain ChessHoldAtExit;
#define ChessEnd return 0; }
#define ChessHoldAtExit atexit(SimpleChess::EndChessMain);

#include "resources.hpp"
#include "sounds.hpp"
#include "console.hpp"
#include "alert.hpp"
#include "board.hpp"
#include "move.hpp"
#include "file.hpp"
#include "utils.hpp"
#include "start.hpp"
#include "reader.hpp"
#include "newgame.hpp"
#include "localgame.hpp"
#include "connectedgame.hpp"

namespace SimpleChess {
	void EndChessMain(void) {
		Console::Pause();
		exit(EXIT_SUCCESS);
	}
};

#endif
