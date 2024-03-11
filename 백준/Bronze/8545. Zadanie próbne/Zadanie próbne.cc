#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int ix = 0;
	while (ix < str.length() / 2)
	{
		swap(str[ix], str[str.length() - ix - 1]);
		ix++;
	}
	cout << str;

	return 0;
}