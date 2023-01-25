#include "Header.h"

void main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


    int choise(0);

    while (1) {
        cout << "1. Відкрита адресація" << endl;
        cout << "2. Метод ланцюжків" << endl;
        cout << "3. 3 методи вирішення колізії" << endl;
        cout << "4. Вихід" << endl;
        vvedinie_data(choise, 1, 4, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");

        switch (choise)
        {
        case 1: {
           funk_1(20, 1, 1);
            break;
        }
        case 2: {
          funk_2();
            break;
        }
        case 3: {
            funk_3();
            break;
        }
        case 4: return;
        }
    }




}

