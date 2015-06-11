//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
//600.  是数字   写的代码有点乱  主要是对于e的处理 e后面必须有数字且不能是小树  .后面可以没有数字  
class Solution {
public:
	bool isNumeric(char* string)
	{
	unsigned int i=0;
	int flag_sign=0;
	int flag_point=0;
	int flag_e=0;
	int flag_e_after=0;
	int flag_point_after=0;
	int flag=0;
	while (string[i])
	{
		if (0==i)
		{
			if ('+'==string[i])
				flag_sign=1;
			else if('-'==string[i])
				flag_sign=1;
			else if (string[i]>='0'&&string[i]<='9')
				;
			else {
				return false;
			}
		}
		else{
			if (flag_e_after==1)
			{
				if ('+'==string[i])
					flag_sign=1;
				else if('-'==string[i])
					flag_sign=1;
				else if (string[i]>='0'&&string[i]<='9')
					;
				else {
					return false;
				}
				flag_e_after=0;
			}
			else if (flag_point_after==1)
			{
				if (string[i]>='0'&&string[i]<='9') flag_point_after=0;
				else	return false;
			}

			else	if (string[i]>='0'&&string[i]<='9');
			else if ('.'==string[i])
			{
				if (flag_point==1)	return false;
				else  {flag_point=1;flag_point_after=1;}
			}
			else if ('e'==string[i]||'E'==string[i])
			{
				if (flag_e==1)	return false;
				else { flag_e=1;flag_e_after=1;flag_point=1;}
			}
			else{
				return false;
			}
		}
		i++;
	}
	if (flag_e_after) {
		return false;
	}
	else return true;
	}

};
