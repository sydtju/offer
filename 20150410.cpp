//两个栈实现队列
class Solution
{
public:
	void push(int node) {
		while(!stack1.empty()){
        	stack2.push(stack1.top());
            stack1.pop();
        }
        	stack2.push(node);
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
	}

	int pop() {
        int temp=stack1.top();
        stack1.pop();
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//链表倒序
/*struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode*head=NULL;
   		ListNode*old_head=pHead;
        ListNode*temp=NULL;
        while(old_head){
            temp=old_head->next;
            old_head->next=head;
            head=old_head;
            old_head=temp;
        }
        return head;
	}
};
//连续子数组的最大和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int i=0;
        long long sum=INT_MIN;
        long long max=INT_MIN;
        if(array.size()==0) return 0;
        for(;i<array.size();i++){
            if(sum+array[i]>array[i]) sum=sum+array[i];
            else sum=array[i];
            if(sum>max) max=sum;
        }
        return (int)max;
	}
};
