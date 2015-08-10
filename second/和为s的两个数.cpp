//这个最好是使用hashset/hashmap 但是OJ里面没有 只能使用set/map 
/*题目描述

输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
	int len=(int)array.size();
	set<int> set_t;
	for(int i=0;i<len;++i)
		set_t.insert(array[i]);
	vector<int> result;
	for(int i=0;i<len;++i)
	{
		if (set_t.find(sum-array[i])!=set_t.end()){
			if(result.size()==0) {
				result.push_back(array[i]>(sum-array[i])?(sum-array[i]):array[i]);
				result.push_back(array[i]>(sum-array[i])?array[i]:(sum-array[i]));
			}
			else{
				if((sum-array[i])*array[i]<result[0]*result[1]) {
						result.pop_back();
						result.pop_back();
						result.push_back(array[i]>(sum-array[i])?(sum-array[i]):array[i]);
						result.push_back(array[i]>(sum-array[i])?array[i]:(sum-array[i]));
				}
			}
		}
	}
	return result;
    }
};
