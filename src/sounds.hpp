/*
 *  sounds.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/21/13.
 *  Copyright (c) 2013-2015 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_sounds_hpp
#define SimpleChess_sounds_hpp

namespace SimpleChess {
	/**
	 * The Sounds class.
	 * The sounds for the menu and selection / placement of pieces @todo FINISH
	 */
	namespace Sounds {
		sf::Music Music1, /**< Music object for 1.wav. */
				  Music2, /**< Music object for 2.wav. */
				  Music3; /**< Music object for 3.wav. */

		/**
		 * Loads all the music objects with their .wav files.
		 */
		void Initialize(void);
	};
};

////////// SOURCE //////////

void SimpleChess::Sounds::Initialize(void) {
	if (!Music1.openFromFile(Resources::GetResource("1.wav"))) {
		exit(EXIT_FAILURE);
	}

	if (!Music2.openFromFile(Resources::GetResource("2.wav"))) {
		exit(EXIT_FAILURE);
	}

	if (!Music3.openFromFile(Resources::GetResource("3.wav"))) {
		exit(EXIT_FAILURE);
	}
}

#endif
