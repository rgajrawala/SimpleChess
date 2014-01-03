/*
 *  main.hpp
 *  ChessPlusPlus
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef ChessPlusPlus_main_hpp
#define ChessPlusPlus_main_hpp

#include <cstdio>
#include <cstdarg>
#include <cstring>

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
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
#define ChessMain() int main(void)

#if defined(__APPLE__) || defined(__MACH__)
#include "resosx.hpp"
#else
#include "reswin.hpp"
#endif

#include "sounds.hpp"
#include "console.hpp"
#include "file.hpp"
#include "board.hpp"
#include "utils.hpp"
#include "reader.hpp"
#include "start.hpp"
#include "gamewindow.hpp"

void EndMain(void) {
#if defined(__CPP_DEBUG__)
    Pause();
#endif
    exit(0);
}

#endif
