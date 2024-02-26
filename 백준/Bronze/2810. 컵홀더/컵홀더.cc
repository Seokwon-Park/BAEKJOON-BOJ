#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	int hold = 1;
	int ix = 0;
	while (ix < n)
	{
		if (str[ix] == 'S')
		{
			hold++;
			ix++;
		}
		else // 'LL'
		{
			hold++;
			ix += 2;
		}
	}

	cout << min(n, hold);

	return 0;
}
