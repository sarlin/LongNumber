#include "LibraryLong.h"

class ClassLong
{
	LongNumber number;

public:

	ClassLong();
	ClassLong(const char *string);
	ClassLong(const ClassLong &right);
	ClassLong(const LongNumber &right);
	ClassLong(const unsigned long long int value);
	~ClassLong();

	char* __str__();
	char* __repr__();

	ClassLong operator=(const ClassLong &right);
	ClassLong operator+(const ClassLong &right);
	ClassLong operator+(const unsigned long long int value);
	ClassLong operator-(const ClassLong &right);
	ClassLong operator-(const unsigned long long int value);
	ClassLong operator*(const ClassLong &right);
	ClassLong operator*(const unsigned long long int value);
	ClassLong operator/(const ClassLong &right);
	ClassLong operator/(const unsigned long long int value);
	ClassLong operator%(const ClassLong &right);
	ClassLong operator%(const unsigned long long int value);

	void ReadText(const char *filename);
	void WriteText(const char *filename);
	void ReadBin(const char *filename);
	void WriteBin(const char *filename);

	friend ClassLong PowMod(ClassLong &base, ClassLong &exp, ClassLong &mod); // res = ClassLong.PowMod(a,b,c)
	friend ClassLong PowMod(ClassLong &base, ClassLong &exp, unsigned long long int mod);
	friend ClassLong PowMod(ClassLong &base, unsigned long long int exp, ClassLong &mod);
	friend ClassLong PowMod(unsigned long long int base, ClassLong &exp, ClassLong &mod);
	friend ClassLong PowMod(ClassLong &base, unsigned long long int exp, unsigned long long int mod);
	friend ClassLong PowMod(unsigned long long int base, ClassLong &exp, unsigned long long int mod);
	friend ClassLong PowMod(unsigned long long int base, unsigned long long int exp, ClassLong &mod);
};
