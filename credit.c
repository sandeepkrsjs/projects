#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int a,b,c,d,sum=0,first=-1;
    printf("Number : ");
    long long cc_no = get_long_long();
    do
    {
        a=cc_no%10;
        cc_no=cc_no/10;
        if(cc_no==0)
        {
            first=a;
        }
        b=cc_no%10;
        cc_no=cc_no/10;
        if(cc_no==0 && a!=first)
        {
            first=b;
        }
        d=b*2;
        c=(d/10)+(d%10);
        sum=sum+a+c;
    }
    while(cc_no>0);

    if(sum%10==0)
    {
        switch(first)
        {
            case 3:
                printf("AMEX\n");
                break;
            case 4:
                printf("VISA\n");
                break;
            case 5:
                printf("MASTERCARD\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}