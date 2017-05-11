#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include<cs50.h>

#define BLOCKSIZE 512

int main(int argc, char* argv[])
{
    //checking for proper use
    if (argc !=2)
    {
        fprintf(stderr, "usage: ./recover fileToBeRecovered\n");
        return 1;
    }
    
    //oprning the card file
    FILE *inptr = fopen(argv[1], "r");
    
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    unsigned char *block = malloc(BLOCKSIZE * sizeof(char));
    if(block==NULL)
    {
        free(block);
        fprintf(stderr,"could not allocate memory to buffer\n");
    }
    FILE *img = NULL;
    char filename[8];
    int check = 0, count = 0;
    
    while(fread(block, BLOCKSIZE * sizeof(char), 1, inptr)==1)    //making sure there is bytes to read
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)      //checking jpeg header format
        {
            if(check) //checking existence of previous file
            {
                fclose(img);
                count++;
            }
            check++;
            sprintf(filename, "%03i.jpg", count);    //filename of jpeg
            img = fopen(filename, "w");             //opening outfile
            fwrite(block, BLOCKSIZE * sizeof(char), 1, img);   //writing into outfile
        }
        else
        {
            if(check)
            {
                fwrite(block, BLOCKSIZE * sizeof(char), 1, img);
            }
        }
    }
    free(block);
    
    fclose(inptr);
    return 0;
}