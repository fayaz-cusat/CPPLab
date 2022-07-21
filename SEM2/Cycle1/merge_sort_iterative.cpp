#include <iostream>

int min(int x, int y) { return x < y ? x : y; }

class MergeSort
{
public:
    static int mergesort(int *arr, int n)
    {
        for (int curr_size = 1; curr_size < n; curr_size *= 2)
        {
            for (int left = 0; left < n - 1; left += 2 * curr_size)
            {
                int mid = min(left + curr_size - 1, n - 1);
                int right = min(left + 2 * curr_size - 1, n - 1);

                merge(arr, left, mid, right);
            }
        }
        return 0;
    }

    static int merge(int *arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int *L = new int[n1];
        int *R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k] = L[i++];
            else
                arr[k] = R[j++];
            k++;
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];

        delete[] L;
        delete[] R;
        return 0;
    }
};

int main()
{
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    int *arr = new int[n];
    std::cout << "Enter a list of integers: ";
    for (int i = 0; i < n; std::cin >> arr[i++])
        ;

    MergeSort::mergesort(arr, n);
    for (int i = 0; i < n; std::cout << arr[i++] << ' ')
        ;
}
