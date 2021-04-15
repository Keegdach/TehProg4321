#include "planes.h"

bool planes::read(std::ifstream& stream) {
    if (!stream.eof())
        stream >> range;
    else return false;
    if (!stream.eof())
        stream >> carry;
    else return false;
    return true;
}

void planes::out(std::ofstream& stream) {
    stream << "Planes; Range: " << range << "; Carry: " << carry << ";" << std::endl;
}

void planes::multi(transport* other, std::ofstream& stream) {
    other->planesMulti(stream);
}

void planes::shipMulti(std::ofstream& stream) {
    stream << "| ship + planes |" << std::endl;
}

void planes::planesMulti(std::ofstream& stream) {
    stream << "| planes + planes |" << std::endl;
}

void planes::trainMulti(std::ofstream& stream) {
    stream << "| train + planes |" << std::endl;
}
void planes::outPlanes(std::ofstream& stream) {
    stream << "Speed: " << transport::speed << "; Estimate time: " << estimateTime() << "; Distance: " << distance << "; Mass: " << mass << "; Type: " << "Planes; Range: " << range << "; Carry: " << carry << ";" << std::endl;
}
void planes::outTrains(std::ofstream& stream) {
    stream << "";
}
void planes::outShips(std::ofstream& stream) {
    stream << "";
}