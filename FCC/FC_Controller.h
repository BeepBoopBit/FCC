#ifndef FC_CONTROLLER_H
#define FC_CONTROLLER_H

#include "FC_Folder.h"
#include "FIleReader.h"

class FC_Controller{
public:
    FC_Controller(){
        FileReader *_fr = new FileReader();
        std::vector<std::string> folderName;
        std::vector<std::vector<std::string>> setName;
        std::vector<std::vector<std::string>> setData;
        _fr->saveFileContent(folderName, setName, setData);
        initFolders(folderName, setName, setData);
    }

private:
    void initFolders(std::vector<std::string> &folders,std::vector<std::vector<std::string>> setName,std::vector<std::vector<std::string>> setData){
        for(int i = 0; i < folders.size(); ++i){
            // Initialize folder
            FC_Folder *newFolder = new FC_Folder(folders[i]);

            // Initialize the sets of the folder
            std::vector<std::string> currentSet = setName[i];
            for(int j = 0; j < setName.size(); ++j){
                newFolder->createSet(currentSet[j]);
            
                // Initialize the data of the set
                std::vector<std::string> currentSetData = setData[i];
                for(int k = 0; k < currentSetData.size()-1; k+=2){
                    newFolder->getLatestSet()->createCard(currentSetData[k], currentSetData[k+1]);
                }
            }


            _folders.push_back(newFolder);
        }
    }

public: // Initial Functions
    void start(){
        bool inGame = true;
        while(inGame){
            system("cls");
            // Display the menu
            std::cout << "BeepBoop Cards\n"
                    << "[1] Use a Folder\n"
                    << "[2] Create Folder\n"
                    << "[3] Exit\n"
                    << "> ";

            // Get the Input
            std::string userInput;
            std::getline(std::cin, userInput);

            if(userInput == "1"){
                useFolder();
            }else if(userInput == "2"){
                createFolder();
            }else if(userInput == "3"){
                inGame = false;
                break;
            }

            // I mean, I don't need to think about security... So I'll use it
            system("cls");
        }
        
    }

private:
    void setStart(){
        bool inGame = true;
        while(inGame){
            while(true){
                system("cls");
                std::cout << "Current Set: [" << _currentFolder->getFolderName() << "]\n"
                    << "[1] Use a Set\n"
                    << "[2] Create Set\n"
                    << "[3] Exit folder\n";
                std::cout << "> ";
                std::string userInput;
                std::getline(std::cin, userInput);
                if(userInput == "1"){
                    useSet();
                }else if(userInput == "2"){
                    createSet();
                }else if(userInput == "3"){
                    inGame = false;
                    break;
                }
            }
        }
    }

    void cardStart(){
        bool inGame = true;
        while(inGame){
            while(true){
                system("cls");
                std::cout << "[" << _currentFolder->getFolderName() << "] "
                    << "[" << _currentFolder->getCurrentSet()->getSetName() << "]\n"
                    << "[1] Start Reviewing\n"
                    << "[2] Create Card\n"
                    << "[3] Exit Set\n";
                std::cout << "> ";
                std::string userInput;
                std::getline(std::cin, userInput);
                if(userInput == "1"){
                    startReviewingCard();
                }else if(userInput == "2"){
                    createCard();
                }else if(userInput == "3"){
                    inGame = false;
                    break;
                }
            }
        }

    }

private: // Menu Choices
    void useFolder(){
        int size = _folders.size();
        std::cout << std::string(20,'=') << '\n';
        // Prints all the folder name
        for(int i = 0; i < size; ++i){
            std::cout << '[' << i << ']' << ' ' << _folders[i]->getFolderName() << '\n';
        }
        std::cout << std::string(20,'=') << '\n';

        // Ask the user about the folder to be use
        bool inGame = true;
        while(inGame){
            std::cout << "> ";
            std::string userInput;
            std::getline(std::cin, userInput);
            // Set the _currentFolder to the folder that the user choose if it's valid
            if(convertToIndex(userInput) < _folders.size()){
                _currentFolder = _folders[convertToIndex(userInput)];
                inGame = false;
            }
        }
        setStart();
    }
    void createFolder(){
        bool isNotSatisfied = true;

        std::string userInput;
        while(isNotSatisfied){
            std::cout << "Enter the folder name: ";
            std::getline(std::cin, userInput);

            std::cout << "Are you satisfied with \"" << userInput << "\"?\n [YES or No] > ";

            std::string userChoice;
            std::getline(std::cin, userChoice);
            if(transformToLower(userChoice) == "yes"){
                break;   
            }
        }
        _folders.push_back(new FC_Folder(userInput));
    }

    void useSet(){
        _currentFolder->showSets();
        while(true){
            std::cout << "> ";
            std::string userInput;
            std::getline(std::cin, userInput);
            int indexOfSet = convertToIndex(userInput);
            if(indexOfSet < _currentFolder->getSetSize()){
                _currentFolder->useSet(indexOfSet);
                break;
            }else{
                std::cout << "[!] Invalid Input\n";
            }
        }
        cardStart();
    }
    void createSet(){
        std::string userInput;
        while(true){
            std::cout << "Enter the set name: ";
            std::getline(std::cin, userInput);

            std::cout << "Are you satisfied with \"" << userInput << "\"?\n [YES or No] > ";

            std::string userChoice;
            std::getline(std::cin, userChoice);
            if(transformToLower(userChoice) == "yes"){
                break;   
            }
        }
        _currentFolder->createSet(userInput);
    }

    void startReviewingCard(){
        while(true){
            system("cls");
            if(_currentFolder->getCurrentSet()->checkIfDone()){
                std::cout << "You have done reviewing all the cards in this set!\n";
                _currentFolder->getCurrentSet()->resetCard();
                system("pause");
                break;
            }
            std::cout << "["<< _currentFolder->getCurrentSet()->getCurrentCardIndex() << "] Should I ask the Front or the Back first?\n"
                << "[1] Front\n"
                << "[2] Back\n"
                << "[3] Exit\n";
            std::cout << "> ";
            std::string userInput;
            std::getline(std::cin, userInput);
            if(userInput == "3"){
                break;
            }
            testAnswer(userInput);
        }
    }
    void createCard(){
        std::string front, back;
        while(true){
            while(true){
                std::cout << "Enter front value: ";
                std::getline(std::cin, front);
                std::cout << "Are you satisfied with \"" << front << "\"?\n [YES or No] > ";
                std::string userChoice;
                std::getline(std::cin, userChoice);
                if(transformToLower(userChoice) == "yes"){
                    break;   
                }
            }
            while(true){
                std::cout << "Enter back value: ";
                std::getline(std::cin, back);
                std::cout << "Are you satisfied with \"" << back << "\"?\n [YES or No] > ";
                std::string userChoice;
                std::getline(std::cin, userChoice);
                if(transformToLower(userChoice) == "yes"){
                    break;   
                }
            }
    
            std::cout << "Are you satisfied with \"" << front << " and " << back << "\"?\n [YES or No] > ";
            std::string userChoice;
            std::getline(std::cin, userChoice);
            if(transformToLower(userChoice) == "yes"){
                break;   
            }
        }
        _currentFolder->getCurrentSet()->createCard(front, back);
    }

public: // auxillary
    void testAnswer(std::string userInput){
        if(userInput == "1"){
            _currentFolder->getCurrentSet()->showCardF();
            std::cout << "> ";
            std::string userAnswer;
            std::getline(std::cin, userAnswer);
            if(_currentFolder->getCurrentSet()->compareAnswerB(userAnswer)){
                std::cout << "Correct!\n";
            }else{
                std::cout << "Wrong!\n";
            }
        }else if(userInput == "2"){
            _currentFolder->getCurrentSet()->showCardB();
            std::cout << "> ";
            std::string userAnswer;
            std::getline(std::cin, userAnswer);
            if(_currentFolder->getCurrentSet()->compareAnswerF(userAnswer)){
                std::cout << "Correct!\n";
            }else{
                std::cout << "Wrong!\n";
            }
        }else{
            std::cout << "[!] Invalid Input\n";
        }
        system("pause");
    }

public: // Factories
    void createFlashcard(std::string front, std::string back){
        _flashcardBuffer.push_back(new Flashcard(front, back));
    }

private: // Utility
    std::string transformToLower(std::string str){
        int size = str.length();
        for(int i = 0; i < size; ++i){
            str[i] = tolower(str[i]);
        }
        return str;
    }
    int convertToIndex(std::string str){
        return std::stoi(str);
    }

private:
    std::vector<Flashcard*> _flashcardBuffer;
    std::vector<FC_Folder*> _folders;
    FC_Folder* _currentFolder;
};


#endif // FC_CONTROLLER_H