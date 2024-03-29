#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<char, int> m;
	m['k'-'a'] = 0;
	m['p'-'a'] = 1;
	m['n'-'a'] = 3;
	m['b'-'a'] = 3;
	m['r'-'a'] = 5;
	m['q'-'a'] = 9;

	int b= 0;
	int w = 0;
	for(int i = 0; i<8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char c;
			cin >> c;
			if (c >= 'a' && c <= 'z')
				b += m[c - 'a'];
			else
				w += m[c-'A'];
		}
	}
	cout << w- b;

	return 0;
}