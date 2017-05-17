/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

unsigned int no_of_words = 0;
node *root = NULL;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //iterating over each letter of the word
    node *cursor = root;
    for(int i=0, n = strlen(word); i<n; i++)
    {
        char letter = word[i];
        char ch = tolower(letter);
        int index = ch - 97;
        //if not find the word, return false
        if(cursor->children[index] == NULL)
        {
            return false;
        }
        else
        {
            cursor = cursor->children[index];
        }
    }
    //if find the word, return true
    if(cursor->is_word == true)
        return true;
    else
        return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */


bool load(const char *dictionary)
{
    //allocating memory to root node
    root = malloc(sizeof(node));
    
    //setting all the variable and pointer to 0
    memset(root, 0, sizeof(node));
    
    //opening dictionary
    FILE *dict = fopen(dictionary, "r");
    
    //if not allocated memory to root
    if(root==NULL)
    {
        fprintf(stderr, "cann't load memory to root\n");
        return false;
    }
    
    char *word = malloc((LENGTH+1)*sizeof(char));
    
    //scaning each letter of the word
    while(fscanf(dict , "%s", word)!=EOF)
    {
        node *cursor = root;
        
        //iterating over each word
        for(int i=0, n=strlen(word); i<n; i++)
        {
            char ch = word[i];
            int index = ch-97;
            if(cursor->children[index] == NULL)
            {
                node *child = malloc(sizeof(node));
                memset(child, 0 , sizeof(node));
                if (child == NULL)
                {
                    fprintf(stderr, "could not allocate memory to child\n");
                    return false;
                }
                cursor->children[index] = child;
                cursor = cursor->children[index];
                child = NULL;
            }
            else
                cursor = cursor->children[index];
        }
        //if the word loade, return true
        cursor->is_word = true;
        
        //for calculating the number of word loaded
        no_of_words++;
        
    }
    free(word);
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    //if dictionary not loaded, return false
    if(root == NULL)
    {
        return 0;
    }
    
    //returning number of words in dictionary
    else
        return no_of_words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */

bool unload(void)
{
    //another pointer that points to root
    node *head = root;
    free_nodes(head);
    return true;
}
void free_nodes(node* ptr)  
{
    if(ptr!=NULL)
    {
        // Go through node's children
        for (int i = 0; i < 27; i++)
        {
            // If child is pointer, recursively check that one as well
            if (ptr->children[i] != NULL) 
            {
                free_nodes(ptr->children[i]);
            }
        }
        // If all chilren are null, free node
        free(ptr);
        
        //setting the pointer to null
        ptr = NULL;
    }
    
}

            