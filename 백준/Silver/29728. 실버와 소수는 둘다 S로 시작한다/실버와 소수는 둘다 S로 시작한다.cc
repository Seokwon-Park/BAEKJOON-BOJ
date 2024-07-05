#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<bool> isPrime(n + 1, true);
	isPrime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	bool isRev = false;
	deque<char> a;
	for (int i = 1; i <= n; i++)
	{
		if (!isPrime[i])
		{
			if (isRev)
			{
				a.push_front('B');
			}
			else
			{
				a.push_back('B');
			}
		}
		else
		{
			if (isRev)
			{
				if (a.front() == 'B')
					a.front() = 'S';
				a.push_front('S');

			}
			else
			{
				if (a.back() == 'B')
					a.back() = 'S';
				a.push_back('S');
			}
			isRev = !isRev;
		}
	}

	int b = 0;
	int s = 0;
	for (auto c : a)
	{
		if (c == 'B')
			b++;
		else
			s++;
	}

	cout << b <<' ' << s;

	return 0;
}