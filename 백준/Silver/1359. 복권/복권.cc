#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll nCr(int n, int r)
{
	ll res = 1;
	for (int i = 0; i < r; i++)
	{
		res *= n - i;
		res /= i + 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	int total = nCr(n, m);
	// 전체 n개 중에 m개 뽑는 경우의 수
	int res = 0;
	for (int i = k; i <= m; i++)
	{
		res += nCr(m, i) * nCr(n - m, m-i);
	}

	cout << fixed << setprecision(9);
	cout << (double)res/ (double)total;

	return 0;
}