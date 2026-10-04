#include <stdio.h>

int binarySearch(int books[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (books[mid] == key)
            return mid;

        else if (books[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int books[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (books[mid] == key)
        return mid;

    else if (books[mid] < key)
        return recursiveBinarySearch(books, mid + 1, high, key);
        

    else
        return recursiveBinarySearch(books, low, mid - 1, key);
}

int main()
{
    int books[10], n, key;
    int result1, result2;

    printf("LIBRARY BOOK SEARCH\n");
    printf("-------------------\n");

    printf("Enter number of books: ");
    scanf("%d", &n);

    printf("Enter Book IDs in sorted order:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &books[i]);
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &key);

    result1 = binarySearch(books, n, key);

    if (result1 != -1)
        printf("\nIterative Binary Search: Book ID %d found at position %d.\n",
               key, result1 + 1);
    else
        printf("\nIterative Binary Search: Book ID %d not found.\n", key);

    result2 = recursiveBinarySearch(books, 0, n - 1, key);

    if (result2 != -1)
        printf("Recursive Binary Search: Book ID %d found at position %d.\n",
               key, result2 + 1);
    else
        printf("Recursive Binary Search: Book ID %d not found.\n", key);

    return 0;
}