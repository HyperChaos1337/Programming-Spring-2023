#include "university.h"
#include "Interface.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    University university("Saint Petersburg Electrotechnical University LETI");
    Interface consoleInterface;
    consoleInterface.university_interface(university);
    return 0;
}
