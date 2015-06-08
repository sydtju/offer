//输入一个链表，反转链表后，输出反转链表后头节点
//链表倒序  三个链表指针变量 ok！
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
		struct ListNode* oldhead=pHead;
		struct ListNode* oldsecond=NULL;
		struct ListNode* newhead=NULL;
		while (oldhead!=NULL)
		{
			oldsecond=oldhead->next;
			oldhead->next=newhead;
			newhead=oldhead;
			oldhead=oldsecond;
		}
		return newhead;
	}
};
