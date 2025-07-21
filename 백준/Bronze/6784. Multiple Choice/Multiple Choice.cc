#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int n;
	string s;
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		s.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		if (x == s[i])
		{
			ans++;
		}
	}

	cout << ans;


	return 0;
}