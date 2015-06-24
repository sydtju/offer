/*
题目描述

在一个字符串(1<=字符串长度<=10000)中找到第一个只出现一次的字符。
返回:
1.字符在字符串的位置
2.当字符串长度为0时，返回-1
解题：标准的hashtable模式
*/
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
			struct node{
		int count;
		int index;
	};
	node hash[128];
	memset(hash,0,sizeof(node)*128);
	int length=str.length();
	int result=0;
	if(length<=0) return -1;
	for (int i=0;i<length;++i){
		hash[(int)str[i]].count++;
		if (0==hash[(int)str[i]].index) hash[(int)str[i]].index=i;
	}
	int temp=10001;
	for (int i=0;i<128;i++){
		if (1==hash[i].count){
			if(hash[i].index<temp) temp=hash[i].index;
		}
	}
	result=(temp==10001)?-1:temp;
	return result;
	}
};
