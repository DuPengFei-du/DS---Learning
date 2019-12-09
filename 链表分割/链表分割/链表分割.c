/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
typedef struct ListNode Node;
class Partition
{
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		//遍历head所代表的链表，把每个结点的值和x进行比较
		//如果小于x，尾插到一条小于x的链表中
		//如果大于x，尾插到一条大于x的链表中
		//先定义两个空的大于小于的链表
		Node* small = NULL;         // 小于 x 的链表
		Node* smallLast = NULL;     // 小于 x 的链表的最后一个结点
		Node* big = NULL;           // 大于等于 x 的链表
		Node* bigLast = NULL;      // 大于等于 x 的链表的最后一个结点
		// 通过 cur 来遍历原链表的每个结点
		Node* cur = pHead;
		while (cur != NULL) {
			if (cur->val < x) {
				// 把 cur 尾插到 small 中
				/*
				让 cur 的下一个变为 NULL
				cur->next = NULL;
				分情况讨论
				如果 small 所在的链表是空链表
				if (small == NULL)
					其实也就是把 cur 头插到 small 所在链表
					让 small 指向 cur 当前指向的结点
					small = cur;
				如果 small 所在的链表不是空链表
					先找到 small 链表中的最后一个结点
					1）从第一个结点遍历一直找到最后去
					2）因为之前的最后一个结点是我们插入的，所以我们记录一下即可	【选择】
						smallLast
					让 smallLast 的下一个结点变成 cur
					smallLast->next = cur;
				记录新的最后一个结点是谁？刚才我们尾插的那个结点 cur
					smallLast = cur;
				最后新的最后一个结点是谁？之前最后一个结点的下一个结点
					smallLast = smallLast->next;
				让 cur 指向原链表的下一个结点
				cur = cur->next;
				Node *next = cur->next;
				尾插
				cur = next;
				*/
				Node* next = cur->next;
				cur->next = NULL;
				if (small == NULL)
				{
					small = cur;
				}
				else
				{
					smallLast->next = cur;
				}
				smallLast = cur;
				cur = next;
			}
			else
			{
				// 把 cur 尾插到 big 中
				Node* next = cur->next;
				cur->next = NULL;
				if (big == NULL)
				{
					big = cur;
				}
				else
				{
					bigLast->next = cur;
				}
				bigLast = cur;
				cur = next;
			}
		}
		// 注意：一定要保证最终链表的最后一个结点的下一个是 NULL
		// 如果没有 < x 的链表怎么办？
		if (small == NULL)
		{
			return big;
		}
		else
		{
			smallLast->next = big;
			return small;
		}
	}
};