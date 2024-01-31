#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		long long a, b;
		cin >> a >> b;
		long long g = gcd(a, b);
		long long l = a / g * b;
		cout << l << '\n';
	}
	

	return 0;
}
