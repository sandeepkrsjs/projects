#include <stdio.h>
#include <cs50.h>
#include<math.h>
int main(void)
{
    float amount, count=0;
    do
    {
        printf("o hai! how much change is owed?\n");
        amount= get_float();
    }
    while(amount<0);
    int amt = round(amount*100);
    while(amt/25>0)
    {
        count = count + (amt/25);
        amt = amt%25;
    }
    while(amt/10>0)
    {
        count = count + (amt/10);
        amt = amt%10;
    }
    while(amt/5>0)
    {
        count= count + (amt/5);
        amt= amt%5;
    }
    while(amt/1>0)
    {
        count= count + (amt/1);
        amt= amt%1;
    }
    printf("%.0f\n",count);
}