#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int treeHeight;
int treeSize;


ll MakeSegTree(vector<ll>& arr, vector<ll>& segTree,int node, int st, int en)
{
	if (st == en) return segTree[node] = st; // 리프노드에는 각 높이의 index를 저장한다.

	int mid = (st + en) / 2;
	ll left = MakeSegTree(arr, segTree, node * 2, st, mid);
	ll right = MakeSegTree(arr, segTree, node * 2 + 1, mid + 1, en);
	
	return segTree[node] = arr[left] < arr[right] ? left : right; // 두 노드의 인덱스의 높이를 비교해서 더 낮은 높이의 인덱스를 저장한ㄷ.
}

ll GetMinHeightIndex(vector<ll>& arr, vector<ll>& segTree,int node, int st, int en, int l, int r)
{
	if (l > en || r < st) return -1; // 구간에 해당하지 않는 경우.
	if (l <= st && en <= r) return segTree[node]; // 만약 구간에 해당하는 값이면 그 구간의 높이 최솟값을 리턴한다.

	int mid = (st + en) / 2;
	ll left = GetMinHeightIndex(arr, segTree, node * 2, st, mid, l,r);
	ll right = GetMinHeightIndex(arr, segTree, node * 2 + 1, mid + 1, en, l, r);

	if (left == -1)
		return right;
	else if (right == -1)
		return left;
	else
		if (arr[left] <= arr[right])
			return left;
		else
			return right;
}

ll GetMaxArea(vector<ll>& arr, vector<ll>& segTree, int st, int en)
{
	int ix = GetMinHeightIndex(arr, segTree, 1, 0, arr.size() - 1, st, en);
	// st를 l en을 r로 해서 l~r 구간의 높이 최솟값의 인덱스를 구한다.

	ll area = (ll)(en - st + 1) * (ll)arr[ix];
	// 그 넓이를 구한다.

	// 최소높이 인덱스를 기준으로 왼쪽 오른쪽 범위에 대해 다시 넓이를 구한다.
	if (st<= ix - 1)
	{
		ll tmp = GetMaxArea(arr, segTree, st, ix - 1); 
		area = max(tmp, area);
	}

	if (ix + 1 <= en)
	{
		ll tmp = GetMaxArea(arr, segTree, ix + 1, en);
		area = max(tmp, area);
	}

	return area;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		treeHeight = (int)ceil(log2(n));
		treeSize = 1 << (treeHeight + 1);
		vector<ll> segTree(treeSize);

		MakeSegTree(arr, segTree, 1, 0, n - 1);

		cout << GetMaxArea(arr, segTree, 0, n - 1) << '\n';

	}

	return 0; 
}