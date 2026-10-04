#include <stdio.h>

int binarySearch(int patients[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (patients[mid] == key)
            return mid;

        if (patients[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int patients[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (patients[mid] == key)
        return mid;

    if (patients[mid] < key)
        return recursiveBinarySearch(patients, mid + 1, high, key);

    return recursiveBinarySearch(patients, low, mid - 1, key);
}

int main()
{
    int patients[10], n, key;

    printf("HOSPITAL PATIENT SEARCH\n");
    printf("-----------------------\n");

    printf("Enter number of patients: ");
    scanf("%d", &n);

    printf("Enter Patient IDs in sorted order:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &patients[i]);

    printf("Enter Patient ID to search: ");
    scanf("%d", &key);

    int result1 = binarySearch(patients, n, key);

    if (result1 != -1)
        printf("\nIterative Binary Search: Patient ID %d found at position %d.\n",
               key, result1 + 1);
    else
        printf("\nIterative Binary Search: Patient ID %d not found.\n", key);

    int result2 = recursiveBinarySearch(patients, 0, n - 1, key);

    if (result2 != -1)
        printf("Recursive Binary Search: Patient ID %d found at position %d.\n",
               key, result2 + 1);
    else
        printf("Recursive Binary Search: Patient ID %d not found.\n", key);

    return 0;
}