#include <iostream>

class Node
{
public:
    int item;
    Node *link;
};

class SortedLinkedList
{
public:
    Node *start;
    SortedLinkedList()
    {
        start = NULL;
    }

    Node *append(int data)
    {
        Node *new_node = new Node;
        new_node->item = data;
        new_node->link = NULL;
        if (!start)
        {
            start = new_node;
        }
        else
        {
            Node *temp = start;
            while (temp->link)
                temp = temp->link;
            if (temp->item > data)
            {
                std::cout << "List must be sorted in ascending order.";
                delete new_node;
                return NULL;
            }
            temp->link = new_node;
        }
        return new_node;
    }

    void print()
    {
        Node *temp = start;
        std::cout << "\n[";
        while (temp)
        {
            std::cout << ' ' << temp->item;
            temp = temp->link;
        }
        std::cout << " ]\n";
    }
};

int list_options(SortedLinkedList &list)
{
    int ch, data;
    do
    {
        std::cout << "1.Append\t 2.END\n>>> ";
        std::cin >> ch;
        if (ch == 1)
        {
            std::cout << "Enter integer to append: ";
            std::cin >> data;
            list.append(data);
            list.print();
        }
    } while (ch != 2);
    return 0;
}

SortedLinkedList *merge(SortedLinkedList &list1, SortedLinkedList &list2)
{
    SortedLinkedList *new_list = new SortedLinkedList;
    Node *temp1 = list1.start;
    Node *temp2 = list2.start;

    while (temp1 && temp2)
    {
        if (temp1->item <= temp2->item)
        {
            new_list->append(temp1->item);
            temp1 = temp1->link;
        }
        else
        {
            new_list->append(temp2->item);
            temp2 = temp2->link;
        }
    }

    while (temp1)
    {
        new_list->append(temp1->item);
        temp1 = temp1->link;
    }

    while (temp2)
    {
        new_list->append(temp2->item);
        temp2 = temp2->link;
    }

    return new_list;
}

int main()
{
    SortedLinkedList list1, list2;
    SortedLinkedList *merged;
    int ch;

    do
    {
        std::cout << "1. List 1\t2. List 2\n3. Merge\t4. END\n>>> ";
        std::cin >> ch;
        if (ch == 1)
            list_options(list1);
        else if (ch == 2)
            list_options(list2);
        else if (ch == 3)
        {
            std::cout << list1.start;
            merged = merge(list1, list2);
            std::cout << list1.start;
            merged->print();
        }
    } while (ch != 4);
}
