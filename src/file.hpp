/*
 *  file.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/26/13.
 *  Copyright (c) 2013-2015 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_file_hpp
#define SimpleChess_file_hpp

namespace SimpleChess {
	/**
	 * The File class.
	 * This is the class for anything to do with reading and writing to files.
	 */
	namespace File {
		std::string Path = "./"; /**< Path where things are stored. */

		/**
		 * Struct for information from the logfile.
		 * @see File
		 */
		class Info {
		public:
			sf::Uint8 Piece1, /**< Initial piece. */
					  Piece2, /**< Captured piece or 0 for none. */
					  Move; /**< The type of move. 0 for move, 1 for capture. */

			sf::Vector2<sf::Uint8> Piece1Loc, /**< Location of piece before it moves. */
								   Piece2Loc; /**< Location of piece after it moves. */
		};

		typedef std::vector<Info> Information;

		/**
		 * Appends str to "SimpleChess.log".
		 * @param str The string to be appended to the file.
		 */
		void Append(std::string);

		/**
		 * Set's the log path.
		 * @see Path
		 * @param str The new path.
		 */
		void SetPath(std::string);

		/**
		 * Clears the file.
		 */
		void Clear(void);

		/**
		 * Reads the file into a vector of information.
		 * @param filename The name of the file to read from.
		 * @param inf Where the information from the file will be dumped.
		 */
		void Read(std::string, SimpleChess::File::Information&);

		/**
		 * Reads the board config file.
		 * @param filename The name of the file to read from.
		 * @param board Where the board state will be dumped.
		 */
		void CreateBoardFromFile(std::string, SimpleChess::Board8&);
	};
};

////////// SOURCE //////////

void SimpleChess::File::SetPath(std::string str) {
	Path = str;
}

void SimpleChess::File::Clear(void) {
	std::ofstream(Path + "log/SimpleChess.log", std::ios::out).close();
}

void SimpleChess::File::Append(std::string str) {
	std::ofstream fl(Path + "log/SimpleChess.log", std::ios::out | std::ios::app);
	if (not fl.is_open()) {
		FError(false, "ERROR: SimpleChess.log could not be opened!");

		throw 1;
		return;
	}

	fl << str;
	fl.close();
}

void SimpleChess::File::Read(std::string filename, SimpleChess::File::Information& inf) {
	std::ifstream fl(Path + filename, std::ios::in);
	if (not fl.is_open()) {
		FError(false, "ERROR: %s could not be opened!", filename.c_str());

		throw 1;
		return;
	}

	sf::Uint8 p1, p2, m, c11, c12, c21, c22;

	while (fl >> p1 >> c11 >> c12 >> m >> p2 >> c21 >> c22) {
		inf.push_back({ p1, p2, m, { c11, c12 }, { c21, c22 } });
	}
}

void SimpleChess::File::CreateBoardFromFile(std::string filename, SimpleChess::Board8& board) {
	std::ifstream fl(Path + filename, std::ios::in);
	if (not fl.is_open()) {
		FError(false, "ERROR: %s could not be opened!", filename.c_str());

		throw 1;
		return;
	}

	std::array<short, 8> binf;

	for (short c = 0; c < 8; c++) {
		if (not (fl >> binf.at(0) >> binf.at(1) >> binf.at(2) >> binf.at(3) >> binf.at(4) >> binf.at(5) >> binf.at(6) >> binf.at(7))) {
			FError(false, "ERROR: %s not formatted correctly!", filename.c_str());

			throw 2;
			return;
		}

		for (int x = 0; x < 8; x++) {
			board.at(c).at(x) = binf.at(x);
		}
	}
}

#endif
