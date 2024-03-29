#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string ans(5, '0');
	string s;
	cin >> s;
	for (auto c : s)
	{
		if (c == 'M')
			ans[0] = c;	
		if (c == 'O')
			ans[1] = c;
		if (c == 'B')
			ans[2] = c;
		if (c == 'I')
			ans[3] = c;
		if (c == 'S')
			ans[4] = c;
	}

	if (ans == "MOBIS")
		cout << "YES";
	else
		cout << "NO";

	return 0;
}