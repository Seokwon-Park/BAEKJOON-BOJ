#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	for (int i = 0; i < 3; i++)
	{
		string s;
		cin >> s;
		int cont = 1;
		int prev = 0;
		int mx = 0;
		for (char c : s)
		{
			int n = c - '0';
			if (n != prev)
			{
				prev = n;
				mx = max(mx, cont);
				cont = 1;
			}
			else
			{
				cont++;
			}
		}
		mx = max(mx, cont);
		cout << mx << '\n';
	}

	return 0;
}