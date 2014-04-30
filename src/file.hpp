/*
 *  file.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/26/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
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
		typedef struct {
		public:
            sf::Uint8 Piece1, /**< Initial piece. */
                      Piece2, /**< Captured piece or 0 for none. */
                      Move; /**< The type of move. 0 for move, 1 for capture. */

			sf::Vector2<sf::Uint8> Piece1Loc, /**< Location of piece before it moves. */
							   Piece2Loc; /**< Location of piece after it moves. */
		} Info;

		typedef std::vector<Info> Information;

		/**
		 * Adds starting paths to Paths.
		 */
		void InitializePaths(void);

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
		void Read(std::string, SimpleChess::File::Information *);

		/**
		 * Reads the board config file.
		 * @param filename The name of the file to read from.
		 * @param board Where the board state will be dumped.
		 */
		void CreateBoardFromFile(std::string, std::array<std::array<short, 8>, 8> *);
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
#ifdef __CPP_DEBUG__
		FError(false, "ERROR: SimpleChess.log could not be opened!");
#endif

        throw 1;
        return;
	}

	fl << str;
	fl.close();
}

void SimpleChess::File::Read(std::string filename, SimpleChess::File::Information* inf) {
	std::ifstream fl(Path + filename, std::ios::in);
	if (not fl.is_open()) {
#ifdef __CPP_DEBUG__
        FError(false, "ERROR: %s could not be opened!", filename.c_str());
#endif

        throw 1;
        return;
	}

    sf::Uint8 p1, p2, m, c11, c12, c21, c22;

	while (fl >> p1 >> c11 >> c12 >> m >> p2 >> c21 >> c22) {
		sf::Vector2<sf::Uint8> pp1 = { c11, c12 };
		sf::Vector2<sf::Uint8> pp2 = { c21, c22 };
		Info bf;
		bf.Piece1 = p1;
		bf.Piece2 = p2;
		bf.Move = m;
		bf.Piece1Loc = pp1;
		bf.Piece2Loc = pp2;
		(*inf).push_back(bf);
	}
}

void SimpleChess::File::CreateBoardFromFile(std::string filename, SimpleChess::Board8 *board) {
	std::ifstream fl(Path + filename, std::ios::in);
	if (not fl.is_open()) {
#ifdef __CPP_DEBUG__
		FError(false, "ERROR: %s could not be opened!", filename.c_str());
#endif

        throw 1;
        return;
	}

	short binf[8];

	for (short c = 0; c < 8; c++) {
		if (not (fl >> binf[0] >> binf[1] >> binf[2] >> binf[3] >> binf[4] >> binf[5] >> binf[6] >> binf[7])) {
#ifdef __CPP_DEBUG__
			FError(false, "ERROR: %s not formatted correctly!", filename.c_str());
#endif

            throw 2;
            return;
		}

		for (int x = 0; x < 8; x++) {
			(*board)[c][x] = binf[x];
		}
	}
}

#endif
