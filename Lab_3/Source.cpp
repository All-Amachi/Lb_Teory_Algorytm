#include "Header.h"
int posit = 0;
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
template <typename T>
void vvedinie_data(T& a, const int& znach_1, const int& znach_2, const string& line_vvoda, const string& line_error) {
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
void vvedenia_data_stroka(string& a, const string& str) {
	int test(0);
	do {
		if (test > 0) {
			cout << "Введите повторно" << endl;
			test = 0;
		}
		cout << str;
		getline(cin, a);
	} while (test++, check(a));
}

void creata_tree(Tlist*& root) {

	int col_elem(0), way_zapoln;
	info per_s_data;
	vvedinie_data(col_elem, 0, INT_MAX, "Введите количество елементов дерева :");
	vvedinie_data(way_zapoln, 0, 1, "Как вы хотите заполнить все узлы? 1 - вручную; 0 - из файла.");
	for (int i = 0; i < col_elem; i++)
	{
		if (way_zapoln == 1) {
			cout << "Ввод значений для узла №" << i << endl;
			vvedenia_data_stroka(per_s_data.sec_name_emp, "Введите фамили :");
			vvedinie_data(per_s_data.num_emp, 1000, 9999, "Введите номер паспорта :");
			vvedinie_data(per_s_data.oklad_emp, 0, 150, "Введите возраст :");
		}
		else {
			inizial_var(per_s_data);
		}
		add_node(per_s_data, root, true);
	}
}

void printBT(const std::string& prefix, const Tlist* node, bool isLeft)
{
	if (node != nullptr)
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << prefix;
			switch (i) {
			case 0:std::cout << (isLeft ? "|-------- " : "L-------- ");
				cout << "Прізвище :" << node->data.sec_name_emp << endl;
				break;
			case 1:
				cout << (isLeft ? "|          " : "           ");
				cout << "Номер працівника :" << node->data.num_emp << endl;
				break;
			case 2:
				//	cout << "|          ";
				cout << (isLeft ? "|          " : "           ");
				cout << "Оклад :" << node->data.oklad_emp << endl;
				break;
			}
		}
		printBT(prefix + (isLeft ? "|          " : "          "), node->right, true);
		printBT(prefix + (isLeft ? "|          " : "          "), node->left, false);
	}
}

void add_node(info x, Tlist*& MyTree, bool decision)
{
	if (NULL == MyTree)
	{
		MyTree = new Tlist;
		MyTree->data = x;
		MyTree->left = MyTree->right = NULL;
	}
	else {
		if (decision) {
			if (x.sec_name_emp <= MyTree->data.sec_name_emp)
			{
				if (MyTree->left != NULL) {
					add_node(x, MyTree->left, 1);
				}
				else
				{
					MyTree->left = new Tlist;
					MyTree->left->left = MyTree->left->right = NULL;
					MyTree->left->data = x;
				}
			}
			else
			{
				if (MyTree->right != NULL)
				{
					add_node(x, MyTree->right, 1);
				}
				else
				{
					MyTree->right = new Tlist;
					MyTree->right->left = MyTree->right->right = NULL;
					MyTree->right->data = x;
				}
			}
		}
		else {
			if (x.sec_name_emp <= MyTree->data.sec_name_emp)
			{
				if (MyTree->left != NULL) {
					add_node(x, MyTree->left, 0);
				}
				else
				{
					MyTree->left = new Tlist;
					MyTree->left->left = MyTree->left->right = NULL;
					MyTree->left->data = x;
				}
			}
			else
			{
				if (MyTree->right != NULL)
				{
					add_node(x, MyTree->right, 0);
				}
				else
				{
					MyTree->right = new Tlist;
					MyTree->right->left = MyTree->right->right = NULL;
					MyTree->right->data = x;
				}
			}
		}
	}
}

void del_chunk_of_tree(Tlist*& tree) {
	int way_del(0);
	vvedinie_data(way_del, 0, 2, "Оберіть шо видаляти. 0 - ліве піддерево, 1 - праве піддерево, 2 - вузол  : ", "Такого пункта в списке нет.Повторите ввод");
	switch (way_del)
	{
	case 0:
		if (tree->left != 0) {
			del(tree->left);
		}
		else {
			cout << "Лівого піддерева нема" << endl;
		}
		break;
	case 1:
		if (tree->right != 0) {
			del(tree->right);
		}
		else {
			cout << "Правого піддерева нема" << endl;
		}
		break;
	case 2:
		Solution var;
		int a;
		vvedinie_data(a, 0, 150, "Ведіть шуканий оклад :");
		var.Poisk_node(tree, a);
		if (var.iskomuy_node != tree) {
			if (var.var_for_poisk.oklad_emp != 0) {
				tree = var.deleteNode(tree, var.var_for_poisk);
				delete var.iskomuy_node;
				var.var_for_poisk.oklad_emp = 0;
			}
			else {
				cout << "Вузла з таким значенням не існує." << endl;
			}
		}
		else {
			del(tree);
		}

		break;
	}
}
void save_first_tree(const std::string& prefix, const Tlist* node, bool isLeft)
{
	if (node != nullptr)
	{
		ofstream file("ishod_tree.txt", std::ios::app);
		for (int i = 0; i < 3; i++)
		{
			file << prefix;
			switch (i) {
			case 0:
				file << (isLeft ? "|-------- " : "L-------- ");
				file << "Прізвище :" << node->data.sec_name_emp << endl;
				break;
			case 1:
				file << (isLeft ? "|          " : "           ");
				file << "Номер працівника :" << node->data.num_emp << endl;
				break;
			case 2:
				file << (isLeft ? "|          " : "           ");
				file << "Оклад :" << node->data.oklad_emp << endl;
				break;
			}
		}
		file.close();
		save_first_tree(prefix + (isLeft ? "|          " : "          "), node->right, true);
		save_first_tree(prefix + (isLeft ? "|          " : "          "), node->left, false);
	}
}
void PreOrder_BinaryTree(Tlist* Node) {
	if (Node != NULL) {
		cout << Node->data.sec_name_emp << endl;
		cout << Node->data.num_emp << endl;
		cout << Node->data.oklad_emp << endl << endl;
		PreOrder_BinaryTree(Node->left);
		PreOrder_BinaryTree(Node->right);
	}
}
void PostOrder_BinaryTree(Tlist* Node) {
	if (Node != NULL) {
		PostOrder_BinaryTree(Node->left);
		PostOrder_BinaryTree(Node->right);
		cout << Node->data.sec_name_emp << endl;
		cout << Node->data.num_emp << endl;
		cout << Node->data.oklad_emp << endl << endl;
	}
}
void Symmetricorder_BinaryTree(Tlist* Node) {
	if (Node != NULL) {
		PostOrder_BinaryTree(Node->left);
		cout << Node->data.sec_name_emp << endl;
		cout << Node->data.num_emp << endl;
		cout << Node->data.oklad_emp << endl << endl;
		PostOrder_BinaryTree(Node->right);
	}
}
void print_tree(Tlist* tree) {
	int way_print(0);
	vvedinie_data(way_print, 0, 2, "Оберіть спосіб друку. 0 - прямий, 1 - зворотній, 2 - симетричний  : ", "Такого пункту в списку немає.Повторіть ввод");
	switch (way_print) {
	case 0:
		PreOrder_BinaryTree(tree);
		break;
	case 1:
		PostOrder_BinaryTree(tree);
		break;
	case 2:
		Symmetricorder_BinaryTree(tree);
		break;
	}
}

void inizial_var(info& per) {
	ofstream file("data.txt", std::ios::app);
	file.seekp(posit, ios::beg);
	array<string, 20> names{ "Бакуменко" , "Блажкевич","Чернуха" , "Дмитрук" , "Ладика" , "Яловенко" , "Безщасний",
		"Чубинський" ,"Забара" ,"Литвинович" , "Юрженко" ,"Шостацький" ,"Абрамець" , 
		"Трегуб" ,"Голобородько" ,"Говдя" , "Ярошенко" ,"Довбуш" ,"Луценко" , "Базика"};
	per.oklad_emp = rand() % (60 - 20 + 1) + 20;
	per.num_emp = rand() % (9999 - 1000 + 1) + 1000;
	per.sec_name_emp = names.at(rand() % 19);
	file.write((char*)&per, sizeof(per));
	posit = file.tellp();
	file.close();
}



void del(Tlist*& tree) {
	if (tree->left)   del(tree->left);
	if (tree->right)  del(tree->right);
	delete tree;
	tree = nullptr;
}
std::ostream& operator<<(std::ostream& out, const TreeColor& a) {
	switch (a) {
	case 0:  out << 'B'; break;
	case 1: out << 'R'; break;
	}
	return out;
}

