#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	if (n % 2 == 0)
		cout << "SK";
	else
		cout << "CY";


	return 0;
}