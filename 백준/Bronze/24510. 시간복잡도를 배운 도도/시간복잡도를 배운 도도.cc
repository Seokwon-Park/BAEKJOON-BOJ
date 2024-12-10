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
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		string s; 
		cin >> s;
		int res = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'f')
			{
				if (s.substr(j, 3) == "for")
				{
					res++;
				}
			}
			if (s[j] == 'w')
			{
				if (s.substr(j, 5) == "while")
				{
					res++;
				}
			}
		}
		mx = max(res, mx);
	}

	cout << mx;
	

	return 0;
}