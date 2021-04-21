#include "pch.h"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\container.h"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\transport.h"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\planes.h"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\ship.h"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\train.h"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\container.cpp"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\transport.cpp"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\planes.cpp"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\ship.cpp"
#include "C:\Users\79832\source\repos\TehProg4321\TehProg4321\train.cpp"

// Функционирование основных модулей программы:
// 1. Ввод одного объекта
// 2. Новые функции
// 3. Сортировка
// 4. Фильтрованный вывод

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test1, T_Input) {
    std::string inp_file = "input.txt";
    std::ifstream ifstr(inp_file);
    transport* checking_tr = transport::readTransport(ifstr);
    bool ok1 = checking_tr->tr_type == 1;
    bool ok2 = checking_tr->distance == 1000;
    bool ok3 = checking_tr->speed == 150;
    bool ok4 = checking_tr->mass == 45.5;
    bool ok5 = ((planes*)checking_tr)->carry == 1225;
    bool ok6 = ((planes*)checking_tr)->range == 400;
    std::cout << checking_tr->tr_type << std::endl;
    std::cout << checking_tr->distance << std::endl;
    std::cout << checking_tr->speed << std::endl;
    std::cout << checking_tr->mass << std::endl;
    std::cout << ((planes*)checking_tr)->carry << std::endl;
    std::cout << ((planes*)checking_tr)->range << std::endl;
    EXPECT_TRUE(ok1 && ok2 && ok3 && ok4 && ok5 && ok6);
    delete checking_tr;
}


TEST(test2, T_Input) {
    std::string inp_file = "input.txt";
    std::ifstream ifstr(inp_file);
    transport* checking_tr = transport::readTransport(ifstr);
    bool ok = checking_tr->estimateTime() == checking_tr->distance / checking_tr->speed;
    delete checking_tr;
    EXPECT_TRUE(ok);
}

TEST(test3, T_Input) {
    std::string inp_file = "input.txt";
    std::ifstream ifstr(inp_file);
    container c{};
    c.readContainer(ifstr);
    element* el = c.starting;
    c.sort();
    for (int i = 0; i < c.size - 1; i++) {
        EXPECT_TRUE(el->t->estimateTime() >= el->forward->t->estimateTime());
        el = el->forward;
    }
}

TEST(test4, T_Input) {
    std::string inp_file = "input.txt";
    std::string out_file = "output.txt";
    std::ifstream ifstr(inp_file);
    std::ofstream ofstr(out_file);
    container c{};
    c.readContainer(ifstr);
    element* el = c.starting;
    int count1 = c.outContainer(ofstr, t_type::TRAIN);
    int count_actual = 0;
    for (int i = 0; i < c.size; i++) {
        if (el->t->tr_type != t_type::TRAIN) {
            count_actual++;
        }
        el = el->forward;
    }
    EXPECT_EQ(count1, count_actual);
}