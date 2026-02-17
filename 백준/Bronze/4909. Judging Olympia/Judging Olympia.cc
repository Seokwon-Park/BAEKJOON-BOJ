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
	
	vector<int> v(6);
	while (1)
	{
		int sum = 0;
		int mx = 0;
		int mn = INF;
		for (int& i : v)
		{
			cin >> i;
			sum += i;
			mx = max(mx, i);
			mn = min(mn, i);
		}
		if (sum == 0) break;
		sum -= mx + mn;
		cout << (double)sum / 4 << '\n';
	}


	return 0;
}