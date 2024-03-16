#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

bool isPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool isPelin(int n)
{
	int tmp = n;
	int rev = 0;
	while (tmp)
	{
		rev *= 10;
		rev += tmp % 10;
		tmp /= 10;
	}
	return rev == n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	while (!isPrime(n) || !isPelin(n)) n++;
	cout << n;
	
	return 0;
}