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
	
	int mx = -1;
	string ans;
	for (int i = 0; i < 7; i++)
	{
		string s;
		int n;
		cin >> s >> n;
		if (n > mx)
		{
			mx = n;
			ans = s;
		}
	}
	cout << ans;

	return 0;
}