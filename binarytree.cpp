#include <iostream>
#include <queue>
#include <math.h>

typedef int Datatype;

using namespace std;

struct TreeNode{
	Datatype data;
	TreeNode* left;
	TreeNode* right;
};

class Tree{
public:
	TreeNode* root=new TreeNode;
	int num;
	queue<TreeNode*> tree;
	Tree() :num(0)
	{

		root->data=0;
		root->left = NULL;
		root->right = NULL;
	}
	~Tree()
	{
	}
	void insert(Datatype it)
	{
		if (NULL == root)return;
		if (0 == num)
		{
			root->data = it;
			num++;
			tree.push(root);
		}
		else
		{
			TreeNode* p = new TreeNode;
			p->data = it;
			p->left = NULL;
			p->right = NULL;
			TreeNode* tmp = tree.front();
			if (NULL == tmp->left)
			{
				tmp->left = p;
				tree.push(p);
				num++;
			}
			else if (NULL==tmp->right)
			{
				tmp->right = p;
				tree.pop();
				num++;
				tree.push(p);
			}
		}
	}
	void print(TreeNode* rt)
	{
		cout << rt->data << "->" << endl;
	}
	
	void pretrave(TreeNode* rt)
	{
		if (NULL==rt)return;
		print(rt);
		pretrave(rt->left);
		pretrave(rt->right);
	}
	void midtrave(TreeNode* rt)
	{
		if (NULL == rt)return;
		midtrave(rt->left);
		print(rt);
		midtrave(rt->right);
	}
	void posttrave(TreeNode* rt)
	{
		if (NULL == rt)return;
		posttrave(rt->left);
		posttrave(rt->right);
		print(rt);
	}

	//利用队列进行层遍历
	void leveltrave(TreeNode* rt)
	{
		if (NULL == rt)return;
		queue<TreeNode*> que;
		que.push(rt);
		while (!que.empty())
		{
			rt = que.front();
			print(rt);
			que.pop();
			if (rt->left != NULL)
			{
				que.push(rt->left);
			}
			if (rt->right != NULL)
			{
				que.push(rt->right);
			}
		}
	}
	void trave()
	{
		leveltrave(root);
	}
};

int main()
{
	Tree my_tree;
	for (int i = 1; i < 8; i++)
	{
		my_tree.insert(i);
	}
	my_tree.trave();
	return 0;
}