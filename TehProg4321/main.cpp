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
    ofst << "Ignoring type 1:" << std::endl;
    c.out_container(ofst, T_type::PLANES);
    ofst << "Ignoring type 2:" << std::endl;
    c.out_container(ofst, T_type::TRAIN);
    c.containerClear();
    cout << "END" << endl;
    return 0;
}