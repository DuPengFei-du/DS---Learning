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
		//����head�������������ÿ������ֵ��x���бȽ�
		//���С��x��β�嵽һ��С��x��������
		//�������x��β�嵽һ������x��������
		//�ȶ��������յĴ���С�ڵ�����
		Node* small = NULL;         // С�� x ������
		Node* smallLast = NULL;     // С�� x ����������һ�����
		Node* big = NULL;           // ���ڵ��� x ������
		Node* bigLast = NULL;      // ���ڵ��� x ����������һ�����
		// ͨ�� cur ������ԭ�����ÿ�����
		Node* cur = pHead;
		while (cur != NULL) {
			if (cur->val < x) {
				// �� cur β�嵽 small ��
				/*
				�� cur ����һ����Ϊ NULL
				cur->next = NULL;
				���������
				��� small ���ڵ������ǿ�����
				if (small == NULL)
					��ʵҲ���ǰ� cur ͷ�嵽 small ��������
					�� small ָ�� cur ��ǰָ��Ľ��
					small = cur;
				��� small ���ڵ������ǿ�����
					���ҵ� small �����е����һ�����
					1���ӵ�һ��������һֱ�ҵ����ȥ
					2����Ϊ֮ǰ�����һ����������ǲ���ģ��������Ǽ�¼һ�¼���	��ѡ��
						smallLast
					�� smallLast ����һ������� cur
					smallLast->next = cur;
				��¼�µ����һ�������˭���ղ�����β����Ǹ���� cur
					smallLast = cur;
				����µ����һ�������˭��֮ǰ���һ��������һ�����
					smallLast = smallLast->next;
				�� cur ָ��ԭ�������һ�����
				cur = cur->next;
				Node *next = cur->next;
				β��
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
				// �� cur β�嵽 big ��
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
		// ע�⣺һ��Ҫ��֤������������һ��������һ���� NULL
		// ���û�� < x ��������ô�죿
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