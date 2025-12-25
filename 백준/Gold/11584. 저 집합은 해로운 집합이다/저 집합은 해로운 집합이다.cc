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
		int a, b;
		cin >> a >> b;
		if (a > b)
		{
			cout << 0 << '\n';
			continue;
		}
		bool chk = true;
		for (int i = 1; i <= 10; i++)
		{
			int aa = a * 3;
			// 1/3 < a/b < 2/3 == break;	
			// b < 3*a < 2*b
			if (b < aa && aa < b * 2)
			{
				cout << i << '\n';
				chk = false;
				break;
			}

			if (aa <= b)
			{
				a = aa;
			}
			else
			{
				a = aa - 2 * b;
			}
		}
		if (chk)
		{
			cout << -1 << '\n';
		}
	}

	return 0;
}