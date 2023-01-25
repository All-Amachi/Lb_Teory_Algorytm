#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;

class Node   // Клас вузлу 
{
public:
	char simb;                         // Змінна символьного типу(інформація)
	Node* next = NULL, * back = NULL;  // Вказівники на наступний, попередній елементи
	Node();                            
	~Node();
};

class List   // Клас списку
{
private:
	bool type;                         // Якщо true - двозв'язний, false - кільцевий
	int size = 0;                      // Розмір списку
	Node* head = NULL, * tail = NULL;  // Вказівники на перший останній елементи списку
public:
	List();
	List(bool who);
	bool Ret_type();  //Повернення типу списку 
	Node* Ret_ptr_head_node();  //Повернення вказівника на початок списку
	void Create_list(int numb, bool how);  //Створення списку
	void Add_node(char new_simb);  //Додавання вузлу в кінець списку
	bool Del_node(int index_node);  //Видалення вузлу в списку
	int Count_nodes();  //Підрахування кількості елементів у списку
	bool Swap_nodes(int index_first_node, int index_second_node);  //Зміна місцями двох вузлів
	void Combi_lists(Node* ptr_head_first_list, Node* ptr_head_second_list);  //Об'єднання двох списків в один
	bool Clear_list();  //Видалення всіх вузлів у списку
	void Print_list();  //Виведення списку на екран
	char Read_list_from_file(ifstream& f_cin);  //Зчитування і додавання вузлів із списку
	void Write_list_to_file(ofstream& f_cout, bool last_element);  //Записування списку в файл
	~List();
};