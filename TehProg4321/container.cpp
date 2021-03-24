#include "container.h"

void container::read_container(std::ifstream& stream) {
    while (!stream.eof()) {
        transport* temp_tr = transport::read_transport(stream);
        if (temp_tr == nullptr) return; // ���� �� ���������, �� ������
        element* el = new element{};
        el->t = temp_tr;
        containerAdd(el);
    }
}

void container::containerAdd(element* el) {
    size++;
    if (starting == nullptr) {
        starting = ending = el;
    }
    else {
        ending->forward = el;
        ending = el;
        el->forward = starting;
    }
}

container::container() {
    size = 0;
    starting = ending = nullptr;
}

void container::containerClear() {
    element* el = starting;
    for (int i = 0; i < size; i++) {
        delete el->t;
        element* next = el->forward;
        delete el;
        el = next;
    }
}

void container::out_container(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++) {
        stream << i + 1 << ". ";
        el->t->out_transport(stream);
        el = el->forward;
    }
}
