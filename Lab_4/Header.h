#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#define N 200

using namespace std;


void zapoln_file();
bool ascending(int a, int b);
bool check();
bool check(string& a);
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




void funk_for_prepare_array_before_sort(vector<int>& mass, int col_elem, int type_before);
void print_mass(vector<int> mass);
void save_after_sort(string line_enter, vector<int> mass);


int Shell(vector<int>mass);
int heapSort(vector<int> arr);
int sort_count(vector<int> arr);
