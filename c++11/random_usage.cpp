#include <iostream>
#include <random>

int main() {
    {
        std::random_device rd;
        for (int i = 0; i < 10; i++) {
            std::cout << rd() << std::endl;
        }
    }

    {
        std::random_device rd;
        std::mt19937_64 mt(rd());
        for (int i = 0; i < 10; i++) {
            std::cout << mt() << std::endl;
        }

        std::uniform_int_distribution<unsigned> dis(1, 100);
        for (int i = 0; i < 10; i++) {
            std::cout << dis(mt) << std::endl;
        }

        std::uniform_real_distribution<double> drs(0.0, 1.0);
        for (int i = 0; i < 10; i++) {
            std::cout << drs(mt) << std::endl;
        }
    }
}
