// ������� 4 - 3 - 2 - 1
// ��������� �� ������ ����������������� ���������� ������.
// ��������� �� ������ �������������� �� ���������� ��������.
// ���������, ����������� �� ������ ����������������� ��������� �������������.
// ���
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
    c.containerClear();
    cout << "END" << endl;
    return 0;
}