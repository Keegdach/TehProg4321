#include "ship.h"

bool ship::read(std::ifstream& stream) {
    if (!stream.eof())
        stream >> displacement;
    else return false;
    if (!stream.eof()) {
        int typ;
        stream >> typ;
        ship_type = (Ship_Type)typ;
    }
    else return false;
    return true;
}

void ship::out(std::ofstream& stream) {
    stream << "Ships; Displacement: " << displacement << "; Ship type: " << ship::type_to_str(ship_type) << ";" << std::endl;
}
void ship::out_trains(std::ofstream& stream) {
    stream << "";
}
void ship::out_planes(std::ofstream& stream) {
    stream << "";
}
void ship::out_ships(std::ofstream& stream) {
    stream << "Speed: " << transport::speed << "; Estimate time: " << estimate_time() << "; Distance: " << distance << "; Mass: " << mass << "; Type: " << "Ships; Displacement: " << displacement << "; Ship type: " << type_to_str(ship_type) << ";" << std::endl;
}
std::string ship::type_to_str(Ship_Type t) {
    switch (t) {
    case 1:
        return "Liner";
    case 2:
        return "Tug";
    case 3:
        return "Tanker";
    default:
        return "Unknown type";
    }
}