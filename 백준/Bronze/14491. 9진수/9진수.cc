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
	
	int t;
	cin >> t;
	string ans = "";
	while (t)
	{
		ans += t % 9 + '0';
		t /= 9;
	}
	cout << string(ans.rbegin(), ans.rend());
	

	return 0;
}
