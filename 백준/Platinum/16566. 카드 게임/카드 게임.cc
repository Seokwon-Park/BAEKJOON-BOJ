#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int find(int x, vector<int>& p)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x], p);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> nxt(m, -1);
	vector<int> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		int ix = upper_bound(v.begin(), v.end(), x) - v.begin();
		int res = find(ix, nxt);
		cout << v[res] << '\n';
		nxt[res] = res + 1;
	}


	return 0;
}