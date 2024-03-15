#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		if (abs(n) % 2)
			cout << n << " is odd\n";
		else
			cout << n << " is even\n";
	}

	return 0;
}