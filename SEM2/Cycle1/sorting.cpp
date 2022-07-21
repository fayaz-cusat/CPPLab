#include <iostream>

int selection_sort(int *arr, int N)
{
    int i, j, min_idx, temp;
    for (i = 0; i < N; i++)
    {
        min_idx = i;
        for (j = i + 1; j < N; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    return 0;
}

int bubble_sort(int *arr, int N)
{
    int i, j, temp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

int insertion_sort(int *arr, int N)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = temp;
    }
    return 0;
}

class MergeSort
{
    static int merge(int *arr, int left, int right, int mid)
    {
        int i, j, n;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int *split1 = new int[n1];
        int *split2 = new int[n2];

        for (i = 0; i < n1; i++)
            split1[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            split2[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;

        while (i < n1 && j < n2)
        {
            if (split1[i] <= split2[j])
            {
                arr[n] = split1[i];
                i++;
            }
            else
            {
                arr[n] = split2[j];
                j++;
            }
            n++;
        }

        while (i < n1)
        {
            arr[n] = split1[i];
            i++;
            n++;
        }

        while (j < n2)
        {
            arr[n] = split2[j];
            j++;
            n++;
        }
        delete split1;
        delete split2;
    }

    static void merge_sort(int *arr, int left, int right)
    {
        if (left >= right)
            return;

        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
};

void print(int *arr, int N)
{
    for (int i = 0; i < N; std::cout << arr[i++] << ' ');
}

int main()
{
    int ch, N;
    std::cout << "Enter length of array: ";
    std::cin >> N;
    int *orig = new int[N];
    int *arr = new int[N];
    std::cout << "Enter array elements: ";
    for (int i = 0; i < N; i++)
        std::cin >> orig[i];
        std::cin >> arr[i];
    do
    {
        std::cout << "1. Selection sort\t2. Bubble sort\t3. Insertion sort\t4. Merge sort\t5. END\n>>> ";
        std::cin >> ch;
        switch (ch)
        {
            case 1:
                selection_sort(arr, N)
                
        }
    }
}
