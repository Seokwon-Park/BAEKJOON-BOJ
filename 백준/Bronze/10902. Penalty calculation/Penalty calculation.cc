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
	int sf = 0;
	int tf = 0;
	int f = 0;
	for (int i = 1; i <= n; i++)
	{
		int s, t;
		cin >> t >> s;
		if (sf < s)
		{
			sf = s;
			tf = t;
			f = i;
		}
	}

	if (sf > 0)
	{
		cout << tf + (f - 1) * 20;
	}
	else
	{
		cout << 0;
	}


	return 0;
}
