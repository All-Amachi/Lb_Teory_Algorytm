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
		cout << "\n 1) ����\n"
			<< " 2) �����\n"
			<< " 3) ����\n"
			<< " 0) �����\n\n"
			<< " >>> ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (true) {
				cout << endl;
				stack->Print_stack();
				cout << "\n\n 1) �������� ������� ��������\n"
					<< " 2) ������ ������� �� �������\n"
					<< " 3) �������� ������� � �������\n"
					<< " 4) �������� �� �������� �����\n"
					<< " 5) ������ ������ ������ � ������� �������� ����� ������\n"
					<< " 6) ����������� ����\n"
					<< " 7) �������� ����� ������ ������� �����\n"
					<< " 8) �������� ���� � ��������\n"
					<< " 9) ������ ������������ � �������� ���� ����� ����\n"
					<< " 10) �������� ��������� �������\n"
					<< " 11) �������� �� �������� ��� �������\n"
					<< " 12) �������� �� �������� ��� ���������\n"
					<< " 13) ������� � �����\n"
					<< " 14) �������� � ����\n"
					<< " 0) �����������\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) break;

				switch (choice) {
				case 1:
					cout << "\nʳ������ ��������: ";
					cin >> choice;
					cout << "\n 1) ��������� ���������\n"
						<< " 2) ��������� ���������\n"
						<< " 0) �����������\n\n"
						<< " >>> ";
					cin >> numb;
					if (numb == 1) {
						cout << "\n������ ����� ����� �����: ";
						stack->Create_stack(choice, true);
						cout << endl;
					}
					else if (numb == 2) stack->Create_stack(choice, false);
					else if (numb == 0) break;
					else cout << "\n��������� �� ���!!!\n\n";
					break;
				case 2:
					cout << "\n������ �����: ";
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
					cout << "\n��������� �� ���!!!\n\n";
				}
			}
			break;
		case 2:
			while (true) {
				cout << endl;
				queue->Print_queue();
				cout << "\n\n 1) �������� ������� ��������\n"
					<< " 2) ������ ������� � ����� �����\n"
					<< " 3) �������� ������� � ������� �����\n"
					<< " 4) �������� �� �������� � �����\n"
					<< " 5) ϳ��������� ������� �������� � ����\n"
					<< " 6) ������ ������� ����������� �������� �����\n"
					<< " 7) ������ ������������ � ��������� �������� � ����\n"
					<< " 8) ������ �������, �� ����� ����� ���������\n"
					<< " 9) ������� � �����\n"
					<< " 10) �������� � ����\n"
					<< " 0) �����������\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) break;

				switch (choice) {
				case 1:
					cout << "\nʳ������ ��������: ";
					cin >> choice;
					cout << "\n 1) ��������� ���������\n"
						<< " 2) ��������� ���������\n"
						<< " 0) �����������\n\n"
						<< " >>> ";
					cin >> numb;
					if (choice == 0) break;

					if (numb == 1) {
						cout << "\n������ ����� ����� �����: ";
						queue->Create_queue(choice, true);
						cout << endl;
					}
					else if (numb == 2) queue->Create_queue(choice, false);
					else if (numb == 0) break;
					else cout << "\n��������� �� ���!!!\n\n";
					break;
				case 2:
					cout << "\n������ �����: ";
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
					cout << "\n��������� �� ���!!!\n\n";
				}
			}
			break;
		case 3:
			while (true) {
				cout << endl;
				deque->Print_deque();
				cout << "\n\n 1) �������� ������� ��������\n"
					<< " 2) ������ ������� � ����� ����\n"
					<< " 3) ������ ������� � ������� ����\n"
					<< " 4) �������� ������� � ���� ����\n"
					<< " 5) �������� ������� � ������� ����\n"
					<< " 6) �������� �� �������� � ����\n"
					<< " 7) ������ � ������� ������ ������� ����\n"
					<< " 8) ������ � ������� ������� ������� ����\n"
					<< " 9) ������� � �����\n"
					<< " 10) �������� � ����\n"
					<< " 0) �����������\n\n"
					<< " >>> ";
				cin >> choice;
				if (choice == 0) break;

				switch (choice) {
				case 1:
					cout << "\nʳ������ ��������: ";
					cin >> choice;
					cout << "\n 1) ��������� ���������\n"
						<< " 2) ��������� ���������\n"
						<< " 0) �����������\n\n"
						<< " >>> ";
					cin >> numb;
					if (choice == 0) break;

					if (numb == 1) {
						cout << "\n������ ����� ����� �����: ";
						deque->Create_deque(choice, true);
						cout << endl;
					}
					else if (numb == 2) deque->Create_deque(choice, false);
					else if (numb == 0) break;
					else cout << "\n��������� �� ���!!!\n\n";
					break;
				case 2:
					cout << "\n������ �����: ";
					cin >> temp;
					deque->Push_back(temp);
					cout << endl;
					break;
				case 3:
					cout << "\n������ �����: ";
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
					cout << "\n��������� �� ���!!!\n\n";
				}
			}
			break;
		case 0:
			return 0;
		default:
			cout << "\n��������� �� ���!!!\n\n";
		}
	}

	return 0;
}