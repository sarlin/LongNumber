#include "ClassLong.h"

ClassLong::ClassLong()
{ 
    this->num.part = (unsigned int*)malloc(sizeof(unsigned int)*(1));
	this->num.part[0] = 0;
    this->num.size = 1;
}

ClassLong::ClassLong(const LongNumber &right)
{
	num = Copy(right);
}

ClassLong::ClassLong(const char* string)
{
	this->num = ReadStr(string);
}

ClassLong::ClassLong(const ClassLong &right)
{
	this->num = Copy(right.num);
}

ClassLong::ClassLong(const unsigned long long int value)
{
	this->num = ReadNum(value);
}

ClassLong::~ClassLong()
{
	if (this->num.size) 
		delete[] this->num.part;
}

char* ClassLong::_str()
{
	ClassLong replica = Copy(this->num);
	return PrintNum(replica.num);
}

char* ClassLong::_rep()
{
	ClassLong replica = Copy(this->num);
	return PrintNum(replica.num);
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
	ClassLong replica = Copy(this->num);
	WriteTextFile(filename, replica.num);
}

void ClassLong::WriteBin(const char* filename)
{
	ClassLong replica = Copy(this->num);
	WriteBinFile(filename, replica.num);
}

ClassLong ClassLong::operator=(const ClassLong &right)
{
	this->num = Copy(right.num);
	return *this;
}

ClassLong ClassLong::operator+(const ClassLong &right) 
{
	return Sum(this->num, right.num);
}

ClassLong ClassLong::operator+(unsigned long long int value)
{
	return Sum(this->num, ReadNum(value));
}

ClassLong ClassLong::operator-(const ClassLong &right) 
{
	return Dif(this->num, right.num);
}

ClassLong ClassLong::operator-(unsigned long long int value)
{
	return Dif(this->num, ReadNum(value));
}

ClassLong ClassLong::operator*(const ClassLong &right)
{
	return Mul(this->num, right.num);
}

ClassLong ClassLong::operator*(unsigned long long int value) 
{
	return Mul(this->num, ReadNum(value));
}

ClassLong ClassLong::operator/(const ClassLong &right)
{
	return Div(this->num, right.num, 1);
}

ClassLong ClassLong::operator/(unsigned long long int value) 
{
	return Div(this->num, ReadNum(value), 1);
}

ClassLong ClassLong::operator%(unsigned long long int value) 
{
	return Div(this->num, ReadNum(value), 2);
}

ClassLong ClassLong::operator%(const ClassLong &right)
{
	return Div(this->num, right.num, 2);
}

ClassLong Pow(ClassLong &base, ClassLong &exp, ClassLong &mod)
{
	return Deg(base.num, exp.num, mod.num);
}

ClassLong Pow(ClassLong &base, ClassLong &exp, unsigned long long int mod)
{
	return Deg(base.num, exp.num, ReadNum(mod));
}

ClassLong Pow(ClassLong &base, unsigned long long int exp, ClassLong &mod)
{
	return Deg(base.num, ReadNum(exp), mod.num);
}

ClassLong Pow(unsigned long long int base, ClassLong &exp, ClassLong &mod)
{
	return Deg(ReadNum(base), exp.num, mod.num);
}

ClassLong Pow(ClassLong &base, unsigned long long int exp, unsigned long long int mod)
{
	return Deg(base.num, ReadNum(exp), ReadNum(mod));
}

ClassLong Pow(unsigned long long int base, ClassLong &exp, unsigned long long int mod)
{
	return Deg(ReadNum(base), exp.num, ReadNum(mod));
}

ClassLong Pow(unsigned long long int base, unsigned long long int exp, ClassLong &mod)
{
	return Deg(ReadNum(base), ReadNum(exp), mod.num);
}
