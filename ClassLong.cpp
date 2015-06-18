#include "stdlib.h"
#include "ClassLong.h"

LN_Class& LN_Class::operator=(const LN_Class& rhv)
{
	this->num = Copy(rhv.num);
	return *this;
}

LN_Class LN_Class::operator+(LN_Class &right) 
{
	LN_Class res;
	res.num = Sum(this->num, right.num);
	return res;
}

LN_Class LN_Class::operator-(LN_Class &right) 
{
	LN_Class res;
	res.num = Dif(this->num, right.num);
	return res;;
}

LN_Class LN_Class::operator*(LN_Class &right) 
{
	LN_Class res;
	res.num = Mul(this->num, right.num);
	return res;
}

LN_Class LN_Class::operator/(LN_Class &right) 
{
	LN_Class res;
	res.num = Div(this->num, right.num, 1);
	return res;
}

LN_Class LN_Class::operator%(LN_Class &right) 
{
	LN_Class res;
	res.num = Div(this->num, right.num, 2);
	return res;
}

LN_Class PowMod(LN_Class &base, LN_Class &exp, LN_Class &mod)
{
	LN_Class res;
	res.num = Deg(base.num, exp.num, mod.num);
	return res;
}

void LN_Class::ReadText(const char* file)
{
	LN_Class res;
	res.num = ReadTextFile(file);
	*this = res;
}

void LN_Class::ReadBin(const char* file)
{
	LN_Class res;
	res.num = ReadBinFile(file);
	*this = res;
}

void LN_Class::WriteText(const char* file) const
{
	WriteTextFile(file, this->num);
}

void LN_Class::WriteBin(const char* file) const
{
	WriteBinFile(file, this->num);
}

void LN_Class::ClearMemory()
{
	Clear((*this).num);
}

LN_Class::LN_Class()
{
	this->num.part = (unsigned int*)malloc(sizeof(unsigned int)*(1));
	this->num.part[0] = 0;
	this->num.size = 1;
}

LN_Class::LN_Class(const LongNumber &right)
{
	num = Copy(right);
}

LN_Class::LN_Class(const char* string)
{
	this->num = ReadStr(string);
}

LN_Class::LN_Class(const LN_Class &right)
{
	this->num = Copy(right.num);
}

LN_Class::LN_Class(const unsigned long long int value)
{
	this->num = ReadN(value);
}

LN_Class::~LN_Class()
{
	if (this->num.size)
		delete[] this->num.part;
}

char* LN_Class::__str__()
{
	LN_Class smth = Copy(this->num);
	return PrintN(smth.num);
}

char* LN_Class::__repr__()
{
	LN_Class smth = Copy(this->num);
	return PrintN(smth.num);
}

LN_Class LN_Class::operator+(unsigned long long int value)
{
	return Sum(this->num, ReadN(value));
}

LN_Class LN_Class::operator-(unsigned long long int value)
{
	return Dif(this->num, ReadN(value));
}

LN_Class LN_Class::operator*(unsigned long long int value)
{
	return Mul(this->num, ReadN(value));
}

LN_Class LN_Class::operator/(unsigned long long int value)
{
	return Div(this->num, ReadN(value), 1);
}

LN_Class LN_Class::operator%(unsigned long long int value)
{
	return Div(this->num, ReadN(value), 2);
}
