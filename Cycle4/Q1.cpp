#include <iostream>

int *insert(int *arr, int &size, int idx, int val)
{
    size++;
    int *new_arr = new int[size];

    for (int i = 0; i < idx; i++)
        new_arr[i] = arr[i];

    new_arr[idx] = val;

    for (int i = idx; i < size; i++)
        new_arr[i + 1] = arr[i];

    delete[] arr;
    return new_arr;
}

int *del(int *arr, int &size, int idx)
{
    size--;
    int *new_arr = new int[size];

    for (int i = 0; i < idx; i++)
        new_arr[i] = arr[i];

    for (int i = idx + 1; i < size; i++)
        new_arr[i - 1] = arr[i];

    delete[] arr;
    return new_arr;
}

int main()
{
    int size, ch;

    std::cout << "Enter number of elements: ";
    std::cin >> size;

    int *arr = new int[size];

    std::cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    do
    {
        std::cout << "1. Insert element\t2. Delete element\t3. Show elements\t4. END\n>>> ";
        std::cin >> ch;
        if (ch == 1)
        {
            int idx, val;
            std::cout << "Enter index: ";
            std::cin >> idx;
            std::cout << "Enter value: ";
            std::cin >> val;
            arr = insert(arr, size, idx, val);
        }
        else if (ch == 2)
        {
            int idx;
            std::cout << "Enter index: ";
            std::cin >> idx;
            arr = del(arr, size, idx);
        }
        else if (ch == 3)
        {
            for (int i = 0; i < size; i++)
                std::cout << arr[i] << ' ';
            std::cout << '\n';
        }
        else
        {
            break;
        }
    } while (true);
}
