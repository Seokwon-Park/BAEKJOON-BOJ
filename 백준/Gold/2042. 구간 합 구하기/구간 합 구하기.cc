#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n, m, k;
ll arr[1000005];
int treeHeight;
int treeSize;
vector<ll> segTree;

ll MakeSegTree(int node, int st, int en)
{
	if (st == en) return segTree[node] = arr[st];

	int mid = (st + en) / 2;
	ll left = MakeSegTree(node * 2, st, mid);
	ll right = MakeSegTree(node * 2 + 1, mid + 1, en);
	
	return segTree[node] = left + right;
}

ll GetSum(int node, int st, int en, int l, int r)
{
	if (l > en || r < st) return 0;
	if (l <= st && en <= r) return segTree[node];

	int mid = (st + en) / 2;
	ll left = GetSum(node * 2, st, mid, l,r);
	ll right = GetSum(node * 2 + 1, mid + 1, en, l, r);

	return left + right;
}

void UpdateSegTree(int node, int st, int en, int ix, ll diff)
{
	if(ix < st || ix> en) return;
	segTree[node] = segTree[node] + diff;

	if (st != en)
	{
		int mid = (st + en) / 2;
		UpdateSegTree(node * 2, st, mid, ix, diff);
		UpdateSegTree(node * 2 + 1, mid + 1, en, ix, diff);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	treeHeight = (int)ceil(log2(n));
	treeSize = 1 << (treeHeight + 1);
	segTree.resize(treeSize);
	MakeSegTree(1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			//index = b
			//value = c
			ll diff = c - arr[b - 1];
			arr[b - 1] = c;
			UpdateSegTree(1, 0, n - 1, b-1, diff);
		}
		else
		{
 			cout << GetSum(1, 0, n - 1, b-1, c-1) << '\n';
		}
	}


	return 0; 
}