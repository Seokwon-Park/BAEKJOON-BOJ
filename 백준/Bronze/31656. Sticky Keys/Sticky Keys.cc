#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	char cur = '\0';
	for (auto c : s)
	{
		if (c != cur)
		{
			cout << c;
			cur = c;
		}
	}

	return 0;
}