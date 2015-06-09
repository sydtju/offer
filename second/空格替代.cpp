//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
//注意的是 找到空格之后是i=i+2 不是加3  因为 本身后面for循环中还有一个++
class Solution {
public:
	string replaceSpace(string str) {
	for (unsigned int i=0;i<str.length();i++)
	{
		if (' '==str[i])
		{
			str.replace(i,1,"%20");
			i=i+2;
		}
	}
	return str;
	}
};
