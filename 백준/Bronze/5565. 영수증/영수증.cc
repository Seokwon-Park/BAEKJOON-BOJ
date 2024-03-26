#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		int m;
		cin >> m;
		n -= m;
	}
	cout << n;

	return 0;
}