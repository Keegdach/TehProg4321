// Вариант 4 - 3 - 2 - 1
// Контейнер на основе однонаправленного кольцевого списка.
// Разбиение на модули осуществляется по объектному принципу.
// Обобщение, построенное на основе непосредственного включения специализаций.
// ООП
#include "container.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "incorrect command line! " << endl
            << "Waited: command in_file out_file"
            << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    if (!ifst.is_open()) {
        std::cout << "I/O File is missing.\n";
        return 1;
    }
    cout << "START" << endl;
    container c{};
    c.readContainer(ifst);
    c.outContainer(ofst);
    c.multi(ofst);
    ofst << "Sorted container" << std::endl;
    c.sort();
    c.outContainer(ofst);
    ofst << "Out planes:" << std::endl;
    c.outContainerPlanes(ofst);
    ofst << "Out trains:" << std::endl;
    c.outContainerTrains(ofst);
    ofst << "Out ships:" << std::endl;
    c.outContainerShips(ofst);
    c.containerClear();
    cout << "END" << endl;
    return 0;
}