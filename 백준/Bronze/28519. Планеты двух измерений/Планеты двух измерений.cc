#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	if (n == m)
		cout << n + m;
	else
		cout << min(n, m)*2 + 1;
	
	return 0;
}