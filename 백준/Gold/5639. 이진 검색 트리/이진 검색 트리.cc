#include <bits/stdc++.h>

using namespace std;

int lc[1000005];
int rc[1000005];
int root = -1;

void insert(int cur, int n)
{
	if (n < cur)
	{
		if (lc[cur] == 0)
			lc[cur] = n;
		else
			insert(lc[cur], n);
	}
	else
	{
		if (rc[cur] == 0)
			rc[cur] = n;
		else
			insert(rc[cur], n);
	}

}

void postorder(int node)
{
	if (lc[node]) postorder(lc[node]);
	if (rc[node]) postorder(rc[node]);
	cout << node << '\n';
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		if (root == -1)
		{
			root = n;
			continue;
		}

		insert(root, n);
	}

	postorder(root);


	return 0;
}