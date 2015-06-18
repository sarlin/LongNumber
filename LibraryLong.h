struct LongNumber
{
	unsigned int size;
	unsigned int* part;
};
struct LongNumber ReadBinFile(const char* file);
void WriteBinFile(const char* file, struct LongNumber number);
const struct LongNumber ReadTextFile(const char* file);
const void WriteTextFile(const char* file, struct LongNumber number);
struct LongNumber Sum(struct LongNumber a, struct LongNumber b);
struct LongNumber Dif(struct LongNumber a, struct LongNumber b);
struct LongNumber Mul(struct LongNumber a, struct LongNumber b);
struct LongNumber Div(struct LongNumber a, struct  LongNumber b, int choice);
struct LongNumber MulSmall(struct LongNumber a, unsigned long long int b);
struct LongNumber Shift(struct LongNumber a, unsigned int s);
struct LongNumber Deg(struct LongNumber a, struct LongNumber b, struct LongNumber c);
struct LongNumber DivSmall(struct LongNumber a, unsigned long long int b);
struct LongNumber Clear(struct LongNumber number);
struct LongNumber Allocate(struct LongNumber number, unsigned int size);
struct LongNumber Zero(struct LongNumber number, unsigned int size);
int Compare(struct LongNumber a, struct LongNumber b);
struct LongNumber Copy(struct LongNumber from);
struct LongNumber Norm(struct LongNumber a);
struct LongNumber ReadStr(const char* num);
char* PrintN(struct LongNumber number);
struct LongNumber ReadN(unsigned long long int value);
