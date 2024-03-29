#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> v(2, 0);
	for (char i : s)
	{
		v[i - 'A']++;
	}

	cout << v[0] << " : " << v[1];

	return 0;
}