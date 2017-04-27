#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //if the number of command line argument is more or less than 2
    if(argc != 2)
    {
        printf("error\n");
        return(1);
    }
    //if exactly 2 command line argument is given
    else
    {
        int key_len = strlen(argv[1]);
        //iterating over each character of key
        for(int i=0; i<key_len; i++)
        {
            //if key is in upper case
            if(isupper(argv[1][i]))
            {
                argv[1][i]=argv[1][i]-65;
            }
            //if key is in lower case
            else if(islower(argv[1][i]))
            {
                argv[1][i]=argv[1][i]-97;
            }
            else
            {
                printf("error\n");
                return(1);
            }
        }
        printf("plaintext:  ");
        //prompt for user
        string s= get_string();
        printf("ciphertext: ");
        int txt_len = strlen(s);
        int count=0;
        //iterating over each character of string
        for(int i=0; i<txt_len; i++)
        {
            int j = (i-count) % key_len;
            //if string is in upper case
            if(isupper(s[i]))
            {
                //calculating encrypted character and printing it
                int p = (((s[i]-65)+argv[1][j])%26);
                char c = p + 65;
                printf("%c",c);
            }
            //if string is in lower case
            else if(islower(s[i]))
            {
                //calculating encrypted character and printing it
                int p = (((s[i]-97)+argv[1][j])%26);
                char c = p + 97;
                printf("%c",c);
            }
            //if string is not letter
            else
            {
                count++;
                printf("%c",s[i]);
                
            }
        }
        printf("\n");
        return(0);
    }
}