#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int e = 0;
	for (auto c : s)
		if (c == 'e')e++;
	cout << 'h';
	for (int i = 0; i < e * 2; i++)
		cout << 'e';
	cout << 'y';

	return 0;
}