#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n, m;
int cur = 1;
int v[105];
int ans = 1;

void func(int k, int loc)
{
	if (k == m || loc == n)
	{
		ans = max(ans, cur);
		return;
	}

	if (loc + 1 <= n)
	{
		cur += v[loc + 1];
		func(k + 1, loc + 1);
		cur -= v[loc + 1];
	}
	if (loc + 2 <= n)
	{
		int tmp = cur;
		cur = cur / 2 + v[loc + 2];
		func(k + 1, loc + 2);
		cur = tmp;
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	func(0,0);

	cout << ans;
	
	return 0;
}

