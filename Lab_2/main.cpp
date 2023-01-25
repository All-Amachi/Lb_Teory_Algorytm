#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Stack* stack = new Stack;
	Queue* queue = new Queue;
	Deque* deque = new Deque;
	ofstream f_out;
	ifstream f_in;
	double temp;
	int choice, numb;

	while (true) {
		cout << "\n 1) Стек\n"
			<< " 2) Черга\n"
			<< " 3) Дека\n"
			<< " 0) Вихід\n\n"
			<< " >>> ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (true) {
				cout << endl;
				stack->Print_stack();
				cout << "\n\n 1) Створити декілько елементів\n"
					<< " 2) Додати елемент на вершину\n"
					<< " 3) Видалити елемент з вершини\n"
					<< " 4) Видалити всі елементи стеку\n"
					<< " 5) Змінити місцями перший і останній елементи стеку місцями\n"
					<< " 6) Перегорнути стек\n"
					<< " 7) Видалити кожен другий елемент стеку\n"
					<< " 8) Вставити зірку в середину\n"
					<< " 9) Знайти максимальний і вставити після нього нуль\n"
					<< " 10) Видалити мінімальний елемент\n"
					<< " 11) Видалити всі елементи крім першого\n"
					<< " 12) Видалити всі елементи крім останього\n"
					<< " 13) Зчитати з файлу\n"
					<< " 14) Записати у файл\n"
					<< " 0) Повернутися\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) break;

				switch (choice) {
				case 1:
					cout << "\nКількість елементів: ";
					cin >> choice;
					cout << "\n 1) Заповнити власноруч\n"
						<< " 2) Заповнити випадково\n"
						<< " 0) Повернутися\n\n"
						<< " >>> ";
					cin >> numb;
					if (numb == 1) {
						cout << "\nВведіть числа через пробіл: ";
						stack->Create_stack(choice, true);
						cout << endl;
					}
					else if (numb == 2) stack->Create_stack(choice, false);
					else if (numb == 0) break;
					else cout << "\nСпробуйте ще раз!!!\n\n";
					break;
				case 2:
					cout << "\nВведіть число: ";
					cin >> temp;
					stack->Push_top(temp);
					cout << endl;
					break;
				case 3:
					stack->Pop_top();
					break;
				case 4:
					stack->Clear_stack();
					break;
				case 5:
					stack->Swap_first_last();
					break;
				case 6:
					stack->Flip_stack();
					break;
				case 7:
					stack->Delete_everyone_second();
					break;
				case 8:
					stack->Insert_star();
					break;
				case 9:
					stack->Search_max_and_insert_after_zero();
					break;
				case 10:
					stack->Delete_min();
					break;
				case 11:
					stack->Clear_besides_first();
					break;
				case 12:
					stack->Clear_besides_last();
					break;
				case 13:
					f_in.open("File_with_stack.txt", ios::in);
					stack->Read_from_file(f_in);
					f_in.close();
					break;
				case 14:
					f_out.open("File_with_stack.txt");
					stack->Write_to_file(f_out);
					f_out.close();
					break;
				default:
					cout << "\nСпробуйте ще раз!!!\n\n";
				}
			}
			break;
		case 2:
			while (true) {
				cout << endl;
				queue->Print_queue();
				cout << "\n\n 1) Створити декілько елементів\n"
					<< " 2) Додати елемент у кінець черги\n"
					<< " 3) Видалити елемент з початку черги\n"
					<< " 4) Видалити всі елементи з черги\n"
					<< " 5) Підрахувати кількість елементів у черзі\n"
					<< " 6) Знайти середне арифметичне елементів черги\n"
					<< " 7) Знайти максимальний і мінімальний елементи у черзі\n"
					<< " 8) Знайти елемент, що стоїть перед мінімальним\n"
					<< " 9) Зчитати з файлу\n"
					<< " 10) Записати у файл\n"
					<< " 0) Повернутися\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) break;

				switch (choice) {
				case 1:
					cout << "\nКількість елементів: ";
					cin >> choice;
					cout << "\n 1) Заповнити власноруч\n"
						<< " 2) Заповнити випадково\n"
						<< " 0) Повернутися\n\n"
						<< " >>> ";
					cin >> numb;
					if (choice == 0) break;

					if (numb == 1) {
						cout << "\nВведіть числа через пробіл: ";
						queue->Create_queue(choice, true);
						cout << endl;
					}
					else if (numb == 2) queue->Create_queue(choice, false);
					else if (numb == 0) break;
					else cout << "\nСпробуйте ще раз!!!\n\n";
					break;
				case 2:
					cout << "\nВведіть число: ";
					cin >> temp;
					queue->Push_back(temp);
					cout << endl;
					break;
				case 3:
					queue->Pop_front();
					break;
				case 4:
					queue->Clear_queue();
					break;
				case 5:
					queue->Count();
					break;
				case 6:
					queue->Average_arithmetic();
					break;
				case 7:
					queue->Search_max_and_min();
					break;
				case 8:
					queue->Search_item_after_min_item();
					break;
				case 9:
					f_in.open("File_with_queue.txt", ios::in);
					queue->Read_from_file(f_in);
					f_in.close();
					break;
				case 10:
					f_out.open("File_with_queue.txt");
					queue->Write_to_file(f_out);
					f_out.close();
					break;
				default:
					cout << "\nСпробуйте ще раз!!!\n\n";
				}
			}
			break;
		case 3:
			while (true) {
				cout << endl;
				deque->Print_deque();
				cout << "\n\n 1) Створити декілько елементів\n"
					<< " 2) Додати елемент в кінець деки\n"
					<< " 3) Додати елемент в початок деки\n"
					<< " 4) Видалити елемент з кінця деки\n"
					<< " 5) Видалити елемент з початку деки\n"
					<< " 6) Видалити всі елементи з деки\n"
					<< " 7) Знайти і зчитати шостий елемент деки\n"
					<< " 8) Знайти і зчитати останній елемент деки\n"
					<< " 9) Зчитати з файлу\n"
					<< " 10) Записати в файл\n"
					<< " 0) Повернутися\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) break;

				switch (choice) {
				case 1:
					cout << "\nКількість елементів: ";
					cin >> choice;
					cout << "\n 1) Заповнити власноруч\n"
						<< " 2) Заповнити випадково\n"
						<< " 0) Повернутися\n\n"
						<< " >>> ";
					cin >> numb;
					if (choice == 0) break;

					if (numb == 1) {
						cout << "\nВведіть числа через пробіл: ";
						deque->Create_deque(choice, true);
						cout << endl;
					}
					else if (numb == 2) deque->Create_deque(choice, false);
					else if (numb == 0) break;
					else cout << "\nСпробуйте ще раз!!!\n\n";
					break;
				case 2:
					cout << "\nВведіть число: ";
					cin >> temp;
					deque->Push_back(temp);
					cout << endl;
					break;
				case 3:
					cout << "\nВведіть число: ";
					cin >> temp;
					deque->Push_front(temp);
					cout << endl;
					break;
				case 4:
					deque->Pop_back();
					break;
				case 5:
					deque->Pop_front();
					break;
				case 6:
					deque->Clear_deque();
					break;
				case 7:
					deque->Read_sixth_item();
					break;
				case 8:
					deque->Read_last_item();
					break;
				case 9:
					f_in.open("File_with_deque.txt", ios::in);
					deque->Read_from_file(f_in);
					f_in.close();
					break;
				case 10:
					f_out.open("File_with_deque.txt");
					deque->Write_to_file(f_out);
					f_out.close();
					break;
				default:
					cout << "\nСпробуйте ще раз!!!\n\n";
				}
			}
			break;
		case 0:
			return 0;
		default:
			cout << "\nСпробуйте ще раз!!!\n\n";
		}
	}

	return 0;
}