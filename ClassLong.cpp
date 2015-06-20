#include "ClassLong.h"

ClassLong::ClassLong()
{ 
    this->num.pointer = (unsigned int*)malloc(sizeof(unsigned int)*(1));
	this->num.pointer[0] = 0;
    this->num.size = 1;
}

ClassLong::ClassLong(const LongNumber &right)
{
	num = copy(right);
}

ClassLong::ClassLong(const char* string)
{
	this->num = ReadString(string);
}

ClassLong::ClassLong(const ClassLong &right)
{
	this->num = copy(right.num);
}

ClassLong::ClassLong(const unsigned long long int value)
{
	this->num = ReadNumber(value);
}

ClassLong::~ClassLong()
{
	if (this->num.size) 
		delete[] this->num.pointer;
}

char* ClassLong::_str()
{
	ClassLong replica = copy(this->num);
	return PrintNumber(replica.num);
}

char* ClassLong::_rep()
{
	ClassLong replica = copy(this->num);
	return PrintNumber(replica.num);
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
	ClassLong RoRoRo = copy(this->num);
	WriteTextFile(filename, RoRoRo.num);
}

void ClassLong::WriteBin(const char* filename)
{
	ClassLong RoRoRo = copy(this->num);
	WriteBinFile(filename, RoRoRo.num);
}

ClassLong ClassLong::operator=(const ClassLong &right)
{
	this->num = copy(right.num);
	return *this;
}

ClassLong ClassLong::operator+(const ClassLong &right) 
{
	return ADD(this->num, right.num);
}

ClassLong ClassLong::operator+(unsigned long long int value)
{
	return ADD(this->num, ReadNumber(value));
}

ClassLong ClassLong::operator-(const ClassLong &right) 
{
	return SUB(this->num, right.num);
}

ClassLong ClassLong::operator-(unsigned long long int value)
{
	return SUB(this->num, ReadNumber(value));
}

ClassLong ClassLong::operator*(const ClassLong &right)
{
	return MUL(this->num, right.num);
}

ClassLong ClassLong::operator*(unsigned long long int value) 
{
	return MUL(this->num, ReadNumber(value));
}

ClassLong ClassLong::operator/(const ClassLong &right)
{
	return DIV(this->num, right.num, 1);
}

ClassLong ClassLong::operator/(unsigned long long int value) 
{
	return DIV(this->num, ReadNumber(value), 1);
}

ClassLong ClassLong::operator%(unsigned long long int value) 
{
	return DIV(this->num, ReadNumber(value), 2);
}

ClassLong ClassLong::operator%(const ClassLong &right)
{
	return DIV(this->num, right.num, 2);
}

ClassLong PowMod(ClassLong &base, ClassLong &exp, ClassLong &mod)
{
	return DEGREE(base.num, exp.num, mod.num);
}

ClassLong PowMod(ClassLong &base, ClassLong &exp, unsigned long long int mod)
{
	return DEGREE(base.num, exp.num, ReadNumber(mod));
}

ClassLong PowMod(ClassLong &base, unsigned long long int exp, ClassLong &mod)
{
	return DEGREE(base.num, ReadNumber(exp), mod.num);
}

ClassLong PowMod(unsigned long long int base, ClassLong &exp, ClassLong &mod)
{
	return DEGREE(ReadNumber(base), exp.num, mod.num);
}

ClassLong PowMod(ClassLong &base, unsigned long long int exp, unsigned long long int mod)
{
	return DEGREE(base.num, ReadNumber(exp), ReadNumber(mod));
}

ClassLong PowMod(unsigned long long int base, ClassLong &exp, unsigned long long int mod)
{
	return DEGREE(ReadNumber(base), exp.num, ReadNumber(mod));
}

ClassLong PowMod(unsigned long long int base, unsigned long long int exp, ClassLong &mod)
{
	return DEGREE(ReadNumber(base), ReadNumber(exp), mod.num);
}
