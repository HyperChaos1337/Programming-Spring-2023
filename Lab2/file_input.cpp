#include "file_input.h"

bool FileInput::read_files(char *path1, char *path2){
    if(!correct_extension(path1) || !correct_extension(path2)){
        return false;
    }
    file1.open(path1); file2.open(path2);
    if(!file1.is_open() && !file2.is_open()){
        error_msg_color();
        std::cout << "Both files don't exist or injured. Try again!" << std::endl;
        clean_color();
        return false;
    }
    else if(!file1.is_open() && file2.is_open() || file1.is_open() && !file2.is_open()){
        error_msg_color();
        std::cout << "One of files doesn't exist or injured. Try again!" << std::endl;
        clean_color();
        return false;
    }
    else if(strcmp(path1, path2) == 0){
        warning_msg_color();
        std::cout << "Opening the same file twice! Try again" << std::endl;
        clean_color();
        return false;
    }
    else{
        char sym1, sym2;
        while (file1.get(sym1)){
            str1.push_back(sym1);
        }
        file1.close();
        while (file2.get(sym2)){
            str2.push_back(sym2);
        }
        file2.close();
        return true;
    }
}

bool FileInput::correct_extension(char* path){

    bool match = false;
    if(path[strlen(path)-1] == 't' &&
    path[strlen(path)-2] == 'x' &&
    path[strlen(path)-3] == 't' &&
    path[strlen(path)-4] == '.') match = true;
    if(!match){
        error_msg_color();
        std::cout << "One or both files have unsupportable extension. Try again!" << std::endl;
        clean_color();
    }
    return match;

}

void FileInput::error_msg_color(){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED);
}

void FileInput::warning_msg_color(){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, 6);
}

void FileInput::clean_color(){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, 7);
}