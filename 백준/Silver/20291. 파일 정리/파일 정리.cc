#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string, int> um;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int ix = s.find('.');
		s = s.substr(ix + 1);
		um[s]++;
	}
	vector<pair<string, int>> v(um.begin(), um.end());
	sort(v.begin(), v.end());
	for (auto [s, i] : v)
	{
		cout << s << ' ' << i << '\n';
	}

	return 0;
}