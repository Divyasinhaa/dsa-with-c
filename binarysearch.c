#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int n);
void choose(int *arr, int *n);
void option(int c, int *arr, int *n);
void insertion(int *arr, int *n, int e, int v);

// Function to insert an element at a specified position
void insertion(int *arr, int *n, int e, int v)
{
    if (e < 0 || e > *n + 1)
    {
        printf("Invalid Position.\n");
        return;
    }

    // Shift elements to make space for the new element
    for (int i = *n; i > e; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[e] = v;
    (*n)++;
    printf("Element Inserted Successfully!\n");
}

void Deletion(int *arr, int *n, int d)
{

    int flag = 0;
    for (int i = 0; i < *n; i++)
    {
        if (d == arr[i])
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("The Element is not Present in the Array\n");
        return;
    }

    // Shift elements one position forward to remove the deleted element
    for (int j = d - 1; j < *n - 1; j++)
        arr[j] = arr[j + 1];
    (*n)--;
    printf("Element Deleted Successfully!\n");
}

int BinarySearch(int arr[], int k, int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == k)
            return printf("%d at  Index %d ", k, m);
        else if (arr[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int LinearSearch(int arr[], int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return printf("%d at  index %d ", k, i);
    }
    return -1;
}

// Function to print the array elements
void printArray(int arr[], int n)
{
    printf("\nThe entered array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

// Function to handle the user's menu choice
void choose(int *arr, int *n)
{
    int c;

    printf("\n\nEnter the Choice for Array: \n");
    printf("1 for Insertion\n");
    printf("2 for Deletion\n");
    printf("3 for Display the Array\n");
    printf("4 for Binary Search to find the Element in the Array \n");
    printf("5 for Linear Search to find the Element in the Array \n");
    printf("0 for Exit from Program \n");
    scanf("%d", &c);

    if (c == 0)
    {
        printf("Exiting program.\n");
        exit(0);
    }

    option(c, arr, n);
}


// Function to handle user's choice
void option(int c, int *arr, int *n)
{
    int e, v;

    switch (c)
    {
    case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &v);
        printf("At which position do you want to insert it?\n");
        printf("Enter the position: ");
        scanf("%d", &e);
        insertion(arr, n, e, v);
        break;
    case 2:
        printf("Enter the index of the element to delete: ");
        scanf("%d", &e);
        Deletion(arr, n, e);
        break;
    case 3:
        printArray(arr, *n);
        break;
    case 4:
        printf("Enter Your Key : ");
        scanf("%d", &e);
        BinarySearch(arr, e, *n);
        break;
    case 5:
        printf("Enter Your Key : ");
        scanf("%d", &e);
        LinearSearch(arr, e, *n);
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
}


int main()
{
    int n;

    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    printf("Enter %d integers for the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Displaying entered numbers
    printArray(arr, n);

    // Choice of array operations
    while (1)
    {
        choose(arr, &n);
    }

    // Free allocated memory before exiting
    free(arr);

    return 0;
}