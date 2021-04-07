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
void planes::out_planes(std::ofstream& stream) {
    stream << "Speed: " << transport::speed << "; Estimate time: " << estimate_time() << "; Distance: " << distance << "; Mass: " << mass << "; Type: " << "Planes; Range: " << range << "; Carry: " << carry << ";" << std::endl;
}
void planes::out_trains(std::ofstream& stream) {
    stream << "";
}
void planes::out_ships(std::ofstream& stream) {
    stream << "";
}