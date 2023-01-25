#pragma once

#include <iostream>
#include <iomanip>
#include <stack> 
#include <string>
#include <vector>
#include <array>
#include <Windows.h>
#include <fstream>
#define COUNT 10
using namespace std;


struct info {
    int oklad_emp = 0;
    int num_emp;
    string sec_name_emp;
};

struct Tlist {
	info data;
	Tlist* left;
	Tlist* right;
};

enum  TreeColor
{
    BLACK = 0,
    RED = 1

};
std::ostream& operator<<(std::ostream& out, const TreeColor& a);

struct Tree
{
    info key;
    Tree* left = nullptr;
    Tree* right = nullptr;
    Tree* parent = nullptr;
    TreeColor color = RED;
};

struct Node { // новая 
    info data;
    Node* parent;
    Node* left;
    Node* right;
    TreeColor color = RED;
};

typedef Node* NodePtr;




class rewriter {
public:
    Tlist* old_root, * new_root = NULL;
    rewriter(Tlist* old) :old_root(old) {};

    void rewrite(Tlist* Node) {
        if (Node != NULL) {
            add_node(Node->data, new_root, 0);
            rewrite(Node->left);
            rewrite(Node->right);
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
                if (x.oklad_emp <= MyTree->data.oklad_emp)
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
                if (x.oklad_emp <= MyTree->data.oklad_emp)
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
};


class Solution {  // удаление узла Tlist
public:
    info var_for_poisk;
    Tlist* iskomuy_node;
    void Poisk_node(Tlist* Node, int key) {
        if (Node != NULL) {
            if (Node->data.oklad_emp == key) {
                var_for_poisk = Node->data;
                iskomuy_node = Node;
            }
            Poisk_node(Node->left, key);
            Poisk_node(Node->right, key);
        }
    }

    Tlist* deleteNode(Tlist* root, info key) { // функции по удалению узла 
        if (root == NULL || root->data.oklad_emp == key.oklad_emp) return deleteRoot(root);
        Tlist* curr = root;
        while (1) {
            string x = curr->data.sec_name_emp;

            if (key.sec_name_emp <= x) {
                if (curr->left == NULL || curr->left->data.oklad_emp == key.oklad_emp) {
                    curr->left = deleteRoot(curr->left);
                    break;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == NULL || curr->right->data.oklad_emp == key.oklad_emp) {
                    curr->right = deleteRoot(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
    Tlist* deleteRoot(Tlist* root) {
        if (!root || root->data.oklad_emp == 0)return NULL;
        if (root->right == NULL) return root->left;
        Tlist* x = root->right;
        while (x->left)x = x->left;
        x->left = root->left;
        return root->right;
    }
};

class Average_item {// сред знач 
public:
    int sum = 0;
    int count = 0;

    void getAverage(Tlist* node) {
        if (node == nullptr) {
            return;
        }
        sum += node->data.oklad_emp;
        count++;
        getAverage(node->left);
        getAverage(node->right);
    }
};
class RedBlackTree {
private:
    NodePtr root;
    NodePtr TNULL;

    void initializeNULLNode(NodePtr node, NodePtr parent) {
        node->data.oklad_emp = 0;
        node->data.num_emp = 0;
        node->data.sec_name_emp = nullptr;

        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = BLACK;
    }

    // Preorder
    void preOrderHelper(NodePtr node) {
        if (node != TNULL) {
            //cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // Inorder
    void inOrderHelper(NodePtr node) {
        if (node != TNULL) {
            inOrderHelper(node->left);
            //cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

    // Post order
    void postOrderHelper(NodePtr node) {
        if (node != TNULL) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            // cout << node->data << " ";
        }
    }


    void deleteFix(NodePtr x) {
        NodePtr s;
        while (x != root && x->color == 0) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == 1) {
                    s->color = RED;
                    x->parent->color = BLACK;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) {
                    s->color = RED;
                    x = x->parent;
                }
                else {
                    if (s->right->color == 0) {
                        s->left->color = BLACK; // RED    BLACK
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else {
                s = x->parent->left;
                if (s->color == 1) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0) {
                    s->color = RED;
                    x = x->parent;
                }
                else {
                    if (s->left->color == 0) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void rbTransplant(NodePtr u, NodePtr v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }



    // For balancing the tree after insertion
    void insertFix(NodePtr k) {
        NodePtr u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == 1) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
            else {
                u = k->parent->parent->right;

                if (u->color == 1) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = BLACK;
    }



public:

    info vat_for_poiska_node_for_del;
    Node* node_poisk;
    void Poisk_node(Node* Node, int key) {
        if (Node != NULL) {
            if (Node->data.oklad_emp == key) {
                vat_for_poiska_node_for_del = Node->data;
                node_poisk = Node;
            }
            Poisk_node(Node->left, key);
            Poisk_node(Node->right, key);
        }
    }
    Node* getRoot()
    {
        return root;
    }
    void setRoot(Node* a) {
        root = a;
    }

    RedBlackTree() {
        TNULL = new Node;
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }
    void deleteNodeHelper(NodePtr node, info key) {
        NodePtr z = TNULL;
        NodePtr x, y;
        while (node != TNULL) {
            if (node->data.oklad_emp == key.oklad_emp) {
                z = node;
            }

            if (node->data.sec_name_emp <= key.sec_name_emp) {   //МОЖЕТ НЕ ВЛЕВО А В ПРАВО
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    void preorder() {
        preOrderHelper(this->root);
    }

    void inorder() {
        inOrderHelper(this->root);
    }

    void postorder() {
        postOrderHelper(this->root);
    }

    /* NodePtr searchTree(int k) {
         return searchTreeHelper(this->root, k);
     }*/

    NodePtr minimum(NodePtr node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    NodePtr maximum(NodePtr node) {
        while (node->right != TNULL) {
            node = node->right;
        }
        return node;
    }

    NodePtr successor(NodePtr x) {
        if (x->right != TNULL) {
            return minimum(x->right);
        }

        NodePtr y = x->parent;
        while (y != TNULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    NodePtr predecessor(NodePtr x) {
        if (x->left != TNULL) {
            return maximum(x->left);
        }

        NodePtr y = x->parent;
        while (y != TNULL && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }

    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void PreOrder_BinaryTree(Tlist* Node) {
        if (Node != NULL) {
            insert(Node->data);
            PreOrder_BinaryTree(Node->left);
            PreOrder_BinaryTree(Node->right);
        }
    }
    // Inserting a node
    void insert(info key) {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        NodePtr y = nullptr;
        NodePtr x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data.sec_name_emp <= x->data.sec_name_emp) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        }
        else if (node->data.sec_name_emp < y->data.sec_name_emp) {
            y->left = node;
        }
        else {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }



    void deleteNode(info data) {
        deleteNodeHelper(this->root, data);
    }


    void printBR(const std::string& prefix, Node* node, bool isLeft)
    {
        if (node != TNULL) // изменил nullprt na TNULL 
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
                    cout << "Номер паспорту :" << node->data.num_emp << endl;
                    break;
                case 2:
                    //	cout << "|          ";
                    cout << (isLeft ? "|          " : "           ");
                    cout << "Вік :" << node->data.oklad_emp << "  (" << node->color << ")" << endl;
                    break;
                }
            }
            printBR(prefix + (isLeft ? "|          " : "          "), node->right, true);
            printBR(prefix + (isLeft ? "|          " : "          "), node->left, false);
        }
    }

    bool CheckRBTree(Node* that)  // проверка на красно-чёрность
    {
        if (that->right == TNULL)
            return true;
        if (that->color == 1) // Нарушение природы 2 "Корневой узел черный
            return false;
        int blackcount = 0; // Подсчитываем количество черных узлов в цепочке

        Node* pCur = root;
        while (pCur)
        {
            if (pCur->color == 0)
                blackcount++;
            pCur = pCur->left; // В качестве примера возьмем крайнюю левую цепочку
        }
        // Свойство проверки 4 «Черные узлы в каждой цепочке равны», свойство проверки 3 «Красные узлы не могут быть соединены»
        return _CheckRBTree(root, blackcount, 0);
    }

    bool _CheckRBTree(Node* pRoot, int counter, int k)
    {
        if (pRoot == TNULL)
            return true;
        if (pRoot->color == 0)
            k++;

        Node* parent = pRoot->parent;

        if (parent && parent->color == RED && pRoot->color == RED) // Нарушение свойства 3 "Красные узлы не могут быть соединены"
            return false;

        if (pRoot == TNULL)
        {
            if (k != counter) // Нарушение свойства 4 "Черные узлы в каждой цепочке равны"
                return false;
        }

        return _CheckRBTree(pRoot->left, counter, k)
            && _CheckRBTree(pRoot->right, counter, k);
    }

};


template <typename T>
void vvedinie_data(T& a, const int& znach_1, const int& znach_2, const string& line_vvoda, const string& line_error = "Повторите ввод.");
void vvedenia_data_stroka(string& a, const string& str);
void del(Tlist*& tree);
void creata_tree(Tlist*& root);
void printBT(const std::string& prefix, const Tlist* node, bool isLeft);
void PreOrder_BinaryTree(Tlist* Node);
void print_tree(Tlist* tree);
void del_chunk_of_tree(Tlist*& tree);
void save_first_tree(const std::string& prefix, const Tlist* node, bool isLeft);
void inizial_var(info& per);
void add_node(info x, Tlist*& MyTree, bool decision);
