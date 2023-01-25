
#include "Header.h"
int posit = 0;
int bar_search::col_iterachiy = 0;
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


void Shell(vector<int>& mass)
{
	int i, j, d;
	d = mass.size() / 2;

	while (d > 0)
	{
		for (i = 0; i < mass.size() - d; i++)
		{
			j = i;

			while (j >= 0 && mass[j] > mass[j + d])
			{
				swap(mass[j], mass[j + d]);
				j--;

			}
		}

		d = d / 2;
	}
	//cout << "Отсорт. мас. :";
	//print_mass(mass);
}

void zapoln_file() {
	ofstream file("rez.txt", ios::binary | ios::out);
	int rand_num = rand() % 1000 + 1;
	for (int i = 0; i < N; i++)
	{
		rand_num = rand() % 1000 + 1;
		file.write((char*)&rand_num, sizeof(rand_num));
	}
	file.close();
}

void print_mass(vector<int> mass) {

	for (const auto& a : mass)
	{
		cout << a << setw(4);
	}
	cout << endl;
}
void funk_for_prepare_array_before_sort(vector<int>& mass, int col_elem) {

	int counter(0);
	ifstream file("rez.txt", ios::binary | ios::in);
	file.seekg(posit, ios::beg);
	int a;
	file.read((char*)&a, sizeof(a));

	for (int i = 0; i < col_elem; i++)
	{
		mass.push_back(a);
		file.read((char*)&a, sizeof(a));
		if (file.eof()) {
			file.clear();
			file.seekg(0, ios::beg);
		}
		counter++;
	}
	//cout << "Колич. шагов счёта: " << counter << endl;
	posit = file.tellg();
	file.close();
}


int lin_search_arr(vector<int> mass, int key, int& col_iterachiy) {
	for (int i = 0; i < mass.size(); i++) {
		col_iterachiy++;
		if (mass[i] == key) {
			col_iterachiy += 2;
			return i;
		}
		col_iterachiy++;
	}
	col_iterachiy++;
	return -1;
}

int barrier_search_arr(vector<int> mass, int key, int& col_iterachiy) {
	mass.push_back(key);
	col_iterachiy++;
	int i(0);
	while (mass[i] != key) {
		col_iterachiy += 2;
		i++;
	}
	col_iterachiy++;
	return i < mass.size() - 1 ? i : -1;
}



int pramuy_search(string osn_str, string key_str) {
	int counetr(0);
	int col_iterachiy(0);
	for (size_t i = 0; i < osn_str.length(); i++)
	{
		col_iterachiy++;
		for (size_t j = i; j < key_str.length() + i; j++)
		{
			col_iterachiy += 2;
			if (osn_str[j] == key_str[counetr++]) {
				col_iterachiy++;
				if (counetr == key_str.length()) {
					cout << "на позиції " << j - key_str.length() + 1 << endl;
				}
			}
			else {
				col_iterachiy++;
				counetr = 0;
				break;
			}
		}
	}
	col_iterachiy++;
	return col_iterachiy;
}



void badCharHeuristic(string str, int size, int& col_iter,
	int badchar[])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++) {
		col_iter += 2;
		badchar[i] = -1;
	}
	for (i = 0; i < size; i++) {
		badchar[(int)str[i]] = i;
		col_iter += 2;
	}
}

int search_Boyler(string txt, string pat)
{
	int col_iter(0);
	int m = pat.size();
	int n = txt.size();
	col_iter += 2;
	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, col_iter, badchar);

	int s = 0;
	col_iter++;
	while (s <= (n - m))
	{
		col_iter++;
		int j = m - 1;
		col_iter++;
		while (j >= 0 && pat[j] == txt[s + j]) {
			col_iter += 2;
			j--;
		}

		if (j < 0)
		{
			col_iter += 2;
			cout << "на позиції " << s << endl;

			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else {
			col_iter += 2;
			s += max(1, j - badchar[txt[s + j]]);
		}
	}
	col_iter++;
	return col_iter;
}
int computeLPSArray(string pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
int KMPSearch(string pat, string txt)
{
	int col_iter(0);
	int M = pat.length();
	int K = txt.length();
	col_iter += 2;

	int* lps = new int[M];
	col_iter++;

	col_iter += computeLPSArray(pat, M, lps);

	int i = 0;
	int j = 0;
	col_iter += 2;
	while (i < K) {
		col_iter++;
		if (pat[j] == txt[i]) {
			col_iter += 3;
			j++;
			i++;
		}

		if (j == M) {
			cout << "на позиції " << i - j << endl;
			col_iter += 2;
			j = lps[j - 1];
		}
		else if (i < K && pat[j] != txt[i]) {
			col_iter++;
			if (j != 0) {
				col_iter += 2;
				j = lps[j - 1];
			}
			else {
				i = i + 1;
				col_iter += 2;
			}
		}
	}
	col_iter++;
	return col_iter;
}

// Fills lps[] for given patttern pat[0..M-1]
int computeLPSArray(string pat, int M, int* lps)
{
	int col_iter(0);
	// length of the previous longest prefix suffix
	int len = 0;
	col_iter++;
	lps[0] = 0; // lps[0] is always 0
	col_iter++;
	// the loop calculates lps[i] for i = 1 to M-1
	col_iter++;
	int i = 1;
	while (i < M) {
		col_iter++;
		if (pat[i] == pat[len]) {
			col_iter += 4;
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			col_iter++;

			if (len != 0) {
				col_iter += 2;
				len = lps[len - 1];
			}
			else // if (len == 0)
			{
				col_iter += 3;
				lps[i] = 0;
				i++;
			}
		}
	}
	col_iter++;
	return col_iter;
}

int Robina_Karpa(string pat, string txt, int q)
{
	int col_iter(0);
	int M = pat.length();
	int K = txt.length();
	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;
	col_iter += 5;
	for (i = 0; i < M - 1; i++) {
		h = (h * O) % q;
		col_iter += 2;
	}

	for (i = 0; i < M; i++)
	{
		p = (O * p + pat[i]) % q;
		t = (O * t + txt[i]) % q;
		col_iter += 3;
	}
	for (i = 0; i <= K - M; i++)
	{
		col_iter++;
		if (p == t)
		{
			col_iter += 2;
			bool flag = true;
			for (j = 0; j < M; j++)
			{
				col_iter++;
				if (txt[i + j] != pat[j])
				{
					col_iter += 2;
					flag = false;
					break;
				}

			}
			if (j == M) {
				cout << "на позиції " << i << endl;
				col_iter++;
			}
		}
		if (i < K - M)
		{
			col_iter++;
			t = (O * (t - txt[i] * h) + txt[i + M]) % q;
			col_iter++;
			if (t < 0) {
				t = (t + q);
				col_iter += 2;
			}
		}
	}
	col_iter++;
	return col_iter;
}