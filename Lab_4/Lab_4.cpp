#include "Header.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    zapoln_file();
    int choice_user(0);
    vector<int> mass;

    while (1) {
        cout << "1. Алгоритм підрахунком." << endl;
        cout << "2. Алгоритм пірамідального сортування." << endl;
        cout << "3. Алгоритм сортування Шелла." << endl;
        cout << "4. Exit." << endl;

        vvedinie_data(choice_user, 1, 4, "Оберіть пункт :", "Такого пункта в списку немає.Повторіть ввод");
        if (choice_user != 4) {
            int old_or_new = 0;

            if (!mass.empty()) {
                vvedinie_data(old_or_new, 0, 1, "0 - створитти новий масив. 1 - використати попередній. Оберіть пункт :", "Такого пункта в списку немає.Повторіть ввод");
            }
            if (!old_or_new) {
                mass.clear();
                int col_nums(0), type_sort_before(0);
                vvedinie_data(col_nums, 1, 10000, "Скількі чисел ви бажаєте обробити :", "Повторіть ввод");
                vvedinie_data(type_sort_before, 0, 2, "Тип сортування чисел до сортування, 0 - випадково, 1 - за збільшенням, 2 - в зворотному порядку\nВаш вибір :", "Повторіть ввод");
                funk_for_prepare_array_before_sort(mass, col_nums, type_sort_before);
                cout << "Початковий масив :";
            }
            print_mass(mass);

        }
        switch (choice_user) {
        case 1:
            cout << "Кількість операцій підрахунком :" << sort_count(mass) << endl;
            save_after_sort("conter.txt", mass);
            break;

        case 2:
            cout << "Кількість операцій пірамадільного сортування :" << heapSort(mass) << endl;
            save_after_sort("piramid.txt", mass);
            //cont_iter_heap_sort = 0;
            break;

        case 3:
            cout << "Количество операций Shell :" << Shell(mass) << endl;
            save_after_sort("shell.txt", mass);
            break;

        case 4:exit(0);
        }

    }


}

