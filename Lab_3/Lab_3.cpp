

#include "Header.h"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    ofstream file_2("data.txt");
    file_2.close();

    RedBlackTree second_tree_2;

    int choice_user(0);
    Tlist* root = NULL;
    Average_item per;
    while (1) {
        cout << "1. Сформувати дерево." << endl;
        cout << "2. Середнє значчення." << endl;
        cout << "3. Друк дерева." << endl;
        cout << "4. Видалення дерева." << endl;
        cout << "5. Видалення частини піддерева." << endl;
        cout << "6. Переписати дерево." << endl;
        cout << "7. Червоно-чорне дерево." << endl;
        cout << "8. Перевірка дерева." << endl;
        cout << "9. Додання та видалення в ч.ч. дереві." << endl;
        cout << "10. Друк." << endl;
        cout << "11. Вихід" << endl;
        vvedinie_data(choice_user, 1, 11, "Оберіть пункт :", "Такого пункта не існує.Повторіть ввод");


        switch (choice_user) {
        case 1: {
            if (second_tree_2.getRoot()->left == NULL) {
                ofstream file("ishod_tree.txt");
                file.close();
                if (root == NULL) {
                    creata_tree(root);
                }
                else if (root != NULL) {
                    del(root);
                    creata_tree(root);
                }
                save_first_tree("", root, 0);
                printBT("", root, 0);
            }
            else {
                cout << "Вы працюєет з ч.ч. деревом." << endl;
            }
            break;
        }
        case 2:
            if (root != NULL && second_tree_2.getRoot()->left == NULL) {
                per.getAverage(root);
                cout << "Середній оклад :" << (double)per.sum / per.count << endl;
            }
            else {
                cout << "Дерево порожнє або воно вже червоно-чорне" << endl;
            }
            break;
        case 3:
            if (root != NULL && second_tree_2.getRoot()->left == NULL) {
                print_tree(root);
            }
            else {
                cout << "Дерево порожнє або воно вже червоно-чорне" << endl;
            }
            break;
            break;
        case 4:
            if (root != NULL && second_tree_2.getRoot()->left == NULL) {
                del(root);
            }
            else {
                cout << "Дерево порожнє або воно вже червоно-чорне" << endl;
            }
            break;
        case 5:
            if (root != NULL && second_tree_2.getRoot()->left == NULL) {
                del_chunk_of_tree(root);
            }
            else {
                cout << "Дерево порожнє або воно вже червоно-чорне" << endl;
            }
            break;
        case 6:
            if (root != NULL && second_tree_2.getRoot()->left == NULL) {
                rewriter var(root);
                var.rewrite(root);
                del(root);
                root = var.new_root;
                printBT("", root, 0);
            }
            else {
                cout << "Дерево порожнє або воно вже червоно-чорне" << endl;
            }
            break;
        case 7:
            if (root != NULL) {
                second_tree_2.PreOrder_BinaryTree(root);
                del(root);

                second_tree_2.printBR("", second_tree_2.getRoot(), 0);
            }
            else {
                cout << "Дерево порожнє" << endl;
            }
            break;
        case 8:
            if (second_tree_2.getRoot()->left != NULL) {
                if (second_tree_2.CheckRBTree(second_tree_2.getRoot()))
                    cout << "Це червоно-чорнє дерево!" << endl;
                else
                    cout << "Не червоно-чорнє дерево!" << endl;
            }
            else {
                cout << "Червоно-чорне дерево не створено" << endl;
            }
            break;

        case 9:
            if (second_tree_2.getRoot()->left != NULL) {
                int del_or_add;
                vvedinie_data(del_or_add, 0, 1, "1 - видалити; 0 - додати.Ваш вибір :");
                if (del_or_add) { // 1
                    int a;
                    vvedinie_data(a, 0, 150, "Введіть оклад працівика :");

                    second_tree_2.Poisk_node(second_tree_2.getRoot(), a);
                    if (second_tree_2.vat_for_poiska_node_for_del.oklad_emp != 0) {
                        second_tree_2.deleteNodeHelper(second_tree_2.getRoot(), second_tree_2.vat_for_poiska_node_for_del);
                        second_tree_2.vat_for_poiska_node_for_del.oklad_emp = 0;
                    }
                    else {
                        cout << "Вузла з таким значенням не існує." << endl;
                    }
                }
                else {
                    info per_s_data;
                    vvedenia_data_stroka(per_s_data.sec_name_emp, "Ведіть прізвище :");
                    vvedinie_data(per_s_data.num_emp, 1000, 9999, "Ведіть номер працівника :");
                    vvedinie_data(per_s_data.oklad_emp, 0, 150, "Ведіть оклад :");
                    second_tree_2.insert(per_s_data);
                }
                if (second_tree_2.getRoot()->left != NULL) {
                    if (second_tree_2.CheckRBTree(second_tree_2.getRoot()))
                        cout << "Це червоно-чорнє дерево!" << endl;
                    else
                        cout << "Не червоно-чорнє дерево!" << endl;
                }
                else {
                    cout << "Червоно-чорне дерево не створено" << endl;
                }
                break;
            }
            else {
                cout << "Червоно-чорне дерево не створено" << endl;
            }
            break;

        case 10:
            if (root != NULL) {
                printBT("", root, 0);
            }
            else if (second_tree_2.getRoot()->right != NULL) {
                second_tree_2.printBR("", second_tree_2.getRoot(), 0);
            }
            else {
                cout << "Дерево порожнє" << endl;
            }
            break;
        case 11:
            if (root != NULL) {
                del(root);
            }
            exit(0);
        }
    }
    return 0;
}

