#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#define N 10000
#define O 256
# define NO_OF_CHARS 256
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

void Shell(vector<int>& mass);
void zapoln_file();
void print_mass(vector<int> mass);
void funk_for_prepare_array_before_sort(vector<int>& mass, int col_elem);
int lin_search_arr(vector<int> mass, int key, int& col_iterachiy);
int barrier_search_arr(vector<int> mass, int key, int& col_iterachiy);


int pramuy_search(string osn_str, string key_str);
int search_Boyler(string txt, string pat);
int KMPSearch(string pat, string txt);
int Robina_Karpa(string pat, string txt, int q);




class bar_search {

public:
	static int col_iterachiy;
	static int binar_search_arr(vector<int> arr, int l, int r, int x) {

		if (r >= l) {
			int mid = l + (r - l) / 2;
			col_iterachiy += 2;
			if (arr[mid] == x) {
				col_iterachiy += 2;
				return mid;
			}
			col_iterachiy++;
			if (arr[mid] > x) {
				col_iterachiy += 2;
				return binar_search_arr(arr, l, mid - 1, x);
			}
			col_iterachiy += 2;
			return binar_search_arr(arr, mid + 1, r, x);
		}
		col_iterachiy++;
		return -1;
	}
};