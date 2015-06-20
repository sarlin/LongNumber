#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dword 4294967296

struct LongNumber
{
    unsigned int size;
    unsigned int* part;
};

struct LongNumber ReadBinFile(const char* file);
void WriteBinFile(const char* file, struct LongNumber number);
struct LongNumber ReadTextFile(const char* file);
void WriteTextFile(const char* file, struct LongNumber number);
struct LongNumber Clear(struct LongNumber number);
struct LongNumber Allocate(struct LongNumber number, unsigned int size);
struct LongNumber Zero(struct LongNumber number, unsigned int size);
struct LongNumber Copy(struct LongNumber from);
struct LongNumber ToNorm(struct LongNumber a);
int Compare(struct LongNumber a, struct LongNumber b);
struct LongNumber Shift(struct LongNumber a, unsigned int s);
struct LongNumber MulSmall(struct LongNumber a, unsigned long long int b);
struct LongNumber DivSmall(struct LongNumber a, unsigned long long int b);
struct LongNumber Sum(struct LongNumber a, struct LongNumber b);
struct LongNumber Dif(struct LongNumber a, struct LongNumber b);
struct LongNumber Mul(struct LongNumber a, struct LongNumber b);
struct LongNumber Div(struct LongNumber a, struct LongNumber b, int sumbols);
struct LongNumber Deg(struct LongNumber a, struct LongNumber b, struct LongNumber c);
struct LongNumber ReadNum(unsigned long long int value);
char* PrintNum(struct LongNumber number); 
struct LongNumber ReadStr(const char* num);
