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
using hashmap = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(10, 1);
	string s = "rabithorse";
	v[2] = 2;

	if (n < 11)
	{
		cout << s.substr(0, n);
	}
	else
	{
		int x = n - 11;
		ll mx = 0;
		vector<int> ans;
		for (int b = 0; b <= x; b++)
		{
			int y = x - b;
			vector<int> tmp = v;
			tmp[2] += b;
			int yleft = y % 9;
			for (int i = 0; i < 10; i++)
			{
				if (i == 2) continue;
				tmp[i] += y / 9;
				if (yleft > 0)
				{
					tmp[i]++;
					yleft--;
				}
			}
			ll res = 1;
			for (int i = 0; i < 10; i++)
			{
				if (i == 2)
				{
					res *= tmp[i] * (tmp[i] - 1) / 2;
				}
				else
				{
					res *= tmp[i];
				}
			}
			if (res > mx)
			{
				mx = res;
				ans = tmp;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			cout << string(ans[i], s[i]);
		}
	}

	return 0;
}