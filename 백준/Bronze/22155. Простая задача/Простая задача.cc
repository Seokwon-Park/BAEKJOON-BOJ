#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int i, f;
		cin >> i >> f;
		if ((i <= 1 && f <= 2) || (i <= 2 && f <= 1))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}