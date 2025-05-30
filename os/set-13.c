
// SSTF*********************************************

#include <stdio.h>
int absolute(int a, int b)
{
    int c;
    c = a - b;
    if (c < 0)
        return -c;
    else
        return c;
}
int main()
{
    int choice, m, n, x, start, i, j, pos, min, a[15], count;
    count = 0;
    printf("\nEnter the number of cylinders :");
    scanf("%d", &m);
    printf("\nEnter the number of requests :");
    scanf("%d", &n);
    printf("\nEnter current position :");
    scanf("%d", &start);
    printf("\nEnter the request queue :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if (a[i] >= m)
        {
            printf("\ninvalid input");
            scanf("%d", &a[i]);
        }
    }
    do
    {
        printf("\n\nDISK SCHEDULING ALGORITHMS\n1. FCFS\n2. SSTF\n3. SCAN\n4. CSCAN\n5. LOOK\n6. C-LOOK");
        printf("\nEnter choice :");
        scanf("%d", &choice);
        count = 0;
        x = start;
        switch (choice)
        {
        case 1:
            printf("\nFCFS :\n");
            printf("Scheduling services the request in the order that follows:\n%d\t", start);
            for (i = 0; i < n; i++)
            {
                x -= a[i];
                if (x < 0)
                    x = -x;
                count += x;
                x = a[i];
                printf("%d\t", x);
            }
            printf("\nTotal Head Movement :%d Cylinders", count);
            break;

        case 2:
            printf("\nSSTF :\n");
            printf("Scheduling services the request in the order that follows:\n%d\t", start);
            for (i = 0; i < n; i++)
            {
                min = absolute(a[i], x);
                pos = i;
                for (j = i; j < n; j++)
                    if (min > absolute(x, a[j]))
                    {
                        pos = j;
                        min = absolute(x, a[j]);
                    }
                count += absolute(x, a[pos]);
                x = a[pos];
                a[pos] = a[i];
                a[i] = x;
                printf("%d\t", x);
            }
            printf("\nTotal Head Movement: %d Cylinders", count);
            break;
        case 3:
            printf("\nSCAN :\n");
            printf("Scheduling services the request in the order that follows:\n");
            count = 0;
            pos = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n - i - 1; j++)
                    if (a[j] > a[j + 1])

                    {
                        x = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = x;
                    }
            for (i = 0; i < n; i++)
                if (a[i] < start)
                    pos++;
            for (i = 0; i < pos; i++)
                for (j = 0; j < pos -
                                    i - 1;
                     j++)
                    if (a[j] < a[j + 1])
                    {
                        x = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = x;
                    }
            x = start;
            printf("%d\t", x);
            for (i = 0; i < pos; i++)
            {
                count += absolute(a[i], x);
                x = a[i];
                printf("%d\t", x);
            }
            count += absolute(x, 0);
            x = 0;
            printf("%d\t", x);
            for (i = pos; i < n; i++)

            {
                count += absolute(a[i], x);
                x = a[i];
                printf("%d\t", x);
            }
            /*for(i=0;i<n;i++)
            printf("%d\t",a[i]);*/
            printf("\nTotal Head Movement: %d Cylinders", count);
            break;
        case 4:
            printf("\nC-SCAN :\n");
            printf("Scheduling Services the request in the order that follows:\n%d\t", start);
            count = 0;
            pos = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n - i - 1; j++)
                    if (a[j] > a[j + 1])
                    {
                        x = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = x;
                    }
            for (i = 0; i < n; i++)
                if (a[i] < start)
                    pos++;
            x = start;
            for (i = pos; i < n; i++)
            {
                count += absolute(x, a[i]);

                x = a[i];
                printf("%d\t", x);
            }
            count += absolute(m - 1, x);
            x = 0;
            printf("%d\t%d\t", m - 1, 0);
            for (i = 0; i < pos; i++)
            {
                count += absolute(x, a[i]);
                x = a[i];
                printf("%d\t", x);
            }
            /*for(i=0;i<n;i++)
            printf("%d\t",a[i]);*/
            printf("\nTotal Head movement: %d Cylinders", count);
            break;
        case 5:
            printf("\nLOOK :\n");
            printf("\nScheduling services the request in the order as follows :\n%d\t", start);
            count = 0;
            pos = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n - i - 1; j++)
                    if (a[j] > a[j + 1])
                    {
                        x = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = x;
                    }
            for (i = 0; i < n; i++)
                if (a[i] < start)
                    pos++;
            for (i = 0; i < pos; i++)
                for (j = 0; j < pos - i - 1; j++)
                    if (a[j] < a[j + 1])
                    {
                        x = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = x;
                    }
            x = start;
            for (i = 0; i < pos; i++)
            {
                count += absolute(a[i], x);
                x = a[i];
                printf("%d\t", x);
            }
            for (i = pos; i < n; i++)
            {
                count += absolute(a[i], x);
                x = a[i];
                printf("%d\t", x);
            }
            printf("\nToal Head Movement: %d Cylinders", count);
            break;
        case 6:
            printf("\nC-LOOK :\n");

            printf("Scheduling Services the request in the order that follows:\n%d\t", start);
            count = 0;
            pos = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n - i - 1; j++)
                    if (a[j] > a[j + 1])
                    {
                        x = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = x;
                    }
            for (i = 0; i < n; i++)
                if (a[i] < start)
                    pos++;
            x = start;
            for (i = pos; i < n; i++)
            {
                count += absolute(x, a[i]);
                x = a[i];
                printf("%d\t", x);
            }
            for (i = 0; i < pos; i++)
            {
                count += absolute(x, a[i]);
                x = a[i];
                printf("%d\t", x);
            }
            /*for(i=0;i<n;i++)
            53
            printf("%d\t",a[i]);*/
            printf("\nTotal Head movement: %d Cylinders", count);
            break;
        }
        printf("\nDo you want to continue(1 to continue) :");
        scanf("%d", &choice);
    } while (choice == 1);
}
