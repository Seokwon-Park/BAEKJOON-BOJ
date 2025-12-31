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

	int a, b;
	cin >> a >> b;
	string ans;
	if ((b & (b - 1)) != 0)
	{
		cout << -1;
		return 0;
	}
	else
	{
		while (a != 0)
		{
			if (a >= b)
			{
				a -= b;
				ans.push_back('G');
			}
			else
			{
				b /= 2;
				ans.push_back('K');
			}
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans;



	return 0;
}