#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, c, p;
	cin >> n >> t >> c >> p;
	n--;
	
	cout << n / t * c * p;

	return 0;
}