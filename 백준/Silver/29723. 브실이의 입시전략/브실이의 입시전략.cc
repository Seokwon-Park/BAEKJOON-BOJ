#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	hashm<string, int> h;

	for (int i = 0; i < n; i++)
	{
		string s;
		int sc;
		cin >> s >> sc;
		h[s] = sc;
	}

	int res = 0;
	for (int i = 0; i < k; i++)
	{
		string s;
		cin >> s;
		res += h[s];
		h.erase(s);
	}

	vector<pair<string, int>> v(h.begin(), h.end());
	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			return a.second < b.second;
		});

	int mn = res;
	int mx = res;
	for (int i = 0; i < m - k; i++)
	{
		mn += v[i].second;
		mx += v[h.size() - 1 - i].second;
	} 
	cout << mn << ' ' << mx;

	return 0;
}
