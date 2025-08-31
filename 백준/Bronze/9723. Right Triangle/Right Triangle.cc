#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		vector<int> v(3);
		for (int& i : v)
			cin >> i;
		sort(v.begin(), v.end());

		cout << "Case #" << i << ": " << (v[0] * v[0] + v[1] * v[1] == v[2] * v[2] ? "YES" : "NO") << '\n';

	}

	return 0;
}