#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = stdin;
    char current;
    char prev = '\n';
    char equals[4];
    int equalsCount = 0;
    
    if(!fp)
	{
		return 0;
	}
	
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
	    if((int)current == 46 || equalsCount > 0)
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
	        if(strcmp(equals, ".eq."))
	        {
	            printf("==");
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
