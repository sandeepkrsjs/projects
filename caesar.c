#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc , string argv[])
{
    //if the number of command line argument is more or less than 2
    if(argc!=2)
    {
        printf("error\n");
        return(1);
    }
    //if exactly 2 command line argument is given
    else
    {
        //converting key argument from string to int
        int k = atoi(argv[1]);
        //prompt for user
        printf("plaintext:  ");
        string s = get_string();
        printf("ciphertext: ");
        //iterating to each character of string
        for(int i=0, n = strlen(s); i<n; i++)
        {
            //if the given character is letter
            if(isalpha(s[i]))
            {
                //if the character is in uppercase
                if(isupper(s[i]))
                {
                    //calculating encrypted character and printing it
                    int x = (((s[i]-65)+k)%26);
                    char c = x + 65;
                    printf("%c",c);
                }
                //if character is in lower case
                if(islower(s[i]))
                {
                    //calculating encrypted character and printing it
                    int x = (((s[i]-97)+k)%26);
                    char c = x+97;
                    printf("%c",c);
                }
            }
            //if the given character is not letter that means symbol or number
            else
            {
                printf("%c",s[i]);
            }
        }
        //printing a new line at the end and returning 0 to main     
        printf("\n");
        return(0);
    }
}