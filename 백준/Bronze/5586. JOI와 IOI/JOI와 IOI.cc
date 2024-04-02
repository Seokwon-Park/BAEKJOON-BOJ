#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int joi = 0;
	int ioi = 0;
	int n = s.size();
	for (int i = 0; i < n - 2; i++)
	{
		if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') joi++;
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') ioi++;
	}

	cout << joi << '\n' << ioi;

	return 0;
}