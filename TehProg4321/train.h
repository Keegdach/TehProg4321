#ifndef PR1_1_TRAIN_H
#define PR1_1_TRAIN_H

#include "transport.h"

class train : public transport {
public:
    int length;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
    void outPlanes(std::ofstream& stream);
    void outTrains(std::ofstream& stream);
    void outShips(std::ofstream& stream);
    void multi(transport* other, std::ofstream& stream) override;
    void shipMulti(std::ofstream& stream) override;
    void planesMulti(std::ofstream& stream) override;
    void trainMulti(std::ofstream& stream) override;
private:
};



#endif //PR1_1_TRAIN_H
