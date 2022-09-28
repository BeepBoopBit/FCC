#ifndef FLASHCARD_H
#define FLASHCARD_H

#include "../includes.h"

class Flashcard{
public: // Constructors
    Flashcard(){

    }
    Flashcard(std::string front, std::string back){
        _fData = front;
        _bData = back;
    }

private:
    std::string _fData, _bData; // Front and Back
    bool _isFrontView = true;
};

#endif // FLASHCARD_H