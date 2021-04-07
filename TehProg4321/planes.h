#ifndef PR1_1_PLANES_H
#define PR1_1_PLANES_H

#include <iostream>
#include <fstream>
#include "transport.h"

class planes : public transport {
public:
    int range;
    int carry;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
    void out_planes(std::ofstream& stream);
    void out_trains(std::ofstream& stream);
private:
};


#endif //PR1_1_PLANES_H