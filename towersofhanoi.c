#include <stdio.h>

#define MAX 20

int stack[3][MAX];
int top[3] = {-1, -1, -1};

void push(int rod, int disk)
{
    top[rod]++;
    stack[rod][top[rod]] = disk;
}

int pop(int rod)
{
    int disk = stack[rod][top[rod]];
    top[rod]--;
    return disk;
}

void moveDisk(int from, int to, char names[])
{
    int disk;

    if (top[from] == -1)
    {
        disk = pop(to);
        push(from, disk);

        printf("Move disk %d: %c -> %c\n",
               disk, names[to], names[from]);
    }

    else if (top[to] == -1)
    {
        disk = pop(from);
        push(to, disk);

        printf("Move disk %d: %c -> %c\n",
               disk, names[from], names[to]);
    }

    
    else if (stack[from][top[from]] < stack[to][top[to]])
    {
        disk = pop(from);
        push(to, disk);

        printf("Move disk %d: %c -> %c\n",
               disk, names[from], names[to]);
    }
    else
    {
        disk = pop(to);
        push(from, disk);

        printf("Move disk %d: %c -> %c\n",
               disk, names[to], names[from]);
    }
}

int main()
{
    int n, i;
    char names[] = {'A', 'B', 'C'};
    printf("Enter number of disks: ");
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        push(0, i);
    }

    int totalMoves = (1 << n) - 1;

    for (i = 1; i <= totalMoves; i++)
    {
        if (n % 2 == 1)
        {
            if (i % 3 == 1)
            {
                moveDisk(0, 2, names);
            }
            else if (i % 3 == 2)
            {
                moveDisk(0, 1, names);
            }
            else
            {
                moveDisk(1, 2, names);
            }
        }
        else
        {
            if (i % 3 == 1)
            {
                moveDisk(0, 1, names);
            }
            else if (i % 3 == 2)
            {
                moveDisk(0, 2, names);
            }
            else
            {
                moveDisk(1, 2, names);
            }
        }
    }

    return 0;
}