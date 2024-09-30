#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> segTree;
int v[100005];

int InitTree(int node, int st, int en)
{
	if (st == en)
		return segTree[node] = v[st];
	int mid = (st + en) / 2;
	int lvalue = InitTree(node * 2, st, mid);
	int rvalue = InitTree(node * 2 + 1, mid + 1, en);
	return segTree[node] = min(lvalue, rvalue);
}

int GetResult(int node, int l, int r, int st, int en)
{
	if (en <l || st > r) return INF;
	if (l <= st && en <= r) return segTree[node];
	int mid = (st + en) / 2;
	int lvalue = GetResult(node * 2, l, r, st, mid);
	int rvalue = GetResult(node * 2 + 1, l, r, mid + 1, en);
	return min(lvalue, rvalue);


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int height = ceil(log2(n));
	int treesz = 1 << (height + 1);
	segTree.resize(treesz);

	InitTree(1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << GetResult(1, a - 1, b - 1, 0, n - 1) << '\n';
	}



	return 0;
}

