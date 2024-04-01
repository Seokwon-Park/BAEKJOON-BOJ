#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);

	string p = "UCPC";
	int findc = 0;
	for (char c : s)
	{
		if (c == p[findc])
			findc++;
		if (findc == 4)
		{
			cout << "I love UCPC";
			return 0;
		}
	}
	cout << "I hate UCPC";

	return 0;
}