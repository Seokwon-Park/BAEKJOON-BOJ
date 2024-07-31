#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n;
	cin >> a >> b >> n;
	
	string ans = to_string(a);

	vector<bool> isPrime(100, true);

	for (int i = 2; i * i <= 99; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 99; j += i)
		{
			isPrime[j] = false;
		}
	}

	while (ans.size() < n-2)
	{
		int back = ans.back() - '0';
		for (int i = 1; i <= 9; i++)
		{
			int num = back * 10 + i;
			if (isPrime[num])
			{
				ans.push_back(i + '0');
				break;
			}
		}
	}

	int back = ans.back() - '0';
	int front = b / 10;
	if (front % 2 == 0 || front % 5 == 0)
	{
		cout << -1;
	}
	else
	{
		ans += to_string(b);
		cout << ans;
	}




	return 0;
}