//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
//每个节点复制一份 插在两个节点中间  然后在复制还原
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
   RandomListNode* temp=pHead;
	RandomListNode* result=NULL;
	if(!pHead) return result;
	while(temp){
		RandomListNode* mid_temp=temp->next;
		temp->next=new RandomListNode(temp->label);
		temp->next->next=mid_temp;
		temp=mid_temp;
	}
	temp=pHead;
	while(temp){
		if(temp->random)	temp->next->random=temp->random->next;
		temp=temp->next->next;
	}
    result=pHead->next;
    RandomListNode* temp_new=result;
    temp=pHead;
    while(temp){
        temp->next=temp_new->next;
        if(temp_new->next)  temp_new->next=temp_new->next->next;
        temp=temp->next;
        temp_new=temp_new->next;
    }
	return result;
    }
};
