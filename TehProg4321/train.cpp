#include "train.h"

bool train::read(std::ifstream& stream) {
    if (!stream.eof())
        stream >> length;
    else return false;
    return true;
}

void train::out(std::ofstream& stream) {
    stream << "Train; Length: " << length << ";" << std::endl;
}
void train::outPlanes(std::ofstream& stream) {
    stream << "";
}
void train::outShips(std::ofstream& stream) {
    stream << "";
}
void train::outTrains(std::ofstream& stream) {
    stream << "Speed: " << transport::speed << "; Estimate time: " << estimateTime() << "; Distance: " << distance << "; Mass: " << mass << "; Type: " << "Train; Length: " << length << ";" << std::endl;
}
void train::multi(transport* other, std::ofstream& stream) {
    other->trainMulti(stream);
}

void train::shipMulti(std::ofstream& stream) {
    stream << "| ship + train |" << std::endl;
}

void train::planesMulti(std::ofstream& stream) {
    stream << "| planes + train |" << std::endl;
}

void train::trainMulti(std::ofstream& stream) {
    stream << "| train + train |" << std::endl;
}
