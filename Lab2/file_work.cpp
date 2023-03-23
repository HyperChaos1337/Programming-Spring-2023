#include "file_work.h"

std::string FileWork::LCS(std::string S1, std::string S2, int m, int n){

    int LCS_table[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = std::max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }
    for(int k = 0; k < strlen(lcsAlgo); k++) lcs += lcsAlgo[k];
    return lcs;

}

void FileWork::print_match(char temp){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN);
    std::cout << temp;
}

void FileWork::print_mismatch(char temp){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED);
    std::cout << temp;
}

void FileWork::set_std_parameters(){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, 7);
}

void FileWork::highlight(std::string text, std::string pattern){

    int i = 0;
    int j = 0;
    while(i < pattern.length() && j < text.length()){
        if(pattern[i] == text[j]){
            print_match(text[j]);
            i++;
            j++;
        }
        else{
            print_mismatch(text[j]);
            j++;
        }
    }
    while(j < text.length()){
        print_mismatch(text[j]);
        j++;
    }
    set_std_parameters();
}