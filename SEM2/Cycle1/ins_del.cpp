
#include <iostream>
using namespace std;

void printArray(int *data, int length)
{
    for (int var = 0; var < length; ++var)
    {
        cout << data[var] << " ";
    }
    cout << endl;
}

int insert(int *mainArray, int insertSize, int pos, int size)
{
    int totalSize = size + insertSize;
    int *tempArray = new int[totalSize];
    for (int var = 0; var < pos; ++var)
    {
        tempArray[var] = mainArray[var];
    }

    cout << "Enter the elements you want to insert" << endl;
    int loc;
    for (loc = pos; loc < (pos + insertSize); ++loc)
    {
        cin >> tempArray[loc];
    }
    for (int var = loc; var < totalSize; ++var)
    {
        tempArray[var] = mainArray[pos];
        pos++;
    }

    for (int var = 0; var < totalSize; ++var)
    {
        mainArray[var] = tempArray[var];
    }
    delete tempArray;
    return totalSize;
}

int deleteElement(int *mainArray, int length)
{
    if (length <= 0)
    {
        cout << "Out of Flow" << endl;
        return 0;
    }
    int searchKey;
    cout << "Enter the element you want to delete ?" << endl;
    cin >> searchKey;
    int var;
    for (var = 0; var < length; ++var)
    {
        if (mainArray[var] == searchKey)
        {
            break;
        }
    }
    if (var >= length)
    {
        cout << "Element Not Found" << endl;
        return -1;
    }

    int newSize = length - 1;
    int *tempArray = new int[newSize];
    for (int i = 0; i < var; ++i)
    {
        tempArray[i] = mainArray[i];
    }
    for (int j = var; j < newSize; ++j)
    {
        tempArray[j] = mainArray[j + 1];
    }

    for (int var = 0; var < newSize; ++var)
    {
        mainArray[var] = tempArray[var];
    }
    return newSize;
}

int main()
{
    int userSize;
    cout << "Enter the no of elements : ";
    cin >> userSize;

    int *array = new int[userSize];
    for (int var = 0; var < userSize; ++var)
    {
        cout << "Value " << var + 1 << " : ";
        cin >> array[var];
    }

    cout << "Input Array : ";
    printArray(array, userSize);
    cout << endl;

    int exitChoice = 1;
    while (exitChoice == 1)
    {
        int choice;
        cout << "1.Insert Element\n2.Delete Element" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int pos, size;
            cout << "Enter position where you want to insert" << endl;
            cin >> pos;
            if (pos >= userSize)
            {
                cout << "Array Overflow" << endl;
                break;
            }
            cout << "Enter size of insert" << endl;
            cin >> size;
            userSize = insert(array, size, pos, userSize);
            printArray(array, userSize);
            break;
        case 2:
            int x;
            x = deleteElement(array, userSize);
            if (x == -1)
            {
                break;
            }
            userSize = x;
            printArray(array, userSize);
            break;
        default:
            cout << "Invalid Statement" << endl;
            break;
        }
        cout << "\n1.Continue\n2.Exit" << endl;
        cin >> exitChoice;
    }
    cout << "Exit." << endl;
    return 0;
}
