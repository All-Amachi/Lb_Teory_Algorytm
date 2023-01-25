#pragma once
#include <iostream>
#include <fstream>
#include "math.h"
#include "Windows.h"

using namespace std;

class Single_List //Клас однозв'язного списку
{
public:
	double numb = 0; //Інформація
	Single_List* next = NULL; //Вказівник на наступний елемент
	Single_List();
	Single_List(double value);
	~Single_List();
};

class Double_List //Клас двозв'язного списку
{
public:
	double numb = 0; //Інформація
	Double_List* next = NULL, * back = NULL; //Вказівники на наступний і попередній елемент
	Double_List();
	Double_List(double value);
	~Double_List();
};


class Stack //Клас стеку
{
private:
	Single_List* top = NULL; //Вказівник на вершину стеку
	int size = 0; //Розмір стеку
public:
	Stack();
	void Create_stack(int count, bool flag); //Створення декількох елементів
	void Print_stack(); //Роздрукування стеку
	void Push_top(double value); //Додавання елементу на вершину стеку
	void Pop_top(); //Видалення елементу з вершини стеку
	void Clear_stack(); //Очищення стеку
	void Swap_first_last(); //Зміна першого і останього елемента місцями
	void Flip_stack(); //Перегортання стеку
	void Delete_everyone_second(); //Видалення кожного другого елементу
	void Insert_star(); //Вставлення зірки у стек
	void Search_max_and_insert_after_zero(); //Вставлення після максимального елементу - нуль
	void Delete_min(); //Видалити мінімальний
	void Clear_besides_first(); //Видалити всі елементи крім першого
	void Clear_besides_last(); //Видалити всі елементи крім останього
	void Read_from_file(ifstream& f_in); //Зчитати з файлу
	void Write_to_file(ofstream& f_out); //Записату в файл
	~Stack();
};

class Queue //Клас черги
{
private:
	Double_List* first = NULL, * last = NULL; //Вказівники на початок і кінець черги
public:
	Queue();
	void Create_queue(int count, bool flag); //Створення декількох елементів
	void Print_queue(); //Роздрукування черги
	void Push_back(double value); //Додавання елементу в кінець черги
	void Pop_front(); //Видалення елемент з початку черги
	void Clear_queue(); //Очищення черги
	void Count(); //Пдірахувати кількість елементів черги
	void Average_arithmetic(); //Череднє арифметичне
	void Search_max_and_min(); //Пошук максимального і мінімального елементів
	void Search_item_after_min_item(); //Пошук елементу, що йде перед мінімальним
	void Read_from_file(ifstream& f_in); //Зчитування з файлу
	void Write_to_file(ofstream& f_out); //Записування у файл
	~Queue();
};

class Deque //Клас деки
{
private:
	Double_List* first = NULL, * last = NULL; //Вказівники на початок і кінець черги
public:
	Deque();
	void Create_deque(int count, bool how); //Створення декількох елементів
	void Print_deque(); //Роздрукування деки
	void Push_front(double value); //Додавання елементу в початок
	void Push_back(double value); //Додавання елементу в кінець
	void Pop_front(); //Видалення елементу з початку
	void Pop_back(); //Видалення елементу з кінця 
	void Clear_deque(); //Очищення деки
	void Read_sixth_item(); //Зчитати шостий елемент
	void Read_last_item(); //Зчитати останній елемент 
	void Read_from_file(ifstream& f_in); //Зчитати з файлу
	void Write_to_file(ofstream& f_out); //Записати у файл
	~Deque();
};

void Print_single_list(Single_List* ptr); //Фуркція роздрокування однозв'язного списку
void Print_double_list(Double_List* ptr); //Функція роздрукування двозв'язного списку