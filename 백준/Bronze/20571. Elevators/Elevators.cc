#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int n;
	cin >> s >> n;
	if (n == 1)
	{
		cout << 0;
	}
	else
	{
		if (s == "residential")
		{
			cout << n / 5 + (n % 5 > 0);
		}
		else if (s == "commercial")
		{
			cout << n / 7 + (n % 7 > 0);
		}
		else
		{
			cout << n / 4 + (n % 4 > 0);
		}
	}

	

	return 0;
}
