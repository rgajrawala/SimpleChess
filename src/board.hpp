/*
 *  board.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/21/13.
 *  Copyright (c) 2013-2015 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_board_hpp
#define SimpleChess_board_hpp

namespace SimpleChess {
	/**
	 * Piece IDs for the board.
	 */
	namespace Pieces {
		static const short Empty = 0, /**< Nothing will be printed. */
						   White_Pawn = 1, /**< A White Pawn will be printed. */
						   White_Rook = 2, /**< A White Rook (Castle) will be printed. */
						   White_Knight = 3, /**< A White Knight (Horse) will be printed. */
						   White_Bishop = 4, /**< A White Bishop will be printed. */
						   White_Queen = 5, /**< A White Queen will be printed. */
						   White_King = 6, /**< A White King will be printed. */
						   Black_Pawn = 7, /**< A Black Pawn will be printed. */
						   Black_Rook = 8, /**< A Black Rook (Castle) will be printed. */
						   Black_Knight = 9, /**< A Black Knight (Horse) will be printed. */
						   Black_Bishop = 10, /**< A Black Bishop will be printed. */
						   Black_Queen = 11, /**< A Black Queen will be printed. */
						   Black_King = 12; /**< A Black King will be printed. */

		/**
		 * Checks if the piece is empty.
		 * @see Empty
		 * @param piece The piece to check.
		 * @return True if the piece is empty, otherwise false.
		 */
		bool isEmpty(const short);

		/**
		 * Checks if the piece is Black::
		 * @see Black_Pawn
		 * @see Black_Rook
		 * @see Black_Knight
		 * @see Black_Bishop
		 * @see Black_Queen
		 * @see Black_King
		 * @param piece The piece to check.
		 * @return True if the piece is black, otherwise false.
		 */
		bool isBlack(const short);

		/**
		 * Checks if the piece if White::
		 * @see White_Pawn
		 * @see White_Rook
		 * @see White_Knight
		 * @see White_Bishop
		 * @see White_Queen
		 * @see White_King
		 * @param piece The piece to check.
		 * @return True if the piece is white, otherwise false.
		 */
		bool isWhite(const short);
	};

	/**
	 * The Background class.
	 * Background IDs for the board.
	 */
	namespace Background {
		static const short Empty = 0, /**< Nothing will be printed. */
						   Valid_Move = 1, /**< A filled green square will be printed. */
						   Valid_Capture = 2, /**< A green-bordered square will be printed. */
						   Enemy_Capture = 3, /**< A filled red square will be printed. */
						   Enemy_Move = 4; /**< A red-bordered square will be printed. */
	};

	typedef std::array<std::array<short, 8>, 8> Board8; /**< Typedef for board. */

	/**
	 * The Texture class.
	 * The images will be loaded into these textures for continuous use.
	 * SimpleChess::Textures::Initialize must first be called.
	 */
	namespace Textures {
		sf::Texture ChessBoard, /**< The board image (chessboard.png) will be loaded into here. */
					Enemy_Capture, /**< The enemy capture (red-bordered square) image (enemy_capture.png) will be loaded into here. */
					Enemy_Move, /**< The enemy move (filled red square) image (enemy_move.png) will be loaded into here. */
					Valid_Capture, /**< The valid capture (green-bordered square) image (valid_capture.png) will be loaded into here. */
					Valid_Move; /**< The valid move (filled green square) image (valid_move.png) will be loaded into here. */

		/**
		 * The SimpleChess::Textures::Black class.
		 * The black pieces' images will be stored here for use.
		 */
		namespace Black {
			sf::Texture Pawn, /**< The piece image for a Black Pawn (black_pawn.png). */
						Rook, /**< The piece image for a Black Rook (Castle) (black_rook.png). */
						Knight, /**< The piece image for a Black Knight (Horse) (black_knight.png). */
						Bishop, /**< The piece image for a Black Bishop (black_bishop.png). */
						King, /**< The piece image for a Black King (black_king.png). */
						Queen; /**< The piece image for a Black Queen (black_queen.png). */
		};

		/**
		 * The SimpleChess::Textures::White class.
		 * The white pieces' images will be stored here for use.
		 */
		namespace White {
			sf::Texture Pawn, /**< The piece image for a White Pawn (white_pawn.png). */
						Rook, /**< The piece image for a White Rook (Castle) (white_rook.png). */
						Knight, /**< The piece image for a White Knight (Horse) (white_knight.png). */
						Bishop, /**< The piece image for a White Bishop (white_bishop.png). */
						King, /**< The piece image for a White King (white_king.png). */
						Queen; /**< The piece image for a White Queen (white_queen.png). */
		};

		/**
		 * Loads all the textures with their images.
		 */
		void Initialize(void);
	};
};

////////// SOURCE //////////

void SimpleChess::Textures::Initialize(void) {
	if (!ChessBoard.loadFromFile(Resources::GetResource("chessboard.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Black::Pawn.loadFromFile(Resources::GetResource("black_pawn.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Black::Rook.loadFromFile(Resources::GetResource("black_rook.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Black::Knight.loadFromFile(Resources::GetResource("black_knight.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Black::Bishop.loadFromFile(Resources::GetResource("black_bishop.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Black::Queen.loadFromFile(Resources::GetResource("black_queen.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Black::King.loadFromFile(Resources::GetResource("black_king.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!White::Pawn.loadFromFile(Resources::GetResource("white_pawn.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!White::Rook.loadFromFile(Resources::GetResource("white_rook.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!White::Knight.loadFromFile(Resources::GetResource("white_knight.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!White::Bishop.loadFromFile(Resources::GetResource("white_bishop.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!White::Queen.loadFromFile(Resources::GetResource("white_queen.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!White::King.loadFromFile(Resources::GetResource("white_king.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Valid_Move.loadFromFile(Resources::GetResource("valid_move.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Valid_Capture.loadFromFile(Resources::GetResource("valid_capture.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Enemy_Move.loadFromFile(Resources::GetResource("enemy_move.png"))) {
		exit(EXIT_FAILURE);
	}

	if (!Enemy_Capture.loadFromFile(Resources::GetResource("enemy_capture.png"))) {
		exit(EXIT_FAILURE);
	}
}

bool SimpleChess::Pieces::isEmpty(const short piece) {
	return piece == 0;
}

bool SimpleChess::Pieces::isBlack(const short piece) {
	return piece > 6;
}

bool SimpleChess::Pieces::isWhite(const short piece) {
	return piece > 0 and piece < 7;
}

#endif
