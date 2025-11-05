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
	
	int n;
	cin >> n;
	int a0;
	cin >> a0;
	vector<int> v(n);
	int ans = 0;
	for (int& i : v)
	{
		cin >> i;
		int rot = abs(i - a0);
		if (rot <= 180)
		{
			ans += rot;
		}
		else
		{
			ans += 360 - rot;
		}
		a0 = i;
	}
	cout << ans;
	
	return 0;
}