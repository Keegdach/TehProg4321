#include "container.h"

void container::read_container(std::ifstream& stream) {
    while (!stream.eof()) {
        transport* temp_tr = transport::read_transport(stream);
        if (temp_tr == nullptr) return; // ???? ?? ?????????, ?? ??????
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

void container::out_container_planes(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++)
    {
        el->t->out_planes(stream);
        el = el->forward;
    }
}

void container::out_container_trains(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++)
    {        
        el->t->out_trains(stream);
        el = el->forward;
    }
}

void container::out_container_ships(std::ofstream& stream) {
    element* el = starting;
    for (int i = 0; i < size; i++)
    {
        el->t->out_ships(stream);
        el = el->forward;
    }
}

