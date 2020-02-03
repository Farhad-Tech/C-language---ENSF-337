/* File: palindrome.c
 *  ENSF 337 - Fall 2018
 *  Exercise E - Lab 3
 *  Abstract: The program receives a string (one or more words) and indicates
 *  if the string is a palindrome or not. Plaindrome is a phrase that spells the
 *  same from both ends
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


/* function prototypes*/
int is_palindrome (const char *str);
/* REQUIRES: str is pointer to a valid C string.
 * PROMISES: the return value is 1 if the string a is palindrome.*/


void strip_out(char *str);
/* REQUIRES: str points to a valid C string terminated with '\0'.
 * PROMISES: strips out any non-alphanumerical characters in str*/

int main(void)
{

    int p =0;
    char str[SIZE], temp[SIZE];
    

    FILE* fid=fopen("palindrome.txt","r");
    fgets(str, SIZE, fid);

    /* Remove end-of-line character if there is one in str.*/
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    strcpy(temp,str);

    /* This loop is infinite if the string "done" never appears in the
     * input.  That's a bit dangerous, but OK in a test harness where
     * the programmer is controlling the input. */
    
    while(strcmp(str, "done") !=0) /* Keep looping unless str matches "done". */
    {
        
#if 1

    		strip_out(str);
        p = is_palindrome(str);

#endif

        if(!p)
            printf("\n \"%s\" is not a palindrome.", temp);
        else
            printf("\n \"%s\" is a palindrome.", temp);
        
        fgets(str, SIZE, fid);
        
        /* Remove end-of-line character if there is one in str.*/
        if(str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1]= '\0';
        strcpy(temp, str);
    }
    
    return 0;
}

int is_palindrome (const char *str)
{

	char lowerstr[strlen(str)], check[strlen(str)];





	for(int i=0 ; i<strlen(str); i++ )
	{
		if((isupper(str[i])==1)) {
			lowerstr[i]=tolower(str[i]);

		}
		else if ((isupper(str[i])!=1)) {
			lowerstr[i]=str[i];

		}

	}
	lowerstr[strlen(str)]='\0';
	check[strlen(str)]='\0';


		for (int i=0 , j=strlen(str)-1; i<strlen(str); i++, j--)
	{
		check[j]=lowerstr[i];

	}





return !(strcmp(lowerstr,check));
}

void strip_out(char *str)
{

for (int i=0; i<strlen(str);i++)
{




	if ((isalnum(str[i]))==0)
			{

		if (i==(strlen(str)-1))
		{

			str[i]='\0';
		}
		for(int j=0; j<strlen(str); j++)
			{
			str[i+j]=str[i+j+1];
			}
				i--;
			}



}

}



