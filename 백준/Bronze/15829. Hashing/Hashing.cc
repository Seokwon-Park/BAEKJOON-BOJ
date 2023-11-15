#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l;
	int r = 1;
	cin >> l;

	int hash = 0;
	int m = 1234567891;
	for (int i = 0; i < l; i++)
	{
		char c;
		cin >> c;

		int charToInt = c - 'a' + 1;
		hash += (charToInt * r) % m;
		r = (r * 31) % m;		
	}

	cout << hash;

	return 0;
}