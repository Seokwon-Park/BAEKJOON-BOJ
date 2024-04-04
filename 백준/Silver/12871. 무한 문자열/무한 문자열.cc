#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int k = lcm(s.size(), t.size());

	string sres, tres;
	for (int i = 0; i < k / s.size(); i++)
		sres += s;
	for (int i = 0; i < k / t.size(); i++)
		tres += t;
	if (sres != tres)
		cout << 0;
	else
		cout << 1;


	return 0;
}