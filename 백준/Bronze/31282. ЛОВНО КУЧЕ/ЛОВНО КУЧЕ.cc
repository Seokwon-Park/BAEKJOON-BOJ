#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int wolf = 0;
	int rabbit = n;
	int jump = 0;
	while (wolf < rabbit)
	{
		wolf += k;
		rabbit += m;
		jump++;
	}
	cout << jump;

	return 0;
}