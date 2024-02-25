#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	while (s.length() != t.length())
	{
		if (t[t.length() - 1] == 'A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	if (s != t)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}



	return 0;
}