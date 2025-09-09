#include "../headers/program.h"

#include "../headers/matrix.h"
#include "../headers/menu.h"
#include "../headers/utilits.h"

using namespace std;

void run_program() {
    Matrix my_matrix;
    int choice;

    task_menu();

    while (true) {
        cout << "\nSelect a task MENU option: ";
        choice = valid_int();

        switch (choice) {
            case 1:
                my_matrix.input_matrix();
                break;
            case 2:
                my_matrix.print_matrix();
                break;
            case 3: {
                cout << "Enter the number you want to multiply your matrix by: ";
                int num = valid_int();
                my_matrix.multiply_by_number(num);
                break;
            }
            case 4:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "Error you have selected an incorrect MENU option" << endl;
                break;
        }
    }
}
