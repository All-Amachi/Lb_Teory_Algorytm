#include "Header.h"

Node::Node() {}
Node::~Node() {}

List::List() {}
List::List(bool who) { this->type = who; }
bool List::Ret_type() { return this->type; }
Node* List::Ret_ptr_head_node() { return this->head; }
void List::Create_list(int numb, bool how) {
	if (numb == 0) return;

	if (how == true) {
		cout << "\nВведіть символи через пробіл: ";
		if (this->type == false) {
			this->head = this->tail = new Node;
			this->head->next = this->head->back = this->head;
			cin >> this->tail->simb;
			for (short i = 0; i < numb - 1; i++) {
				this->tail->next = new Node;
				this->tail->next->back = this->tail;
				this->tail->next->next = this->head;
				this->tail = this->tail->next;
				this->head->back = this->tail;
				cin >> this->tail->simb;
			}
		}
		else {
			this->head = this->tail = new Node;
			cin >> this->head->simb;
			for (short i = 0; i < numb - 1; i++) {
				this->tail->next = new Node;
				this->tail->next->back = this->tail;
				this->tail = tail->next;
				cin >> this->tail->simb;
			}
		}
	}
	else {
		if (this->type == false) {
			this->head = this->tail = new Node;
			this->head->next = this->head->back = this->head;
			this->tail->simb = (char)(rand() % 95 + 32);
			for (short i = 0; i < numb - 1; i++) {
				this->tail->next = new Node;
				this->tail->next->back = this->tail;
				this->tail->next->next = this->head;
				this->tail = this->tail->next;
				this->head->back = this->tail;
				this->tail->simb = (char)(rand() % 95 + 32);
			}
		}
		else {
			this->head = this->tail = new Node;
			this->tail->simb = (char)(rand() % 95 + 32);
			for (short i = 0; i < numb - 1; i++) {
				this->tail->next = new Node;
				this->tail->next->back = this->tail;
				this->tail = this->tail->next;
				this->tail->simb = (char)(rand() % 95 + 32);
			}
		}
	}
	this->size = numb;
}
void List::Add_node(char new_simb) {
	if (this->type == false)
	{
		if (this->size == 0)
		{
			this->head = this->tail = new Node;
			this->head->next = this->head->back = this->head;
			this->tail->simb = new_simb;
		}
		else
		{
			tail->next = new Node;
			tail->next->back = tail;
			tail->next->next = head;
			tail = tail->next;
			head->back = tail;
			this->tail->simb = new_simb;
		}
	}
	else
	{
		if (this->size == 0)
		{
			this->head = this->tail = new Node;
			this->tail->simb = new_simb;
		}
		else
		{
			tail->next = new Node;
			tail->next->back = tail;
			tail = tail->next;
			this->tail->simb = new_simb;
		}
	}
	this->size++;
}
bool List::Del_node(int index_node) {
	if (index_node > this->size || index_node < 1)
		return false;

	if (this->size == 1) {
		delete this->head;
		this->head = this->tail = NULL;
		this->size = 0;
		return true;
	}

	Node* ptr;
	if (this->type == false) {
		if (this->size / 2 >= index_node) {
			ptr = this->head;
			for (short i = 0; i < index_node - 1; i++)
				ptr = ptr->next;
			if (ptr == this->head)
				this->head = this->head->next;
		}
		else {
			ptr = this->tail;
			for (short i = this->size; i > index_node; i--)
				ptr = ptr->back;
			if (ptr == this->tail)
				this->tail = this->tail->back;
		}
		ptr->back->next = ptr->next;
		ptr->next->back = ptr->back;
		delete ptr;
	}
	else
	{
		if (this->size / 2 >= index_node)
		{
			ptr = this->head;
			for (short i = 0; i < index_node - 1; i++)
				ptr = ptr->next;
			if (ptr == this->head)
			{
				this->head = this->head->next;
				this->head->back = NULL;
				delete ptr;
				this->size--;
				return true;
			}
		}
		else
		{
			ptr = this->tail;
			for (short i = this->size; i > index_node; i--)
				ptr = ptr->back;
			if (ptr == this->tail)
			{
				this->tail = this->tail->back;
				this->tail->next = NULL;
				delete ptr;
				this->size--;
				return true;
			}
		}
		ptr->back->next = ptr->next;
		ptr->next->back = ptr->back;
		delete ptr;
	}
	this->size--;
	return true;
}
int List::Count_nodes() {
	if (this->head == NULL) return 0;
	int count = 0;
	Node* ptr = this->head;
	do {
		count++;
		ptr = ptr->next;
	} while (ptr != NULL && ptr->back != this->tail);
	return count;
}
bool List::Swap_nodes(int index_first_node, int index_second_node) {
	if (index_first_node > this->size ||
		index_first_node < 1 ||
		index_second_node > this->size ||
		index_second_node < 1)
		return false;
	if (this->size == 1)
		return true;

	char temp;
	Node* ptr = NULL;
	if (index_second_node - index_first_node == this->size - 1) {
		if (this->type == false) {
			temp = this->head->simb;
			this->head->simb = this->tail->simb;
			this->tail->simb = temp;
			return true;
		}
	}
	if (index_second_node - index_first_node != 1)
		return false;
	if (this->size / 2 >= index_first_node) {
		ptr = this->head;
		for (short i = 0; i < index_first_node - 1; i++)
			ptr = ptr->next;
		temp = ptr->simb;
		ptr->simb = ptr->next->simb;
		ptr->next->simb = temp;
	}
	else {
		ptr = this->tail;
		for (short i = this->size; i > index_second_node; i--)
			ptr = ptr->back;
		temp = ptr->simb;
		ptr->simb = ptr->back->simb;
		ptr->back->simb = temp;
	}
	return true;
}
void List::Combi_lists(Node* ptr_head_first_list, Node* ptr_head_second_list) {
	if (ptr_head_first_list == NULL) {
		if (ptr_head_second_list == NULL)
			return;

		this->head = this->tail = new Node;
		this->tail->simb = ptr_head_second_list->simb;
		ptr_head_second_list = ptr_head_second_list->next;
		this->size++;
		while (ptr_head_second_list != NULL) {
			this->tail->next = new Node;
			this->tail->next->back = this->tail;
			this->tail = this->tail->next;
			this->tail->simb = ptr_head_second_list->simb;
			ptr_head_second_list = ptr_head_second_list->next;
			this->size++;
		}
	}
	else {
		this->head = this->tail = new Node;
		this->tail->simb = ptr_head_first_list->simb;
		ptr_head_first_list = ptr_head_first_list->next;
		this->size++;
		while (ptr_head_first_list != NULL) {
			this->tail->next = new Node;
			this->tail->next->back = this->tail;
			this->tail = this->tail->next;
			this->tail->simb = ptr_head_first_list->simb;
			ptr_head_first_list = ptr_head_first_list->next;
			this->size++;
		}

		if (ptr_head_second_list == NULL)
			return;

		while (ptr_head_second_list != NULL)
		{
			this->tail->next = new Node;
			this->tail->next->back = this->tail;
			this->tail = this->tail->next;
			this->tail->simb = ptr_head_second_list->simb;
			ptr_head_second_list = ptr_head_second_list->next;
			this->size++;
		}
	}
}
bool List::Clear_list() {
	if (this->size == 0)
		return false;

	Node* ptr = this->tail;
	for (short i = 0; i < this->size - 1; i++){
		this->tail = this->tail->back;
		delete ptr;
		ptr = this->tail;
	}
	delete this->head;
	this->head = this->tail = NULL;
	this->size = 0;
	return true;
}
void List::Print_list() {
	if (this->type == false)        
		cout << "Кільцевий: ";
	else
		cout << "Двозв'язний: ";

	if (this->head == NULL) {
		cout << "пустий\n";
		return;
	}

	Node* ptr = this->head;
	do {
		cout << ptr->simb << " ";
		ptr = ptr->next;
	} while (ptr != NULL && ptr->back != this->tail);
	cout << endl;
}
char List::Read_list_from_file(ifstream& f_cin) {
	char temp_simb;
	f_cin.get();
	temp_simb = f_cin.get();
	if (temp_simb == '\n' || temp_simb == EOF)
		return temp_simb;

	if (this->type == false) {
		this->head = this->tail = new Node;
		this->tail->next = this->tail->back = this->tail;
		this->tail->simb = temp_simb;
		this->size++;
		temp_simb = f_cin.get();
		while (temp_simb != '\n' && temp_simb != EOF) {
			this->tail->next = new Node;
			this->tail->next->back = this->tail;
			this->tail = this->tail->next;
			this->tail->next = this->head;
			this->head->back = this->tail;
			this->tail->simb = temp_simb;
			this->size++;
			temp_simb = f_cin.get();
		}
	}
	else {
		this->head = this->tail = new Node;
		this->tail->simb = temp_simb;
		this->size++;
		temp_simb = f_cin.get();
		while (temp_simb != '\n' && temp_simb != EOF) {
			this->tail->next = new Node;
			this->tail->next->back = this->tail;
			this->tail = this->tail->next;
			this->tail->simb = temp_simb;
			this->size++;
			temp_simb = f_cin.get();
		}
	}
	return temp_simb;
}
void List::Write_list_to_file(ofstream& f_cout, bool last_element) {
	if (this->type == false) f_cout << "K:";
	else f_cout << "D:";
	if (this->head == NULL) {
		if (last_element == false)
			f_cout << endl;
		return;
	}
	Node* ptr = this->head;
	do {
		f_cout << ptr->simb;
		ptr = ptr->next;
	} while (ptr != NULL && ptr->back != this->tail);
	if (last_element == false)
		f_cout << endl;
}
List::~List() {}