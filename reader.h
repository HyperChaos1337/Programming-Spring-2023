#ifndef PR_LAB1_READER_H
#define PR_LAB1_READER_H

#include <conio.h>

class Reader{
public:
    char scan_key(){
        switch (_getch()){
            case 13:
                return 'E';
                break;
            case 72:
                return 'U';
                break;
            case 80:
                return 'D';
                break;
        }
        return 0;
    }
};

#endif