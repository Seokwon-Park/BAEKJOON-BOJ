#include <bits/stdc++.h>

using namespace std;

vector<int> child[55];
int p[55];
int c[55];

void update(int del)
{
	c[p[del]]--;
	if (!child[del].empty())
		for (int nxt : child[del])
		{
			update(nxt);
		}
	else
	{
		c[del] = -1;
		return;
	}
	c[del] = -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		p[i] = parent;
		if (parent != -1)
		{
			child[parent].push_back(i);
			c[parent]++;
		}
	}

	int del;
	cin >> del;
	update(del);

	cout << count(c, c + n, 0);

	return 0;
}
