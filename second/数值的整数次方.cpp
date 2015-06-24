
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution {
public:
    double Power(double base, int exponent) {
	if (0==exponent) return 1;
	int flag=exponent>0?1:-1;
	int e=abs(exponent);
	double base0=base;
	double result=1.0;
	while (e)
	{
		if (e&1) result=result*base0;
		e=e>>1;
		base0=base0*base0;
	}
	return flag>0?result:1.0/result;
	}
};
