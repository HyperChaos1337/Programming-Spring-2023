#include "reader.h"

char Reader::scan_key(){
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