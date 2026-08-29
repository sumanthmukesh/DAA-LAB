#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

int hashFunction(int key)
{

    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

int search(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return 0;
}

int main()
{
    int n, T, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    printf("Enter target value T: ");
    scanf("%d", &T);

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
        {
            int required = T - hashTable[i];

            if (search(required) && required != hashTable[i])
            {
                printf("Pair found: %d + %d = %d\n",
                       hashTable[i], required, T);
                return 0;
            }
        }
    }

    printf("No pair found\n");

    return 0;
}