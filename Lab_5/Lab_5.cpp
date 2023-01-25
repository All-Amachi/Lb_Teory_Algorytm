

#include "Header.h"
void main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    zapoln_file();
    vector<int> mass;
    string ishod_str = "a;sdkmLK:CNvpah;agkvncjznvfpuva'a;dif;vnfugajkavabangawuuuyukavabangacnvajgoadjkcnvldfuihtpa[ijauifgkcnv;ufhfa;kcvlfh;cknvzufhgaijcmvnpgaudhfkncvzuhd";
    int choice_user(0);
    int col_iterachiy(0);
    while (1) {
        cout << "1. Пошук числа в масиві" << endl;
        cout << "2. Пошук підрядка в рядку" << endl;
        cout << "3. Вихід." << endl;

        vvedinie_data(choice_user, 1, 3, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");



        switch (choice_user) {
        case 1: {
            mass.clear();
            int col_nums(0);
            vvedinie_data(col_nums, 1, 10000, "Скільки чисел повинно бути в масиві :", "Повторіть ввод");
            funk_for_prepare_array_before_sort(mass, col_nums);
            cout << "Вихідний масив :";
            print_mass(mass);

            int key(0);
            vvedinie_data(key, 1, N, "Введіть ключові значення пошука :", "Помилка !Допустимі значення від 1 до " + N);
            int index = lin_search_arr(mass, key, col_iterachiy);
            cout << "Линейный поиск" << endl;
            if (index >= 0) {
                cout << "Значення " << key << " знаходиться під індексом " << index << endl;
            }
            else {
                cout << "Такого значения немає в масиві!!!" << endl;
            }
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;
            cout << "Пошук з бар'єром" << endl;
            index = barrier_search_arr(mass, key, col_iterachiy);
            if (index >= 0) {
                cout << "Значення " << key << " знаходиться під індексом " << index << endl;
            }
            else {
                cout << "Такого значения немає в масиві!!!" << endl;
            }
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;
            cout << "Бінарний пошук" << endl;
            Shell(mass);
            index = bar_search::binar_search_arr(mass, 0, mass.size() - 1, key);
            col_iterachiy = bar_search::col_iterachiy;
            if (index >= 0) {
                cout << "Значення " << key << " знаходиться під індексом " << index << endl;
            }
            else {
                cout << "Такого значения немає в масиві!!!" << endl;
            }
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;
            break;
        }
        case 2: {
            string searching_str = "kavabangawuuuyukavabanga";
            cout << "Прямий пошук підрядка" << endl;
            col_iterachiy = pramuy_search(ishod_str, searching_str);
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;

            cout << "Алгоритм Бойера-Мура" << endl;
            col_iterachiy = search_Boyler(ishod_str, searching_str);
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;

            cout << "Алгоритм м Кнута-Морріса-Пратта" << endl;
            col_iterachiy = KMPSearch(searching_str, ishod_str);
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;

            cout << "Алгоритм Рабина – Карпа" << endl;
            col_iterachiy = Robina_Karpa(searching_str, ishod_str, 101);
            cout << "Кількість ітерацій :" << col_iterachiy << endl;
            col_iterachiy = 0;
            break; }
        case 3:exit(0);
        }

    }
}

