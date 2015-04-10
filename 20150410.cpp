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
