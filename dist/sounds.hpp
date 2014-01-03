/*
 *  sounds.hpp
 *  ChessPlusPlus
 *
 *  Created by Ronak Gajrawala on 12/21/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef ChessPlusPlus_sounds_hpp
#define ChessPlusPlus_sounds_hpp

/**
 * The Sounds class.
 * The sounds for the menu and selection / placement of pieces @todo FINISH
 */
class Sounds {
public:
    sf::Music Music1, /**< Music object for 1.wav. */
              Music2, /**< Music object for 2.wav. */
              Music3; /**< Music object for 3.wav. */
    
    /**
     * Loads all the music objects with their .wav files.
     */
    void Initialize(void);
} Sounds;

////////// SOURCE //////////

void Sounds::Initialize(void) {
    if(!this->Music1.openFromFile(GetResource("1.wav"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Music2.openFromFile(GetResource("2.wav"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Music3.openFromFile(GetResource("3.wav"))) {
        exit(EXIT_FAILURE);
    }
}

#endif
