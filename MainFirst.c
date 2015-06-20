#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "LibraryLong.h"

int main(int argc, const char * argv[])
{
	struct LongNumber a,b,result;
	
	if ((argc < 5) || (argc > 7))
	{
		printf("Error: wrong arguments' number\n");
		return 0;
	}

	if (argc > 7)
		{
			printf("Error: Too many arguments\n");
			return 0;
		}

		FILE* firstLongNumFile = fopen(argv[1], "r");
		if (!firstLongNumFile)
		{
			printf("Error: Unable to open file: %s \n", argv[1]);
			return 0;
		}
		fclose(firstLongNumFile);

		const char* operation = argv[2];
		if ((strlen(operation) > 1 || operation[0] == '\0') || (operation[0] != '+' && operation[0] != '-' && operation[0] != 'u' && operation[0] != '/' && operation[0] != '%' && operation[0] != 'd'))
		{
			printf("Error: Unknown operation: %s \n", operation);
			return 0;
		}

		FILE* secondLongNumFile = fopen(argv[3], "r");
		if (!secondLongNumFile)
		{
			printf("Error: Unable to open file: %s \n", argv[3]);
			return 0;
		}
		fclose(secondLongNumFile);

		FILE* resultLongNumFile = fopen(argv[4], "r");
		if (!resultLongNumFile)
		{
			printf("Error: Unable to open file: %s \n", argv[4]);
			return 0;
		}
		fclose(resultLongNumFile);

		int bin = 0;

		if (argc == 6)
		{
			if (argv[2][0] == 'd')
			{
				FILE* moduleLongNumFile = fopen(argv[5], "r");
				if (!moduleLongNumFile)
				{
					printf("Error: Unable to open file: %s \n", argv[5]);
					return 0;
				}
				fclose(moduleLongNumFile);
			}
			else
			{
				if (strcmp(argv[5], "-b"))
				{
					printf("Error: Invalid flag: %s \n", argv[5]);
					return 0;
				}
				bin = 1;
			}

		}

		if (argc == 7)
		{
			FILE* moduleLongNumFile = fopen(argv[5], "r");
			if (!moduleLongNumFile)
			{
				printf("Error: Unable to open file: %s \n", argv[5]);
				return 0;
			}
			fclose(moduleLongNumFile);

			if (strcmp(argv[6], "-b"))
			{
				printf("Error: Invalid flag: %s \n", argv[6]);
				return 0;
			}
			bin = 1;
		}

		if (bin == 1)
			a = ReadBinFile(argv[1]);
		else
			a = ReadTextFile(argv[1]);

		if (bin == 1)
			b = ReadBinFile(argv[3]);
		else
			b = ReadTextFile(argv[3]);

		switch (operation[0]) {
		case '+':
		{
					result = Sum(a, b);
					break;
		}
		case '-':
		{
					result = Dif(a, b);
					break;
		}
		case 'u':
		{
					result = Mul(a, b);
					break;
		}
		case '/':
		{
					result = Div(a, b, 0);
					break;
		}
		case '%':
		{
					result = Div(a, b, 1);
					break;
		}
		case 'd':
		{
					struct LongNumber c;
					if (bin == 1)
						c = ReadBinFile(argv[5]);
					else
						c = ReadTextFile(argv[5]);

					result = Deg(a, b, c);
					c = Clear(c);
					break;
		}
		}
		
		if (bin == 1)
			WriteBinFile(argv[4], result);
		else
			WriteTextFile(argv[4], result);

	a = Clear(a);
	b = Clear(b);
	result = Clear(result);

	return 0;
}

