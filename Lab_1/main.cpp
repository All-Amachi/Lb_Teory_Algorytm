#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	vector <List> Lists;
	vector <List>::iterator it;
	ofstream f_cout;
	ifstream f_cin;
	int choice, numb_1, numb_2;
	char simb;
	bool flag;

	while (1) {
		cout << " 1) Подивитися списки\n";
		cout << " 2) Додати список\n";
		cout << " 3) Видалити список\n";
		cout << " 4) Об'єднати два списки в один\n";
		cout << " 5) Видалити всі елементи в списку\n";
		cout << " 6) Підрахувати кількість вузлів у списку\n";
		cout << " 7) Додати вузол в кінець списку\n";
		cout << " 8) Видалити вузол у списку\n";
		cout << " 9) Змінити два сусідні елементи місцями\n";
		cout << " 10) Записати списки в файл\n";
		cout << " 11) Зчитати з файлу списки\n";
		cout << " 0) Вихід\n\n";
		cout << " >>> ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			if (Lists.size() == 0) {
				cout << "Списків ще не створенно!\n\n";
				break;
			}
			for (short i = 0; i < Lists.size(); i++)
				Lists[i].Print_list();
			cout << endl;
			break;
		case 2:
			while (1) {
				cout << " 1) Двозв'язний список\n"
					<< " 2) Кільцевий список\n"
					<< " 0) Назад\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) {
					cout << endl;
					break;
				}
				cout << "\nКількість елементів\n\n >>> ";
				cin >> numb_1;

				cout << "\n 1) Заповнити з екрану\n"
					<< " 2) Заповнити випадково\n"
					<< " 0) Назад\n\n"
					<< " >>> ";
				cin >> numb_2;
				if (numb_2 == 1) flag = true;
				else if (numb_2 == 2) flag = false;
				else break;

				switch (choice) {
				case 1:
					Lists.push_back(List(true));
					Lists[Lists.size() - 1].Create_list(numb_1, flag);
					break;
				case 2:
					Lists.push_back(List(false));
					Lists[Lists.size() - 1].Create_list(numb_1, flag);
					break;
				default:
					cout << "\nСпробуйте ще раз!\n\n";
					continue;
				}
				cout << endl;
				break;
			}
			break;
		case 3:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nОберіть список \"0 - Назад\"\n\n >>> ";
			cin >> choice;
			if (choice == 0) {
				cout << endl;
				break;
			}

			it = Lists.begin() + choice - 1;
			Lists.erase(it);
			break;
		case 4:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nВведіть два номери списків через пробіл\n\"Якщо хоча б один з номерів = 0 - Назад\"\n\n >>> ";
			cin >> numb_1 >> numb_2;
			if (numb_1 == 0 || numb_2 == 0) {
				cout << endl;
				break;
			}

			if (Lists[numb_1 - 1].Ret_type() == false || Lists[numb_2 - 1].Ret_type() == false) {
				cout << "\nДля кільцевого/х списків це не виконується!\n\n";
				break;
			}

			Lists.push_back(List(true));
			Lists[Lists.size() - 1].Combi_lists(Lists[numb_1 - 1].Ret_ptr_head_node(), Lists[numb_2 - 1].Ret_ptr_head_node());
			break;
		case 5:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nВведіть номер списку \"0 - Назад в меню\"\n\n >>> ";
			cin >> choice;
			if (choice == 0) {
				cout << endl;
				break;
			}

			flag = Lists[choice - 1].Clear_list();
			if (flag == false)
				cout << "\nСписок пустий!\n\n";
			break;
		case 6:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nВведіть номер списку \"0 - Назад в меню\"\n\n >>> ";
			cin >> choice;
			if (choice == 0) {
				cout << endl;
				break;
			}

			cout << "\nСписок має довжину = " << Lists[choice - 1].Count_nodes() << "\n\n";
			break;
		case 7:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nВведіть номер списку \"0 - Назад в меню\"\n\n >>> ";
			cin >> choice;
			if (choice == 0) {
				cout << endl;
				break;
			}

			cout << "\nВведіть символ\n\n >>> ";
			cin >> simb;
			Lists[choice - 1].Add_node(simb);
			break;
		case 8:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nВведіть номер списку \"0 - Назад в меню\"\n\n >>> ";
			cin >> choice;
			if (choice == 0) {
				cout << endl;
				break;
			}

			cout << "\nВведіть номер елементу \"0 - Назад в меню\"\n\n >>> ";
			cin >> numb_1;
			if (numb_1 == 0) {
				cout << endl;
				break;
			}

			flag = Lists[choice - 1].Del_node(numb_1);
			if (flag == false)
				cout << "\nНевірно вибран елемент!\n\n";
			break;
		case 9:
			for (short i = 0; i < Lists.size(); i++) {
				cout << i + 1 << ") ";
				Lists[i].Print_list();
			}

			cout << "\nВведіть номер списку \"0 - Hазад\"\n\n >>> ";
			cin >> choice;
			if (choice == 0) {
				cout << endl;
				break;
			}

			cout << "\nВведіть номери двох сусідніх елементів через пробіл\n\n >>> ";
			cin >> numb_1 >> numb_2;

			if (numb_1 > numb_2)
				flag = Lists[choice - 1].Swap_nodes(numb_2, numb_1);
			else
				flag = Lists[choice - 1].Swap_nodes(numb_1, numb_2);

			if (flag == false)
				cout << "\nЕлементи не є сусідніми!\n\n";
			break;
		case 10:
			f_cout.open("File_with_lists.txt");
			numb_1 = Lists.size();
			for (short i = 0; i < numb_1 - 1; i++)
				Lists[i].Write_list_to_file(f_cout, false);
			Lists[numb_1 - 1].Write_list_to_file(f_cout, true);
			f_cout.close();
			break;
		case 11:
			f_cin.open("File_with_lists.txt", ios::in);
			if ((simb = f_cin.get()) == EOF)
				cout << "\nФайл пустий!\n\n";
			else {
				while (1) {
					if (simb == 'D')
						Lists.push_back(List(true));
					else
						Lists.push_back(List(false));
					simb = Lists[Lists.size() - 1].Read_list_from_file(f_cin);
					if (simb == EOF)
						break;
					else
						simb = f_cin.get();
				}
			}
			f_cin.close();
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "\nСпробуйте ще раз!\n\n";
			continue;
		}
	}
	return 0;
}