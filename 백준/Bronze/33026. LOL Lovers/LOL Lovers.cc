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

	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = 0;
	int o = 0;
	for (auto c : s)
	{
		if (c == 'L') l++;
		if (c == 'O') o++;
	}

	int cl = 0;
	int co = 0;
	
	int ans = -1;

	for(int i = 0; i< s.size()-1; i++)
	{
		if (s[i] == 'L') cl++;
		if (s[i] == 'O') co++;
		if (l - cl != cl && o - co != co)
		{
			ans = i+1;
			break;
		}
	}

	cout << ans;

	return 0;
}