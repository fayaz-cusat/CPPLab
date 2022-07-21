#include <iostream>

int linear_search(int *arr, int N, int item)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == item)
        {
            std::cout << "Found item at index " << i << ".\n";
            return i;
        }
    }
    std::cout << "Item does not exist.\n";
    return -1;
}

int binary_search(int *arr, int N, int item)
{
    int mid, low = 0, high = N - 1;
    while (low != high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == item)
        {
            std::cout << "Found item at index " << mid << ".\n";
            return mid;
        }
        else if (arr[mid] > item)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (arr[high] == item)
    {
        std::cout << "Found item at index " << high << ".\n";
        return high;
    }
    std::cout << "Item does not exist.\n";
    return -1;
}

int ternary_search(int *arr, int N, int item)
{
    int mid1, mid2, low = 0, high = N - 1;
    while (low != high)
    {
        mid1 = (low + high) / 3;
        mid2 = 2 * mid1;
        if (arr[mid1] == item)
        {
            std::cout << "Found item at index " << mid1 << ".\n";
            return mid1;
        }
        if (arr[mid2] == item)
        {
            std::cout << "Found item at index " << mid2 << ".\n";
            return mid2;
        }
        if (item < arr[mid1])
            high = mid1 - 1;
        else if (item > arr[mid2])
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    if (arr[high] == item)
    {
        std::cout << "Found item at index " << high << ".\n";
        return high;
    }
    std::cout << "Item does not exist.\n";
    return -1;
}

int interpolation_search(int *arr, int N, int item)
{
    int pos, low = 0, high = N - 1;
    while (low != high)
    {
        pos = low + (((item - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[pos] == item)
        {
            std::cout << "Found item at index " << pos << ".\n";
            return pos;
        }
        if (arr[pos] < item)
            low = pos + 1;
        else
            high = pos - 1;
    }
    if (arr[high] == item)
    {
        std::cout << "Found item at index " << high << ".\n";
        return high;
    }
    std::cout << "Item does not exist.\n";
    return -1;
}

int fibonacci_search(int *arr, int N, int item)
{
    int fibm1 = 0;
    int fibm2 = 1;
    int fib = 1;

    while (fib < N)
    {
        fibm2 = fibm1;
        fibm1 = fib;
        fib = fibm2 + fibm1;
    }

    int offset = -1;

    while (fib > 1)
    {
        int i = (offset + fibm2) > (N - 1) ? (N - 1) : (offset + fibm2);

        if (arr[i] == item)
        {
            std::cout << "Found item at index " << i << ".\n";
            return i;
        }
        if (arr[i] < item)
        {
            fib = fibm1;
            fibm1 = fibm2;
            fibm2 = fib - fibm1;
            offset = i;
        }
        else
        {
            fib = fibm2;
            fibm1 = fibm1 - fibm2;
            fibm2 = fib - fibm1;
        }
    }

    if (fibm1 && arr[offset + 1] == item)
    {
        std::cout << "Found item at index " << offset + 1 << ".\n";
        return offset + 1;
    }

    std::cout << "Item does not exist.\n";
    return -1;
}

int main()
{
    int N, prev, ch, item;

    std::cout << "Enter number of elements: ";
    std::cin >> N;

    int *arr = new int[N];
    std::cout << "Enter elements: ";
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        if (i > 0)
            if (arr[i] < arr[i - 1])
            {
                std::cout << "Array must be sorted in ascending order.\n";
                break;
            }
    }

    do
    {
        std::cout << "1. Linear search\t2. Binary search\t3. Ternary search\t4. Interpolation search\t5. Fibonacci search\t6. END\n>>> ";
        std::cin >> ch;
        if (ch == 6)
            break;
        std::cout << "Enter item to search for: ";
        std::cin >> item;
        switch (ch)
        {
        case 1:
            linear_search(arr, N, item);
            break;
        case 2:
            binary_search(arr, N, item);
            break;
        case 3:
            ternary_search(arr, N, item);
            break;
        case 4:
            interpolation_search(arr, N, item);
            break;
        case 5:
            fibonacci_search(arr, N, item);
            break;
        }
    } while (true);
}
