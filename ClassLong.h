#include "LongNumber.h"

class ClassLong
{
	LongNumber num;

public:

	ClassLong();
	ClassLong(const char *string);
	ClassLong(const ClassLong &right);
	ClassLong(const LongNumber &right);
	ClassLong(const unsigned long long int value);
	~ClassLong();

	char* _str();
	char* _rep();

	void ReadText(const char *filename);
	void WriteText(const char *filename);
	void ReadBin(const char *filename);
	void WriteBin(const char *filename);

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

	friend ClassLong Pow(ClassLong &base, ClassLong &exp, ClassLong &mod); 
	friend ClassLong Pow(ClassLong &base, ClassLong &exp, unsigned long long int mod);
	friend ClassLong Pow(ClassLong &base, unsigned long long int exp, ClassLong &mod);
	friend ClassLong Pow(unsigned long long int base, ClassLong &exp, ClassLong &mod);
	friend ClassLong Pow(ClassLong &base, unsigned long long int exp, unsigned long long int mod);
	friend ClassLong Pow(unsigned long long int base, ClassLong &exp, unsigned long long int mod);
	friend ClassLong Pow(unsigned long long int base, unsigned long long int exp, ClassLong &mod);
};
