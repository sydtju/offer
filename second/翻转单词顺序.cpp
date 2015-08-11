//JOBDU
class Solution {
public:
    string ReverseSentence(string str) {
	stack<int> temp;
	string result;
	while(str.length())
	{
		if (str.back()==' ')
		{
			while (temp.size())
			{
				result.push_back(temp.top());
				temp.pop();				
			}
			result.push_back(' ');
			str.pop_back();
		}
		else{
		temp.push(str.back());
		str.pop_back();
		}
	}
	while (temp.size())
	{
		result.push_back(temp.top());
		temp.pop();
	}
	return result;
    }
};
