#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> isUsed(98, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	int mod = n*n%p;
	int ix = 1;
	while (isUsed[mod] == -1)
	{
		isUsed[mod] = ix++;
		mod = mod * n % p;
	}
	cout << ix - isUsed[mod];

	return 0;
}