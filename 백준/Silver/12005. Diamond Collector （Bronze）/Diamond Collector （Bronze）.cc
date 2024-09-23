#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int cnt[10005];
int pfsum[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = i; j < n; j++)
		{
			if (v[j] - v[i] <= k)
				cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << ans;
	

	return 0;
}

