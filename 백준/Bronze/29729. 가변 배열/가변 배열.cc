#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int s, n, m;
	cin >> s >> n >> m;
	int cur = 0;
	
	for (int i = 0; i < n + m; i++)
	{
		int x;
		cin >> x;
		cur+= (x == 1? 1 : -1);
		if (cur > s)
		{
			s *= 2;
		}
	}
	cout << s;

	

	return 0;
}