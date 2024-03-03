#include <bits/stdc++.h>

using namespace std;

int lc[10005];
int rc[10005];
vector<int> lv[10005];
int p[10005];
int x;
int depth = INT_MIN;

void inorder(int cur, int level)
{
	depth = max(level, depth);
	if (lc[cur] != -1) inorder(lc[cur], level + 1);
	lv[level].push_back(x++);
	if (rc[cur] != -1) inorder(rc[cur], level + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int node, l, r;
		cin >> node >> l >> r;
		lc[node] = l;
		p[l] = node;
		rc[node] = r;
		p[r] = node;
	}

	int root = -1;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == 0)
		{
			root = i;
			break;
		}
	}

	inorder(root, 1);

	int mxw = 0;
	int mxlv = 0;

	for (int i = 1; i <= depth; i++)
	{
		int width = 0;
		if (lv[i].size() == 1)
		{
			width = 1;
		}
		else
		{
			width = lv[i][lv[i].size() - 1] - lv[i][0] + 1;
		}
		if (width > mxw)
		{
			mxw = width;
			mxlv = i;
		}
	}

	cout << mxlv << ' ' << mxw;

	return 0;
}