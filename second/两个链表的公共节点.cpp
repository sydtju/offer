//输入两个链表，找出它们的第一个公共结点。
//先求出两个链表的长度  计算出差值 将较大的链表的指针指到差值位置 然后依次向下遍历
//找两个地址相同的节点返回 Y字形
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
	ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
		ListNode * point1=pHead1;
		ListNode * point2=pHead2;
		int length1=0,length2=0;
		int abslength=0;
		if (NULL==point1)	return NULL;
		if (NULL==point2)	return NULL;
		while(point1){
			length1++;
			point1=point1->next;
		}
		while(point2){
			length2++;
			point2=point2->next;
		}
        point1=pHead1;
        point2=pHead2;
		if (length1>=length2)
		{
			abslength=length1-length2;
			while(abslength--){
				point1=point1->next;
			}
		} 
		else
		{
			abslength=length2-length1;
			while(abslength--){
				point2=point2->next;
			}
		}
		while (NULL!=point1&&NULL!=point2)
		{
			if(point1==point2) return point1;
			point1=point1->next;
			point2=point2->next;
		}
		return NULL;
	}
};
