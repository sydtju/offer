//一个链表中包含环，请找出该链表的环的入口结点。
//用map是n*log(n)的复杂度  用hash_map是n的复杂度
//这个可以使用快慢指针来判定是否有环  但是却无法判断环的入口节点！
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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		map<ListNode*,int> hmap;
		ListNode* point=pHead;
		map<ListNode*,int>::iterator it;
		while (point)
		{
			it=hmap.find(point);
			if (it!=hmap.end())
			{
				return point;
			}
			else{
				hmap.insert(pair<ListNode*,int>(point,point->val));
			}
			point=point->next;
		}
		return NULL;
	}
};
