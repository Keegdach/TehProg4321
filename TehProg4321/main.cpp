// ������� 4 - 3 - 2 - 1
// ��������� �� ������ ����������������� ���������� ������.
// ��������� �� ������ �������������� �� ���������� ��������.
// ���������, ����������� �� ������ ����������������� ��������� �������������.
// OOP
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
    cout << "START" << endl;
    container c{};
    c.read_container(ifst);
    c.out_container(ofst);
    ofst << "Sorted container" << std::endl;
    c.sort();
    c.out_container(ofst);
    ofst << "Out planes:" << std::endl;
    c.out_container_planes(ofst);
    ofst << "Out trains:" << std::endl;
    c.out_container_trains(ofst);
    ofst << "Out ships:" << std::endl;
    c.out_container_ships(ofst);
    c.containerClear();
    cout << "END" << endl;
    return 0;
}