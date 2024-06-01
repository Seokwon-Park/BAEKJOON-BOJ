#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int win1=0, win2=0;
		for (int i = 0; i < n; i++)
		{
			char p1, p2;
			cin >> p1 >> p2;
			if (p1 != p2)
			{
				if (p1 == 'R' && p2 == 'P')
					win2++;
				else if (p1 == 'P' && p2 == 'S')
					win2++;
				else if (p1 == 'S' && p2 == 'R')
					win2++;
				else
					win1++;
			}
		}
		if (win1 == win2)
		{
			cout << "TIE";
		}
		else if (win1 > win2)
		{
			cout << "Player 1";
		}
		else
		{
			cout << "Player 2";
		}
		cout << '\n';
	}
	return 0;
}