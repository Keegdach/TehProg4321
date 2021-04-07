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
void train::out_planes(std::ofstream& stream) {
    stream << "";
}
void train::out_ships(std::ofstream& stream) {
    stream << "";
}
void train::out_trains(std::ofstream& stream) {
    stream << "Speed: " << transport::speed << "; Estimate time: " << estimate_time() << "; Distance: " << distance << "; Mass: " << mass << "; Type: " << "Train; Length: " << length << ";" << std::endl;
}
