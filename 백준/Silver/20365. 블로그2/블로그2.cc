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

	int n;
	cin >> n;
	string s;
	cin >> s;

	int red = 0;
	int blue = 0;
	char prev = -1;
	for (int i = 0; i < n; i++)
	{
		if (prev == -1)
		{
			if (s[i] == 'B')
				blue++;
			if (s[i] == 'R')
				red++;
			prev = s[i];
		}
		else if (prev != s[i])
		{
			if (s[i] == 'B')
			{
				blue++;
			}
			if (s[i] == 'R')
				red++;
			prev = s[i];
		}
	}

	if (red > blue)
	{
		cout << 1 + blue;
	}
	else
	{
		cout << 1 + red;
	}


	return 0;
}
