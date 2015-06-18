#include "LibraryLong.h"

class LN_Class
{
	LongNumber num;

public:

	LN_Class();
	LN_Class(const char *string);
	LN_Class(const LN_Class &right);
	LN_Class(const LongNumber &right);
	LN_Class(const unsigned long long int value);
	~LN_Class();

	char* __str__();
	char* __repr__();

	LN_Class& operator=(const LN_Class& rhv); 
	LN_Class operator+(LN_Class &right);
	LN_Class operator-(LN_Class &right);
	LN_Class operator*(LN_Class &right);
	LN_Class operator/(LN_Class &right);
	LN_Class operator%(LN_Class &right);

	void ReadText(const char* filename);
	void WriteText(const char* filename) const;
	void ReadBin(const char* filename);
	void WriteBin(const char* filename) const;
	void ClearMemory();

	friend LN_Class PowMod(LN_Class &base, LN_Class &exp, LN_Class &mod);

	LN_Class operator+(const unsigned long long int value);
	LN_Class operator-(const unsigned long long int value);
	LN_Class operator*(const unsigned long long int value);
	LN_Class operator/(const unsigned long long int value);
	LN_Class operator%(const unsigned long long int value);

	friend LN_Class PowMod(LN_Class &base, LN_Class &exp, unsigned long long int mod);
	friend LN_Class PowMod(LN_Class &base, unsigned long long int exp, LN_Class &mod);
	friend LN_Class PowMod(unsigned long long int base, LN_Class &exp, LN_Class &mod);
	friend LN_Class PowMod(LN_Class &base, unsigned long long int exp, unsigned long long int mod);
	friend LN_Class PowMod(unsigned long long int base, LN_Class &exp, unsigned long long int mod);
	friend LN_Class PowMod(unsigned long long int base, unsigned long long int exp, LN_Class &mod);
};
