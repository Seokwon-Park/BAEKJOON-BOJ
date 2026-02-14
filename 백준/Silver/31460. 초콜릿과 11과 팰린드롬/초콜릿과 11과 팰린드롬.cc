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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << 0 << '\n';
			continue;
		}
		cout << 1;
		for (int i = 0; i < n-2; i++)
		{
			cout << 2;
		}
		cout << 1 << '\n';
	}

	return 0;
}