//寻找两个链表的第一个交叉节点  运行通过  
//思路：求出两个链表的长度 求得长度的差值   然后将较长链表的指针移动到差值长度的点    然后同步遍历  
//原理:两个链表如果有相交的点 那么就是一个Y型，也就是说后面的每个节点都是重合的 也就是两个长度一样的棒子 戳在桌面上
//找第一个相交的节点就是 减去差值之后 同步遍历
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
	 int length1=0;
	 int length2=0;
	 int offset=0;
	 ListNode *p1=pHead1;
	 ListNode *p2=pHead2;
	 while(p1){
		 length1++;
		 p1=p1->next;
	 }
	 while(p2){
		 length2++;
		 p2=p2->next;
	 }
	 p1=pHead1;
	 p2=pHead2;
	 offset=length1>=length2?length1-length2:length2-length1;
	 if(length1>=length2){
		 while(offset--){
			 p1=p1->next;      
		 }
	 }
	 else{
		 while(offset--){
			 p2=p2->next;      
		 }
	 }
	 while(p1){
		 if(p1==p2){
			 return p1;
		 }
		 else{
			 p1=p1->next;
			 p2=p2->next;
		 }
	 }
	 return NULL;
 }
};
