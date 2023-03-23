#include <iostream>

#include "file_input.h"
#include "file_work.h"
#include "failure.h"

int main(int argc, char** argv){

    FileInput fileInput;
    FileWork fileWork;
    Failure failure;
    failure.error(argc);
    if(fileInput.read_files(argv[1], argv[2])){
        std::cout << "----------File1----------" << std::endl;
        fileWork.lcs = fileWork.LCS(fileInput.str1, fileInput.str2,
                                    fileInput.str1.length(), fileInput.str2.length());
        fileWork.highlight(fileInput.str1, fileWork.lcs);
        std::cout << std::endl;
        fileWork.set_std_parameters();
        std::cout << "----------File2----------" << std::endl;
        fileWork.highlight(fileInput.str2, fileWork.lcs);
        std::cout << std::endl;
    }
    return 0;
}
