#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;

bool isPrime(int num)
{
	if (num == 1) return false;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}


void func(int k, string num)
{
	if (!num.empty() && !isPrime(stoi(num))) return;
	if (n == k)
	{
		cout << num << '\n';
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		func(k + 1, num + (char)(i + '0'));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	func(0, "");

	return 0;
}
