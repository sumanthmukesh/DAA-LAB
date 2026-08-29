#include <stdio.h>

#define SIZE 10

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
    printf("%d inserted at index %d\n", key, index);
}


void search(int key)
{
    int index = hashFunction(key);
    

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            printf("%d found at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        
    }

    printf("%d not found in hash table\n", key);
}


void display()
{
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d : Empty\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int choice, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    while (1)
    {
        printf("\n--- HASH TABLE ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}