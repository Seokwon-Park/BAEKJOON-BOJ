#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int aix, bix;
	bool isfind = false;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				aix = i;
				bix = j;
				isfind = true;
				break;
			}
		}
		if (isfind) break;
	}

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (i == bix && j == aix)
				cout << a[j];
			else if (i == bix)
				cout << a[j];
			else if (j == aix)
				cout << b[i];
			else
				cout << '.';
		}
		cout << '\n';
	}

	return 0;
}
