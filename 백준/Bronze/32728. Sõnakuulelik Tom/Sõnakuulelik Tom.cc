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

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<string> v(3);

	map<char, int> m;
	m['s'] = 0;
	m['r'] = 1;
	m['p'] = 2;
	for (auto c : s)
	{
		int ix = m[c];
		while(v[ix].size() == k) ix= (ix+1)%3;
		v[ix].push_back(c);
	}
	for (auto s : v)
	{
		cout << s << '\n';
	}
	
	return 0;
}