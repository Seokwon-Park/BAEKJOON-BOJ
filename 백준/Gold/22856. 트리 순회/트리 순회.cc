#include <bits/stdc++.h>

#define INF LLONG_MAX

using namespace std;

int rc[100005];
int lc[100005];
int cnt;
int vis = 1;
int n;
int last;
bool isFind;

void inorder2(int root)
{	
	if (lc[root] != -1)
	{
		vis++;
		cnt++;
		inorder2(lc[root]);
	}
	if (rc[root] != -1)
	{
		vis++;
		cnt++;
		inorder2(rc[root]);
	}
	if (root == last) isFind = true;
	if (isFind) return;
	else cnt++;
		
	

}

void inorder(int root)
{
	if (lc[root] != -1)
	{
		vis++;
		inorder(lc[root]);
	}
	last = root;
	if (rc[root] != -1)
	{
		vis++;
		inorder(rc[root]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int p, l, r;
		cin >> p >> l >> r;
		lc[p] = l;
		rc[p] = r;
	}

	inorder(1);
	//cout << last << '\n';

	vis = 1;
	inorder2(1);
	cout << cnt;

	return 0;
}