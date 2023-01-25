#include "Header.h"
int cont_iter_heap_sort = 0;
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
bool check(string& a) {
	if (a[0] == '\n' || a[0] == ' ' || a[0] == 0) {
		return 1;
	}
	else return 0;
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
void funk_for_prepare_array_before_sort(vector<int>& mass, int col_elem, int type_before) {
	int spos_zapoln(0);
	vvedinie_data(spos_zapoln, 0, 1, "0 - сгенеруванти нові значення. 1 - взяти з файлу :", "Введіть повторно.");

	if (!spos_zapoln) {
		for (int i = 0; i < col_elem; i++)
		{
			mass.push_back(rand() % 1000 + 1);
		}
	}
	else {
		int counter(0);
		ifstream file("rez.txt");
		int a;
		file.read((char*)&a, sizeof(a));
		for (int i = 0; i < col_elem; i++)
		{
			mass.push_back(a);
			file.read((char*)&a, sizeof(a));
			counter++;
		}
		file.close();
	}
	switch (type_before) {
	case 0:break;
	case 1:
		sort(mass.begin(), mass.end());
		break;
	case 2:
		sort(mass.begin(), mass.end(), ascending);
		break;
	}
}
bool ascending(int a, int b)
{
	return a > b;
}
void print_mass(vector<int> mass) {

	for (const auto& a : mass)
	{
		cout << a << setw(4);
	}
	cout << endl;
}

int Shell(vector<int>mass) //сортировка Шелла
{
	int i, j, d, per_for_count_iter(0);
	d = mass.size() / 2;

	while (per_for_count_iter++, d > 0)
	{
		for (i = 0; i < mass.size() - d; i++)
		{
			j = i;
			per_for_count_iter += 2;
			while (per_for_count_iter += 2, j >= 0 && mass[j] > mass[j + d])
			{
				swap(mass[j], mass[j + d]);
				j--;
				per_for_count_iter += 4;
			}
		}
		per_for_count_iter += 2; // перед выходом из for произошла проверка на выход
		d = d / 2;
	}
	per_for_count_iter += 2;

	cout << "Відсортований масив :";
	print_mass(mass);

	return per_for_count_iter;
}
void save_after_sort(string line_enter, vector<int> mass) {
	ofstream file;
	file.open(line_enter);
	char gap = ' ';
	for (auto& a : mass)
	{
		file << a << gap;
	}
	file.close();
}



void heapify(vector<int>& arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	cont_iter_heap_sort += 3;
	if (l < n && arr[l] > arr[largest]){
		cont_iter_heap_sort += 2;
		largest = l;
	}
	cont_iter_heap_sort++;
	if (r < n && arr[r] > arr[largest]) {
		cont_iter_heap_sort += 2;
		largest = r;
	}

	cont_iter_heap_sort++;
	if (largest != i)
	{
		cont_iter_heap_sort++;
		swap(arr[i], arr[largest]);
		cont_iter_heap_sort += 3;
		heapify(arr, n, largest);
	}
}

int heapSort(vector<int> arr)
{
	int n = arr.size();
	cont_iter_heap_sort++;
	for (int i = n / 2 - 1; i >= 0; i--) {
		cont_iter_heap_sort++;
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cont_iter_heap_sort += 3;
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
	cout << "Відсортований масив :";
	print_mass(arr);
	cont_iter_heap_sort++;
	n = cont_iter_heap_sort;
	cont_iter_heap_sort = 0;
	return n;
}

int sort_count(vector<int> arr) {
	int cont_iter(0);
	int max = *max_element(arr.begin(), arr.end());
	//int min = *min_element(arr.begin(), arr.end());

	int* c = new int[++max] {0};
	cont_iter += max + 1;

	for (int i = 0; i < arr.size(); i++)
	{
		cont_iter += 2;
		c[arr[i]] = ++c[arr[i]];
	}
	int b(0);
	cont_iter++;
	for (int i = 0; i <= max; i++)
	{
		cont_iter++;
		for (int j = 0; j < c[i]; j++)
		{
			cont_iter += 2;
			arr[b++] = i;
		}
	}
	cout << "Відсортований масив :";
	print_mass(arr);
	cont_iter++;
	return cont_iter;
}