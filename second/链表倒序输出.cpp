//输入一个链表，从尾到头打印链表每个节点的值。返回新链表的头结点。
//链表倒序输出
/**
*  struct ListNode {
*	    int val;
*	    struct ListNode *next;
*	    ListNode(int x) :
*			  val(x), next(NULL) {
*	    }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		struct ListNode* oldhead=head;
		struct ListNode* oldsecond=NULL;
		struct ListNode* newhead=NULL;
		vector<int> result;
		while (oldhead!=NULL)
		{
			oldsecond=oldhead->next;
			oldhead->next=newhead;
			newhead=oldhead;
			oldhead=oldsecond;
		}
		while (newhead!=NULL)
		{
			result.push_back(newhead->val);
			newhead=newhead->next;
		}
		return result;
	}
};
