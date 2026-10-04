#include <stdio.h>

int binarySearch(int seats[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (seats[mid] == key)
            return mid;

        if (seats[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int seats[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (seats[mid] == key)
        return mid;

    if (seats[mid] < key)
        return recursiveBinarySearch(seats, mid + 1, high, key);

    return recursiveBinarySearch(seats, low, mid - 1, key);
}

int main()
{
    int seats[10], n, key;

    printf("COLLEGE SEAT NUMBER SEARCH\n");
    printf("--------------------------\n");

    printf("Enter number of seats: ");
    scanf("%d", &n);

    printf("Enter Seat Numbers in sorted order:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &seats[i]);

    printf("Enter Seat Number to search: ");
    scanf("%d", &key);

    int result1 = binarySearch(seats, n, key);

    if (result1 != -1)
        printf("\nIterative Binary Search: Seat Number %d found at position %d.\n",
               key, result1 + 1);
    else
        printf("\nIterative Binary Search: Seat Number %d not found.\n", key);

    int result2 = recursiveBinarySearch(seats, 0, n - 1, key);

    if (result2 != -1)
        printf("Recursive Binary Search: Seat Number %d found at position %d.\n",
               key, result2 + 1);
    else
        printf("Recursive Binary Search: Seat Number %d not found.\n", key);

    return 0;
}