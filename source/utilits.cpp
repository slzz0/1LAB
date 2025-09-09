#include "../headers/utilits.h"

#include <iostream>

int valid_int() {
    int number;

    while (true) {
        if (std::cin >> number) {
            if (std::cin.get() == '\n') {
                return number;
            } else {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "Please enter only numbers without characters, try again: ";
            }
        } else {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please enter a valid number: ";
        }
    }
}