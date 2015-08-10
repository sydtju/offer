//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

class Solution {
    vector<int> temp;
public:
    void push(int value) {
        temp.push_back(value);
    }
    void pop() {
		temp.pop_back();
    }
    int top() {
        int top=temp.back();
        return top;        
    }
    int min() {
        int length=(int)temp.size();
        if(!length) return 0;
        int result=temp[0];
        for(int i=0;i<length;++i){
           result=temp[i]>result?result:temp[i];
        }
        return result;
    }
};
