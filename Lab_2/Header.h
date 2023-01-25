#pragma once
#include <iostream>
#include <fstream>
#include "math.h"
#include "Windows.h"

using namespace std;

class Single_List //���� ������'������ ������
{
public:
	double numb = 0; //����������
	Single_List* next = NULL; //�������� �� ��������� �������
	Single_List();
	Single_List(double value);
	~Single_List();
};

class Double_List //���� �����'������ ������
{
public:
	double numb = 0; //����������
	Double_List* next = NULL, * back = NULL; //��������� �� ��������� � ��������� �������
	Double_List();
	Double_List(double value);
	~Double_List();
};


class Stack //���� �����
{
private:
	Single_List* top = NULL; //�������� �� ������� �����
	int size = 0; //����� �����
public:
	Stack();
	void Create_stack(int count, bool flag); //��������� �������� ��������
	void Print_stack(); //������������� �����
	void Push_top(double value); //��������� �������� �� ������� �����
	void Pop_top(); //��������� �������� � ������� �����
	void Clear_stack(); //�������� �����
	void Swap_first_last(); //���� ������� � ��������� �������� ������
	void Flip_stack(); //������������ �����
	void Delete_everyone_second(); //��������� ������� ������� ��������
	void Insert_star(); //���������� ���� � ����
	void Search_max_and_insert_after_zero(); //���������� ���� ������������� �������� - ����
	void Delete_min(); //�������� ���������
	void Clear_besides_first(); //�������� �� �������� ��� �������
	void Clear_besides_last(); //�������� �� �������� ��� ���������
	void Read_from_file(ifstream& f_in); //������� � �����
	void Write_to_file(ofstream& f_out); //�������� � ����
	~Stack();
};

class Queue //���� �����
{
private:
	Double_List* first = NULL, * last = NULL; //��������� �� ������� � ����� �����
public:
	Queue();
	void Create_queue(int count, bool flag); //��������� �������� ��������
	void Print_queue(); //������������� �����
	void Push_back(double value); //��������� �������� � ����� �����
	void Pop_front(); //��������� ������� � ������� �����
	void Clear_queue(); //�������� �����
	void Count(); //���������� ������� �������� �����
	void Average_arithmetic(); //������ �����������
	void Search_max_and_min(); //����� ������������� � ���������� ��������
	void Search_item_after_min_item(); //����� ��������, �� ��� ����� ���������
	void Read_from_file(ifstream& f_in); //���������� � �����
	void Write_to_file(ofstream& f_out); //����������� � ����
	~Queue();
};

class Deque //���� ����
{
private:
	Double_List* first = NULL, * last = NULL; //��������� �� ������� � ����� �����
public:
	Deque();
	void Create_deque(int count, bool how); //��������� �������� ��������
	void Print_deque(); //������������� ����
	void Push_front(double value); //��������� �������� � �������
	void Push_back(double value); //��������� �������� � �����
	void Pop_front(); //��������� �������� � �������
	void Pop_back(); //��������� �������� � ���� 
	void Clear_deque(); //�������� ����
	void Read_sixth_item(); //������� ������ �������
	void Read_last_item(); //������� ������� ������� 
	void Read_from_file(ifstream& f_in); //������� � �����
	void Write_to_file(ofstream& f_out); //�������� � ����
	~Deque();
};

void Print_single_list(Single_List* ptr); //������� ������������� ������'������ ������
void Print_double_list(Double_List* ptr); //������� ������������� �����'������ ������