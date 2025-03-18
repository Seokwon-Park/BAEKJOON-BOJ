#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	int m = 8;
	int y = 2024;
	y += (m - 1 + 7 * (n-1)) / 12;
	m = (m - 1 + 7 * (n-1)) % 12 + 1;
	cout << y << ' ' << m;
	
	
	

	return 0;
}



