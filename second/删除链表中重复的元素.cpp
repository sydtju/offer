//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//这个题 加个头然后就实现就行了 没有技巧
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:

    ListNode* deleteDuplication(ListNode* pHead)
    {
		ListNode* head=new ListNode(0);
		head->next=pHead;
		ListNode* c_point=pHead;
		ListNode* pre_point=head;
		if(head==NULL) return NULL;
		while (c_point)
		{
			if (!c_point->next) break;
			if ((c_point->val!=c_point->next->val))
			{
				pre_point=c_point;
			}
			else
			{
				while(c_point->next!=NULL&&c_point->val==c_point->next->val) {
					ListNode *temp=c_point->next;
					delete c_point;
					if(!temp) break;else c_point=temp;
				}
				pre_point->next=c_point->next;
			}
			c_point=c_point->next;
		}
		ListNode *reslut=head->next;
		delete head;
		return reslut;
    }
};
