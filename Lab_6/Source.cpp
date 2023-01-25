#include "Header.h"

bool check() {
	if (cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return 1;
	}
	else {
		cin.ignore(32767, '\n');
		return 0;
	}
}



void funk_1(int num, bool from_funk_1, bool what) {

	open_adres var;

	vector<visited_or_not> main_array(num);

	vector<int> mass_wirh_key{ 46, 47, 48, 49, 50 };
	vector<int> mass_wirh_key_2{ 7, 5, 2, 19, 37, 54, 49, 8, 10 };
	if (what) {
		for (int i = 0; i < mass_wirh_key.size(); i++)
		{
			var.add_elem(main_array, from_funk_1, mass_wirh_key[i], 0);
		}
	}
	else {
		for (int i = 0; i < mass_wirh_key_2.size(); i++)
		{
			var.add_elem(main_array, from_funk_1, mass_wirh_key_2[i], 0);
		}
	}
	var.print(main_array);
	int choise_user(0);

	while (1) {
		cout << "1. Додати." << endl;
		cout << "2. Видалити." << endl;
		cout << "3. Знайти." << endl;
		cout << "4. Друк." << endl;
		cout << "5. Вихід." << endl;
		vvedinie_data(choise_user, 1, 5, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");
		switch (choise_user) {
		case 1: {
			int add_per(0);
			vvedinie_data(add_per, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.add_elem(main_array, from_funk_1, add_per, 1);
			break;
		}
		case 2: {
			int del_elem(0);
			vvedinie_data(del_elem, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.delet(main_array, from_funk_1, del_elem);
			break;
		}
		case 3:
		{
			int ser_elem(0);
			vvedinie_data(ser_elem, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.searche(main_array, from_funk_1, ser_elem);
			break;
		}
		case 4: var.print(main_array); break;
		case 5:
			return;
		}
	}
}
bool open_adres::field_for_item_is(vector<visited_or_not> main_array) {
	bool ret = false;
	int i = main_array.size();
	while (main_array[--i].was_or && i > 0) {

	}
	return i > 0 ? true : false;
}

void open_adres::add_elem(vector<visited_or_not>& main_array, bool from_funk_1, int elem, bool check_or_not) {
	if (check_or_not) {
		if (!field_for_item_is(main_array)) {
			recount(main_array, from_funk_1);
		}
	}
	int posit;
	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_funk_open_adres(elem, from_funk_1, i, main_array.size());
		if (!main_array[posit].was_or) {
			main_array[posit].key = elem;
			main_array[posit].was_or = 1;
			break;
		}
	}
}

int open_adres::hesh_funk_open_adres(int key, bool from_funk_1, int i, int size) {
	if (from_funk_1) {
		return fmod(size * fmod(key * 0.618034, 1) + i, size);
	}
	return fmod(fmod(key, size) + i, size);

}
void open_adres::recount(vector<visited_or_not>& main_array, bool from_funk_1) {
	vector<visited_or_not> dopl_arr(main_array.size() + 10);
	for (int i = 0; i < main_array.size(); i++)
	{
		add_elem(dopl_arr, from_funk_1, main_array[i].key, 0);
	}
	main_array = dopl_arr;
}
void open_adres::delet(vector<visited_or_not>& main_array, bool from_funk_1, int elem) {
	int posit;
	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_funk_open_adres(elem, from_funk_1, i, main_array.size());
		if (!main_array[posit].was_or) {
			cout << "Такого елемента в масиві немає !!!" << endl;
			break;
		}
		else if (main_array[posit].key == elem) {
			main_array.erase(main_array.begin() + posit);
			break;
		}
		if (i == main_array.size() - 1) {
			cout << "Такого елемента в масиві немає !!!" << endl;
		}
	}
}

void open_adres::print(vector<visited_or_not> main_array) {
	for (int i = 0; i < main_array.size(); i++)
	{
		if (main_array[i].was_or) {
			cout << i << " >> " << main_array[i].key << endl;
		}
	}
}
void open_adres::searche(vector<visited_or_not> main_array, bool from_funk_1, int elem) {
	int posit;
	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_funk_open_adres(elem, from_funk_1, i, main_array.size());
		if (!main_array[posit].was_or) {
			cout << "Такого елемента в масиві немає !!!" << endl;
			break;
		}
		else if (main_array[posit].key == elem) {
			cout << "Элемент " << elem << " знаходиться під індексом " << posit << endl;
			break;
		}
	}
}

void funk_2() {
	lancug_probir var;

	int start_size = 9;
	vector<vector<int>> main_array(start_size);

	vector<int> mass_wirh_key{ 7, 5, 2, 19, 37, 54, 49, 8, 10 };
	for (int i = 0; i < mass_wirh_key.size(); i++)
	{
		var.add_elem(main_array, mass_wirh_key[i]);
	}

	var.print(main_array);
	int choise_user(0);


	while (1) {
		cout << "1. Додати." << endl;
		cout << "2. Видалити." << endl;
		cout << "3. Друк." << endl;
		cout << "4. Вихід." << endl;
		vvedinie_data(choise_user, 1, 4, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");
		switch (choise_user) {
		case 1: {
			int add_per(0);
			vvedinie_data(add_per, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.add_elem(main_array, add_per);
			break;
		}
		case 2: {
			int del_elem(0);
			vvedinie_data(del_elem, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.delet(main_array, del_elem);
			break;
		}
		case 3:
		{
			var.print(main_array); break;
			break;
		}
		case 4: return;
		}
	}
}

int lancug_probir::hesh_funk_lancug_probir(int key, int size) {
	return fmod(key, size);
}
void lancug_probir::add_elem(vector<vector<int>>& main_array, int elem) {

	int posit = hesh_funk_lancug_probir(elem);
	main_array[posit].push_back(elem);
}
void lancug_probir::delet(vector<vector<int>>& main_array, int elem) {
	int posit = hesh_funk_lancug_probir(elem);
	int i(0);
	while (i != main_array[posit].size()) {
		if (main_array[posit][i] == elem) {
			break;
		}
		i++;
	}
	if (i < main_array[posit].size()) {
		main_array[posit].erase(main_array[posit].begin() + i);
	}
	else {
		cout << "Такого елемента в масиві немає !!!" << endl;
	}
}
void lancug_probir::print(vector<vector<int>> main_array) {
	for (int i = 0; i < main_array.size(); i++)
	{
		if (main_array[i].size() != 0) {
			cout << "Елементи " << i << " рядка : ";
		}
		for (int j = 0; j < main_array[i].size(); j++)
		{
			cout << main_array[i][j] << setw(4);
		}
		if (main_array[i].size() != 0) {
			cout << endl;
		}
	}
}
void funk_3() {

	int start_size = 11;
	open_adres var_lin;
	int choise_user(0);


	vector<visited_or_not> main_array_lin(start_size);
	while (1) {
		cout << "1. Лін. пробіровання." << endl;
		cout << "2. Квадр. пробіровання." << endl;
		cout << "3. Подвійне пробіровання." << endl;
		cout << "4. Вихід." << endl;
		vvedinie_data(choise_user, 1, 4, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");
		switch (choise_user) {
		case 1: {
			funk_1(11, 0, 0);
			break;
		}
		case 2:
		{
			work_square_method(11); break;
		}
		case 3: {
			work_double_method(11);
			break;
		}
		case 4:return;
		}
	}
}
int double_chesh::hesh_fuk_for_first_task(int key, int size, int i) {
	return fmod(fmod(key, size) + i * (1 + fmod(key, size - 1)), size);
}
void double_chesh::add_elem(vector<visited_or_not>& main_array, int elem, bool check_or_not) {
	if (check_or_not) {
		if (!field_for_item_is(main_array)) {
			recount(main_array);
		}
	}
	int posit;

	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_fuk_for_first_task(elem, main_array.size(), i);

		if (!main_array[posit].was_or) {
			main_array[posit].key = elem;
			main_array[posit].was_or = true;
			break;
		}
	}

}
void double_chesh::delet(vector<visited_or_not>& main_array, int elem) {

	int posit;
	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_fuk_for_first_task(elem, main_array.size(), i);
		if (!main_array[posit].was_or) {
			cout << "Такого елемента в масиві немає !!!" << endl;
			break;
		}
		else if (main_array[posit].key == elem) {
			main_array.erase(main_array.begin() + posit);
			break;
		}
		if (i == main_array.size() - 1) {
			cout << "Такого елемента в масиві немає !!!" << endl;
		}
	}

}
bool double_chesh::field_for_item_is(vector<visited_or_not> main_array) {
	bool ret = false;
	int i = main_array.size();
	while (main_array[--i].was_or && i > 0) {}
	return i > 0 ? true : false;
}

void double_chesh::recount(vector<visited_or_not>& main_array) {
	vector<visited_or_not> dopl_arr(main_array.size() + 10);
	for (int i = 0; i < main_array.size(); i++)
	{
		add_elem(dopl_arr, main_array[i].key, 0);
	}
	main_array = dopl_arr;
}

void work_double_method(int num) {
	double_chesh var;

	vector<int> mass_wirh_key{ 7, 5, 2, 19, 37, 54, 49, 8, 10 };
	vector<visited_or_not> main_array(num);
	for (int i = 0; i < mass_wirh_key.size(); i++)
	{
		var.add_elem(main_array, mass_wirh_key[i], 0);
	}
	var.print(main_array);
	int choise_user(0);

	while (1) {
		cout << "1. Додати." << endl;
		cout << "2. Видалити." << endl;
		cout << "3. Друк." << endl;
		cout << "4. Вихід." << endl;
		vvedinie_data(choise_user, 1, 5, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");
		switch (choise_user) {
		case 1: {
			int add_per(0);
			vvedinie_data(add_per, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.add_elem(main_array, add_per, 1);
			break;
		}
		case 2: {
			int del_elem(0);
			vvedinie_data(del_elem, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.delet(main_array, del_elem);
			break;
		}
		case 3:
			var.print(main_array); break;
		case 4:
			return;
		}
	}


}

void double_chesh::print(vector<visited_or_not> main_array) {
	for (int i = 0; i < main_array.size(); i++)
	{
		if (main_array[i].was_or) {
			cout << i << " >> " << main_array[i].key << endl;
		}
	}
}

int sq_prob::hesh_funk_sq_prob(int key, int size, int i) {
	return fmod(fmod(key, size) + 1 * i + 3 * i * i, size);
}
bool sq_prob::field_for_item_is(vector<visited_or_not> main_array) {
	bool ret = false;
	int i = main_array.size();
	while (main_array[--i].was_or && i > 0) {}
	return i > 0 ? true : false;
}
void sq_prob::add_elem(vector<visited_or_not>& main_array, int elem, bool check_or_not) {
	if (check_or_not) {
		if (!field_for_item_is(main_array)) {
			recount(main_array);
			print(main_array);
		}
	}
	int posit;

	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_funk_sq_prob(elem, main_array.size(), i);
		if (!main_array[posit].was_or) {
			main_array[posit].key = elem;
			main_array[posit].was_or = true;
			break;
		}
	}
}
void sq_prob::recount(vector<visited_or_not>& main_array) {
	vector<visited_or_not> dopl_arr(main_array.size() + 10);
	for (int i = 0; i < main_array.size(); i++)
	{
		add_elem(dopl_arr, main_array[i].key, 0);
	}
	main_array = dopl_arr;
}
void sq_prob::delet(vector<visited_or_not>& main_array, int elem) {
	int posit;
	for (int i = 0; i < main_array.size(); i++)
	{
		posit = hesh_funk_sq_prob(elem, main_array.size(), i);
		if (!main_array[posit].was_or) {
			cout << "Такого елемента в масиві немає !!!" << endl;
			break;
		}
		else if (main_array[posit].key == elem) {
			main_array.erase(main_array.begin() + posit);
			break;
		}
		if (i == main_array.size() - 1) {
			cout << "Такого елемента в масиві немає !!!" << endl;
		}
	}
}
void work_square_method(int num) {
	sq_prob var;

	vector<int> mass_wirh_key{ 7, 5, 2, 19, 37, 54, 49, 8, 10 };
	vector<visited_or_not> main_array(num);
	for (int i = 0; i < mass_wirh_key.size(); i++)
	{
		var.add_elem(main_array, mass_wirh_key[i], 0);
	}
	var.print(main_array);
	int choise_user(0);

	while (1) {
		cout << "1. Додати." << endl;
		cout << "2. Видалити." << endl;
		cout << "3. Друк." << endl;
		cout << "4. Вихід." << endl;
		vvedinie_data(choise_user, 1, 5, "Оберіть пункт :", "Такого пункта немає в списку.Повторіть ввод");
		switch (choise_user) {
		case 1: {
			int add_per(0);
			vvedinie_data(add_per, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.add_elem(main_array, add_per, 1);
			break;
		}
		case 2: {
			int del_elem(0);
			vvedinie_data(del_elem, 1, 150, "Введіть значення :", "Повторіть ввод");
			var.delet(main_array, del_elem);
			break;
		}
		case 3:
			var.print(main_array); break;
		case 4:
			return;
		}
	}
}
void sq_prob::print(vector<visited_or_not> main_array) {
	for (int i = 0; i < main_array.size(); i++)
	{
		if (main_array[i].was_or) {
			cout << i << " >> " << main_array[i].key << endl;
		}
	}
}


