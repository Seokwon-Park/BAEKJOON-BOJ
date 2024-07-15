#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n+1);
	vector<int> ps(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		ps[i] = ps[i - 1] + v[i];
	}

	int ans = 0;
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			int sum = ps[r] - ps[l - 1];
			if (sum % (r - l + 1) != 0) continue;
			int avg = sum / (r - l + 1);
			for (int i = l; i <= r; i++)
			{
				if (avg == v[i])
				{
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;

	return 0;
}