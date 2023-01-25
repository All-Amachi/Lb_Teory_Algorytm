#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;

class Node   // ���� ����� 
{
public:
	char simb;                         // ����� ����������� ����(����������)
	Node* next = NULL, * back = NULL;  // ��������� �� ���������, ��������� ��������
	Node();                            
	~Node();
};

class List   // ���� ������
{
private:
	bool type;                         // ���� true - �����'�����, false - ��������
	int size = 0;                      // ����� ������
	Node* head = NULL, * tail = NULL;  // ��������� �� ������ ������� �������� ������
public:
	List();
	List(bool who);
	bool Ret_type();  //���������� ���� ������ 
	Node* Ret_ptr_head_node();  //���������� ��������� �� ������� ������
	void Create_list(int numb, bool how);  //��������� ������
	void Add_node(char new_simb);  //��������� ����� � ����� ������
	bool Del_node(int index_node);  //��������� ����� � ������
	int Count_nodes();  //ϳ���������� ������� �������� � ������
	bool Swap_nodes(int index_first_node, int index_second_node);  //���� ������ ���� �����
	void Combi_lists(Node* ptr_head_first_list, Node* ptr_head_second_list);  //��'������� ���� ������ � ����
	bool Clear_list();  //��������� ��� ����� � ������
	void Print_list();  //��������� ������ �� �����
	char Read_list_from_file(ifstream& f_cin);  //���������� � ��������� ����� �� ������
	void Write_list_to_file(ofstream& f_cout, bool last_element);  //����������� ������ � ����
	~List();
};