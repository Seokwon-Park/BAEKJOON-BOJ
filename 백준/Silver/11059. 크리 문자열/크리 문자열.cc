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

	string s;
	cin >> s;

	vector<int> v(s.size() + 1);
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i] - '0';
		v[i + 1] = v[i] + x;
	}
	
	int ans = 0;
	for (int len = 2; len <= s.size(); len+=2)
	{
		for (int st = 0; st + len <= s.size(); st++)
		{
			int l = v[st + len / 2] - v[st];
			int r = v[st+len] - v[st+len/2]; 
			if (l == r)
			{
				ans = len;
				break;
			}
		}
	}

	cout << ans;



	return 0;
}