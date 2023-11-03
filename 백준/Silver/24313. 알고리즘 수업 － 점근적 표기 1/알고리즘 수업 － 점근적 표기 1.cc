#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a1, a0;
	int c;
	int n0;

	cin >> a1 >> a0 >> c >> n0;

	int fn0 = a1 * n0 + a0;
	int gn0 = c * n0;

	cout << (fn0 <= gn0 && a1 <= c);
			
	return 0;
}