#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	// 닭 a마리 소 b마리
	// y = 2a + 4b
	// x = a+b;
	// 2b = y-2x;
	// 2a = 4x-y;
	
	cout << (4 * x - y) / 2 << ' ' << (y - x * 2) / 2;


	return 0;
}