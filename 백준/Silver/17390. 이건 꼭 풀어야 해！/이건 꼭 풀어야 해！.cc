#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n+1);
	vector<int> pfsum(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin()+1, v.end());
	
	for (int i = 1; i <= n; i++)
	{
		pfsum[i] = pfsum[i - 1] + v[i];
	}

	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << pfsum[r] - pfsum[l - 1] << '\n';
	}
	



	return 0;
}
