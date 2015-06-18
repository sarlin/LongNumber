#include "LibraryLong.h"

class LN_Class
{
	LongNumber num;

public:

	LN_Class() {} 

	LN_Class& operator=(const LN_Class& rhv); 
	LN_Class operator+(LN_Class &right);
	LN_Class operator-(LN_Class &right);
	LN_Class operator*(LN_Class &right);
	LN_Class operator/(LN_Class &right);
	LN_Class operator%(LN_Class &right);

	void ReadText(const char* filename);
	void WriteText(const char* filename);
	void ReadBin(const char* filename);
	void WriteBin(const char* filename);
	void ClearMemory();

	friend LN_Class Degree(LN_Class &base, LN_Class &exp, LN_Class &mod); 
};
