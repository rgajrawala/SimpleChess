//
//  file.hpp
//  SimpleChess
//
//  Created by Ronak Gajrawala on 12/26/13.
//  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
//

#ifndef SimpleChess_file_hpp
#define SimpleChess_file_hpp

class File {
private:
    std::string Path = "./"; /**< The path to keep the logfile. */
public:
    /**
     * Struct for information from the logfile.
     * @see File
     */
    typedef struct {
    public:
        short Piece1, /**< Initial piece. */
              Piece2, /**< Captured piece or 0 for none. */
              Move; /**< The type of move. 0 for move, 1 for capture. */
        
        sf::Vector2<short> Piece1Loc, /**< Location of piece before it moves. */
                           Piece2Loc; /**< Location of piece after it moves. */
    } Info;
    
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
     * @param inf Where the information from the file will be dumped.
     */
    void Read(File::Information *);
    
    /**
     * Reads the board config file.
     * @param filename The name of the file.
     * @param board Where the board state will be dumped.
     */
    void CreateBoardFromFile(std::string, std::array<std::array<short, 8>, 8> *);
} File;

////////// SOURCE //////////

void File::SetPath(std::string str) {
    this->Path = str;
}

void File::Clear(void) {
    fopen((this->Path + "SimpleChess.log").c_str(), "w");
}

void File::Append(std::string str) {
    FILE* File = fopen((this->Path + "SimpleChess.log").c_str(), "a");
    if(File == NULL) {
        Console.Log(__LINE__, __FILE__, __func__, "WARNING: SimpleChess.log could not be opened and will not be written to.");
        return;
    }
    fprintf(File, "%s", str.c_str());
    fclose(File);
}

void File::Read(File::Information* inf) {
    std::ifstream fl(this->Path + "SimpleChess.log");
    if(not fl.is_open()) {
        Console.Log(__LINE__, __FILE__, __func__, "ERROR: SimpleChess.log could not be opened!");
        throw 1;
        return;
    }
    
    short p1, p2, m, c11, c12, c21, c22;
    
    while(fl >> p1 >> c11 >> c12 >> m >> p2 >> c21 >> c22) {
        sf::Vector2<short> pp1 = {c11, c12};
        sf::Vector2<short> pp2 = {c21, c22};
        File::Info bf;
        bf.Piece1 = p1;
        bf.Piece2 = p2;
        bf.Move = m;
        bf.Piece1Loc = pp1;
        bf.Piece2Loc = pp2;
        (*inf).push_back(bf);
    }
}

void File::CreateBoardFromFile(std::string filename, std::array<std::array<short, 8>, 8> *board) {
    std::ifstream fl(this->Path + filename);
    if(!fl.is_open()) {
        Console.Log(__LINE__, __FILE__, __func__, "ERROR: %s could not be opened!", filename.c_str());
        throw 1;
        return;
    }
    
    short binf[8];
    
    for(short c = 0; c < 8; c++) {
        if(not (fl >> binf[1] >> binf[2] >> binf[3] >> binf[4] >> binf[5] >> binf[6] >> binf[7])) {
            Console.Log(__LINE__, __FILE__, __func__, "ERROR: %s not formatted correctly!", filename.c_str());
            throw 2;
            return;
        }
        
        for(int x = 0; x < 8; x++) {
            (*board)[c][x] = binf[x];
        }
    }
}

#endif
