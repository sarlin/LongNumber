#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LibraryLong.h"

#define DWord 4294967296

struct LongNumber ReadBinFile(const char* file)
{
	FILE* in = fopen(file, "rb");
	struct LongNumber number;

	fseek(in, 0, SEEK_END);
	unsigned int quotient, ost, size = ftell(in);

	quotient = size / sizeof(unsigned int);
	ost = size % sizeof(unsigned int);

	if (ost == 0)
		number = Allocate(number, quotient);
	else
		number = Allocate(number, quotient + 1);

	fseek(in, SEEK_SET, 0);

	for (int i = 0; i < quotient; i++)
		fread(&number.part[i], sizeof(unsigned int), 1, in);

	number.size = quotient;

	if (ost != 0)
	{
		unsigned char ch;
		number.size++;
		number.part[quotient] = 0;
		for (int j = 0; j<ost; j++)
		{
			fread(&ch, sizeof(unsigned char), 1, in);
			number.part[quotient] |= (ch << j * 8);
		}
	}

	fclose(in);

	return number;
}

void WriteBinFile(const char* file, struct LongNumber number)
{
	FILE* out = fopen(file, "wb");

	for (int i = 0; i < number.size; i++)
	{
		fwrite(&number.part[i], sizeof(unsigned int), 1, out);
	}

	fclose(out);
}

const struct LongNumber ReadTextFile(const char* file)
{
	struct LongNumber bin, number;
	unsigned int a, carry = 0, tmp, current = 1, j = 0, x = 0;
	char ch;

	FILE *in = fopen(file, "r");

	fseek(in, 0, SEEK_END);
	number.size = ftell(in);

	fseek(in, SEEK_SET, 0);

	number = Allocate(number, number.size);
	number = Zero(number, number.size);

	bin.size = number.size / 9 + 1;

	bin = Allocate(bin, bin.size);
	bin = Zero(bin, bin.size);

	long long int i = number.size - 1;

	while ((ch = getc(in)) != EOF)
	{
		number.part[i--] = ch - '0';
	}

	fclose(in);

	while (number.size != 1 || number.part[0] != 0)
	{
		carry = 0;

		for (i = number.size - 1; i >= 0; i--)
		{
			tmp = carry * 10 + number.part[i];
			number.part[i] = tmp / 2;
			carry = tmp - number.part[i] * 2;
		}

		number = Norm(number);

		bin.part[j] = ((current << x) * carry) | bin.part[j];

		x++;

		if (x == 32)
		{
			x = 0;
			j++;
		}
	}

	number = Clear(number);

	bin = Norm(bin);

	return bin;
}

const void WriteTextFile(const char* file, struct LongNumber number)
{
	FILE* out = fopen(file, "w");

	struct LongNumber decimal;
	unsigned int a, j = 0;
	unsigned int carry = 0;
	long long int tmp, i = number.size - 1;

	decimal.size = number.size * 10;

	decimal = Allocate(decimal, decimal.size);
	decimal = Zero(decimal, decimal.size);

	while (number.size != 1 || number.part[0] != 0)
	{
		carry = 0;

		for (i = number.size - 1; i >= 0; i--)
		{
			tmp = carry * DWord + number.part[i];
			number.part[i] = tmp / 10;
			carry = tmp - (long long int) number.part[i] * 10;
		}

		decimal.part[j] = carry;
		j++;

		number = Norm(number);
	}

	decimal = Norm(decimal);

	for (int i = decimal.size - 1; i > -1; i--)
		fprintf(out, "%c", decimal.part[i]);

	fclose(out);
}

struct LongNumber ReadStr(const char* num)
{
	struct LongNumber bin, number;
	char ch;
	long long int i = 0;

	for (; i < strlen(num); i++)
	if (num[i] < '0' || num[i] > '9')
	{
		printf("Error: Wrong string: %s \n", num);
		bin.part = (unsigned int*)malloc(sizeof(unsigned int)*(1));
		bin.part[0] = 0;
		bin.size = 1;
		return bin;
	}

	number.size = strlen(num);

	number = Allocate(number, number.size);
	number = Zero(number, number.size);

	bin.size = number.size / 9 + 1;

	bin = Allocate(bin, bin.size);
	bin = Zero(bin, bin.size);

	unsigned int a, carry = 0, tmp, current, j, x;

	i = number.size - 1;

	for (; i > -1; --i)
		number.part[i] = num[number.size - i - 1] - '0';

	current = 1;
	j = 0;
	x = 0;

	while (number.size != 1 || number.part[0] != 0)
	{
		carry = 0;

		for (i = number.size - 1; i >= 0; i--)
		{
			tmp = carry * 10 + number.part[i];
			number.part[i] = tmp / 2;
			carry = tmp - number.part[i] * 2;
		}

		number = Norm(number);

		bin.part[j] = ((current << x) * carry) | bin.part[j];

		x++;

		if (x == 32)
		{
			x = 0;
			j++;
		}
	}

	number = Clear(number);

	bin = Norm(bin);

	return bin;
}

char* PrintN(struct LongNumber number)
{
	struct LongNumber decimal;

	decimal.size = number.size * 10;

	decimal = Allocate(decimal, decimal.size);
	decimal = Zero(decimal, decimal.size);

	unsigned int a, j = 0;
	long long int tmp, i = number.size - 1;
	char carry = 0;

	while (number.size != 1 || number.part[0] != 0)
	{
		carry = 0;

		for (i = number.size - 1; i >= 0; i--)
		{
			tmp = carry * DWord + number.part[i];
			number.part[i] = tmp / 10;
			carry = tmp - (long long int) number.part[i] * 10;
		}

		carry += '0';

		decimal.part[j] = carry;
		j++;

		number = Norm(number);
	}

	decimal = Norm(decimal);

	char *string = NULL;
	j = 0;

	string = (char*)malloc(sizeof(char)*(1));
	string[0] = '\0';

	for (i = decimal.size - 1; i > -1; i--)
		printf("%c", decimal.part[i]);

	free(decimal.part);
	decimal.size = 0;

	return string;
}

struct LongNumber ReadN(unsigned long long int value)
{
	struct LongNumber num;

	num.part = (unsigned int*)malloc(sizeof(unsigned int)*(3));
	num.size = 0;

	unsigned long long int carry = value;

	do
	{
		num.size++;
		num.part[num.size - 1] = carry % DWord;
		carry = carry / DWord;
	} while (carry);

	return num;
}

struct LongNumber Clear(struct LongNumber number)
{
	free(number.part);
	return number;
}

struct LongNumber Allocate(struct LongNumber number, unsigned int size)
{
	number.part = (unsigned int*)malloc(sizeof(unsigned int)*(size));
	return number;
}

struct LongNumber Zero(struct LongNumber number, unsigned int size)
{
	memset(number.part, 0, size * sizeof(unsigned int));
	return number;
}

struct LongNumber Shift(struct LongNumber a, unsigned int s) 
{
	struct LongNumber current;

	current.size = a.size + s;
	current = Allocate(current, current.size);
	current = Zero(current, s);

	for (int i = s; i < a.size + s; i++)
	{
		current.part[i] = a.part[i - s];
	}

	return current;
}

struct LongNumber MulSmall(struct LongNumber a, unsigned long long int b)
{
	unsigned long long int tmp, carry = 0;
	unsigned int i, j;

	struct LongNumber res;

	res.size = a.size + 1;
	res = Allocate(res, res.size);
	res = Zero(res, res.size); 

	carry = 0;

	for (j = 0; j < a.size; j++)
	{
		tmp = b * (unsigned long long int) a.part[j] + (unsigned long long int) carry + (unsigned long long int) res.part[j];
		carry = tmp / DWord;
		res.part[j] = tmp % DWord;
	}

	res.part[a.size] = carry;

	res = Norm(res);

	return res;
}

struct LongNumber DivSmall(struct LongNumber a, unsigned long long int b)
{
	unsigned long long int tmp;
	unsigned int carry = 0;
	int i;

	struct LongNumber res;
	res.size = a.size;
	res = Allocate(res, res.size);
	res = Zero(res, res.size);

	for (i = a.size - 1; i > -1; i--)
	{
		tmp = (unsigned long long int) carry * DWord + (unsigned long long int) a.part[i];
		res.part[i] = tmp / b;
		carry = tmp - (unsigned long long int) res.part[i] * (unsigned long long int) b;
	}

	res = Norm(res);

	return res;
}

struct LongNumber Copy(struct LongNumber from)
{
	struct LongNumber cpy;

	cpy.size = from.size;
	cpy = Allocate(cpy, cpy.size);
	memcpy(cpy.part, from.part, cpy.size * sizeof(unsigned int));

	return cpy;
}

int Compare(struct LongNumber a, struct LongNumber b)  
{
	if (a.size > b.size)
		return 1;

	if (a.size < b.size)
		return -1;

	int i = a.size - 1;

	while (a.part[i] == b.part[i] && i > 0)
		i--;

	if (a.part[i] > b.part[i])
		return 1;

	if (a.part[i] < b.part[i])
		return -1;

	if (a.part[i] == b.part[i])
		return 0;
}

struct LongNumber Sum(struct LongNumber a, struct LongNumber b)
{
	unsigned long long int tmp;
	unsigned int carry = 0, i;
	LongNumber res;

	if (a.size < b.size)
	{
		return Sum(b, a);
	}

	res.size = a.size + 1;
	res = Allocate(res, res.size);
	res = Zero(res, res.size);

	for (i = 0; i<b.size; i++)
	{
		tmp = (unsigned long long int) a.part[i] + (unsigned long long int) b.part[i] + (unsigned long long int) carry;
		if (tmp >= DWord)
		{
			tmp= tmp - DWord;
			carry = 1;
		}
		else carry = 0;
		
		res.part[i] = tmp;
	}

	for (; i < a.size; i++)
	{
		tmp = (unsigned long long int) a.part[i] + (unsigned long long int) carry;

		if (tmp >= DWord)
		{
			res.part[i] = tmp - DWord;
			carry = 1;
		}
		else
		{
			res.part[i] = tmp;
			carry = 0;
		}
	}

	if (carry == 1)
	{
		res.part[i] = carry;
		res.size = a.size + 1;
	}
	else
		res.size = a.size;

	res = Norm(res);

	return res;
}

struct LongNumber Dif(struct LongNumber a, struct LongNumber b)
{
	long long int tmp;
	unsigned int carry = 0, i;
	struct LongNumber res;

	if (Compare(a, b) < 0)
	{
		res = Dif(b, a);
		return res;
	}

	res.size = a.size;
	res = Allocate(res, res.size);
	res = Zero(res, res.size);

	for (i = 0; i<b.size; i++)
	{
		tmp = (long long int)a.part[i] - (long long int) b.part[i] - (long long int) carry;

		if (tmp < 0)
		{
			tmp = tmp + DWord;
			carry = 1;
		}
		else carry = 0;
		res.part[i] = tmp;
	}

	for (; i<a.size; i++)
	{
		tmp = (long long int) a.part[i] - (long long int) carry;

		if (tmp < 0)
		{
			res.part[i] = tmp + DWord;
			carry = 1;
		}
		else
		{
			res.part[i] = tmp;
			carry = 0;
		}
	}

	res = Norm(res);

	return res;
}

struct LongNumber Mul(struct LongNumber a, struct LongNumber b)
{
	unsigned long long int tmp;
	unsigned int carry = 0, i, j;

	struct LongNumber res;

	res.size = a.size + b.size;
	res = Allocate(res, res.size);
	res = Zero(res, res.size);

	for (i = 0; i < b.size; i++)
	{
		carry = 0;

		for (j = 0; j < a.size; j++)
		{
			tmp = (unsigned long long int) b.part[i] * (unsigned long long int) a.part[j] + (unsigned long long int) carry + (unsigned long long int) res.part[i + j];
			carry = tmp / DWord;
			res.part[i + j] = tmp % DWord;
		}
		res.part[i + a.size] = carry;
	}

	res = Norm(res);

	return res;
}

struct LongNumber Div(struct LongNumber a, struct LongNumber b, int choice)
{
	struct LongNumber ost; 

	if (Compare(a, b) < 0) 
	{
		struct LongNumber res;
		res.size = 1;
		res = Allocate(res, res.size);
		res.part[0] = 0;

		if (choice == 1)
			return res;
		else
			return a;
	}

	if (b.size == 1)  
	{
		if (b.part[0] == 0) 
		{
			ost.size = 0;
			ost.part = NULL;

			return ost;
		}

		LongNumber res = DivSmall(a, b.part[0]);

		ost = Dif(a, MulSmall(res, b.part[0]));

		return res;

	}

	ost = Copy(a);

	struct LongNumber res;
	res.size = a.size - b.size + 1;
	res = Allocate(res, res.size);
	res = Zero(res, res.size); 
	unsigned int i;

	for (i = a.size - b.size + 1; i != 0; i--)
	{
		unsigned long long int qGuessMax = DWord, qGuessMin = 0, qGuess;

		while (qGuessMax - qGuessMin > 1)
		{
			qGuess = (qGuessMax + qGuessMin) / 2;
			struct LongNumber tmp = MulSmall(b, qGuess);
			tmp = Shift(tmp, i - 1);
			if (Compare(tmp, ost) > 0)
				qGuessMax = qGuess;
			else
				qGuessMin = qGuess;

			tmp = Clear(tmp);
		}

		struct LongNumber tmp = MulSmall(b, qGuessMin);
		tmp = Shift(tmp, i - 1);

		ost = Dif(ost, tmp);

		tmp = Clear(tmp);

		res.part[i - 1] = qGuessMin;
	}

	if (choice == 1)
	{
		res = Norm(res);
		ost = Clear(ost);
		return res;
	}
	else
	{
		ost = Norm(ost);
		res = Clear(res);
		return ost;
	}
}

struct LongNumber Deg(struct LongNumber a, struct LongNumber b, struct LongNumber c)
{
	struct LongNumber res;
	if (a.size < c.size)
		res.size = c.size + c.size;
	else
		res.size = a.size + a.size;

	res = Allocate(res, res.size);
	res = Zero(res, res.size); 
	res.part[0] = 1;

	struct LongNumber com;
	com.size = 1;
	com = Allocate(com, com.size);
	com.part[0] = 0;

	struct LongNumber value;
	value.size = res.size;
	value = Allocate(value, value.size);
	value = Zero(value, value.size);

	memcpy(value.part, a.part, a.size * sizeof(unsigned int));

	struct LongNumber pow = Copy(b);

	while ((Compare(pow, com)) > 0)
	{
		if ((pow.part[0] & 1) == 1)
		{
			res = Mul(res, value);
			res = Div(res, c, 2);
		}

		value = Mul(value, value);
		value = Div(value, c, 2);
		pow = DivSmall(pow, 2);
	}

	com = Clear(com);
	pow = Clear(pow);
	value = Clear(value);

	return res;
}

struct LongNumber Norm(struct LongNumber a)
{
	unsigned int i = a.size - 1;

	while ((i>0) && (a.part[i] == 0))
		i--;

	a.size = i + 1;

	return a;
}
