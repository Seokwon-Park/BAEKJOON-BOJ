#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	istringstream iss(s);
	string n;
	int ans = 0;
	while (getline(iss, n, ','))
	{
		ans += stoi(n);
	}
	cout << ans;

	return 0;
}