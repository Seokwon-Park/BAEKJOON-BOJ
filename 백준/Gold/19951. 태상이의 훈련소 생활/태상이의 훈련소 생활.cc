#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	vector<int> tmp(n + 2, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		tmp[a] += k;
		tmp[b+1] += -k;
	}
	
	vector<int> pfsum(n + 2);
	for(int i = 1; i<=n; i++)
	{
		pfsum[i] = pfsum[i - 1] + tmp[i];
		v[i] += pfsum[i];
		cout << v[i] << ' ';
	}


	

	return 0;
}