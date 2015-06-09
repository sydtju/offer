	//最大子数组问题
	//一维DP问题   注意 处理数组为0的情况！！！！
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max=array[0];
		int result=INT_MIN;
		unsigned int length=array.size();
        if (0==length) return 0;
		for (unsigned int i=1;i<length;i++ )
		{
			max=max+array[i]>=array[i]?max+array[i]:array[i];
			if(max>result)
				result=max;
		}
		return result;
	}
