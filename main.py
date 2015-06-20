import LN_Class
import sys
import os

if ((len(sys.argv) < 5) || (len(sys.argv) > 7) :
    print "Error: Wrong arguments' number"
    sys.exit(0)

if not os.path.exists(sys.argv[1]):
    print "Error: Unable to open file: ", sys.argv[1]
    sys.exit(0)

if ((len(sys.argv[2]) > 1 or sys.argv[2][0] == '\0') or sys.argv[2][0] != '+' and sys.argv[2][0] != '-' and sys.argv[2][0] != '*' and sys.argv[2][0] != '/' and sys.argv[2][0] != '%' and sys.argv[2][0] != '^') :
    print "Error: Unknown operation: ", sys.argv[2][0]
    sys.exit(0)   

if not os.path.isfile(sys.argv[3]) :
    print "Error: Unable to open file: ", sys.argv[3]
    sys.exit(0)

if not os.path.isfile(sys.argv[4]) :
    print "Error: Unable to open file: ", sys.argv[4]
    sys.exit(0)

bin = 0

if len(sys.argv) == 5 :
    if sys.argv[2][0] == '^' :
        print "Error: module file is missed"
        sys.exit(0)

if len(sys.argv) == 6 :
    if sys.argv[2][0] == '^' :
	if not os.path.isfile(sys.argv[5]) :
	    print "Error: Unable to open file: ", sys.argv[5]
	    sys.exit(0)
    else :
        if sys.argv[5] != "-b" : 
	    print "Error: Invalid flag: ", sys.argv[5]
	    sys.exit(0)
	    
	bin = 1

if len(sys.argv) == 7 : 
    if not os.path.isfile(sys.argv[5]) :
        print "Error: Unable to open file: ", sys.argv[5]
	sys.exit(0)

    if sys.argv[6] != "-b" :
        print "Error: Invalid flag: ", sys.argv[6]
        sys.exit(0)

    bin = 1

a = LN_Class.LN_Class()

b = LN_Class.LN_Class()

if bin == 1 :
    a.ReadBin(sys.argv[1])
else :
    a.ReadText(sys.argv[1])
    
if bin == 1 :
    b.ReadBin(sys.argv[3])
else :
    b.ReadText(sys.argv[3])
    
result = LN_Class.LN_Class()
    
if sys.argv[2][0] == '+' :
    result = a + b

if sys.argv[2][0] == '-' :
    result = a - b

if sys.argv[2][0] == '*' :
    result = a * b

if sys.argv[2][0] == '/' :
    result = a / b

if sys.argv[2][0] == '%' :
    result = a % b
    
if sys.argv[2][0] == '^' :
    c = LN_Class.LN_Class()
    if bin == 1 :
	c.ReadBin(sys.argv[5])
    else :
	c.ReadText(sys.argv[5])

    result = LN_Class.PowMod(a, b, c)
  
if bin == 1 :
    result.WriteBin(sys.argv[4])
else :
    result.WriteText(sys.argv[4])
