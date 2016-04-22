/*
 *  move.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 3/10/14.
 *  Copyright (c) 2014-2015 Usandfriends. All rights reserved.
 */

#ifndef SimpleChess_move_hpp
#define SimpleChess_move_hpp

namespace SimpleChess {
	/**
	 * The Move class.
	 * Shows the paths of each piece.
	 */
	namespace Move {
		/**
		 * Shows the paths a White Pawn can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 * @param isFriendly True if show green paths, false if show red paths.
		 */
		void ShowWhitePawnPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a White Rook can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowWhiteRookPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a White Knight can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowWhiteKnightPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a White Bishop can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowWhiteBishopPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a White Queen can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowWhiteQueenPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a White King can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowWhiteKingPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a Black Pawn can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowBlackPawnPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a Black Rook can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowBlackRookPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a Black Knight can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowBlackKnightPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a Black Bishop can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowBlackBishopPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a Black Queen can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowBlackQueenPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);

		/**
		 * Shows the paths a Black King can take.
		 * @param board The board to edit.
		 * @param boardbackground The board's background to edit.
		 * @param piece The location of the piece to show the paths of.
		 */
		void ShowBlackKingPath(SimpleChess::Board8&, SimpleChess::Board8&, sf::Vector2i, bool);
	};
};

////////// SOURCE //////////

void SimpleChess::Move::ShowWhitePawnPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	if (piece.y - 1 >= 0) {
		if (board[piece.y - 1][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y - 1][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;

			if (piece.y is 6 and board[piece.y - 2][piece.x] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 2][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			}
		}
	}

	if (piece.x - 1 >= 0 and piece.y - 1 >= 0 and board[piece.y - 1][piece.x - 1] > 6) {
		boardbackground[piece.y - 1][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
	}

	if (piece.y - 1 >= 0 and piece.x + 1 < 8 and board[piece.y - 1][piece.x + 1] > 6) {
		boardbackground[piece.y - 1][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
	}
}

void SimpleChess::Move::ShowWhiteRookPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	for (int x = piece.x + 1; x < 8; x++) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 6) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1; x >= 0; x--) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 6) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y + 1; y < 8; y++) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 6) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y - 1; y >= 0; y--) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 6) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}
}

void SimpleChess::Move::ShowWhiteKnightPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	if (piece.x + 2 < 8) {
		if (piece.y + 1 < 8) {
			if (board[piece.y + 1][piece.x + 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x + 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x + 2] > 6) {
				boardbackground[piece.y + 1][piece.x + 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.y - 1 >= 0) {
			if (board[piece.y - 1][piece.x + 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x + 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x + 2] > 6) {
				boardbackground[piece.y - 1][piece.x + 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.x - 2 >= 0) {
		if (piece.y + 1 < 8) {
			if (board[piece.y + 1][piece.x - 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x - 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x - 2] > 6) {
				boardbackground[piece.y + 1][piece.x - 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.y - 1 >= 0) {
			if (board[piece.y - 1][piece.x - 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x - 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x - 2] > 6) {
				boardbackground[piece.y - 1][piece.x - 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.y + 2 < 8) {
		if (piece.x + 1 < 8) {
			if (board[piece.y + 2][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 2][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 2][piece.x + 1] > 6) {
				boardbackground[piece.y + 2][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.x - 1 >= 0) {
			if (board[piece.y + 2][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 2][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 2][piece.x - 1] > 6) {
				boardbackground[piece.y + 2][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.y - 2 >= 0) {
		if (piece.x + 1 < 8) {
			if (board[piece.y - 2][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 2][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 2][piece.x + 1] > 6) {
				boardbackground[piece.y - 2][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.x - 1 >= 0) {
			if (board[piece.y - 2][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 2][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 2][piece.x - 1] > 6) {
				boardbackground[piece.y - 2][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}
}

void SimpleChess::Move::ShowWhiteBishopPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	for (int x = piece.x - 1, y = piece.y - 1; x >= 0 and y >= 0; x--, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y - 1; x < 8 and y >= 0; x++, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y + 1; x < 8 and y < 8; x++, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1, y = piece.y + 1; x >= 0 and y < 8; x--, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}
}

void SimpleChess::Move::ShowWhiteKingPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	if (piece.x + 1 < 8) {
		if (board[piece.y][piece.x + 1] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][piece.x + 1] > 6) {
			boardbackground[piece.y][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}
	}

	if (piece.x - 1 >= 0) {
		if (board[piece.y][piece.x - 1] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][piece.x - 1] > 6) {
			boardbackground[piece.y][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}
	}

	if (piece.y - 1 >= 0) {
		if (board[piece.y - 1][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y - 1][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y - 1][piece.x] > 6) {
			boardbackground[piece.y - 1][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}

		if (piece.x + 1 < 8) {
			if (board[piece.y - 1][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x + 1] > 6) {
				boardbackground[piece.y - 1][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}

		if (piece.x - 1 >= 0) {
			if (board[piece.y - 1][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x - 1] > 6) {
				boardbackground[piece.y - 1][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.y + 1 < 8) {
		if (board[piece.y + 1][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y + 1][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y + 1][piece.x] > 6) {
			boardbackground[piece.y + 1][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}

		if (piece.x + 1 < 8) {
			if (board[piece.y + 1][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x + 1] > 6) {
				boardbackground[piece.y + 1][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}

		if (piece.x - 1 >= 0) {
			if (board[piece.y + 1][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x - 1] > 6) {
				boardbackground[piece.y + 1][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}
}

void SimpleChess::Move::ShowWhiteQueenPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	for (int x = piece.x + 1; x < 8; x++) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 6) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1; x >= 0; x--) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 6) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y + 1; y < 8; y++) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 6) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y - 1; y >= 0; y--) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 6) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1, y = piece.y - 1; x >= 0 and y >= 0; x--, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y - 1; x < 8 and y >= 0; x++, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y + 1; x < 8 and y < 8; x++, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1, y = piece.y + 1; x >= 0 and y < 8; x--, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 6) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}
}

void SimpleChess::Move::ShowBlackPawnPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	if (piece.y + 1 < 8) {
		if (board[piece.y + 1][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y + 1][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;

			if (piece.y is 1 and board[piece.y + 2][piece.x] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 2][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			}
		}
	}

	if (piece.x - 1 >= 0 and piece.y + 1 < 8 and board[piece.y + 1][piece.x - 1] > 0 and board[piece.y + 1][piece.x - 1] < 7) {
		boardbackground[piece.y + 1][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
	}

	if (piece.x + 1 < 8 and piece.y + 1 < 8 and board[piece.y + 1][piece.x + 1] > 0 and board[piece.y + 1][piece.x + 1] < 7) {
		boardbackground[piece.y + 1][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
	}
}

void SimpleChess::Move::ShowBlackRookPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	for (int x = piece.x + 1; x < 8; x++) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 0 and board[piece.y][x] < 7) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1; x >= 0; x--) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 0 and board[piece.y][x] < 7) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y + 1; y < 8; y++) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 0 and board[y][piece.x] < 7) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y - 1; y >= 0; y--) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 0 and board[y][piece.x] < 7) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}
}

void SimpleChess::Move::ShowBlackKnightPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	if (piece.x + 2 < 8) {
		if (piece.y + 1 < 8) {
			if (board[piece.y + 1][piece.x + 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x + 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x + 2] > 0 and board[piece.y + 1][piece.x + 2] < 7) {
				boardbackground[piece.y + 1][piece.x + 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.y - 1 >= 0) {
			if (board[piece.y - 1][piece.x + 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x + 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x + 2] > 0 and board[piece.y - 1][piece.x + 2] < 7) {
				boardbackground[piece.y - 1][piece.x + 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.x - 2 >= 0) {
		if (piece.y + 1 < 8) {
			if (board[piece.y + 1][piece.x - 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x - 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x - 2] > 0 and board[piece.y + 1][piece.x - 2] < 7) {
				boardbackground[piece.y + 1][piece.x - 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.y - 1 >= 0) {
			if (board[piece.y - 1][piece.x - 2] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x - 2] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x - 2] > 0 and board[piece.y - 1][piece.x - 2] < 7) {
				boardbackground[piece.y - 1][piece.x - 2] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.y + 2 < 8) {
		if (piece.x + 1 < 8) {
			if (board[piece.y + 2][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 2][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 2][piece.x + 1] > 0 and board[piece.y + 2][piece.x + 1] < 7) {
				boardbackground[piece.y + 2][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.x - 1 >= 0) {
			if (board[piece.y + 2][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 2][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 2][piece.x - 1] > 0 and board[piece.y + 2][piece.x - 1] < 7) {
				boardbackground[piece.y + 2][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.y - 2 >= 0) {
		if (piece.x + 1 < 8) {
			if (board[piece.y - 2][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 2][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 2][piece.x + 1] > 0 and board[piece.y - 2][piece.x + 1] < 7) {
				boardbackground[piece.y - 2][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
		if (piece.x - 1 >= 0) {
			if (board[piece.y - 2][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 2][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 2][piece.x - 1] > 0 and board[piece.y - 2][piece.x - 1] < 7) {
				boardbackground[piece.y - 2][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}
}

void SimpleChess::Move::ShowBlackBishopPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	for (int x = piece.x - 1, y = piece.y - 1; x >= 0 and y >= 0; x--, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y - 1; x < 8 and y >= 0; x++, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y + 1; x < 8 and y < 8; x++, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1, y = piece.y + 1; x >= 0 and y < 8; x--, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}
}

void SimpleChess::Move::ShowBlackKingPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	if (piece.x + 1 < 8) {
		if (board[piece.y][piece.x + 1] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][piece.x + 1] > 0 and board[piece.y][piece.x + 1] < 7) {
			boardbackground[piece.y][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}
	}

	if (piece.x - 1 >= 0) {
		if (board[piece.y][piece.x - 1] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][piece.x - 1] > 0 and board[piece.y][piece.x - 1] < 7) {
			boardbackground[piece.y][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}
	}

	if (piece.y - 1 >= 0) {
		if (board[piece.y - 1][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y - 1][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y - 1][piece.x] > 0 and board[piece.y - 1][piece.x] < 7) {
			boardbackground[piece.y - 1][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}

		if (piece.x + 1 < 8) {
			if (board[piece.y - 1][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x + 1] > 0 and board[piece.y - 1][piece.x + 1] < 7) {
				boardbackground[piece.y - 1][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}

		if (piece.x - 1 >= 0) {
			if (board[piece.y - 1][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y - 1][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y - 1][piece.x - 1] > 0 and board[piece.y - 1][piece.x - 1] < 7) {
				boardbackground[piece.y - 1][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}

	if (piece.y + 1 < 8) {
		if (board[piece.y + 1][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y + 1][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y + 1][piece.x] > 0 and board[piece.y + 1][piece.x] < 7) {
			boardbackground[piece.y + 1][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
		}

		if (piece.x + 1 < 8) {
			if (board[piece.y + 1][piece.x + 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x + 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x + 1] > 0 and board[piece.y + 1][piece.x + 1] < 7) {
				boardbackground[piece.y + 1][piece.x + 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}

		if (piece.x - 1 >= 0) {
			if (board[piece.y + 1][piece.x - 1] is SimpleChess::Pieces::Empty) {
				boardbackground[piece.y + 1][piece.x - 1] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
			} else if (board[piece.y + 1][piece.x - 1] > 0 and board[piece.y + 1][piece.x - 1] < 7) {
				boardbackground[piece.y + 1][piece.x - 1] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			}
		}
	}
}

void SimpleChess::Move::ShowBlackQueenPath(SimpleChess::Board8& board, SimpleChess::Board8& boardbackground, sf::Vector2i piece, bool isFriendly) {
	for (int x = piece.x + 1; x < 8; x++) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 0 and board[piece.y][x] < 7) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1; x >= 0; x--) {
		if (board[piece.y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[piece.y][x] > 0 and board[piece.y][x] < 7) {
			boardbackground[piece.y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y + 1; y < 8; y++) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 0 and board[y][piece.x] < 7) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int y = piece.y - 1; y >= 0; y--) {
		if (board[y][piece.x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][piece.x] > 0 and board[y][piece.x] < 7) {
			boardbackground[y][piece.x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1, y = piece.y - 1; x >= 0 and y >= 0; x--, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y - 1; x < 8 and y >= 0; x++, y--) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x + 1, y = piece.y + 1; x < 8 and y < 8; x++, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}

	for (int x = piece.x - 1, y = piece.y + 1; x >= 0 and y < 8; x--, y++) {
		if (board[y][x] is SimpleChess::Pieces::Empty) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Move : Background::Enemy_Move;
		} else if (board[y][x] > 0 and board[y][x] < 7) {
			boardbackground[y][x] = isFriendly ? Background::Valid_Capture : Background::Enemy_Capture;
			break;
		} else {
			break;
		}
	}
}

#endif
