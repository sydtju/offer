/*
题目描述

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}，
{2,3,4,2,6,[2,5,1]}。
*/
//方法：遵循的原则是将可能的最大值放到队列里面   也就是说当框中加入num[i]的时候 它与队列中排在它前面的数 进行比较
//将其中的小于它的数 都pop掉 直到大于自己的数或者队列为空 就把自己放进去 
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {   
	deque<int> que;
	vector<int> max;
	if (size<=0||num.size()<size) return max;
	for(unsigned int i=0;i<size;++i){
		while (!que.empty()&&num[que.back()]<num[i])
				que.pop_back();
			que.push_back(i);
	}
	max.push_back(num[que.front()]);
	for (unsigned int j=size;j<num.size();++j)
	{
		while (!que.empty()&&num[que.back()]<num[j])
				que.pop_back();
			que.push_back(j);

		if (que.front()<=j-size)
				que.pop_front();
		max.push_back(num[que.front()]);
	}
	return max;
    }
};
