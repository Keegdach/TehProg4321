#include "container.h"

void container::readContainer(std::ifstream& stream) {
    while (!stream.eof()) {
        transport* temp_tr = transport::readTransport(stream);
        if (temp_tr == nullptr) return; // Если не считалось, то ошибка
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

void container::outContainer(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++) {
        stream << i + 1 << ". ";
        el->t->outTransport(stream);
        el = el->forward;
    }
}

void container::sort() {
    element* el1 = starting;
    element* el2 = starting;
    for (int i = 0; i < size - 1; i++) {
        el2 = el1->forward;
        for (int j = 0; j < size - 1 - i; j++) {
            if (transport::comparator(el1->t, el2->t)) {
                transport* el_temp = el1->t;
                el1->t = el2->t;
                el2->t = el_temp;
            }
            el2 = el2->forward;
        }
        el1 = el1->forward;
    }
}

void container::outContainerPlanes(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++)
    {
        el->t->outPlanes(stream);
        el = el->forward;
    }
}

void container::outContainerTrains(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++)
    {        
        el->t->outTrains(stream);
        el = el->forward;
    }
}

void container::outContainerShips(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++)
    {
        el->t->outShips(stream);
        el = el->forward;
    }
}

void container::multi(std::ofstream& ofst) {
    ofst << "MULTIMETHOD" << std::endl;
    element* el1 = starting;
    int count1 = 0;
    for (int i = 0; i < size; i++) {
        element* el2 = starting;
        for (int j = 0; j < size; j++) {
            if (i == j) {
                el2 = el2->forward;
                continue;
            }
            el1->t->multi(el2->t, ofst);
            el2->t->outTransport(ofst);
            el1->t->outTransport(ofst);
            el2 = el2->forward;
        }
        el1 = el1->forward;
    }
}

