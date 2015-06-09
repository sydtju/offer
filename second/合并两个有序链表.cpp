//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//首先是  初始参数范围判断 是不是有NULL  然后制作一个新的链表头   最后的时候 再释放掉  中间比较的时候 一定注意
//比较完成之后  剩下的链表也要接上
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
		ListNode* plist1=pHead1;
		ListNode* plist2=pHead2;
		ListNode* newhead=new ListNode(0);
		ListNode* rear=newhead;
		ListNode* temp=NULL;
		if (NULL==plist1)
		{
			return plist2;
		}
		if (NULL==plist2)
		{
			return plist1;
		}
		while (NULL!=plist1&&NULL!=plist2)
		{
			if (plist1->val<=plist2->val)
			{
				rear->next=plist1;
				plist1=plist1->next;
				rear=rear->next;
			}
			else{
				rear->next=plist2;
				plist2=plist2->next;
				rear=rear->next;
			}
		}
		if (NULL==plist1)
		{
			rear->next=plist2;
		}
		if (NULL==plist2)
		{
			rear->next=plist1;
		}
		temp=newhead;
		newhead=newhead->next;
		delete temp;
		temp=NULL;
		return newhead;
	}
};
