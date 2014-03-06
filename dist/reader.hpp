/*
 *  reader.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/26/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_reader_hpp
#define SimpleChess_reader_hpp

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
        short moveNumber;
        
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
    Window.create(sf::VideoMode(900, 640), "SimpleChess - Reader", sf::Style::Close);
    Window.setFramerateLimit(10);
    
    if(!Icon.loadFromFile(Resources::GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    Window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());
    
    if(!Font.loadFromFile(Resources::GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    moveNumber = 0;
    
    NextButton.setFillColor(sf::Color::Yellow);
    NextButton.setSize(sf::Vector2f(240.0, 50.0));
    NextButton.setPosition(650.0, 520.0);
    
    NextBtnText.setColor(sf::Color::Blue);
    NextBtnText.setCharacterSize(40);
    NextBtnText.setPosition(722.0, 520.0);
    NextBtnText.setFont(Font);
    NextBtnText.setString("Next");
    
    GoBackButton.setFillColor(sf::Color::Yellow);
    GoBackButton.setSize(sf::Vector2f(240.0, 50.0));
    GoBackButton.setPosition(650.0, 580.0);
    
    GoBackBtnText.setColor(sf::Color::Blue);
    GoBackBtnText.setCharacterSize(40);
    GoBackBtnText.setPosition(722.0, 580.0);
    GoBackBtnText.setFont(Font);
    GoBackBtnText.setString("Back");
    
    try {
        File::Read("log/SimpleChess.log", &FileInfo);
        File::CreateBoardFromFile("config/default.chessconf", &Board);
    } catch (int e) {
        StartPage::SetWhoWon(-1);
        Window.close();
    }
}

void SimpleChess::Reader::OnMouseMove(void) {
    Mouse.x = Event.mouseMove.x;
    Mouse.y = Event.mouseMove.y;
}

void SimpleChess::Reader::OnKeyPressed(void) {
    if(((Event.key.code is sf::Keyboard::W or Event.key.code is sf::Keyboard::C) and Event.key.control) or ((Event.key.code is sf::Keyboard::W or Event.key.code is sf::Keyboard::C) and Event.key.alt)) {
        Window.close();
    }
}

void SimpleChess::Reader::OnMouseButtonReleased(void) {
    if(Utils::Contains(Mouse.x, Mouse.y, NextButton.getPosition().x, NextButton.getPosition().y, NextButton.getSize().x, NextButton.getSize().y)) {
        if (moveNumber < 0) {
            moveNumber = 0;
            return;
        } else if (moveNumber >= FileInfo.size() - 1) {
            moveNumber = FileInfo.size() - 1;
            return;
        }
        
        Board[FileInfo.at(moveNumber).Piece2Loc.y][FileInfo.at(moveNumber).Piece2Loc.x] = FileInfo.at(moveNumber).Piece1;
        Board[FileInfo.at(moveNumber).Piece1Loc.y][FileInfo.at(moveNumber).Piece1Loc.x] = Pieces::Empty;
        moveNumber++;
    } else if(Utils::Contains(Mouse.x, Mouse.y, GoBackButton.getPosition().x, GoBackButton.getPosition().y, GoBackButton.getSize().x, GoBackButton.getSize().y)) {
        if (moveNumber <= 0) {
            moveNumber = 0;
            return;
        } else if (moveNumber > FileInfo.size() - 1) {
            moveNumber = FileInfo.size() - 1;
            return;
        }
        moveNumber--;
        
        if (FileInfo.at(moveNumber).Move == 0) {
            Board[FileInfo.at(moveNumber).Piece2Loc.y][FileInfo.at(moveNumber).Piece2Loc.x] = Pieces::Empty;
            Board[FileInfo.at(moveNumber).Piece1Loc.y][FileInfo.at(moveNumber).Piece1Loc.x] = FileInfo.at(moveNumber).Piece1;
        } else {
            Board[FileInfo.at(moveNumber).Piece2Loc.y][FileInfo.at(moveNumber).Piece2Loc.x] = FileInfo.at(moveNumber).Piece2;
            Board[FileInfo.at(moveNumber).Piece1Loc.y][FileInfo.at(moveNumber).Piece1Loc.x] = FileInfo.at(moveNumber).Piece1;
        }
    }
}

void SimpleChess::Reader::OnEvent(void) {
    switch(Event.type) {
        case sf::Event::Closed: Window.close();
        case sf::Event::KeyPressed: OnKeyPressed(); break;
        case sf::Event::MouseMoved: OnMouseMove(); break;
        case sf::Event::MouseButtonReleased: OnMouseButtonReleased(); break;
        default: break;
    }
}

void SimpleChess::Reader::Main(void) {
    Initialize();
    while(Window.isOpen()) {
        Window.clear(sf::Color::Black);
        
        while(Window.pollEvent(Event)) {
            OnEvent();
        }
        
        Display();
    }
}

void SimpleChess::Reader::Display(void) {
    Sprite.setTexture(Textures::ChessBoard);
    Sprite.setPosition(0.0, 0.0);
    Window.draw(Sprite);
    
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            bool isNotEmpty = true;
            
            switch(SimpleChess::Reader::Board.at(y).at(x)) {
                case Pieces::Empty: isNotEmpty = false; break;
                case Pieces::Black_Pawn: Sprite.setTexture(Textures::Black::Pawn); break;
                case Pieces::Black_Rook: Sprite.setTexture(Textures::Black::Rook); break;
                case Pieces::Black_Knight: Sprite.setTexture(Textures::Black::Knight); break;
                case Pieces::Black_Bishop: Sprite.setTexture(Textures::Black::Bishop); break;
                case Pieces::Black_Queen: Sprite.setTexture(Textures::Black::Queen); break;
                case Pieces::Black_King: Sprite.setTexture(Textures::Black::King); break;
                case Pieces::White_Pawn: Sprite.setTexture(Textures::White::Pawn); break;
                case Pieces::White_Rook: Sprite.setTexture(Textures::White::Rook); break;
                case Pieces::White_Knight: Sprite.setTexture(Textures::White::Knight); break;
                case Pieces::White_Bishop: Sprite.setTexture(Textures::White::Bishop); break;
                case Pieces::White_Queen: Sprite.setTexture(Textures::White::Queen); break;
                case Pieces::White_King: Sprite.setTexture(Textures::White::King); break;
            }
            
            if(isNotEmpty) {
                Sprite.setPosition(float(x * 80), float(y * 80));
                Window.draw(Sprite);
            }
        }
    }
    
    Window.draw(PlayerTurn);
    Window.draw(LastMove);
    Window.draw(GoBackButton);
    Window.draw(NextButton);
    Window.draw(GoBackBtnText);
    Window.draw(NextBtnText);
    
    Window.display();
}

#endif
