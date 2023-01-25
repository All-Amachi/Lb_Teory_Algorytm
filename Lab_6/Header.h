#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <cmath>
struct visited_or_not {
	bool was_or = false;
	int key;
};
using namespace std;

bool check();
template <class C>
void vvedinie_data(C& a, const int& znach_1, const int& znach_2, const string& line_vvoda, const string& line_error) {
	int test(0);
	do {
		if (test > 0) {
			cout << line_error << endl;
			test = 0;
		}
		cout << line_vvoda;
		cin >> a;
	} while (test++, check() || (a < znach_1 || a > znach_2));
}

class open_adres {
public:

	int hesh_funk_open_adres(int key, bool from_funk_1, int i, int size = 20);
	void add_elem(vector<visited_or_not>& main_array, bool from_funk_1, int elem, bool check_or_not);
	void recount(vector<visited_or_not>& main_array, bool from_funk_1);
	void delet(vector<visited_or_not>& main_array, bool from_funk_1, int elem);
	void searche(vector<visited_or_not> main_array, bool from_funk_1, int elem);
	bool field_for_item_is(vector<visited_or_not> main_array);
	void print(vector<visited_or_not> main_array);
};


class lancug_probir {

public:
	int hesh_funk_lancug_probir(int key, int size = 9);
	void add_elem(vector<vector<int>>& main_array, int elem);
	void delet(vector<vector<int>>& main_array, int elem);
	void print(vector<vector<int>> main_array);
};
class double_chesh {

public:
	int hesh_fuk_for_first_task(int key, int size, int i);
	void add_elem(vector<visited_or_not>& main_array, int elem, bool check_or_not);
	void delet(vector<visited_or_not>& main_array, int elem);
	bool field_for_item_is(vector<visited_or_not> main_array);
	void recount(vector<visited_or_not>& main_array);
	void print(vector<visited_or_not> main_array);
};
class sq_prob
{
public:
	int hesh_funk_sq_prob(int key, int size, int i);
	void add_elem(vector<visited_or_not>& main_array, int elem, bool check_or_not);
	bool field_for_item_is(vector<visited_or_not> main_array);
	void recount(vector<visited_or_not>& main_array);
	void delet(vector<visited_or_not>& main_array, int elem);
	void print(vector<visited_or_not> main_array);
};

void funk_1(int num, bool from_funk_1, bool what);
void funk_2();
void funk_3();
void work_double_method(int num);
void work_square_method(int num);