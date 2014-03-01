/*
 *  reader.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/26/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_reader_hpp
#define SimpleChess_reader_hpp

/***********
 * @todo Create the board reader, next move / last move.
 ***********/

namespace SimpleChess {
    /**
     * The Reader class.
     * The main starting page or menu is created and handled here.
     */
    namespace Reader {
        sf::RenderWindow Window; /**< The window of the menu. */
        sf::Font Font; /**< The font that the text on the menu will use (sansation.ttf). */
        sf::Event Event; /**< Any window events. */
        sf::Vector2u Mouse; /**< Mouse coordinates. */
        sf::Image Icon; /**< The icon for the window */
        sf::Sprite Sprite; /**< The Sprite that will load the board and pieces. */
        
        sf::Text PlayerTurn, /**< Stores who's turn it is. */
                 LastMove, /**< Stores the last move. */
                 NextBtnText, /**< Text for the Next Button. */
                 GoBackBtnText; /**< Text for the Go-Back Button. */
        
        sf::RectangleShape NextButton, /**< The button that says "Next". */
                           GoBackButton; /**< The button that says "Back". */
        
        File::Information FileInfo; /**< File information necessary for the replay. */
        SimpleChess::Board8 Board; /**< The board we will be replaying. */
        unsigned short moveNumber;
        
        /**
         * Creates the menu and other important parts of the start page.
         */
        void Initialize(void);
        
        /**
         * Main loop for the start page.
         * Initializes, runs / loops, and cleans up.
         */
        void Main(void);
        
        /**
         * Event handler for window events.
         */
        void OnEvent(void);
        
        /**
         * Event handler for mouse moves.
         * @see OnEvent
         */
        void OnMouseMove(void);
        
        /**
         * Event handler for key presses.
         * @see OnEvent
         */
        void OnKeyPressed(void);
        
        /**
         * Handler for mouse button releases.
         * @see OnEvent
         */
        void OnMouseButtonReleased(void);
        
        /**
         * Draws pieces and chessboard onto screen.
         */
        void Display(void);
    };
};

////////// SOURCE //////////

void SimpleChess::Reader::Initialize(void) {
    SimpleChess::Reader::Window.create(sf::VideoMode(900, 640), "SimpleChess - Reader", sf::Style::Close);
    SimpleChess::Reader::Window.setFramerateLimit(10);
    
    if(!SimpleChess::Reader::Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    SimpleChess::Reader::Window.setIcon(SimpleChess::Reader::Icon.getSize().x, SimpleChess::Reader::Icon.getSize().y, SimpleChess::Reader::Icon.getPixelsPtr());
    
    if(!SimpleChess::Reader::Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    SimpleChess::Reader::moveNumber = 0;
    
    SimpleChess::Reader::NextButton.setFillColor(sf::Color::Yellow);
    SimpleChess::Reader::NextButton.setSize(sf::Vector2f(240.0, 50.0));
    SimpleChess::Reader::NextButton.setPosition(650.0, 520.0);
    
    SimpleChess::Reader::NextBtnText.setColor(sf::Color::Blue);
    SimpleChess::Reader::NextBtnText.setCharacterSize(40);
    SimpleChess::Reader::NextBtnText.setPosition(722.0, 520.0);
    SimpleChess::Reader::NextBtnText.setFont(SimpleChess::Reader::Font);
    SimpleChess::Reader::NextBtnText.setString("Next");
    
    SimpleChess::Reader::GoBackButton.setFillColor(sf::Color::Yellow);
    SimpleChess::Reader::GoBackButton.setSize(sf::Vector2f(240.0, 50.0));
    SimpleChess::Reader::GoBackButton.setPosition(650.0, 580.0);
    
    SimpleChess::Reader::GoBackBtnText.setColor(sf::Color::Blue);
    SimpleChess::Reader::GoBackBtnText.setCharacterSize(40);
    SimpleChess::Reader::GoBackBtnText.setPosition(722.0, 580.0);
    SimpleChess::Reader::GoBackBtnText.setFont(SimpleChess::Reader::Font);
    SimpleChess::Reader::GoBackBtnText.setString("Back");
    
    try {
        SimpleChess::File::Read("log/SimpleChess.log", &SimpleChess::Reader::FileInfo);
        SimpleChess::File::CreateBoardFromFile("config/default.chessconf", &SimpleChess::Reader::Board);
    } catch (int e) {
        SimpleChess::StartPage::SetWhoWon(-1);
    }
}

void SimpleChess::Reader::OnMouseMove(void) {
    SimpleChess::Reader::Mouse.x = Event.mouseMove.x;
    SimpleChess::Reader::Mouse.y = Event.mouseMove.y;
}

void SimpleChess::Reader::OnKeyPressed(void) {
    if(((SimpleChess::Reader::Event.key.code is sf::Keyboard::W or SimpleChess::Reader::Event.key.code is sf::Keyboard::C) and SimpleChess::Reader::Event.key.control) or ((SimpleChess::Reader::Event.key.code is sf::Keyboard::W or SimpleChess::Reader::Event.key.code is sf::Keyboard::C) and SimpleChess::Reader::Event.key.alt)) {
        SimpleChess::Reader::Window.close();
    }
}

void SimpleChess::Reader::OnMouseButtonReleased(void) {
    if(Utils.Contains(SimpleChess::Reader::Mouse.x, SimpleChess::Reader::Mouse.y, SimpleChess::Reader::NextButton.getPosition().x, SimpleChess::Reader::NextButton.getPosition().y, SimpleChess::Reader::NextButton.getSize().x, SimpleChess::Reader::NextButton.getSize().y)) {
        if (moveNumber > SimpleChess::Reader::FileInfo.size()) {
            moveNumber = SimpleChess::Reader::FileInfo.size();
        }
        
        Board[SimpleChess::Reader::FileInfo.at(moveNumber).Piece2Loc.y][SimpleChess::Reader::FileInfo.at(moveNumber).Piece2Loc.x] = Board[SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.y][SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.x];
        Board[SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.y][SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.x] = SimpleChess::Pieces::Empty;
        moveNumber++;
    } else if(Utils.Contains(SimpleChess::Reader::Mouse.x, SimpleChess::Reader::Mouse.y, SimpleChess::Reader::GoBackButton.getPosition().x, SimpleChess::Reader::GoBackButton.getPosition().y, SimpleChess::Reader::GoBackButton.getSize().x, SimpleChess::Reader::GoBackButton.getSize().y)) {
        if (moveNumber < 0) {
            moveNumber = 0;
        }
        
        Board[SimpleChess::Reader::FileInfo.at(moveNumber).Piece2Loc.y][SimpleChess::Reader::FileInfo.at(moveNumber).Piece2Loc.x] = Board[SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.y][SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.x];
        Board[SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.y][SimpleChess::Reader::FileInfo.at(moveNumber).Piece1Loc.x] = SimpleChess::Pieces::Empty;
        moveNumber--;
    }
}

void SimpleChess::Reader::OnEvent(void) {
    switch(SimpleChess::Reader::Event.type) {
        case sf::Event::Closed: SimpleChess::Reader::Window.close();
        case sf::Event::KeyPressed: SimpleChess::Reader::OnKeyPressed(); break;
        case sf::Event::MouseMoved: SimpleChess::Reader::OnMouseMove(); break;
        case sf::Event::MouseButtonReleased: SimpleChess::Reader::OnMouseButtonReleased(); break;
        default: break;
    }
}

void SimpleChess::Reader::Main(void) {
    SimpleChess::Reader::Initialize();
    while(SimpleChess::Reader::Window.isOpen()) {
        SimpleChess::Reader::Window.clear(sf::Color::Black);
        
        while(SimpleChess::Reader::Window.pollEvent(SimpleChess::Reader::Event)) {
            SimpleChess::Reader::OnEvent();
        }
        
        SimpleChess::Reader::Display();
    }
}

void SimpleChess::Reader::Display(void) {
    SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::ChessBoard);
    SimpleChess::Reader::Sprite.setPosition(0.0, 0.0);
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::Sprite);
    
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            bool isNotEmpty = true;
            
            switch(SimpleChess::Reader::Board.at(y).at(x)) {
                case SimpleChess::Pieces::Empty: isNotEmpty = false; break;
                case SimpleChess::Pieces::Black_Pawn: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::Black::Pawn); break;
                case SimpleChess::Pieces::Black_Rook: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::Black::Rook); break;
                case SimpleChess::Pieces::Black_Knight: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::Black::Knight); break;
                case SimpleChess::Pieces::Black_Bishop: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::Black::Bishop); break;
                case SimpleChess::Pieces::Black_Queen: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::Black::Queen); break;
                case SimpleChess::Pieces::Black_King: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::Black::King); break;
                case SimpleChess::Pieces::White_Pawn: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::White::Pawn); break;
                case SimpleChess::Pieces::White_Rook: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::White::Rook); break;
                case SimpleChess::Pieces::White_Knight: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::White::Knight); break;
                case SimpleChess::Pieces::White_Bishop: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::White::Bishop); break;
                case SimpleChess::Pieces::White_Queen: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::White::Queen); break;
                case SimpleChess::Pieces::White_King: SimpleChess::Reader::Sprite.setTexture(SimpleChess::Textures::White::King); break;
            }
            
            if(isNotEmpty) {
                SimpleChess::Reader::Sprite.setPosition(float(x * 80), float(y * 80));
                SimpleChess::Reader::Window.draw(SimpleChess::Reader::Sprite);
            }
        }
    }
    
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::PlayerTurn);
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::LastMove);
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::GoBackButton);
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::NextButton);
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::GoBackBtnText);
    SimpleChess::Reader::Window.draw(SimpleChess::Reader::NextBtnText);
    
    SimpleChess::Reader::Window.display();
}

#endif
