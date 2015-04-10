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
//字符串空格替换
class Solution {
public:
	string replaceSpace(string str) {
   		for (int i=0;i<str.size();i++)
   		{
	   		if (str[i]==' ')
	   		{
			str.erase(i,1);
			str.insert(i,"%20");
            i=i+2;
            }
   		}
        return str;
	}
};
//合并有序链表
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *head=new ListNode(0);
        ListNode  *temp1=pHead1;
        ListNode  *temp2=pHead2;
        ListNode  *re_head=head;

		while(temp1!=NULL&&temp2!=NULL){
			if((temp1->val)<(temp2->val)){  
            	head->next=temp1;
                temp1=temp1->next;
                head=head->next;
            }
            else{
                head->next=temp2;
                temp2=temp2->next;
                head=head->next;
            }
        }
        if(temp1==NULL){
            while(temp2){
                head->next=temp2;
                temp2=temp2->next;
                head=head->next;
            }
        }
        if(temp2==NULL){
            while(temp1){
                head->next=temp1;
                temp1=temp1->next;
                head=head->next;
            }
        } 
    	head=re_head->next;
        delete re_head;
        return head;
	}
};
