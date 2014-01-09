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

/**
 * The Reader class.
 * The main starting page or menu is created and handled here.
 */
class Reader {
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
    Board8 Board; /**< The board we will be replaying. */
    unsigned short moveNumber;
public:
    
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
} Reader;

////////// SOURCE //////////

void Reader::Initialize(void) {
    this->Window.create(sf::VideoMode(900, 640), "SimpleChess - Reader", sf::Style::Close);
    this->Window.setFramerateLimit(10);
    
    if(!this->Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    this->Window.setIcon(this->Icon.getSize().x, this->Icon.getSize().y, this->Icon.getPixelsPtr());
    
    if(!this->Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    this->moveNumber = 0;
    
    this->NextButton.setFillColor(sf::Color::Yellow);
    this->NextButton.setSize(sf::Vector2f(240.0, 50.0));
    this->NextButton.setPosition(650.0, 520.0);
    
    this->NextBtnText.setColor(sf::Color::Blue);
    this->NextBtnText.setCharacterSize(40);
    this->NextBtnText.setPosition(722.0, 520.0);
    this->NextBtnText.setFont(this->Font);
    this->NextBtnText.setString("Next");
    
    this->GoBackButton.setFillColor(sf::Color::Yellow);
    this->GoBackButton.setSize(sf::Vector2f(240.0, 50.0));
    this->GoBackButton.setPosition(650.0, 580.0);
    
    this->GoBackBtnText.setColor(sf::Color::Blue);
    this->GoBackBtnText.setCharacterSize(40);
    this->GoBackBtnText.setPosition(722.0, 580.0);
    this->GoBackBtnText.setFont(this->Font);
    this->GoBackBtnText.setString("Back");
    
    try {
        File.Read("log/SimpleChess.log", &this->FileInfo);
        File.CreateBoardFromFile("config/default.chessconf", &this->Board);
    } catch (int e) {
        StartPage.SetWhoWon(-1);
    }
}

void Reader::OnMouseMove(void) {
    this->Mouse.x = Event.mouseMove.x;
    this->Mouse.y = Event.mouseMove.y;
}

void Reader::OnKeyPressed(void) {
    if(((this->Event.key.code is sf::Keyboard::W or this->Event.key.code is sf::Keyboard::C) and this->Event.key.control) or ((this->Event.key.code is sf::Keyboard::W or this->Event.key.code is sf::Keyboard::C) and this->Event.key.alt)) {
        this->Window.close();
    }
}

void Reader::OnMouseButtonReleased(void) {
    if(Utils.Contains(this->Mouse.x, this->Mouse.y, this->NextButton.getPosition().x, this->NextButton.getPosition().y, this->NextButton.getSize().x, this->NextButton.getSize().y)) {
        if (moveNumber > this->FileInfo.size()) {
            moveNumber = this->FileInfo.size();
        }
        
        Board[this->FileInfo.at(moveNumber).Piece2Loc.y][this->FileInfo.at(moveNumber).Piece2Loc.x] = Board[this->FileInfo.at(moveNumber).Piece1Loc.y][this->FileInfo.at(moveNumber).Piece1Loc.x];
        Board[this->FileInfo.at(moveNumber).Piece1Loc.y][this->FileInfo.at(moveNumber).Piece1Loc.x] = Pieces::Empty;
        moveNumber++;
    } else if(Utils.Contains(this->Mouse.x, this->Mouse.y, this->GoBackButton.getPosition().x, this->GoBackButton.getPosition().y, this->GoBackButton.getSize().x, this->GoBackButton.getSize().y)) {
        if (moveNumber < 0) {
            moveNumber = 0;
        }
        
        Board[this->FileInfo.at(moveNumber).Piece2Loc.y][this->FileInfo.at(moveNumber).Piece2Loc.x] = Board[this->FileInfo.at(moveNumber).Piece1Loc.y][this->FileInfo.at(moveNumber).Piece1Loc.x];
        Board[this->FileInfo.at(moveNumber).Piece1Loc.y][this->FileInfo.at(moveNumber).Piece1Loc.x] = Pieces::Empty;
        moveNumber--;
    }
}

void Reader::OnEvent(void) {
    switch(this->Event.type) {
        case sf::Event::Closed: this->Window.close();
        case sf::Event::KeyPressed: this->OnKeyPressed(); break;
        case sf::Event::MouseMoved: this->OnMouseMove(); break;
        case sf::Event::MouseButtonReleased: this->OnMouseButtonReleased(); break;
        default: break;
    }
}

void Reader::Main(void) {
    this->Initialize();
    while(this->Window.isOpen()) {
        this->Window.clear(sf::Color::Black);
        
        while(this->Window.pollEvent(this->Event)) {
            this->OnEvent();
        }
        
        this->Display();
    }
}

void Reader::Display(void) {
    this->Sprite.setTexture(Textures.ChessBoard);
    this->Sprite.setPosition(0.0, 0.0);
    this->Window.draw(this->Sprite);
    
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            bool isNotEmpty = true;
            
            switch(this->Board.at(y).at(x)) {
                case Pieces::Empty: isNotEmpty = false; break;
                case Pieces::Black_Pawn: this->Sprite.setTexture(Textures.Black.Pawn); break;
                case Pieces::Black_Rook: this->Sprite.setTexture(Textures.Black.Rook); break;
                case Pieces::Black_Knight: this->Sprite.setTexture(Textures.Black.Knight); break;
                case Pieces::Black_Bishop: this->Sprite.setTexture(Textures.Black.Bishop); break;
                case Pieces::Black_Queen: this->Sprite.setTexture(Textures.Black.Queen); break;
                case Pieces::Black_King: this->Sprite.setTexture(Textures.Black.King); break;
                case Pieces::White_Pawn: this->Sprite.setTexture(Textures.White.Pawn); break;
                case Pieces::White_Rook: this->Sprite.setTexture(Textures.White.Rook); break;
                case Pieces::White_Knight: this->Sprite.setTexture(Textures.White.Knight); break;
                case Pieces::White_Bishop: this->Sprite.setTexture(Textures.White.Bishop); break;
                case Pieces::White_Queen: this->Sprite.setTexture(Textures.White.Queen); break;
                case Pieces::White_King: this->Sprite.setTexture(Textures.White.King); break;
            }
            
            if(isNotEmpty) {
                this->Sprite.setPosition(float(x * 80), float(y * 80));
                this->Window.draw(this->Sprite);
            }
        }
    }
    
    this->Window.draw(this->PlayerTurn);
    this->Window.draw(this->LastMove);
    this->Window.draw(this->GoBackButton);
    this->Window.draw(this->NextButton);
    this->Window.draw(this->GoBackBtnText);
    this->Window.draw(this->NextBtnText);
    
    this->Window.display();
}

#endif
