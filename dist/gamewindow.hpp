/*
 *  SimpleChess::GameWindow::hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_gamewindow_hpp
#define SimpleChess_gamewindow_hpp

namespace SimpleChess {
    /**
     * The GameWindow class.
     * Loads the window along with functions to create, clear, write to, and display it.
     */
    namespace GameWindow {
        sf::Event Event; /**< Where the window's new event will be stored. */
        sf::Text PlayerTurn, /**< Stores who's turn it is. */
                 LastMove; /**< Stores the last move. */
        sf::Font Font; /**< Stores the font file (sansation.ttf) for the text. */
        sf::RenderWindow Window; /**< The window for the app. */
        sf::Image Icon; /**< The icon for the application. */
        sf::Sprite Sprite; /**< The Sprite that will load the board and pieces. */
        SimpleChess::Board8 BoardBackground, /**< The board's background. */
                            Board; /**< The board's pieces. */
        
        /**
         * Intializes Window.
         * @see sf::Window::create
         * @param Mode The window's video mode.
         * @param Title The window's title.
         * @param Style The window's style.
         * @param Settings Miscellaneous window settings.
         */
        void Create(sf::VideoMode, const sf::String&, sf::Uint32, const sf::ContextSettings&);
        
        /**
         * Draws the drawable object onto the window.
         * @see sf::Window::draw
         * @param Sprite The Sprite to draw.
         */
        void Draw(sf::Drawable&);
        
        /**
         * Checks if the window is open.
         * @see sf::Window::isOpen
         * @return Returns true if the window is open and false if it is not.
         */
        bool IsOpen(void);
        
        /**
         * Saves the window's event into Event.
         * @see sf::Window::pollEvent
         * @param Event Where the window's event will be saved.
         * @return Returns true if there is an event to get and false if not.
         */
        bool GetEvent(sf::Event&);
        
        /**
         * Clears the window (black background).
         * @see sf::Window::Clear
         */
        void Clear(void);
        
        /**
         * Closes the window.
         * @see sf::Window::close
         */
        void Close(void);
        
        /**
         * Displays the window.
         * @see sf::Window::display
         */
        void Print(void);
        
        /**
         * Draws the chessboard and it's pieces on to the window.
         */
        void Display(void);
        
        /**
         * Intializes the board and window.
         */
        void Initialize(void);
        
        /**
         * Handler function for key press.
         */
        void OnKeyPress(void);
        
        /**
         * Handler function for mouse move.
         */
        void OnMouseMove(void);
        
        /**
         * Handler function for mouse button click.
         */
        void OnMouseButtonPress(void);
        
        /**
         * Handler function for any event.
         * Then redirects to the other handler events.
         */
        void OnEvent(void);
        
        /**
         * Main function for game.
         */
        void Main(void);
    };
    
    /**
     * The Move class.
     * Shows the paths of each piece.
     * Also initializes the pieces' coordinates and board.
     */
    namespace Move {
        sf::Vector2i Select, /**< The user's selection coordinates. */
                     Coord, /**< The user's raw current-click coordinates. */
                     Piece; /**< The user's refined current-click coordinates. @see Coord */
        
        int PlayerTurn = 1; /**< Which player's turn it is. */
        
        /**
         * Sets PlayerTurn back to 1 (White).
         * @see PlayerTurn
         */
        void Initialize(void);
        
        /**
         * Refines the raw clicks (Coord) from the user and stores the new, refined values (Piece).
         * @see Piece
         * @see Coord
         */
        void InitializePiece(void);
        
        /**
         * Sets the user's selection.
         * @see Select
         * @see Piece
         */
        void InitializeSelect(void);
        
        /**
         * Resets the board's background to empty.
         * @see Empty
         */
        void InitializeBoard(void);
        
        /**
         * Shows the paths a White Pawn can take.
         */
        void ShowWhitePawnPath(void);
        
        /**
         * Shows the paths a White Rook can take.
         */
        void ShowWhiteRookPath(void);
        
        /**
         * Shows the paths a White Knight can take.
         */
        void ShowWhiteKnightPath(void);
        
        /**
         * Shows the paths a White Bishop can take.
         */
        void ShowWhiteBishopPath(void);
        
        /**
         * Shows the paths a White Queen can take.
         */
        void ShowWhiteQueenPath(void);
        
        /**
         * Shows the paths a White King can take.
         */
        void ShowWhiteKingPath(void);
        
        /**
         * Shows the paths a Black Pawn can take.
         */
        void ShowBlackPawnPath(void);
        
        /**
         * Shows the paths a Black Rook can take.
         */
        void ShowBlackRookPath(void);
        
        /**
         * Shows the paths a Black Knight can take.
         */
        void ShowBlackKnightPath(void);
        
        /**
         * Shows the paths a Black Bishop can take.
         */
        void ShowBlackBishopPath(void);
        
        /**
         * Shows the paths a Black Queen can take.
         */
        void ShowBlackQueenPath(void);
        
        /**
         * Shows the paths a Black King can take.
         */
        void ShowBlackKingPath(void);
        
        /**
         * Handler for player 1's turn.
         */
        void OnPlayer1Turn(void);
        
        /**
         * Handler for player 2's turn.
         */
        void OnPlayer2Turn(void);
        
        /**
         * Handler for player's turn.
         */
        void MovePiece(void);
        
        /**
         * Checks if a king is missing and acts accordingly.
         */
        void IfGameIsOver(void);
    };
};

////////// SOURCE //////////

void SimpleChess::GameWindow::Initialize(void) {
    if (not SimpleChess::GameWindow::Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    SimpleChess::GameWindow::PlayerTurn.setFont(SimpleChess::GameWindow::Font);
    SimpleChess::GameWindow::PlayerTurn.setString("Player 1\'s Turn");
    SimpleChess::GameWindow::PlayerTurn.setCharacterSize(11);
    SimpleChess::GameWindow::PlayerTurn.setPosition(680.0, 10.0);
    SimpleChess::GameWindow::PlayerTurn.setColor(sf::Color::White);
    
    SimpleChess::GameWindow::LastMove.setFont(SimpleChess::GameWindow::Font);
    SimpleChess::GameWindow::LastMove.setString("Last move:\nBoard Created.");
    SimpleChess::GameWindow::LastMove.setCharacterSize(11);
    SimpleChess::GameWindow::LastMove.setPosition(680.0, 40.0);
    SimpleChess::GameWindow::LastMove.setColor(sf::Color::White);
    
	for (short y = 0; y < 8; y++) {
		for (short x = 0; x < 8; x++) {
			SimpleChess::GameWindow::BoardBackground[y][x] = Background::Empty;
		}
	}
	
	SimpleChess::GameWindow::Board[0][0] = SimpleChess::Pieces::Black_Rook;
	SimpleChess::GameWindow::Board[0][1] = SimpleChess::Pieces::Black_Knight;
	SimpleChess::GameWindow::Board[0][2] = SimpleChess::Pieces::Black_Bishop;
	SimpleChess::GameWindow::Board[0][3] = SimpleChess::Pieces::Black_Queen;
	SimpleChess::GameWindow::Board[0][4] = SimpleChess::Pieces::Black_King;
	SimpleChess::GameWindow::Board[0][5] = SimpleChess::Pieces::Black_Bishop;
	SimpleChess::GameWindow::Board[0][6] = SimpleChess::Pieces::Black_Knight;
	SimpleChess::GameWindow::Board[0][7] = SimpleChess::Pieces::Black_Rook;
	
	for (short x = 0; x < 8; x++) {
		SimpleChess::GameWindow::Board[1][x] = SimpleChess::Pieces::Black_Pawn;
		SimpleChess::GameWindow::Board[6][x] = SimpleChess::Pieces::White_Pawn;
	}
	
	for (short y = 2; y < 6; y++) {
		for (short x = 0; x < 8; x++) {
			SimpleChess::GameWindow::Board[y][x] = SimpleChess::Pieces::Empty;
		}
	}
	
	SimpleChess::GameWindow::Board[7][0] = SimpleChess::Pieces::White_Rook;
	SimpleChess::GameWindow::Board[7][1] = SimpleChess::Pieces::White_Knight;
	SimpleChess::GameWindow::Board[7][2] = SimpleChess::Pieces::White_Bishop;
	SimpleChess::GameWindow::Board[7][3] = SimpleChess::Pieces::White_Queen;
	SimpleChess::GameWindow::Board[7][4] = SimpleChess::Pieces::White_King;
	SimpleChess::GameWindow::Board[7][5] = SimpleChess::Pieces::White_Bishop;
	SimpleChess::GameWindow::Board[7][6] = SimpleChess::Pieces::White_Knight;
	SimpleChess::GameWindow::Board[7][7] = SimpleChess::Pieces::White_Rook;
    
    SimpleChess::GameWindow::Window.create(sf::VideoMode(900, 640), "SimpleChess - Game", sf::Style::Close);
    SimpleChess::GameWindow::Window.setFramerateLimit(10);
    
    if (not SimpleChess::GameWindow::Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    SimpleChess::GameWindow::Window.setIcon(SimpleChess::GameWindow::Icon.getSize().x, SimpleChess::GameWindow::Icon.getSize().y, SimpleChess::GameWindow::Icon.getPixelsPtr());
}

void SimpleChess::GameWindow::Create(sf::VideoMode Mode, const sf::String& Title, sf::Uint32 Style = sf::Style::Default, const sf::ContextSettings& Settings = sf::ContextSettings()) {
    Window.create(Mode, Title, Style, Settings);
}

void SimpleChess::GameWindow::Draw(sf::Drawable& Sprite) {
    Window.draw(Sprite);
}

bool SimpleChess::GameWindow::IsOpen(void) {
    return Window.isOpen();
}

bool SimpleChess::GameWindow::GetEvent(sf::Event& Event) {
    return Window.pollEvent(Event);
}

void SimpleChess::GameWindow::Clear(void) {
    Window.clear(sf::Color::Black);
}

void SimpleChess::GameWindow::Close(void) {
    Window.close();
}

void SimpleChess::GameWindow::Print(void) {
    Window.display();
}

void SimpleChess::GameWindow::Display(void) {
    SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::ChessBoard);
    SimpleChess::GameWindow::Sprite.setPosition(0.0, 0.0);
    SimpleChess::GameWindow::Draw(SimpleChess::GameWindow::Sprite);
    
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            bool isNotEmpty = true;
            
            switch (SimpleChess::GameWindow::BoardBackground.at(y).at(x)) {
                case Background::Empty: isNotEmpty = false; break;
                case Background::Enemy_Capture: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Enemy_Capture); break;
                case Background::Enemy_Move: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Enemy_Move); break;
                case Background::Valid_Capture: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Valid_Capture); break;
                case Background::Valid_Move: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Valid_Move); break;
            }
            
            if (isNotEmpty) {
                SimpleChess::GameWindow::Sprite.setPosition(float(x * 80), float(y * 80));
                SimpleChess::GameWindow::Draw(SimpleChess::GameWindow::Sprite);
            }
        }
    }
    
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            bool isNotEmpty = true;
            
            switch (SimpleChess::GameWindow::Board.at(y).at(x)) {
                case SimpleChess::Pieces::Empty: isNotEmpty = false; break;
                case SimpleChess::Pieces::Black_Pawn: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Black::Pawn); break;
                case SimpleChess::Pieces::Black_Rook: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Black::Rook); break;
                case SimpleChess::Pieces::Black_Knight: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Black::Knight); break;
                case SimpleChess::Pieces::Black_Bishop: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Black::Bishop); break;
                case SimpleChess::Pieces::Black_Queen: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Black::Queen); break;
                case SimpleChess::Pieces::Black_King: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::Black::King); break;
                case SimpleChess::Pieces::White_Pawn: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::White::Pawn); break;
                case SimpleChess::Pieces::White_Rook: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::White::Rook); break;
                case SimpleChess::Pieces::White_Knight: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::White::Knight); break;
                case SimpleChess::Pieces::White_Bishop: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::White::Bishop); break;
                case SimpleChess::Pieces::White_Queen: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::White::Queen); break;
                case SimpleChess::Pieces::White_King: SimpleChess::GameWindow::Sprite.setTexture(SimpleChess::Textures::White::King); break;
            }
            
            if (isNotEmpty) {
                SimpleChess::GameWindow::Sprite.setPosition(float(x * 80), float(y * 80));
                SimpleChess::GameWindow::Draw(SimpleChess::GameWindow::Sprite);
            }
        }
    }
    
    SimpleChess::GameWindow::Draw(SimpleChess::GameWindow::PlayerTurn);
    SimpleChess::GameWindow::Draw(SimpleChess::GameWindow::LastMove);
    
    SimpleChess::GameWindow::Print();
}

void SimpleChess::GameWindow::OnKeyPress(void) {
    if ((SimpleChess::GameWindow::Event.key.code is sf::Keyboard::Escape) or ((SimpleChess::GameWindow::Event.key.control is true or SimpleChess::GameWindow::Event.key.alt is true) and (SimpleChess::GameWindow::Event.key.code is sf::Keyboard::W or SimpleChess::GameWindow::Event.key.code is sf::Keyboard::C))) {
        SimpleChess::GameWindow::Close();
    }
}

void SimpleChess::GameWindow::OnMouseMove(void) {
    SimpleChess::Move::Coord.x = SimpleChess::GameWindow::Event.mouseMove.x;
    SimpleChess::Move::Coord.y = SimpleChess::GameWindow::Event.mouseMove.y;
}

void SimpleChess::GameWindow::OnMouseButtonPress(void) {
    SimpleChess::Move::MovePiece();
}

void SimpleChess::GameWindow::OnEvent(void) {
    switch (SimpleChess::GameWindow::Event.type) {
        case sf::Event::Closed: SimpleChess::GameWindow::Close(); break;
        case sf::Event::KeyPressed: SimpleChess::GameWindow::OnKeyPress(); break;
        case sf::Event::MouseMoved: SimpleChess::GameWindow::OnMouseMove(); break;
        case sf::Event::MouseButtonPressed: SimpleChess::GameWindow::OnMouseButtonPress(); break;
        default: break;
    }
}

void SimpleChess::GameWindow::Main(void) {
    SimpleChess::File::Clear();
    SimpleChess::Move::Initialize();
    SimpleChess::GameWindow::Initialize();
    
    while(SimpleChess::GameWindow::IsOpen()) {
        SimpleChess::GameWindow::Clear();
        
        while(SimpleChess::GameWindow::GetEvent(SimpleChess::GameWindow::Event)) {
            SimpleChess::GameWindow::OnEvent();
        }
        
        SimpleChess::GameWindow::Display();
    }
}

void SimpleChess::Move::Initialize(void) {
    SimpleChess::Move::PlayerTurn = 1;
}

void SimpleChess::Move::InitializePiece(void) {
    SimpleChess::Move::Piece.x = (SimpleChess::Move::Coord.x - (SimpleChess::Move::Coord.x % 80)) / 80;
    SimpleChess::Move::Piece.y = (SimpleChess::Move::Coord.y - (SimpleChess::Move::Coord.y % 80)) / 80;
}

void SimpleChess::Move::InitializeSelect(void) {
    Select = Piece;
}

void SimpleChess::Move::InitializeBoard(void) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Empty;
        }
    }
}

void SimpleChess::Move::ShowWhitePawnPath(void) {
    if (SimpleChess::Move::Piece.y - 1 >= 0) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] = Background::Valid_Move;
            
            if (SimpleChess::Move::Piece.y is 6 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x] = Background::Valid_Move;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.x - 1 >= 0 and SimpleChess::Move::Piece.y - 1 >= 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] > 6) {
        SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] = Background::Valid_Capture;
    }
    
    if (SimpleChess::Move::Piece.y - 1 >= 0 and SimpleChess::Move::Piece.x + 1 < 8 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] > 6) {
        SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] = Background::Valid_Capture;
    }
}

void SimpleChess::Move::ShowWhiteRookPath(void) {
    for (int x = SimpleChess::Move::Piece.x + 1; x < 8; x++) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1; x >= 0; x--) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y + 1; y < 8; y++) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y - 1; y >= 0; y--) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
}

void SimpleChess::Move::ShowWhiteKnightPath(void) {
    if (SimpleChess::Move::Piece.x + 2 < 8) {
        if (SimpleChess::Move::Piece.y + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] = Background::Valid_Capture;
            }
        }
        if (SimpleChess::Move::Piece.y - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] = Background::Valid_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.x - 2 >= 0) {
        if (SimpleChess::Move::Piece.y + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] = Background::Valid_Capture;
            }
        }
        if (SimpleChess::Move::Piece.y - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] = Background::Valid_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.y + 2 < 8) {
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.y - 2 >= 0) {
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
}

void SimpleChess::Move::ShowWhiteBishopPath(void) {
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
}

void SimpleChess::Move::ShowWhiteKingPath(void) {
    if (SimpleChess::Move::Piece.x + 1 < 8) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] = Background::Valid_Capture;
        }
    }
    
    if (SimpleChess::Move::Piece.x - 1 >= 0) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] = Background::Valid_Capture;
        }
    }
    
    if (SimpleChess::Move::Piece.y - 1 >= 0) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] = Background::Valid_Capture;
        }
        
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.y + 1 < 8) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] = Background::Valid_Capture;
        }
        
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] = Background::Valid_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] > 6) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
}

void SimpleChess::Move::ShowWhiteQueenPath(void) {
    for (int x = SimpleChess::Move::Piece.x + 1; x < 8; x++) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1; x >= 0; x--) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y + 1; y < 8; y++) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y - 1; y >= 0; y--) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 6) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
}

void SimpleChess::Move::ShowBlackPawnPath(void) {
    if (SimpleChess::Move::Piece.y + 1 < 8) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
            
            if (SimpleChess::Move::Piece.y is 1 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.x - 1 >= 0 and SimpleChess::Move::Piece.y + 1 < 8 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] < 7) {
        SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Capture;
    }
    
    if (SimpleChess::Move::Piece.x + 1 < 8 and SimpleChess::Move::Piece.y + 1 < 8 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] < 7) {
        SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Capture;
    }
}

void SimpleChess::Move::ShowBlackRookPath(void) {
    for (int x = SimpleChess::Move::Piece.x + 1; x < 8; x++) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1; x >= 0; x--) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y + 1; y < 8; y++) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y - 1; y >= 0; y--) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
}

void SimpleChess::Move::ShowBlackKnightPath(void) {
    if (SimpleChess::Move::Piece.x + 2 < 8) {
        if (SimpleChess::Move::Piece.y + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 2] = Background::Enemy_Capture;
            }
        }
        if (SimpleChess::Move::Piece.y - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 2] = Background::Enemy_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.x - 2 >= 0) {
        if (SimpleChess::Move::Piece.y + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 2] = Background::Enemy_Capture;
            }
        }
        if (SimpleChess::Move::Piece.y - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 2] = Background::Enemy_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.y + 2 < 8) {
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 2][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.y - 2 >= 0) {
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 2][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
}

void SimpleChess::Move::ShowBlackBishopPath(void) {
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
}

void SimpleChess::Move::ShowBlackKingPath(void) {
    if (SimpleChess::Move::Piece.x + 1 < 8) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Capture;
        }
    }
    
    if (SimpleChess::Move::Piece.x - 1 >= 0) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Capture;
        }
    }
    
    if (SimpleChess::Move::Piece.y - 1 >= 0) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x] = Background::Enemy_Capture;
        }
        
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if (SimpleChess::Move::Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y - 1][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
    
    if (SimpleChess::Move::Piece.y + 1 < 8) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x] = Background::Enemy_Capture;
        }
        
        if (SimpleChess::Move::Piece.x + 1 < 8) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if (Piece.x - 1 >= 0) {
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] is SimpleChess::Pieces::Empty) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Move;
            } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] < 7) {
                SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y + 1][SimpleChess::Move::Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
}

void SimpleChess::Move::ShowBlackQueenPath(void) {
    for (int x = SimpleChess::Move::Piece.x + 1; x < 8; x++) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1; x >= 0; x--) {
        if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y + 1; y < 8; y++) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int y = SimpleChess::Move::Piece.y - 1; y >= 0; y--) {
        if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[y][SimpleChess::Move::Piece.x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][SimpleChess::Move::Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x + 1, y = SimpleChess::Move::Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for (int x = SimpleChess::Move::Piece.x - 1, y = SimpleChess::Move::Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Empty) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Move;
        } else if (SimpleChess::GameWindow::Board[y][x] > 0 and SimpleChess::GameWindow::Board[y][x] < 7) {
            SimpleChess::GameWindow::BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
}

void SimpleChess::Move::OnPlayer1Turn(void) {
    if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] > 0 and SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] < 7) {
        SimpleChess::Sounds::Music2.play();
        SimpleChess::Move::InitializeSelect();
        SimpleChess::Move::InitializeBoard();
        
        switch (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x]) {
            case SimpleChess::Pieces::White_Pawn: SimpleChess::Move::ShowWhitePawnPath(); break;
            case SimpleChess::Pieces::White_Rook: SimpleChess::Move::ShowWhiteRookPath(); break;
            case SimpleChess::Pieces::White_Knight: SimpleChess::Move::ShowWhiteKnightPath(); break;
            case SimpleChess::Pieces::White_Bishop: SimpleChess::Move::ShowWhiteBishopPath(); break;
            case SimpleChess::Pieces::White_King: SimpleChess::Move::ShowWhiteKingPath(); break;
            case SimpleChess::Pieces::White_Queen: SimpleChess::Move::ShowWhiteQueenPath(); break;
        }
    } else if (SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] is Background::Valid_Move or SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] is Background::Valid_Capture) {
        SimpleChess::Sounds::Music1.play();
        std::stringstream ss, dss;
        short omove = SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x];
        SimpleChess::Move::InitializeBoard();
        short opp = SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x];
        
        if (SimpleChess::Move::Select.y != SimpleChess::Move::Piece.y or SimpleChess::Move::Select.x != SimpleChess::Move::Piece.x) {
            SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] = SimpleChess::GameWindow::Board[SimpleChess::Move::Select.y][SimpleChess::Move::Select.x];
            
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::White_Pawn and SimpleChess::Move::Piece.y is 0) {
                SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] = SimpleChess::Pieces::White_Queen;
            }
            
            SimpleChess::GameWindow::Board[SimpleChess::Move::Select.y][SimpleChess::Move::Select.x] = SimpleChess::Pieces::Empty;
            SimpleChess::Move::PlayerTurn = SimpleChess::Move::PlayerTurn is 1 ? 2 : 1;
            SimpleChess::GameWindow::PlayerTurn.setString("Player 2\'s Turn");
        }
        
        if (omove is Background::Valid_Capture) {
            ss << Utils.PStringify(SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x]) << " (" << SimpleChess::Move::Select.x << ", " << SimpleChess::Move::Select.y << ") captured " << Utils.PStringify(opp) << " (" << SimpleChess::Move::Piece.x << ", " << SimpleChess::Move::Piece.y << ").";
            dss << SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] << " " << SimpleChess::Move::Select.x << " " << SimpleChess::Move::Select.y << " " << 1 << " " << opp << " " << SimpleChess::Move::Piece.x << " " << SimpleChess::Move::Piece.y;
#ifdef __CPP_DEBUG__
            SimpleChess::Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
        } else {
            ss << Utils.PStringify(SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x]) << " (" << SimpleChess::Move::Select.x << ", " << SimpleChess::Move::Select.y << ") moved to (" << SimpleChess::Move::Piece.x << ", " << SimpleChess::Move::Piece.y << ").";
            dss << SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] << " " << SimpleChess::Move::Select.x << " " << SimpleChess::Move::Select.y << " " << 2 << " " << opp << " " << SimpleChess::Move::Piece.x << " " << SimpleChess::Move::Piece.y;
#ifdef __CPP_DEBUG__
            SimpleChess::Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
        }
        
        SimpleChess::File::Append(dss.str() + "\n");
        SimpleChess::GameWindow::LastMove.setString("Last move:\n" + ss.str());
    }
}

void SimpleChess::Move::OnPlayer2Turn(void) {
    if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] > 6) {
        SimpleChess::Sounds::Music2.play();
        SimpleChess::Move::InitializeSelect();
        SimpleChess::Move::InitializeBoard();
        
        switch (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x]) {
            case SimpleChess::Pieces::Black_Pawn: SimpleChess::Move::ShowBlackPawnPath(); break;
            case SimpleChess::Pieces::Black_Rook: SimpleChess::Move::ShowBlackRookPath(); break;
            case SimpleChess::Pieces::Black_Knight: SimpleChess::Move::ShowBlackKnightPath(); break;
            case SimpleChess::Pieces::Black_Bishop: SimpleChess::Move::ShowBlackBishopPath(); break;
            case SimpleChess::Pieces::Black_King: SimpleChess::Move::ShowBlackKingPath(); break;
            case SimpleChess::Pieces::Black_Queen: SimpleChess::Move::ShowBlackQueenPath(); break;
        }
    } else if (SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] is Background::Enemy_Move or SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] is Background::Enemy_Capture) {
        SimpleChess::Sounds::Music1.play();
        std::stringstream ss, dss;
        short omove = SimpleChess::GameWindow::BoardBackground[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x];
        SimpleChess::Move::InitializeBoard();
        short opp = SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x];
        
        if (SimpleChess::Move::Select.y != SimpleChess::Move::Piece.y or SimpleChess::Move::Select.x != SimpleChess::Move::Piece.x) {
            SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] = SimpleChess::GameWindow::Board[SimpleChess::Move::Select.y][SimpleChess::Move::Select.x];
            
            if (SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] is SimpleChess::Pieces::Black_Pawn and SimpleChess::Move::Piece.y is 7) {
                SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] = SimpleChess::Pieces::Black_Queen;
            }
            
            SimpleChess::GameWindow::Board[SimpleChess::Move::Select.y][SimpleChess::Move::Select.x] = SimpleChess::Pieces::Empty;
            SimpleChess::Move::PlayerTurn = SimpleChess::Move::PlayerTurn is 1 ? 2 : 1;
            SimpleChess::GameWindow::PlayerTurn.setString("Player 1\'s Turn");
        }
        
        if (omove is Background::Enemy_Capture) {
            ss << Utils.PStringify(SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x]) << " (" << SimpleChess::Move::Select.x << ", " << SimpleChess::Move::Select.y << ") captured " << Utils.PStringify(opp) << " (" << SimpleChess::Move::Piece.x << ", " << SimpleChess::Move::Piece.y << ").";
            dss << SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] << " " << SimpleChess::Move::Select.x << " " << SimpleChess::Move::Select.y << " " << 1 << " " << opp << " " << SimpleChess::Move::Piece.x << " " << SimpleChess::Move::Piece.y;
#ifdef __CPP_DEBUG__
            SimpleChess::Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
        } else {
            ss << Utils.PStringify(SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x]) << " (" << SimpleChess::Move::Select.x << ", " << SimpleChess::Move::Select.y << ") moved to (" << SimpleChess::Move::Piece.x << ", " << SimpleChess::Move::Piece.y << ").";
            dss << SimpleChess::GameWindow::Board[SimpleChess::Move::Piece.y][SimpleChess::Move::Piece.x] << " " << SimpleChess::Move::Select.x << " " << SimpleChess::Move::Select.y << " " << 2 << " " << opp << " " << SimpleChess::Move::Piece.x << " " << SimpleChess::Move::Piece.y;
#ifdef __CPP_DEBUG__
            SimpleChess::Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
        }
        
        SimpleChess::File::Append(dss.str() + "\n");
        SimpleChess::GameWindow::LastMove.setString("Last move:\n" + ss.str());
    }
}

void SimpleChess::Move::MovePiece(void) {
    SimpleChess::Move::InitializePiece();
    SimpleChess::Move::PlayerTurn is 1 ? SimpleChess::Move::OnPlayer1Turn() : SimpleChess::Move::OnPlayer2Turn();
    SimpleChess::Move::IfGameIsOver();
}

void SimpleChess::Move::IfGameIsOver(void) {
    bool WhiteKingExists = false;
    bool BlackKingExists = false;
    
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (WhiteKingExists and BlackKingExists) {
                return;
            }
            
            if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::Black_King) {
                BlackKingExists = true;
            } else if (SimpleChess::GameWindow::Board[y][x] is SimpleChess::Pieces::White_King) {
                WhiteKingExists = true;
            }
        }
    }
    
    if (not BlackKingExists) {
        SimpleChess::StartPage::SetWhoWon(1);
    } else if (not WhiteKingExists) {
        SimpleChess::StartPage::SetWhoWon(2);
    }
    
    SimpleChess::GameWindow::Close();
}

#endif
