#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<bool> isPrime(1005, true);

	vector<int> primes;
	for (int i = 2; i <= 1000; i++)
	{
		if (!isPrime[i]) continue;
		else primes.push_back(i);
		for (int j = i * i; j <= 1000; j += i)
			isPrime[j] = false;
	}

	int m = primes.size();
	int tc;
	cin >> tc;
	while (tc--)
	{
		int k;
		cin >> k;
		vector<int> ans;
		bool isFind = false;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int tmp = k - primes[i] - primes[j];
				if (binary_search(primes.begin(), primes.end(), tmp)) 
				{
					ans.push_back(primes[i]);
					ans.push_back(primes[j]);
					ans.push_back(tmp);
					isFind = true;
					break;
				}
			}
			if (isFind)break;
		}
		if (ans.empty())
			cout << 0;
		else
		{
			sort(ans.begin(), ans.end());
			for (int i : ans)
				cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}