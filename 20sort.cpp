#include <iostream>
using namespace std;

const int n = 10;

void merge(int *arr, int start, int mid, int end)
{
    int temp[(end - start) + 1] = {0};
    int left = start;
    int right = mid + 1;
    int index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++;
        }
        else
        {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while (left <= mid)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }

    while (right <= end)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }

    index = 0;

    while (start <= end)
    {
        arr[start] = temp[index];
        start++;
        index++;
    }
    return;
}

void mergeSort(int *arr, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int mid = start + (end - start) / 2;

    // left part
    mergeSort(arr, start, mid);

    // right part
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);

    return;
}

const int capacity = n;
int lowerStack[capacity];
int upperStack[capacity];
int lowerTos = -1;
int upperTos = -1;

bool checkUnderflow(int &tos)
{
    return (tos == -1);
}

bool checkOverflow(int &tos)
{
    return (tos == (capacity - 1));
}

int popStack(int *stack, int &tos)
{

    if (checkUnderflow(tos))
    {
        cout << "Stack Underflow!";
        return -1;
    }
    int data = stack[tos];
    tos--;
    return data;
}

void pushStack(int *stack, int element, int &tos)
{
    if (checkOverflow(tos))
    {
        cout << "Stack Overflow!";
        return;
    }
    tos++;
    stack[tos] = element;
    return;
}

void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int quick(int *arr, int size, int start, int end, int pivot)
{
    int left = start;
    int right = end;

    while (pivot != left || pivot != right)
    {
        // right to left
        while (arr[pivot] <= arr[right] && pivot != right)
        {
            right--;
        }
        if (pivot == right)
        {
            return pivot;
        }
        swapElements(arr[pivot], arr[right]);
        pivot = right;
        // left to right
        while (arr[pivot] >= arr[left] && pivot != left)
        {
            left++;
        }
        if (pivot == left)
        {
            return pivot;
        }
        swapElements(arr[pivot], arr[left]);
        pivot = left;
    }
    return pivot;
}

void quickSort(int *arr, int size)
{
    int beg = 0;
    int end = 0;
    int loc = 0;
    if (size > 1)
    {
        pushStack(lowerStack, 0, lowerTos);
        pushStack(upperStack, size - 1, upperTos);
    }
    while (lowerTos != -1)
    {
        beg = lowerStack[lowerTos];
        popStack(lowerStack, lowerTos);
        end = upperStack[upperTos];
        popStack(upperStack, upperTos);
        loc = quick(arr, size, beg, end, beg);

        if (beg < loc - 1)
        {
            pushStack(lowerStack, beg, lowerTos);
            pushStack(upperStack, loc - 1, upperTos);
        }
        if (end > loc + 1)
        {
            pushStack(lowerStack, loc + 1, lowerTos);
            pushStack(upperStack, end, upperTos);
        }
    }
    return;
}

int main()
{
    int arr[n] = {0};
    cout << "\nEnter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nArray is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int choice = 0;
    do
    {
        cout << "\n1. Merge Sort\n2. Quick Sort\n3. Exit";
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            mergeSort(arr, 0, n - 1);
            cout << "\nSorted array : ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            break;

        case 2:
            quickSort(arr, n);
            cout << "\nSorted array : ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            break;

        case 3:
            break;

        default:
            cout << "Invalid option! try again";
        }
    } while (choice != 3);
    return 0;
}