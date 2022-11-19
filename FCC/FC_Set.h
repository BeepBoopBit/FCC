#ifndef FC_SET_H
#define FC_SET_H

#include"Flashcard.h"

class FC_Set{
public: // Constructors
    FC_Set(){
        
    }

    FC_Set(std::string name){
        _name = name;
    }

public:
    void showCardF(){
        std::cout << _flashcards[_currentCard++]->getFront() << '\n';
    }
    void showCardB(){
        std::cout << _flashcards[_currentCard++]->getBack() << '\n';
    }
    bool compareAnswerB(std::string answer){
        // Assume that showCardF() was called before this function
        return answer == _flashcards[_currentCard-1]->getBack();
    }
    bool compareAnswerF(std::string answer){
        // Assume that showCardB() was called before this function
        return answer == _flashcards[_currentCard-1]->getFront();
    }
    void createCard(std::string front, std::string back){
        _flashcards.push_back(new Flashcard(front, back));
    }
    void resetCard(){
        _currentCard = 0;
    }
public: // Getters
    std::string getSetName(){
        return _name;
    }
    int getCurrentCardIndex(){
        return _currentCard;
    }

    bool checkIfDone(){
        return _currentCard == _flashcards.size();
    }

public: // setters
    void removeFlashcard(int index){
        // deallocate the memory
        delete _flashcards[index];

        // delete it in the vector (expensive)
        _flashcards.erase(_flashcards.begin() + index, _flashcards.begin()+index+1);
    }
    void setCurrentCard(int index){
        _currentCard = index;
    }

private:
    std::vector<Flashcard*> _flashcards;
    std::string _name;
    int _currentCard = 0;
};


#endif // FC_SET_H