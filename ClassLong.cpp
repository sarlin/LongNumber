#include "ClassLong.h"

ClassLong::ClassLong()
{ 
    this->Number.part = (unsigned int*)malloc(sizeof(unsigned int)*(1));
	this->Number.part[0] = 0;
    this->Number.size = 1;
}

ClassLong::ClassLong(const LongNumber &right)
{
	Number = Copy(right);
}

ClassLong::ClassLong(const char* string)
{
	this->Number = ReadStr(string);
}

ClassLong::ClassLong(const ClassLong &right)
{
	this->Number = Copy(right.Number);
}

ClassLong::ClassLong(const unsigned long long int value)
{
	this->Number = ReadNum(value);
}

ClassLong::~ClassLong()
{
	if (this->Number.part != 0) 
		this->Number = Clear(Number);
}

char* ClassLong::__str__()
{
	ClassLong replica = Copy(this->Number);
	return PrintNum(replica.Number);
}

char* ClassLong::__repr__()
{
	ClassLong replica = Copy(this->Number);
	return PrintNum(replica.Number);
}

ClassLong ClassLong::operator=(const ClassLong &right)
{
	this->Number = Copy(right.Number);
	return *this;
}

ClassLong ClassLong::operator+(const ClassLong &right) 
{
	return Sum(this->Number, right.Number);
}

ClassLong ClassLong::operator+(unsigned long long int value)
{
	return Sum(this->Number, ReadNum(value));
}

ClassLong ClassLong::operator-(const ClassLong &right) 
{
	return Dif(this->Number, right.Number);
}

ClassLong ClassLong::operator-(unsigned long long int value)
{
	return Dif(this->Number, ReadNum(value));
}

ClassLong ClassLong::operator*(const ClassLong &right) 
{
	return Mul(this->Number, right.Number);
}

ClassLong ClassLong::operator*(unsigned long long int value)
{
	return Mul(this->Number, ReadNum(value));
}

ClassLong ClassLong::operator/(const ClassLong &right) 
{
	return Div(this->Number, right.Number, 1);
}

ClassLong ClassLong::operator/(unsigned long long int value)
{
	return Div(this->Number, ReadNum(value), 1);
}

ClassLong ClassLong::operator%(const ClassLong &right) 
{
	return Div(this->Number, right.Number, 2);
}

ClassLong ClassLong::operator%(unsigned long long int value) 
{
	return Div(this->Number, ReadNum(value), 2);
}

void ClassLong::ReadText(const char* filename)
{
	*this = ReadTextFile(filename);
}

void ClassLong::ReadBin(const char* filename)
{
	*this = ReadBinFile(filename);
}

void ClassLong::WriteText(const char* filename)
{
	ClassLong replica = Copy(this->Number);
	WriteTextFile(filename, replica.Number);
}

void ClassLong::WriteBin(const char* filename)
{
	ClassLong replica = Copy(this->Number);
	WriteBinFile(filename, replica.Number);
}

ClassLong PowMod(ClassLong &base, ClassLong &exp, ClassLong &mod)
{
	return Deg(base.Number, exp.Number, mod.Number);
}

ClassLong PowMod(ClassLong &base, ClassLong &exp, unsigned long long int mod)
{
	return Deg(base.Number, exp.Number, ReadNum(mod));
}

ClassLong PowMod(ClassLong &base, unsigned long long int exp, ClassLong &mod)
{
	return Deg(base.Number, ReadNum(exp), mod.Number);
}

ClassLong PowMod(unsigned long long int base, ClassLong &exp, ClassLong &mod)
{
	return Deg(ReadNum(base), exp.Number, mod.Number);
}

ClassLong PowMod(ClassLong &base, unsigned long long int exp, unsigned long long int mod)
{
	return Deg(base.Number, ReadNum(exp), ReadNum(mod));
}

ClassLong PowMod(unsigned long long int base, ClassLong &exp, unsigned long long int mod)
{
	return Deg(ReadNum(base), exp.Number, ReadNum(mod));
}

ClassLong PowMod(unsigned long long int base, unsigned long long int exp, ClassLong &mod)
{
	return Deg(ReadNum(base), ReadNum(exp), mod.Number);
}
