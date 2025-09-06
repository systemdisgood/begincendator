#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE* ifp = NULL;
FILE* ofp = NULL;

int main(int argc, char* argv[])
{
	// may be output file is existing or locked
	bool can_write_file = false;
	if(1 == argc)
	{
		fprintf(stderr, "Error! No arguments!\nUse argument \"help\" to get help.\n");
		return(EXIT_FAILURE);
	}
	else if(2 == argc)
	{
		if(0 == strcmp(argv[1], "help"))
		{
			printf("some help\n");
		}
		else 
		{
			fprintf(stderr, "Error! No such single argument!\nUse argument \"help\" to get help.\n");
			return(EXIT_FAILURE);
		}
	}
	else if(3 == argc)
	{
		if((ofp = fopen(argv[2], "r")) == NULL)
		{
			printf("Output file is not readable.\nMay be it is not exist or locked.\n");
		can_write_file = true;
		}
		else
		{
			fclose(ofp);
			printf("Rewrite file? (y/N)\n");
			int answer = getchar();
			if(answer != '\n')
			{
				int trash_char = '\0';
				while((trash_char = getchar()) != '\n' && trash_char != EOF);
			}
			printf("%d\n", answer);
			if('y' == answer || 'Y' == answer) can_write_file = true;
			else return 0;
		}
		if(can_write_file)
		{
			if((ofp = fopen(argv[2], "r+")) == NULL)
			{
				fprintf(stderr, "Error! Can not open output file!\n");
				return EXIT_FAILURE;
			}
			if((ifp = fopen(argv[1], "r")) == NULL)
			{
				fprintf(stderr, "Error! Can not open input file!\n");
				return EXIT_FAILURE;
			}

			
			fclose(ifp);
			fclose(ofp);
		}
	}
	return EXIT_SUCCESS;
}
