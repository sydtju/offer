//输入一个链表，输出该链表中倒数第k个结点
//注意 指针执行NULL时停止  所以不用减1  
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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* head=pListHead;
		ListNode* end=pListHead;
		unsigned int count=k;
		while (count--)
		{
			if (end)//指向NULL时候停止 所以倒数是k位 即使只有k个节点
			{
				end=end->next;
			}
			else{
				return NULL;
			}
		}
		while (end)//指向NULL时候停止 所以倒数是k位
		{
			if (end)
			{
				end=end->next;
				head=head->next;
			}
			else{
				return NULL;
			}
		}
		return head;
	}
};
