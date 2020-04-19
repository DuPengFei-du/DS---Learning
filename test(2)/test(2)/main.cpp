//��β��ͷ��ӡ������
//��һ�ֽⷨ
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//����vector���飬����β�壬Ȼ��ת�Ϳ�����
class Solution {
public:
	vector<int> reversePrint(ListNode* head)
	{
		//��������ķ�ת�⺯��
		vector<int> ret;
		while (head != NULL)
		{
			ret.push_back(head->val);
			head = head->next;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};


//�ڶ��ֽⷨ������ջ
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
	vector<int> reversePrint(ListNode* head)
	{
		//�ȸ�����һ��ջ
		stack<int> s;
		vector<int> ret;
		while (head)
		{
			//����Ԫ����ջ
			s.push(head->val);
			head = head->next;
		}
		//Ȼ���ջ
		while (!s.empty())
		{
			ret.push_back(s.top());
			s.pop();
		}
		return ret;
	}
};


//������˼·
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
	vector<int> res;
	vector<int> reversePrint(ListNode* head)
	{
		//���õݹ�
		if (head == NULL)
			return res;
		reversePrint(head->next);
		res.push_back(head->val);
		return res;
	}
};