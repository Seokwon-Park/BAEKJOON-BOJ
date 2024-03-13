#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c; // 3*b/a = x/c
	cin >> a >> b >> c;

	cout << 3 * b / a * c;
	
	return 0;
}