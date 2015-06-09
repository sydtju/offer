//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
//这里需要注意的是  size() 返回的是unsigned int类型  另外就是程序注释中提到
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int temp=0;
		if (0==stack1.size())
		{
			return 0;
		}
		else{
			unsigned int limit=stack1.size();//这里要是用limit 不能直接放在for里面使用  因为size返回的值是变化的！！
			for (unsigned int i=0;i<limit;i++)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			temp=stack2.top();
			stack2.pop();
			limit=stack2.size();
			for (unsigned int i=0;i<limit;i++)
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			return temp;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
