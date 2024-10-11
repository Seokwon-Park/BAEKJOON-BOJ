#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string a, b;
	cin >> n >> a >> b;

	bool isDiff = false;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			isDiff = false;
		}
		else
		{
			if (!isDiff)
			{
				ans += 1;
				isDiff = true;
			}
		}
	}
	cout << ans;

	return 0;
}

