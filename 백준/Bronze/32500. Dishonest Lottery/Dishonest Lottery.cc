#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int cnt[55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n * 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int m;
			cin >> m;
			cnt[m]++;
		}
	}
	set<int> ans;
	for (int i = 1; i <= 50; i++)
	{
		if (cnt[i] > n * 2)
			ans.insert(i);
	}

	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		for (auto i : ans)
			cout << i << ' ';
	}
	
	return 0;
}

