#include <iostream>
#include <string>
#include <queue>

using namespace std;

class BT
{
private:
	struct Node
	{
		char value;
		Node* left;
		Node* right;
		Node(char val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};

	Node* head, * nil;
	Node* table[26];

public:
	BT()
	{
		nil = new Node('.', NULL, NULL);
		head = new Node('A', nil, nil);
		table[0] = head;
	}
	~BT()
	{
		delete head;
	}

	void BT_insert(Node* parent, char lv, char rv)
	{
		int ix;
		if (lv != '.')
		{		
			nil = new Node('.', nil, nil);
			Node* l = new Node(lv, nil, nil);
			parent->left = l;			
			ix = lv - 'A';
			table[ix] = l;
		}
		if (rv != '.')
		{
			Node* r = new Node(rv, nil, nil);
			parent->right = r;
			ix = rv - 'A';
			table[ix] = r;
		}
	}

	Node* BT_find(char key)
	{
		return table[key - 'A'];
	}

	Node* getRoot()
	{
		return head;
	}


	void preorder(Node* t)
	{
		if (t->value != '.')
		{
			cout << t->value;
			preorder(t->left);
			preorder(t->right);
		}
	}
	void inorder(Node* t)
	{
		if (t->value != '.')
		{
			 
			inorder(t->left);
			cout << t->value;
			inorder(t->right);
		}
	}
	void postorder(Node* t)
	{
		if (t->value != '.')
		{
			postorder(t->left);
			postorder(t->right);
			cout << t->value;
		}
	}

};

int main()
{
	BT t;
	int nnum;
	char pval, lval, rval;
	cin >> nnum;
	for (int i = 0; i < nnum; i++)
	{
		cin >> pval >> lval >> rval;		
		t.BT_insert(t.BT_find(pval), lval, rval);
	}

	t.preorder(t.getRoot());
	cout << '\n';
	t.inorder(t.getRoot());
	cout << '\n';
	t.postorder(t.getRoot());

	return 0;
}