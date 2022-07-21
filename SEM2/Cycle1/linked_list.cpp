#include <iostream>

class Node
{
public:
    int item;
    Node *link;
};

class LinkedList
{
public:
    Node *start;
    LinkedList()
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
            temp->link = new_node;
        }
        print();
        return new_node;
    }

    Node *insert(int idx, int data)
    {
        Node *new_node = new Node;
        new_node->item = data;
        if (idx == 0)
        {
            new_node->link = start;
            start = new_node;
        }
        else
        {
            Node *temp = start;
            for (int i = 0; i < idx - 1; i++)
                temp = temp->link;
            new_node->link = temp->link;
            temp->link = new_node;
        }
        print();
        return new_node;
    }

    Node *del(int idx)
    {
        Node *temp = start;
        if (idx == 0)
        {
            start = start->link;
            delete temp;
            print();
            return temp;
        }
        else
        {
            for (int i = 0; i < idx - 1; i++)
                temp = temp->link;
            Node *del_node = temp->link;
            temp->link = del_node->link;
            delete del_node;
            print();
            return del_node;
        }
    }

    int get(int idx)
    {
        Node *temp = start;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->link;
        }
        return temp->item;
    }

    Node *find(int data)
    {
        Node *temp = start;
        int idx = 0;
        while (temp)
        {
            if (temp->item == data)
            {
                std::cout << "\nItem found at index " << idx << ".\n";
                return temp;
            }
            temp = temp->link;
            idx++;
        }
        std::cout << "\nItem does not exist.\n";
        return temp;
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

int main()
{
    LinkedList list;

    int ch, idx, data;
    do
    {
        std::cout << "\n1. Append\t2. Insert\t3. Delete\t4. Get\t5. Search\t6. Print\t7. END\n>>> ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            std::cout << "Enter integer to append: ";
            std::cin >> data;
            list.append(data);
            break;

        case 2:
            std::cout << "Enter index and integer to insert: ";
            std::cin >> idx >> data;
            list.insert(idx, data);
            break;

        case 3:
            std::cout << "Enter index to delete: ";
            std::cin >> idx;
            list.del(idx);
            break;

        case 4:
            std::cout << "Enter index: ";
            std::cin >> idx;
            std::cout << list.get(idx) << '\n';
            break;

        case 5:
            std::cout << "Enter integer to search for: ";
            std::cin >> data;
            list.find(data);
            break;

        case 6:
            list.print();
            break;
        }
    } while (ch != 7);
}
