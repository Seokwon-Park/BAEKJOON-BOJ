#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	string ans = "";
	int tmp = m;
	while (tmp)
	{
		int k = tmp % n;
		if (k < 10)
		{
			ans.push_back(k + '0');
		}
		else
		{
			ans.push_back('A' + k - 10);
		}
		tmp /= n;
	}

	if (!ans.empty())
	{
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	else
	{
		cout << 0;
	}

	return 0;
}

