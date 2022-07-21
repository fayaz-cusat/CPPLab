class Node
{
public:
    int item;
    Node *left;
    Node *right;

    Node(int data)
    {
        item = data;
        left = NULL;
        right = NULL;
    }
}

class BinaryTree
{
    Node *head = NULL;

    Node *add_item(int data)
    {
        if (!head)
        {
            head  = new Node(data);
            return head;
        }
        Node *temp = head;
        while (true)
        {
            if (data > temp -> item)
            {
                if (!temp -> right)
                {
                    temp -> right = new Node(data);
                    return temp -> right;
                }
                else
                    temp = temp -> right;
            }
            else
            {
                if (!temp -> left)
                {
                    temp -> left = new Node(data);
                    return temp -> left;
                }
                else
                    temp = temp -> left;
            }
        }
    }
}

void print_tree(BinaryTree &tree)
{
    Node *temp = tree.head;
    while(temp)
    {
        std::cout << temp -> item << ' ';
        if (temp -> left)
            std::cout << temp -> left -> item;
        
        if (temp -> right)
            std::cout << temp -> right -> item;
    }
}
