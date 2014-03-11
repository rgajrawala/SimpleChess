/*
 *  gamewindow.hpp
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

        /**
         * The Move class.
         * Anything to do with the board.
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
};

////////// SOURCE //////////

void SimpleChess::GameWindow::Initialize(void) {
	if (not Font.loadFromFile(Resources::GetResource("sansation.ttf"))) {
		exit(EXIT_FAILURE);
	}

	PlayerTurn.setFont(Font);
	PlayerTurn.setString("Player 1\'s Turn");
	PlayerTurn.setCharacterSize(11);
	PlayerTurn.setPosition(680.0, 10.0);
	PlayerTurn.setColor(sf::Color::White);

	LastMove.setFont(Font);
	LastMove.setString("Last move:\nBoard Created.");
	LastMove.setCharacterSize(11);
	LastMove.setPosition(680.0, 40.0);
	LastMove.setColor(sf::Color::White);

	for (short y = 0; y < 8; y++) {
		for (short x = 0; x < 8; x++) {
			BoardBackground[y][x] = Background::Empty;
		}
	}

	Board[0][0] = SimpleChess::Pieces::Black_Rook;
	Board[0][1] = SimpleChess::Pieces::Black_Knight;
	Board[0][2] = SimpleChess::Pieces::Black_Bishop;
	Board[0][3] = SimpleChess::Pieces::Black_Queen;
	Board[0][4] = SimpleChess::Pieces::Black_King;
	Board[0][5] = SimpleChess::Pieces::Black_Bishop;
	Board[0][6] = SimpleChess::Pieces::Black_Knight;
	Board[0][7] = SimpleChess::Pieces::Black_Rook;

	for (short x = 0; x < 8; x++) {
		Board[1][x] = SimpleChess::Pieces::Black_Pawn;
		Board[6][x] = SimpleChess::Pieces::White_Pawn;
	}

	for (short y = 2; y < 6; y++) {
		for (short x = 0; x < 8; x++) {
			Board[y][x] = SimpleChess::Pieces::Empty;
		}
	}

	Board[7][0] = SimpleChess::Pieces::White_Rook;
	Board[7][1] = SimpleChess::Pieces::White_Knight;
	Board[7][2] = SimpleChess::Pieces::White_Bishop;
	Board[7][3] = SimpleChess::Pieces::White_Queen;
	Board[7][4] = SimpleChess::Pieces::White_King;
	Board[7][5] = SimpleChess::Pieces::White_Bishop;
	Board[7][6] = SimpleChess::Pieces::White_Knight;
	Board[7][7] = SimpleChess::Pieces::White_Rook;

	Window.create(sf::VideoMode(900, 640), "SimpleChess - Game", sf::Style::Close);
	Window.setFramerateLimit(10);

	if (not Icon.loadFromFile(Resources::GetResource("white_knight.png"))) {
		exit(EXIT_FAILURE);
	}
	Window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());
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
	Sprite.setTexture(SimpleChess::Textures::ChessBoard);
	Sprite.setPosition(0.0, 0.0);
	Draw(Sprite);

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			bool isNotEmpty = true;

			switch (BoardBackground.at(y).at(x)) {
				case Background::Empty: isNotEmpty = false; break;
				case Background::Enemy_Capture: Sprite.setTexture(SimpleChess::Textures::Enemy_Capture); break;
				case Background::Enemy_Move: Sprite.setTexture(SimpleChess::Textures::Enemy_Move); break;
				case Background::Valid_Capture: Sprite.setTexture(SimpleChess::Textures::Valid_Capture); break;
				case Background::Valid_Move: Sprite.setTexture(SimpleChess::Textures::Valid_Move); break;
			}

			if (isNotEmpty) {
				Sprite.setPosition(float(x * 80), float(y * 80));
				Draw(Sprite);
			}
		}
	}

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			bool isNotEmpty = true;

			switch (Board.at(y).at(x)) {
				case SimpleChess::Pieces::Empty: isNotEmpty = false; break;
				case SimpleChess::Pieces::Black_Pawn: Sprite.setTexture(SimpleChess::Textures::Black::Pawn); break;
				case SimpleChess::Pieces::Black_Rook: Sprite.setTexture(SimpleChess::Textures::Black::Rook); break;
				case SimpleChess::Pieces::Black_Knight: Sprite.setTexture(SimpleChess::Textures::Black::Knight); break;
				case SimpleChess::Pieces::Black_Bishop: Sprite.setTexture(SimpleChess::Textures::Black::Bishop); break;
				case SimpleChess::Pieces::Black_Queen: Sprite.setTexture(SimpleChess::Textures::Black::Queen); break;
				case SimpleChess::Pieces::Black_King: Sprite.setTexture(SimpleChess::Textures::Black::King); break;
				case SimpleChess::Pieces::White_Pawn: Sprite.setTexture(SimpleChess::Textures::White::Pawn); break;
				case SimpleChess::Pieces::White_Rook: Sprite.setTexture(SimpleChess::Textures::White::Rook); break;
				case SimpleChess::Pieces::White_Knight: Sprite.setTexture(SimpleChess::Textures::White::Knight); break;
				case SimpleChess::Pieces::White_Bishop: Sprite.setTexture(SimpleChess::Textures::White::Bishop); break;
				case SimpleChess::Pieces::White_Queen: Sprite.setTexture(SimpleChess::Textures::White::Queen); break;
				case SimpleChess::Pieces::White_King: Sprite.setTexture(SimpleChess::Textures::White::King); break;
			}

			if (isNotEmpty) {
				Sprite.setPosition(float(x * 80), float(y * 80));
				Draw(Sprite);
			}
		}
	}

	Draw(PlayerTurn);
	Draw(LastMove);

	Print();
}

void SimpleChess::GameWindow::OnKeyPress(void) {
	if ((Event.key.code is sf::Keyboard::Escape) or ((Event.key.control is true or Event.key.alt is true) and (Event.key.code is sf::Keyboard::W or Event.key.code is sf::Keyboard::C))) {
		Close();
	}
}

void SimpleChess::GameWindow::OnMouseMove(void) {
	Move::Coord.x = Event.mouseMove.x;
	Move::Coord.y = Event.mouseMove.y;
}

void SimpleChess::GameWindow::OnMouseButtonPress(void) {
	Move::MovePiece();
}

void SimpleChess::GameWindow::OnEvent(void) {
	switch (Event.type) {
		case sf::Event::Closed: Close(); break;
		case sf::Event::KeyPressed: OnKeyPress(); break;
		case sf::Event::MouseMoved: OnMouseMove(); break;
		case sf::Event::MouseButtonPressed: OnMouseButtonPress(); break;
		default: break;
	}
}

void SimpleChess::GameWindow::Main(void) {
	SimpleChess::File::Clear();
	Move::Initialize();
	Initialize();

	while (IsOpen()) {
		Clear();

		while (GetEvent(Event)) {
		OnEvent();
		}

		Display();
	}
}

void SimpleChess::GameWindow::Move::Initialize(void) {
	PlayerTurn = 1;
}

void SimpleChess::GameWindow::Move::InitializePiece(void) {
	Piece.x = (Coord.x - (Coord.x % 80)) / 80;
	Piece.y = (Coord.y - (Coord.y % 80)) / 80;
}

void SimpleChess::GameWindow::Move::InitializeSelect(void) {
	Select = Piece;
}

void SimpleChess::GameWindow::Move::InitializeBoard(void) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			GameWindow::BoardBackground[y][x] = Background::Empty;
		}
	}
}

void SimpleChess::GameWindow::Move::OnPlayer1Turn(void) {
	if (GameWindow::Board[Piece.y][Piece.x] > 0 and GameWindow::Board[Piece.y][Piece.x] < 7) {
		SimpleChess::Sounds::Music2.play();
		InitializeSelect();
		InitializeBoard();

		switch (GameWindow::Board[Piece.y][Piece.x]) {
			case SimpleChess::Pieces::White_Pawn: SimpleChess::Move::ShowWhitePawnPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::White_Rook: SimpleChess::Move::ShowWhiteRookPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::White_Knight: SimpleChess::Move::ShowWhiteKnightPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::White_Bishop: SimpleChess::Move::ShowWhiteBishopPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::White_King: SimpleChess::Move::ShowWhiteKingPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::White_Queen: SimpleChess::Move::ShowWhiteQueenPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
		}
	} else if (GameWindow::BoardBackground[Piece.y][Piece.x] is Background::Valid_Move or GameWindow::BoardBackground[Piece.y][Piece.x] is Background::Valid_Capture) {
		SimpleChess::Sounds::Music1.play();
		std::stringstream ss, dss;
		short omove = GameWindow::BoardBackground[Piece.y][Piece.x];
		InitializeBoard();
		short opp = GameWindow::Board[Piece.y][Piece.x];

		if (Select.y != Piece.y or Select.x != Piece.x) {
			GameWindow::Board[Piece.y][Piece.x] = GameWindow::Board[Select.y][Select.x];

			if (GameWindow::Board[Piece.y][Piece.x] is SimpleChess::Pieces::White_Pawn and Piece.y is 0) {
				GameWindow::Board[Piece.y][Piece.x] = SimpleChess::Pieces::White_Queen;
			}

			GameWindow::Board[Select.y][Select.x] = SimpleChess::Pieces::Empty;
			PlayerTurn = PlayerTurn is 1 ? 2 : 1;
			GameWindow::PlayerTurn.setString("Player 2\'s Turn");
		}

		if (omove is Background::Valid_Capture) {
			ss << Utils::PStringify(GameWindow::Board[Piece.y][Piece.x]) << " (" << Select.x << ", " << Select.y << ") captured " << Utils::PStringify(opp) << " (" << Piece.x << ", " << Piece.y << ").";
			dss << GameWindow::Board[Piece.y][Piece.x] << " " << Select.x << " " << Select.y << " " << 1 << " " << opp << " " << Piece.x << " " << Piece.y;
#ifdef __CPP_DEBUG__
			Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
		} else {
			ss << Utils::PStringify(GameWindow::Board[Piece.y][Piece.x]) << " (" << Select.x << ", " << Select.y << ") moved to (" << Piece.x << ", " << Piece.y << ").";
			dss << GameWindow::Board[Piece.y][Piece.x] << " " << Select.x << " " << Select.y << " " << 0 << " " << opp << " " << Piece.x << " " << Piece.y;
#ifdef __CPP_DEBUG__
			Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
		}

		SimpleChess::File::Append(dss.str() + "\n");
		GameWindow::LastMove.setString("Last move:\n" + ss.str());
	}
}

void SimpleChess::GameWindow::Move::OnPlayer2Turn(void) {
	if (GameWindow::Board[Piece.y][Piece.x] > 6) {
		SimpleChess::Sounds::Music2.play();
		InitializeSelect();
		InitializeBoard();

		switch (GameWindow::Board[Piece.y][Piece.x]) {
			case SimpleChess::Pieces::Black_Pawn: SimpleChess::Move::ShowBlackPawnPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::Black_Rook: SimpleChess::Move::ShowBlackRookPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::Black_Knight: SimpleChess::Move::ShowBlackKnightPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::Black_Bishop: SimpleChess::Move::ShowBlackBishopPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::Black_King: SimpleChess::Move::ShowBlackKingPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
			case SimpleChess::Pieces::Black_Queen: SimpleChess::Move::ShowBlackQueenPath(GameWindow::Board, GameWindow::BoardBackground, Piece); break;
		}
	} else if (GameWindow::BoardBackground[Piece.y][Piece.x] is Background::Enemy_Move or GameWindow::BoardBackground[Piece.y][Piece.x] is Background::Enemy_Capture) {
		SimpleChess::Sounds::Music1.play();
		std::stringstream ss, dss;
		short omove = GameWindow::BoardBackground[Piece.y][Piece.x];
		InitializeBoard();
		short opp = GameWindow::Board[Piece.y][Piece.x];

		if (Select.y != Piece.y or Select.x != Piece.x) {
			GameWindow::Board[Piece.y][Piece.x] = GameWindow::Board[Select.y][Select.x];

			if (GameWindow::Board[Piece.y][Piece.x] is SimpleChess::Pieces::Black_Pawn and Piece.y is 7) {
				GameWindow::Board[Piece.y][Piece.x] = SimpleChess::Pieces::Black_Queen;
			}

			GameWindow::Board[Select.y][Select.x] = SimpleChess::Pieces::Empty;
			PlayerTurn = PlayerTurn is 1 ? 2 : 1;
			GameWindow::PlayerTurn.setString("Player 1\'s Turn");
		}

		if (omove is Background::Enemy_Capture) {
			ss << Utils::PStringify(GameWindow::Board[Piece.y][Piece.x]) << " (" << Select.x << ", " << Select.y << ") captured " << Utils::PStringify(opp) << " (" << Piece.x << ", " << Piece.y << ").";
			dss << GameWindow::Board[Piece.y][Piece.x] << " " << Select.x << " " << Select.y << " " << 1 << " " << opp << " " << Piece.x << " " << Piece.y;
#ifdef __CPP_DEBUG__
			Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
			} else {
			ss << Utils::PStringify(GameWindow::Board[Piece.y][Piece.x]) << " (" << Select.x << ", " << Select.y << ") moved to (" << Piece.x << ", " << Piece.y << ").";
			dss << GameWindow::Board[Piece.y][Piece.x] << " " << Select.x << " " << Select.y << " " << 0 << " " << opp << " " << Piece.x << " " << Piece.y;
#ifdef __CPP_DEBUG__
			Console::Log(__LINE__, __FILE__, __func__, "%s", ss.str().c_str());
#endif
		}

		SimpleChess::File::Append(dss.str() + "\n");
		GameWindow::LastMove.setString("Last move:\n" + ss.str());
	}
}

void SimpleChess::GameWindow::Move::MovePiece(void) {
	InitializePiece();
	PlayerTurn is 1 ? OnPlayer1Turn() : OnPlayer2Turn();
	IfGameIsOver();
}

void SimpleChess::GameWindow::Move::IfGameIsOver(void) {
	bool WhiteKingExists = false,
		 BlackKingExists = false;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (WhiteKingExists and BlackKingExists) {
				return;
			}

			if (GameWindow::Board[y][x] is SimpleChess::Pieces::Black_King) {
				BlackKingExists = true;
			} else if (GameWindow::Board[y][x] is SimpleChess::Pieces::White_King) {
				WhiteKingExists = true;
			}
		}
	}

	if (not BlackKingExists) {
		SimpleChess::StartPage::SetWhoWon(1);
	} else if (not WhiteKingExists) {
		SimpleChess::StartPage::SetWhoWon(2);
	}

	GameWindow::Close();
}

#endif
