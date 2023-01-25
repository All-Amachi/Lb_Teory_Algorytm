#include "Header.h"

Single_List::Single_List() {}
Single_List::Single_List(double value) { this->numb = value; }
Single_List::~Single_List() {}

Double_List::Double_List() {}
Double_List::Double_List(double value) { this->numb = value; }
Double_List::~Double_List() {}

void Print_single_list(Single_List* ptr)
{
	if (ptr == NULL)
		return;
	Print_single_list(ptr->next);
	cout << ptr->numb << " ";
}
void Print_double_list(Double_List* ptr)
{
	if (ptr == NULL)
		return;
	Print_double_list(ptr->next);
	cout << ptr->numb << " ";
}

Stack::Stack() {}
void Stack::Create_stack(int count, bool flag) {
	double temp;
	if (flag == true) {
		for (int i = 0; i < count; i++) {
			cin >> temp;
			this->Push_top(temp);
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			temp = rand() % 101 - 50 + rand() % 101 * 0.01;
			this->Push_top(temp);
		}
	}
}
void Stack::Print_stack() {
	cout << "Елементи стеку: ";
	if (this->top == NULL) {
		cout << "НЕМАЄ";
		return;
	}
	Print_single_list(this->top);
}
void Stack::Push_top(double value) {
	Single_List* ptr = new Single_List(value);
	ptr->next = this->top;
	this->top = ptr;
	this->size++;
}
void Stack::Pop_top() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr = this->top;
	this->top = this->top->next;
	delete ptr;
	this->size--;
}
void Stack::Clear_stack() {
	Single_List* ptr_del;
	while (this->top != NULL) {
		ptr_del = this->top;
		this->top = this->top->next;
		delete ptr_del;
	}
	this->size = 0;
}
void Stack::Swap_first_last() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	double temp = this->top->numb;
	Single_List* ptr = this->top;
	while (ptr->next != NULL)
		ptr = ptr->next;
	this->top->numb = ptr->numb;
	ptr->numb = temp;
}
void Stack::Flip_stack() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr_1 = NULL, * ptr_2 = NULL;
	if (this->top->next == NULL)
		return;
	if (this->top->next->next == NULL) {
		ptr_1 = this->top->next;
		this->top->next = NULL;
		ptr_1->next = this->top;
		this->top = ptr_1;
		return;
	}
	ptr_1 = this->top->next;
	ptr_2 = ptr_1->next;
	ptr_1->next = this->top;
	this->top->next = NULL;
	while (ptr_2->next != NULL) {
		this->top = ptr_1;
		ptr_1 = ptr_2;
		ptr_2 = ptr_2->next;
		ptr_1->next = this->top;
	}
	ptr_2->next = ptr_1;
	this->top = ptr_2;
}
void Stack::Delete_everyone_second() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr_back = this->top, * ptr_del = this->top->next;
	if (this->top->next == NULL)
		return;
	ptr_back->next = ptr_del->next;
	delete ptr_del;
	this->size--;
	while (ptr_back->next != NULL && ptr_back->next->next != NULL) {
		ptr_back = ptr_back->next;
		ptr_del = ptr_back->next;
		ptr_back->next = ptr_del->next;
		delete ptr_del;
		this->size--;
	}
}
void Stack::Insert_star() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr_search = this->top, * ptr = NULL;
	int count = ceil(this->size / 2.0) - 1;
	for (short i = 0; i < count; i++)
		ptr_search = ptr_search->next;
	ptr = new Single_List(0);
	ptr->next = ptr_search->next;
	ptr_search->next = ptr;
	this->size++;
}
void Stack::Search_max_and_insert_after_zero() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr = this->top, * ptr_search = this->top;
	while (ptr_search->next != NULL) {
		ptr_search = ptr_search->next;
		if (ptr_search->numb > ptr->numb)
			ptr = ptr_search;
	}
	ptr_search = new Single_List(0);
	ptr_search->next = ptr->next;
	ptr->next = ptr_search;
	this->size++;
}
void Stack::Delete_min() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr_back = this->top,
		* ptr_del = this->top,
		* ptr_search = this->top;
	if (this->top->next == NULL) {
		delete this->top;
		this->size--;
		this->top = NULL;
		return;
	}
	if (this->top->next->next == NULL) {
		if (ptr_search->numb > ptr_search->next->numb)
			ptr_del = ptr_del->next;
		if (ptr_del == this->top)
			this->top = this->top->next;
		else
			this->top->next = NULL;
		delete ptr_del;
		this->size--;
		return;
	}
	while (ptr_search->next != NULL) {
		if (ptr_search->next->numb < ptr_del->numb) {
			ptr_back = ptr_search;
			ptr_del = ptr_search->next;
		}
		ptr_search = ptr_search->next;
	}
	if (ptr_del == this->top) {
		this->top = this->top->next;
		delete ptr_del;
		this->size--;
		return;
	}
	if (ptr_del->next == NULL) {
		ptr_back->next = NULL;
		delete ptr_del;
		this->size--;
		return;
	}
	ptr_back->next = ptr_del->next;
	delete ptr_del;
	this->size--;
}
void Stack::Clear_besides_first() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr_del = this->top;
	if (this->top->next == NULL)
		return;
	do {
		this->top = this->top->next;
		delete ptr_del;
		ptr_del = this->top;

	} while (this->top->next != NULL);
	this->size = 1;
}
void Stack::Clear_besides_last() {
	if (this->top == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Single_List* ptr_del = NULL;
	if (this->top->next == NULL)
		return;
	do {
		ptr_del = this->top->next;
		this->top->next = ptr_del->next;
		delete ptr_del;

	} while (this->top->next != NULL);
	this->size = 1;
}
void Stack::Read_from_file(ifstream& f_in) {
	this->Clear_stack();
	Single_List* ptr = NULL;
	string str = "";
	char ch;
	while ((ch = f_in.get()) != EOF) {
		if ((ch > 47 && ch < 58) || ch == 46 || ch == 45)
			str += (char)ch;
		else if (ch == 32) {
			if (this->top == NULL)
				this->top = ptr = new Single_List(atof(str.c_str()));
			else {
				ptr->next = new Single_List(atof(str.c_str()));
				ptr = ptr->next;
			}
			this->size++;
			str = "";
		}
		else break;
	}
}
void Stack::Write_to_file(ofstream& f_out) {
	Single_List* ptr = this->top;
	while (ptr != NULL) {
		f_out << ptr->numb << " ";
		ptr = ptr->next;
	}
}
Stack::~Stack() {}

Queue::Queue() {}
void Queue::Create_queue(int count, bool flag) {
	double temp;
	if (flag == true) {
		for (short i = 0; i < count; i++) {
			cin >> temp;
			this->Push_back(temp);
		}
	}
	else {
		for (short i = 0; i < count; i++) {
			temp = rand() % 101 - 50 + rand() % 101 * 0.01;
			this->Push_back(temp);
		}
	}
}
void Queue::Print_queue() {
	cout << "Елементи черги: ";
	if (this->first == NULL) {
		cout << "НЕМАЄ";
		return;
	}
	Print_double_list(this->last);
}
void Queue::Push_back(double value) {
	if (this->first == NULL) {
		this->first = this->last = new Double_List(value);
		return;
	}
	this->last->back = new Double_List(value);
	this->last->back->next = this->last;
	this->last = this->last->back;
}
void Queue::Pop_front() {
	if (this->first == NULL)
		return;
	Double_List* ptr_del = this->first;
	if (this->first->back == NULL) {
		delete this->first;
		this->first = this->last = NULL;
		return;
	}
	this->first = this->first->back;
	this->first->next = NULL;
	delete ptr_del;
}
void Queue::Clear_queue() {
	Double_List* ptr_del = NULL;
	while (this->first != NULL) {
		ptr_del = this->first;
		this->first = this->first->back;
		delete ptr_del;
	}
	this->first = this->last = NULL;
}
void Queue::Count() {
	int count = 0;
	Double_List* ptr_counter = this->first;
	while (ptr_counter != NULL) {
		count++;
		ptr_counter = ptr_counter->back;
	}
	cout << "\nДовжина черги: " << count << endl;
}
void Queue::Average_arithmetic() {
	double avg = 0, count = 0;
	Double_List* ptr = this->first;
	while (ptr != NULL) {
		avg += ptr->numb;
		count++;
		ptr = ptr->back;
	}
	if (count == 0)
		cout << "\nСередне арифметичне черги = 0\n\n";
	else
		cout << "\nСередне арифметичне черги = " << avg / count << "\n\n";
}
void Queue::Search_max_and_min() {
	if (this->first == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	double max = 0, min = 0;
	Double_List* ptr = this->first;
	max = min = ptr->numb;
	ptr = ptr->back;
	while (ptr != NULL) {
		if (ptr->numb > max)
			max = ptr->numb;
		if (ptr->numb < min)
			min = ptr->numb;
		ptr = ptr->back;
	}
	cout << "\nМаксимальний елемент черги = " << max;
	cout << "\n\nМінімальний елемент черги = " << min << "\n\n";
}
void Queue::Search_item_after_min_item() {
	if (this->first == NULL) {
		cout << "\nНемає елементів!!!\n\n";
		return;
	}
	Double_List* ptr_search = NULL, * ptr_min = NULL;
	ptr_min = this->first;
	ptr_search = this->first->back;
	while (ptr_search != NULL) {
		if (ptr_search->numb < ptr_min->numb)
			ptr_min = ptr_search;
		ptr_search = ptr_search->back;
	}
	if (ptr_min->next == NULL) {
		cout << "\nТакого елементу немає у черзі!!!\n\n";
		return;
	}
	cout << "\nЕлемент, що стоїть перед мінімальним = " << ptr_min->next->numb << "\n\n";
}
void Queue::Read_from_file(ifstream& f_in) {
	string str = "";
	char ch;
	while ((ch = f_in.get()) != EOF) {
		if ((ch > 47 && ch < 58) || ch == 46 || ch == 45)
			str += (char)ch;
		else if (ch == 32) {
			this->Push_back(atof(str.c_str()));
			str = "";
		}
		else break;
	}
}
void Queue::Write_to_file(ofstream& f_out) {
	Double_List* ptr = this->first;
	while (ptr != NULL) {
		f_out << ptr->numb << " ";
		ptr = ptr->back;
	}
}
Queue::~Queue() {}

Deque::Deque() {}
void Deque::Create_deque(int count, bool flag) {
	double temp;
	if (flag == true) {
		for (short i = 0; i < count; i++) {
			cin >> temp;
			this->Push_back(temp);
		}
	}
	else {
		for (short i = 0; i < count; i++) {
			temp = rand() % 101 - 50 + rand() % 101 * 0.01;
			this->Push_back(temp);
		}
	}
}
void Deque::Print_deque() {
	cout << "Елементи деки:";
	if (this->first == NULL) {
		cout << " НЕМАЄ";
		return;
	}
	Print_double_list(this->last);
}
void Deque::Push_front(double value) {
	if (this->first == NULL) {
		this->first = this->last = new Double_List(value);
		return;
	}
	this->first->next = new Double_List(value);
	this->first->next->back = this->first;
	this->first = this->first->next;
}
void Deque::Push_back(double value) {
	if (this->first == NULL) {
		this->first = this->last = new Double_List(value);
		return;
	}
	this->last->back = new Double_List(value);
	this->last->back->next = this->last;
	this->last = this->last->back;
}
void Deque::Pop_front() {
	if (this->first == NULL)
		return;
	Double_List* ptr_del = this->first;
	if (this->first->back == NULL) {
		delete this->first;
		this->first = this->last = NULL;
		return;
	}
	this->first = this->first->back;
	this->first->next = NULL;
	delete ptr_del;
}
void Deque::Pop_back() {
	if (this->first == NULL)
		return;
	Double_List* ptr_del = this->last;
	if (this->last->next == NULL) {
		delete this->last;
		this->first = this->last = NULL;
		return;
	}
	this->last = this->last->next;
	this->last->back = NULL;
	delete ptr_del;
}
void Deque::Clear_deque() {
	Double_List* ptr_del = NULL;
	while (this->first != NULL) {
		ptr_del = this->first;
		this->first = this->first->back;
		delete ptr_del;
	}
	this->first = this->last = NULL;
}
void Deque::Read_sixth_item() {
	Double_List* ptr_search = this->first;
	short count = 1;
	if (this->first != NULL)
		for (; count < 6 && ptr_search->back != NULL; count++)
			ptr_search = ptr_search->back;
	if (count == 6)
		cout << "\nШостий елемент = " << ptr_search->numb << "\n\n";
	else
		cout << "\nШостого елементу немає у деці!!!\n\n";
}
void Deque::Read_last_item() {
	if (this->last == NULL)
		cout << "\nНемає елементів!!!\n\n";
	else
		cout << "\nОстанній елемент = " << this->last->numb << "\n\n";
}
void Deque::Read_from_file(ifstream& f_in) {
	string str = "";
	char ch;
	while ((ch = f_in.get()) != EOF) {
		if ((ch > 47 && ch < 58) || ch == 46 || ch == 45)
			str += (char)ch;
		else if (ch == 32) {
			this->Push_back(atof(str.c_str()));
			str = "";
		}
		else break;
	}
}
void Deque::Write_to_file(ofstream& f_out) {
	Double_List* ptr = this->first;
	while (ptr != NULL) {
		f_out << ptr->numb << " ";
		ptr = ptr->back;
	}
}
Deque::~Deque() {}