#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// 1-2 2-4 3-7 4-10 5-14 6-

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> v(3);
	int i = 0;
	int ans = 0;
	while (i < n)
	{
		if (i == 0)
		{
			ans = 2;
			v[i%3]++;
		}
		else
		{
			ans += v[(i + 1) % 3] + v[(i + 2) % 3]+1;
			v[i % 3]++;
		}
		i++;
	}
	
	cout << ans;


	return 0;
}