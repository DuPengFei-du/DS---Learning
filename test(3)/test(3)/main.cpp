/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//��������head��NULL����ֱ�ӷ���NULL (ֻ�е�һ�ε��ô�NULL�Ż��ߵ�������֮ǰ�ͻ��ߵ�head->next==NULL)
		//�������head����head->next==NULL����head��ԭ����tail����Ҫ����
		if (head == NULL || head->next == NULL) {
			return head;
		}

		//���û������������˳���������������ݹ���û�һֱ�ݹ���ȥ��ֱ���ҵ�tail�ڵ㣬�˴����صľ���tail
		ListNode* tail = reverseList(head->next);

		//�˴���head��ÿ�εݹ���õĴ����������[1,2,3,4,5]Ϊ�����˴��ֱ���4��3��2��1 ע��û��5����Ϊ5�����˳�������ǰ�淵����
		//head->nextָ��ԭ�����е�ǰ����Ԫ�ص�nextԪ�أ���headΪ4ʱ��nextΪ5��headΪ3ʱ��nextΪ4
		//��˴˴���next��nextָ�����ڴ����Ԫ�أ�����5ָ��4����4ָ��3�ȵ�
		head->next->next = head;
		//ͬʱ���ڴ����Ԫ�ز�����ָ����ǰ��next�����ҽ���next�ÿգ��ȵ�������Ԫ��ʱ����Ĳ���������ָ��ԭ��ǰ���Ԫ��
		//���Ƕ���ԭ�����һ��Ԫ��1�������������head,��Ϊû������Ĳ����ˣ�����1��nextΪNULL������Ҫ��
		head->next = NULL;
		//ÿ�εݹ鷵�ض��Ƿ���ͬһ��tail����5��ͬʱ5Ҳ�Ƿ�ת������ĵ�һ��Ԫ�ء����tail�����һ�εݹ���˳����������صģ�Ȼ��ÿ�εݹ鷵�غ󶼷��ظ���һ�㣬���һ��headΪ1��ʱ�򣬴���������������tail
		return tail;
	}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

struct ListNode* reverseList(struct ListNode* head)
{
	Node* pNewHead = NULL;
	Node* cur = head;
	while (cur)
	{
		head = cur->next;
		cur->next = pNewHead;
		pNewHead = cur;
		cur = head;
	}
	return pNewHead;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head)
{
	//��ת����
	Node* prev = NULL;
	Node* cur = head;
	Node* next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}