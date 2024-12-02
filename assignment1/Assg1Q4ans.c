#include <stdio.h>

/*
Student number: A0287336U
Student name: Yang Hanming
Tutorial group: 10
*/

int func(int arg) {
    int i = 32; // t0
    int count = 0; // v0
    while (1) 
    {
        if (arg >= 0)
        {
            count++;
            i--;
        } else
        {
            i--;
        }
        if (i == 0) break;
        arg <<= 1;
    }
    return count;
}

int main(void)
{
    for (int i = -10; i < 10; i++)
    {
        printf("%d\n", func(i));
    }
    return 0;
}
