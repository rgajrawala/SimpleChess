/*
 *  gamewindow.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_gamewindow_hpp
#define SimpleChess_gamewindow_hpp

/**
 * The GameWindow class.
 * Loads the window along with functions to create, clear, write to, and display it.
 */
class GameWindow {
public:
    sf::Event Event; /**< Where the window's new event will be stored. */
    sf::Text PlayerTurn, /**< Stores who's turn it is. */
             LastMove; /**< Stores the last move. */
    sf::Font Font; /**< Stores the font file (sansation.ttf) for the text. */
    sf::RenderWindow Window; /**< The window for the app. */
    sf::Image Icon; /**< The icon for the application. */
    sf::Sprite Sprite; /**< The Sprite that will load the board and pieces. */
    Board8 BoardBackground, /**< The board's background. */
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
} GameWindow;

/**
 * The Move class.
 * Shows the paths of each piece.
 * Also initializes the pieces' coordinates and board.
 */
class Move {
public:
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
} Move;

////////// SOURCE //////////

void GameWindow::Initialize(void) {
    if(!this->Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    this->PlayerTurn.setFont(this->Font);
    this->PlayerTurn.setString("Player 1\'s Turn");
    this->PlayerTurn.setCharacterSize(11);
    this->PlayerTurn.setPosition(680.0, 10.0);
    this->PlayerTurn.setColor(sf::Color::White);
    
    this->LastMove.setFont(this->Font);
    this->LastMove.setString("Last move:\nBoard Created.");
    this->LastMove.setCharacterSize(11);
    this->LastMove.setPosition(680.0, 40.0);
    this->LastMove.setColor(sf::Color::White);
    
	for(short y = 0; y < 8; y++) {
		for(short x = 0; x < 8; x++) {
			this->BoardBackground[y][x] = Background::Empty;
		}
	}
	
	this->Board[0][0] = Pieces::Black_Rook;
	this->Board[0][1] = Pieces::Black_Knight;
	this->Board[0][2] = Pieces::Black_Bishop;
	this->Board[0][3] = Pieces::Black_Queen;
	this->Board[0][4] = Pieces::Black_King;
	this->Board[0][5] = Pieces::Black_Bishop;
	this->Board[0][6] = Pieces::Black_Knight;
	this->Board[0][7] = Pieces::Black_Rook;
	
	for(short x = 0; x < 8; x++) {
		this->Board[1][x] = Pieces::Black_Pawn;
		this->Board[6][x] = Pieces::White_Pawn;
	}
	
	for(short y = 2; y < 6; y++) {
		for(short x = 0; x < 8; x++) {
			this->Board[y][x] = Pieces::Empty;
		}
	}
	
	this->Board[7][0] = Pieces::White_Rook;
	this->Board[7][1] = Pieces::White_Knight;
	this->Board[7][2] = Pieces::White_Bishop;
	this->Board[7][3] = Pieces::White_Queen;
	this->Board[7][4] = Pieces::White_King;
	this->Board[7][5] = Pieces::White_Bishop;
	this->Board[7][6] = Pieces::White_Knight;
	this->Board[7][7] = Pieces::White_Rook;
    
    this->Window.create(sf::VideoMode(900, 640), "SimpleChess - Game", sf::Style::Close);
    this->Window.setFramerateLimit(10);
    
    if(!this->Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    this->Window.setIcon(this->Icon.getSize().x, this->Icon.getSize().y, this->Icon.getPixelsPtr());
}

void GameWindow::Create(sf::VideoMode Mode, const sf::String& Title, sf::Uint32 Style = sf::Style::Default, const sf::ContextSettings& Settings = sf::ContextSettings()) {
    Window.create(Mode, Title, Style, Settings);
}

void GameWindow::Draw(sf::Drawable& Sprite) {
    Window.draw(Sprite);
}

bool GameWindow::IsOpen(void) {
    return Window.isOpen();
}

bool GameWindow::GetEvent(sf::Event& Event) {
    return Window.pollEvent(Event);
}

void GameWindow::Clear(void) {
    Window.clear(sf::Color::Black);
}

void GameWindow::Close(void) {
    Window.close();
}

void GameWindow::Print(void) {
    Window.display();
}

void GameWindow::Display(void) {
    this->Sprite.setTexture(Textures.ChessBoard);
    this->Sprite.setPosition(0.0, 0.0);
    this->Draw(this->Sprite);
    
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            bool isNotEmpty = true;
            
            switch(this->BoardBackground.at(y).at(x)) {
                case Background::Empty: isNotEmpty = false; break;
                case Background::Enemy_Capture: this->Sprite.setTexture(Textures.Enemy_Capture); break;
                case Background::Enemy_Move: this->Sprite.setTexture(Textures.Enemy_Move); break;
                case Background::Valid_Capture: this->Sprite.setTexture(Textures.Valid_Capture); break;
                case Background::Valid_Move: this->Sprite.setTexture(Textures.Valid_Move); break;
            }
            
            if(isNotEmpty) {
                this->Sprite.setPosition(float(x * 80), float(y * 80));
                this->Draw(this->Sprite);
            }
        }
    }
    
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
                this->Draw(this->Sprite);
            }
        }
    }
    
    this->Draw(this->PlayerTurn);
    this->Draw(this->LastMove);
    
    this->Print();
}

void GameWindow::OnKeyPress(void) {
    if((this->Event.key.code is sf::Keyboard::Escape) or ((this->Event.key.control is true or this->Event.key.alt is true) and (this->Event.key.code is sf::Keyboard::W or this->Event.key.code is sf::Keyboard::C))) {
        this->Close();
    }
}

void GameWindow::OnMouseMove(void) {
    Move.Coord.x = this->Event.mouseMove.x;
    Move.Coord.y = this->Event.mouseMove.y;
}

void GameWindow::OnMouseButtonPress(void) {
    Move.MovePiece();
}

void GameWindow::OnEvent(void) {
    switch(this->Event.type) {
        case sf::Event::Closed: this->Close(); break;
        case sf::Event::KeyPressed: this->OnKeyPress(); break;
        case sf::Event::MouseMoved: this->OnMouseMove(); break;
        case sf::Event::MouseButtonPressed: this->OnMouseButtonPress(); break;
        default: break;
    }
}

void GameWindow::Main(void) {
    File.Clear();
    Move.Initialize();
    this->Initialize();
    
    while(this->IsOpen()) {
        this->Clear();
        
        while(this->GetEvent(this->Event)) {
            this->OnEvent();
        }
        
        this->Display();
    }
}

void Move::Initialize(void) {
    this->PlayerTurn = 1;
}

void Move::InitializePiece(void) {
    this->Piece.x = (this->Coord.x - (this->Coord.x % 80)) / 80;
    this->Piece.y = (this->Coord.y - (this->Coord.y % 80)) / 80;
}

void Move::InitializeSelect(void) {
    Select = Piece;
}

void Move::InitializeBoard(void) {
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            GameWindow.BoardBackground[y][x] = Background::Empty;
        }
    }
}

void Move::ShowWhitePawnPath(void) {
    if(this->Piece.y - 1 >= 0) {
        if(GameWindow.Board[this->Piece.y - 1][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x] = Background::Valid_Move;
            
            if(this->Piece.y is 6 and GameWindow.Board[this->Piece.y - 2][this->Piece.x] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x] = Background::Valid_Move;
            }
        }
    }
    
    if(this->Piece.x - 1 >= 0 and this->Piece.y - 1 >= 0 and GameWindow.Board[this->Piece.y - 1][this->Piece.x - 1] > 6) {
        GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 1] = Background::Valid_Capture;
    }
    
    if(this->Piece.y - 1 >= 0 and this->Piece.x + 1 < 8 and GameWindow.Board[this->Piece.y - 1][this->Piece.x + 1] > 6) {
        GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 1] = Background::Valid_Capture;
    }
}

void Move::ShowWhiteRookPath(void) {
    for(int x = this->Piece.x + 1; x < 8; x++) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 6) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1; x >= 0; x--) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 6) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y + 1; y < 8; y++) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 6) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y - 1; y >= 0; y--) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 6) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
}

void Move::ShowWhiteKnightPath(void) {
    if(this->Piece.x + 2 < 8) {
        if(this->Piece.y + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 2] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 2] > 6) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 2] = Background::Valid_Capture;
            }
        }
        if(this->Piece.y - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 2] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 2] > 6) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 2] = Background::Valid_Capture;
            }
        }
    }
    
    if(this->Piece.x - 2 >= 0) {
        if(this->Piece.y + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 2] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 2] > 6) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 2] = Background::Valid_Capture;
            }
        }
        if(this->Piece.y - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 2] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 2] > 6) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 2] = Background::Valid_Capture;
            }
        }
    }
    
    if(this->Piece.y + 2 < 8) {
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 2][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x + 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y + 2][this->Piece.x + 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y + 2][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x - 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y + 2][this->Piece.x - 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
    
    if(this->Piece.y - 2 >= 0) {
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y - 2][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x + 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y - 2][this->Piece.x + 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 2][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x - 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y - 2][this->Piece.x - 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
}

void Move::ShowWhiteBishopPath(void) {
    for(int x = this->Piece.x - 1, y = this->Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1, y = this->Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
}

void Move::ShowWhiteKingPath(void) {
    if(this->Piece.x + 1 < 8) {
        if(GameWindow.Board[this->Piece.y][this->Piece.x + 1] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x + 1] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y][this->Piece.x + 1] > 6) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x + 1] = Background::Valid_Capture;
        }
    }
    
    if(this->Piece.x - 1 >= 0) {
        if(GameWindow.Board[this->Piece.y][this->Piece.x - 1] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x - 1] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y][this->Piece.x - 1] > 6) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x - 1] = Background::Valid_Capture;
        }
    }
    
    if(this->Piece.y - 1 >= 0) {
        if(GameWindow.Board[this->Piece.y - 1][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x] > 6) {
            GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x] = Background::Valid_Capture;
        }
        
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
    
    if(this->Piece.y + 1 < 8) {
        if(GameWindow.Board[this->Piece.y + 1][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x] > 6) {
            GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x] = Background::Valid_Capture;
        }
        
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 1] = Background::Valid_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 1] = Background::Valid_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] > 6) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 1] = Background::Valid_Capture;
            }
        }
    }
}

void Move::ShowWhiteQueenPath(void) {
    for(int x = this->Piece.x + 1; x < 8; x++) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 6) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1; x >= 0; x--) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 6) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y + 1; y < 8; y++) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 6) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y - 1; y >= 0; y--) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 6) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1, y = this->Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1, y = this->Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Move;
        } else if(GameWindow.Board[y][x] > 6) {
            GameWindow.BoardBackground[y][x] = Background::Valid_Capture;
            break;
        } else {
            break;
        }
    }
}

void Move::ShowBlackPawnPath(void) {
    if(this->Piece.y + 1 < 8) {
        if(GameWindow.Board[this->Piece.y + 1][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x] = Background::Enemy_Move;
            
            if(this->Piece.y is 1 and GameWindow.Board[this->Piece.y + 2][this->Piece.x] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x] = Background::Enemy_Move;
            }
        }
    }
    
    if(this->Piece.x - 1 >= 0 and this->Piece.y + 1 < 8 and GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] < 7) {
        GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 1] = Background::Enemy_Capture;
    }
    
    if(this->Piece.x + 1 < 8 and this->Piece.y + 1 < 8 and GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] < 7) {
        GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 1] = Background::Enemy_Capture;
    }
}

void Move::ShowBlackRookPath(void) {
    for(int x = this->Piece.x + 1; x < 8; x++) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 0 and GameWindow.Board[this->Piece.y][x] < 7) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1; x >= 0; x--) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 0 and GameWindow.Board[this->Piece.y][x] < 7) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y + 1; y < 8; y++) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 0 and GameWindow.Board[y][this->Piece.x] < 7) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y - 1; y >= 0; y--) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 0 and GameWindow.Board[y][this->Piece.x] < 7) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
}

void Move::ShowBlackKnightPath(void) {
    if(this->Piece.x + 2 < 8) {
        if(this->Piece.y + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 2] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 2] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x + 2] < 7) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 2] = Background::Enemy_Capture;
            }
        }
        if(this->Piece.y - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 2] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 2] > 0 and GameWindow.Board[this->Piece.y - 1][this->Piece.x + 2] < 7) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 2] = Background::Enemy_Capture;
            }
        }
    }
    
    if(this->Piece.x - 2 >= 0) {
        if(this->Piece.y + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 2] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 2] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x - 2] < 7) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 2] = Background::Enemy_Capture;
            }
        }
        if(this->Piece.y - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 2] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 2] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 2] > 0 and GameWindow.Board[this->Piece.y - 1][this->Piece.x - 2] < 7) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 2] = Background::Enemy_Capture;
            }
        }
    }
    
    if(this->Piece.y + 2 < 8) {
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 2][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x + 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y + 2][this->Piece.x + 1] > 0 and GameWindow.Board[this->Piece.y + 2][this->Piece.x + 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y + 2][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x - 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y + 2][this->Piece.x - 1] > 0 and GameWindow.Board[this->Piece.y + 2][this->Piece.x - 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y + 2][this->Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
    
    if(this->Piece.y - 2 >= 0) {
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y - 2][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x + 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y - 2][this->Piece.x + 1] > 0 and GameWindow.Board[this->Piece.y - 2][this->Piece.x + 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 2][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x - 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y - 2][this->Piece.x - 1] > 0 and GameWindow.Board[this->Piece.y - 2][this->Piece.x - 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y - 2][this->Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
}

void Move::ShowBlackBishopPath(void) {
    for(int x = this->Piece.x - 1, y = this->Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1, y = this->Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
}

void Move::ShowBlackKingPath(void) {
    if(this->Piece.x + 1 < 8) {
        if(GameWindow.Board[this->Piece.y][this->Piece.x + 1] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x + 1] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y][this->Piece.x + 1] > 0 and GameWindow.Board[this->Piece.y][this->Piece.x + 1] < 7) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x + 1] = Background::Enemy_Capture;
        }
    }
    
    if(this->Piece.x - 1 >= 0) {
        if(GameWindow.Board[this->Piece.y][this->Piece.x - 1] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x - 1] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y][this->Piece.x - 1] > 0 and GameWindow.Board[this->Piece.y][this->Piece.x - 1] < 7) {
            GameWindow.BoardBackground[this->Piece.y][this->Piece.x - 1] = Background::Enemy_Capture;
        }
    }
    
    if(this->Piece.y - 1 >= 0) {
        if(GameWindow.Board[this->Piece.y - 1][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x] > 0 and GameWindow.Board[this->Piece.y - 1][this->Piece.x] < 7) {
            GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x] = Background::Enemy_Capture;
        }
        
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x + 1] > 0 and GameWindow.Board[this->Piece.y - 1][this->Piece.x + 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if(this->Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y - 1][this->Piece.x - 1] > 0 and GameWindow.Board[this->Piece.y - 1][this->Piece.x - 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y - 1][this->Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
    
    if(this->Piece.y + 1 < 8) {
        if(GameWindow.Board[this->Piece.y + 1][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x] < 7) {
            GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x] = Background::Enemy_Capture;
        }
        
        if(this->Piece.x + 1 < 8) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x + 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x + 1] = Background::Enemy_Capture;
            }
        }
        
        if(Piece.x - 1 >= 0) {
            if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] is Pieces::Empty) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 1] = Background::Enemy_Move;
            } else if(GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] > 0 and GameWindow.Board[this->Piece.y + 1][this->Piece.x - 1] < 7) {
                GameWindow.BoardBackground[this->Piece.y + 1][this->Piece.x - 1] = Background::Enemy_Capture;
            }
        }
    }
}

void Move::ShowBlackQueenPath(void) {
    for(int x = this->Piece.x + 1; x < 8; x++) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 0 and GameWindow.Board[this->Piece.y][x] < 7) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1; x >= 0; x--) {
        if(GameWindow.Board[this->Piece.y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[this->Piece.y][x] > 0 and GameWindow.Board[this->Piece.y][x] < 7) {
            GameWindow.BoardBackground[this->Piece.y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y + 1; y < 8; y++) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 0 and GameWindow.Board[y][this->Piece.x] < 7) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int y = this->Piece.y - 1; y >= 0; y--) {
        if(GameWindow.Board[y][this->Piece.x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][this->Piece.x] > 0 and GameWindow.Board[y][this->Piece.x] < 7) {
            GameWindow.BoardBackground[y][this->Piece.x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1, y = this->Piece.y - 1; x >= 0 and y >= 0; x--, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y - 1; x < 8 and y >= 0; x++, y--) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x + 1, y = this->Piece.y + 1; x < 8 and y < 8; x++, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
    
    for(int x = this->Piece.x - 1, y = this->Piece.y + 1; x >= 0 and y < 8; x--, y++) {
        if(GameWindow.Board[y][x] is Pieces::Empty) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Move;
        } else if(GameWindow.Board[y][x] > 0 and GameWindow.Board[y][x] < 7) {
            GameWindow.BoardBackground[y][x] = Background::Enemy_Capture;
            break;
        } else {
            break;
        }
    }
}

void Move::OnPlayer1Turn(void) {
    if(GameWindow.Board[this->Piece.y][this->Piece.x] > 0 and GameWindow.Board[this->Piece.y][this->Piece.x] < 7) {
        Sounds.Music2.play();
        this->InitializeSelect();
        this->InitializeBoard();
        
        switch(GameWindow.Board[this->Piece.y][this->Piece.x]) {
            case Pieces::White_Pawn: Move::ShowWhitePawnPath(); break;
            case Pieces::White_Rook: Move::ShowWhiteRookPath(); break;
            case Pieces::White_Knight: Move::ShowWhiteKnightPath(); break;
            case Pieces::White_Bishop: Move::ShowWhiteBishopPath(); break;
            case Pieces::White_King: Move::ShowWhiteKingPath(); break;
            case Pieces::White_Queen: Move::ShowWhiteQueenPath(); break;
        }
    } else if(GameWindow.BoardBackground[this->Piece.y][this->Piece.x] is Background::Valid_Move or GameWindow.BoardBackground[this->Piece.y][this->Piece.x] is Background::Valid_Capture) {
        Sounds.Music1.play();
        std::stringstream ss, dss;
        short omove = GameWindow.BoardBackground[this->Piece.y][this->Piece.x];
        this->InitializeBoard();
        short opp = GameWindow.Board[this->Piece.y][this->Piece.x];
        
        if(this->Select.y != this->Piece.y or this->Select.x != this->Piece.x) {
            GameWindow.Board[this->Piece.y][this->Piece.x] = GameWindow.Board[this->Select.y][this->Select.x];
            
            if(GameWindow.Board[this->Piece.y][this->Piece.x] is Pieces::White_Pawn and this->Piece.y is 0) {
                GameWindow.Board[this->Piece.y][this->Piece.x] = Pieces::White_Queen;
            }
            
            GameWindow.Board[this->Select.y][this->Select.x] = Pieces::Empty;
            this->PlayerTurn = this->PlayerTurn is 1 ? 2 : 1;
            GameWindow.PlayerTurn.setString("Player 2\'s Turn");
        }
        
        if(omove is Background::Valid_Capture) {
            ss << Utils.PStringify(GameWindow.Board[this->Piece.y][this->Piece.x]) << " (" << this->Select.x << ", " << this->Select.y << ") captured " << Utils.PStringify(opp) << " (" << this->Piece.x << ", " << this->Piece.y << ").";
            dss << GameWindow.Board[this->Piece.y][this->Piece.x] << " " << this->Select.x << " " << this->Select.y << " " << 1 << " " << opp << " " << this->Piece.x << " " << this->Piece.y;
            Console.Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
        } else {
            ss << Utils.PStringify(GameWindow.Board[this->Piece.y][this->Piece.x]) << " (" << this->Select.x << ", " << this->Select.y << ") moved to (" << this->Piece.x << ", " << this->Piece.y << ").";
            dss << GameWindow.Board[this->Piece.y][this->Piece.x] << " " << this->Select.x << " " << this->Select.y << " " << 2 << " " << opp << " " << this->Piece.x << " " << this->Piece.y;
            Console.Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
        }
        
        File.Append(dss.str() + "\n");
        GameWindow.LastMove.setString("Last move:\n" + ss.str());
    }
}

void Move::OnPlayer2Turn(void) {
    if(GameWindow.Board[this->Piece.y][this->Piece.x] > 6) {
        Sounds.Music2.play();
        this->InitializeSelect();
        this->InitializeBoard();
        
        switch(GameWindow.Board[this->Piece.y][this->Piece.x]) {
            case Pieces::Black_Pawn: Move::ShowBlackPawnPath(); break;
            case Pieces::Black_Rook: Move::ShowBlackRookPath(); break;
            case Pieces::Black_Knight: Move::ShowBlackKnightPath(); break;
            case Pieces::Black_Bishop: Move::ShowBlackBishopPath(); break;
            case Pieces::Black_King: Move::ShowBlackKingPath(); break;
            case Pieces::Black_Queen: Move::ShowBlackQueenPath(); break;
        }
    } else if(GameWindow.BoardBackground[this->Piece.y][this->Piece.x] is Background::Enemy_Move or GameWindow.BoardBackground[this->Piece.y][this->Piece.x] is Background::Enemy_Capture) {
        Sounds.Music1.play();
        std::stringstream ss, dss;
        short omove = GameWindow.BoardBackground[this->Piece.y][this->Piece.x];
        this->InitializeBoard();
        short opp = GameWindow.Board[this->Piece.y][this->Piece.x];
        
        if(this->Select.y != this->Piece.y or this->Select.x != this->Piece.x) {
            GameWindow.Board[this->Piece.y][this->Piece.x] = GameWindow.Board[this->Select.y][this->Select.x];
            
            if(GameWindow.Board[this->Piece.y][this->Piece.x] is Pieces::Black_Pawn and this->Piece.y is 7) {
                GameWindow.Board[this->Piece.y][this->Piece.x] = Pieces::Black_Queen;
            }
            
            GameWindow.Board[this->Select.y][this->Select.x] = Pieces::Empty;
            this->PlayerTurn = this->PlayerTurn is 1 ? 2 : 1;
            GameWindow.PlayerTurn.setString("Player 1\'s Turn");
        }
        
        if(omove is Background::Enemy_Capture) {
            ss << Utils.PStringify(GameWindow.Board[this->Piece.y][this->Piece.x]) << " (" << this->Select.x << ", " << this->Select.y << ") captured " << Utils.PStringify(opp) << " (" << this->Piece.x << ", " << this->Piece.y << ").";
            dss << GameWindow.Board[this->Piece.y][this->Piece.x] << " " << this->Select.x << " " << this->Select.y << " " << 1 << " " << opp << " " << this->Piece.x << " " << this->Piece.y;
            Console.Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
        } else {
            ss << Utils.PStringify(GameWindow.Board[this->Piece.y][this->Piece.x]) << " (" << this->Select.x << ", " << this->Select.y << ") moved to (" << this->Piece.x << ", " << this->Piece.y << ").";
            dss << GameWindow.Board[this->Piece.y][this->Piece.x] << " " << this->Select.x << " " << this->Select.y << " " << 2 << " " << opp << " " << this->Piece.x << " " << this->Piece.y;
            Console.Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
        }
        
        File.Append(dss.str() + "\n");
        GameWindow.LastMove.setString("Last move:\n" + ss.str());
    }
}

void Move::MovePiece(void) {
    this->InitializePiece();
    this->PlayerTurn is 1 ? this->OnPlayer1Turn() : this->OnPlayer2Turn();
    this->IfGameIsOver();
}

void Move::IfGameIsOver(void) {
    bool WhiteKingExists = false;
    bool BlackKingExists = false;
    
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            if(WhiteKingExists and BlackKingExists) {
                return;
            }
            
            if(GameWindow.Board[y][x] is Pieces::Black_King) {
                BlackKingExists = true;
            } else if(GameWindow.Board[y][x] is Pieces::White_King) {
                WhiteKingExists = true;
            }
        }
    }
    
    if(not BlackKingExists) {
        StartPage.SetWhoWon(1);
    } else if(not WhiteKingExists) {
        StartPage.SetWhoWon(2);
    }
    
    GameWindow.Close();
}

#endif
