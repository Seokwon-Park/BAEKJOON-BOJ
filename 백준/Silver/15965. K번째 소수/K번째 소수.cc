#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<bool> isPrime(10000000, true);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	for (int i = 2; i*i < 10000000; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j < 10000000; j += i)
		{
			isPrime[j] = false;
		}
	}

	int tmp = 2;
	int nth = 1;
	while (nth < k)
	{
		tmp++;
		if (!isPrime[tmp])continue;
		nth++;
	}
	
	cout << tmp;

	return 0;
}