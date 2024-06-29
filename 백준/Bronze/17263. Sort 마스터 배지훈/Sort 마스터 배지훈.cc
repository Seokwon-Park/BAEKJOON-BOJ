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

	int mx = -1;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		mx = max(m, mx);
	}

	cout << mx;
	return 0;
}