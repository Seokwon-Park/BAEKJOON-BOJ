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

	int d;
	cin >> d;
	int ans = 0;
	for (int i = 1; i * i <= d; i++)
	{
		if (d % i == 0)
		{
			if (i * i == d) ans++;
			else ans+=2;
		}
	}
	cout << ans;


	return 0;
}