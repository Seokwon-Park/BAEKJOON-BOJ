#include<bits/stdc++.h>

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
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 < n && s[i] == 'E' && s[i + 1] == 'W')
			ans++;
	}

	cout << ans;

	return 0;
}