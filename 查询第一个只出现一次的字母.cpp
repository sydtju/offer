//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
//输出描述:如果当前字符流没有存在出现一次的字符，返回#字符。
//用了一个队列 一个map
class Solution
{
public:
void Insert(char ch)
{
	it=s.find(ch);
	if (it!=s.end())
	{
		s[(*it).first]=2;
	}
	else{
		s.insert(pair<char,int>(ch,1));
		dat.push_back(ch);
	}
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{

	while (1)
	{
		if (dat.size()==0)
		{
			return '#';
		}
		it=s.find(dat.front());
		if (it!=s.end())
		{
			if ((*it).second==1)
			{
				return dat.front();
			}
			else{
				dat.pop_front();
			}
		}
		else{
			return dat.front();
		}
	}
}
private:
	deque<char> dat;
	map<char,int> s;
	map<char,int>::iterator it;
};
