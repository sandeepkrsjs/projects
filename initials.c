#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    //ask user for input
    string s = get_string();
    //make sure a string is given as input
    if(s!=NULL)
    {
        //print first vharacter of the string
        printf("%c",toupper(s[0]));
        //iterate over each character in the string
        for(int i=0, n=strlen(s); i<n; i++)
        {
            //enter into this, if a space id typed
            if(s[i]==32)
            {
                //print the upper case of character after the space
                printf("%c",toupper(s[i+1]));
            }
        }
        printf("\n");
    }
}