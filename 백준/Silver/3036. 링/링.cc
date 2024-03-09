#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int gcd(int a, int b)
{
	if (b == 0) return a;
	int r = a % b;
	return gcd(b, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a;
	cin >> a;
	n--;
	while (n--)
	{
		int b;
		cin >> b;
		int g = gcd(a, b);
		cout << a / g << '/' << b / g << '\n';
	}


	return 0;
}