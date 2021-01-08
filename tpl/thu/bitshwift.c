
/*
Bitwise Shift
For these, the integer promotions are performed on each operand (which must be an integer type) and then a bitwise shift is executed. The type of the result is the type of the promoted left operand.
New bits are filled with zeros, with a possible exception noted in the implementation-defined behavior, below.
Operation Operator Example
Shift left << a = b << c Shift right >> a = b >> c
There’s also the same similar shorthand for shifting:
Operator Example Longhand equivalent
>>= a>>=c a=a>>c <<= a<<=c a=a<<c
Watch for undefined behavior: no negative shifts, and no shifts that are larger than the size of the promoted left operand.
Also watch for implementation-defined behavior: if you right-shift a negative number, the results are implementation-defined. (It’s perfectly fine to right-shift a signed int, just make sure it’s positive.)



*/
