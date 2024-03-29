#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int c;
	cin >> c;
	cout << stoi(a) + stoi(b) - c << '\n';
	cout << stoi(a + b) - c;

	return 0;
}