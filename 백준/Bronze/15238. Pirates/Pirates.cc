#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(26, 0);
	for (auto c : s)
	{
		v[c - 'a']++;
	}

	int x = max_element(v.begin(), v.end()) - v.begin();

	cout << (char)('a' + x) << ' ' << v[x];

	return 0;
}