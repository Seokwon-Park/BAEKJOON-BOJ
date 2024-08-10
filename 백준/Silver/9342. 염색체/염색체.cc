#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		int acnt = 0;
		while (s[acnt] == 'A') acnt++;
		if (acnt == 0)
		{
			if (s[0] != 'B' && s[0] != 'C' && s[0] != 'D' && s[0] != 'E' && s[0] != 'F')
			{
				cout << "Good\n";
				continue;
			}
			else
			{
				acnt = 1;
				while (s[acnt] == 'A') acnt++;
			}
		}
		int fcnt = acnt;
		while (s[fcnt] == 'F') fcnt++;
		if (fcnt - acnt == 0)
		{
			cout << "Good\n";
			continue;
		}

		int ccnt = fcnt;
		while (s[ccnt] == 'C') ccnt++;
		if (ccnt - fcnt == 0)
		{
			cout << "Good\n";
			continue;
		}

		if (ccnt + 1 < s.size())
		{
			cout << "Good\n";
			continue;
		}
		else if (ccnt + 1 == s.size())
		{
			if (s[ccnt] != 'B' && s[ccnt] != 'C' && s[ccnt] != 'D' && s[ccnt] != 'E' && s[ccnt] != 'F')
			{
				cout << "Good\n";
				continue;
			}
		}

		cout << "Infected!\n";
	}


	return 0;
}