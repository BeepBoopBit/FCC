#ifndef FCC_H
#define FCC_H

#include "FC_Controller.h"

class MyFCC{

public:
    MyFCC(){

    }

public:
    void InitMenu(){
        std::cout << "BeepBoop Cards\n";
        std::cout << "[1] Create Folders\n";
        std::cout << "[2] Use Folders\n";
        std::cout << "[3] Show Folders\n";
    }

private:
    void createFolder(){

    }

private:
    void createFlashcard(std::string fData, std::string bData){
        _flashcards.push_back(new Flashcard(fData,bData));
    }
    void checkAnswer(Flashcard fc, std::string data){
    }

private:
    std::vector<Flashcard*> _flashcards;
    bool isFront = true;
    FC_Controller *_fController = _fController->get_instance();

};

#endif // FCC_H