//从尾到头打印单链表
//第一种解法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//利用vector数组，进行尾插，然后反转就可以了
class Solution {
public:
	vector<int> reversePrint(ListNode* head)
	{
		//利用数组的反转库函数
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


//第二种解法，利用栈
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
		//先给出来一个栈
		stack<int> s;
		vector<int> ret;
		while (head)
		{
			//先让元素入栈
			s.push(head->val);
			head = head->next;
		}
		//然后出栈
		while (!s.empty())
		{
			ret.push_back(s.top());
			s.pop();
		}
		return ret;
	}
};


//第三种思路
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
		//利用递归
		if (head == NULL)
			return res;
		reversePrint(head->next);
		res.push_back(head->val);
		return res;
	}
};