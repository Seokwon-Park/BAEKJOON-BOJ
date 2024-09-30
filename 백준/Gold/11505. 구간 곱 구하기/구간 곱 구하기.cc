#include<bits/stdc++.h>
#include <assert.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<ll> segTree;
ll v[1000005];

ll InitTree(int node, int st, int en)
{
	if (st == en)
		return segTree[node] = v[st];
	int mid = (st + en) / 2;
	ll lvalue = InitTree(node * 2, st, mid);
	ll rvalue = InitTree(node * 2 + 1, mid + 1, en);
	return segTree[node] = (lvalue * rvalue) % MOD;
}

ll GetResult(int node, int l, int r, int st, int en)
{
	if (en <l || st > r) return 1;
	if (l <= st && en <= r) return segTree[node];
	int mid = (st + en) / 2;
	ll lvalue = GetResult(node * 2, l, r, st, mid);
	ll rvalue = GetResult(node * 2 + 1, l, r, mid + 1, en);

	return (lvalue * rvalue) % MOD;
}

void UpdateTree(int node, int st, int en, int ix, ll newVal, ll divMod) // 어떤 인덱스의 값을 newVal로 교체
// 이과정에서 ix가 포함되는 범위에 대해 v[ix]의 모듈로 역원(divmod)을 곱한뒤 newVal을 다시곱해준다.
{
	if (ix< st || ix >en) return;
		segTree[node] = (((segTree[node] * divMod) % MOD) * newVal) % MOD;
	if (st == en)return;

	int mid = (st + en) / 2;
	UpdateTree(node * 2, st, mid, ix, newVal, divMod);
	UpdateTree(node * 2 + 1, mid + 1, en, ix, newVal, divMod);
}


ll fast_pow(ll n, ll k) // 빠른 제곱 알고리즘을 통한 모듈로 역원 계산
{
	if (k == 0)
		return 1;
	ll res = fast_pow(n, k / 2);
	if (k % 2 == 0)
	{
		return (res * res) % MOD;
	}
	else
	{
		return (((res * res) % MOD) * n) % MOD;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int height = ceil(log2(n));
	int treesz = 1 << (height + 1);
	segTree.resize(treesz);

	InitTree(1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		// 인덱스가 0부터 시작하기 때문에 1씩 빼야함
		if (a == 1)
		{
			ll prev = v[b - 1];
			v[b - 1] = c;
			ll divMod = fast_pow(prev, MOD - 2); // 바꾸기 전의 값으 모듈러 역원을 구한다.
			if (divMod != 0)
			{
				UpdateTree(1, 0, n - 1, b - 1, c, divMod);
			}
			else
			{
				InitTree(1, 0, n - 1);
			}
		}
		else
		{
			cout << GetResult(1, b - 1, c - 1, 0, n - 1) << '\n';
		}
	}

	return 0;
}

