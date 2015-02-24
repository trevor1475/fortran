//Trevor Livingston - 4to95.c - Feb 4/15
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = stdin;
    char current;
    char prev = '\n';
    char equals[5];
    int equalsCount = 0;
    
    if(!fp)
	{
		return 0;
	}
	
	//use redirection
	while((current = fgetc(fp)) != EOF)
	{
	    if((int)current >= 65 && (int)current <=90)
	    {
	        //upper to lower, ascii manipulation
	        current += 32;
	    }
	    if(prev == '\n' && current == 'c')
	    {
	        //proper commenting for fortran 95
	        current = '!';
	    }
	    if((prev == ' ' && (int)current == 46) || equalsCount > 0)
	    {
	        //storing 4 char values after a '.' and later checks if .EQ. needs to be changed to ==
	        equals[equalsCount] = current;
	        equalsCount++;
	    }
	    else
	    {
	        //otherwise, just redirect the char to the outfile
	        printf("%c", current);
	        prev = current;
	    }
	    if(equalsCount == 4)
	    {
	    	equals[4] = '\0';
	        if(strcmp(equals, ".eq.") == 0)
	        {
	            printf("==");
	        }
	        else if(strcmp(equals, ".ge.") == 0)
	        {
	        	printf(">=");
	        }
	        else if(strcmp(equals, ".gt.") == 0)
	        {
	        	printf(">");
	        }
	        else if(strcmp(equals, ".le.") == 0)
	        {
	        	printf("<=");
	        }
	        else if(strcmp(equals, ".lt.") == 0)
	        {
	        	printf("<");
	        }
	        else
	        {
	            //if string didnt match .EQ. just print it out like normal
	            printf("%s", equals);
	        }
	        equalsCount = 0;
	    }
	}
	return 0;
}
