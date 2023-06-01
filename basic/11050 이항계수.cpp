#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;
	else return factorial(n - 1) * n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	cout << factorial(n) / (factorial(n - k) * factorial(k));

	return 0;
}
