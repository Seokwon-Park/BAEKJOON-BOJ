#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int kor = a / c + (a % c > 0 ? 1 : 0);
	int math = b / d + (b % d > 0 ? 1 : 0);
	cout << l - max(kor, math);

	return 0;
}