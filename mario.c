#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height= get_int();
    }
    while(height<0 || height>23);
    for(int i=1; i<=height; i++)
    {
        for(int x=1; x<=height-i; x++)
        {
            printf(" ");
        }
        for(int y=1; y<=i+1; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}
