#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		bool IsNeg = (n < 0 ? true : false);

		n = abs(n);
		int k = 0;
		int cur = 1;
		vector<int> res;
		while (n)
		{
			res.push_back(n % 3);
			n /= 3;
		}
		res.push_back(0);
		for (int i = 0; i < res.size() - 1; i++)
		{
			if (res[i] > 1)
			{
				res[i + 1] += 1;
				res[i] -= 3;
			}
		}
		if (res.back() == 0) res.pop_back();
		reverse(res.begin(), res.end());
		for (auto i : res)
		{
			if (i < 0)
			{
				cout << (IsNeg ?'1':'-');
			}
			else if(i>0)
			{
				
				cout << (IsNeg ? '-' : '1');
			}
			else
			{
				cout << i;
			}
		}
		cout << '\n';
	}

	return 0;
}