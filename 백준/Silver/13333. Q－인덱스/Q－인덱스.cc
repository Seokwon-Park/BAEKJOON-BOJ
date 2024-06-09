#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int ans = 0;
	for (int k = 0; k < 10000; k++)
	{
		int greq = 0;
		for (int j = 0; j < n; j++)
		{
			if (v[j] >= k)
			{
				greq++;
			}
		}
		if (greq >= k)
		{
			ans = max(ans, k);
		}
	}
	cout << ans;
}