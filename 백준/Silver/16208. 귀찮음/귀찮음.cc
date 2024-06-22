#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		sum -= v[i];
		ans += v[i] * sum;
	}
	cout << ans;


	return 0;
}
