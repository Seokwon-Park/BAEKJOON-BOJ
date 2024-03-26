#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	for (auto& c : s)
	{
		if (c - 3 < 'A')
			c = c - 3 + 26;
		else
			c = c - 3;
	}
	cout << s;

	return 0;
}