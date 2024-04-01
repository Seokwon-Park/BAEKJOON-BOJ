#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	while(n--)
	{
		string s;
		getline(cin, s);
		s[0] = toupper(s[0]);
		cout << s << '\n';

	}

	return 0;
}