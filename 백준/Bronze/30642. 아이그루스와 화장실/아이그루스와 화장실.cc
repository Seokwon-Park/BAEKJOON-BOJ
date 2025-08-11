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
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x;
	cin >> x;
	if (s == "annyong")
	{
		if (x % 2 != 1)
		{
			if (x - 1 >= 1)
			{
				cout << x - 1;
			}
			else if (x + 1 <= n)
			{
				cout << x + 1;
			}
		}
		else
		{
			cout << x;
		}
	}
	else
	{
		if (x % 2 != 0)
		{
			if (x - 1 >= 1)
			{
				cout << x - 1;
			}
			else if (x + 1 <= n)
			{
				cout << x + 1;
			}
		}
		else
		{
			cout << x;
		}
	}

	return 0;
}