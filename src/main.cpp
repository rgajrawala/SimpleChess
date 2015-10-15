/*
 *  main.cpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#define __CPP_DEBUG__ /** If you are debugging. @note Currently, this changes very little. */

/*
 * @todo Add Castle button.
 * @todo Add background music.
 * @todo Add undo move button.
 */

#include "main.hpp"

ChessMain
	// Make sure the config folder (and its contents) and the log folder (and its contents) are in this directory.
	SimpleChess::File::SetPath("");
	// Make sure the res folder (and its contents) are in this directory.
	SimpleChess::Resources::SetPath("./res/");

	SimpleChess::Textures::Initialize();
	SimpleChess::Sounds::Initialize();

	while (true) {
		switch (SimpleChess::StartPage::Main()) {
			case 0: SimpleChess::NewGame::Main(); break;
			case 1: SimpleChess::Reader::Main(); break;
			case 2: SimpleChess::ConnectedGame::Main(); break;
			case 3: SimpleChess::LocalGame::Main(); break;
			default: SimpleChess::StartPage::Go = -1;
		}
	}
ChessEnd
