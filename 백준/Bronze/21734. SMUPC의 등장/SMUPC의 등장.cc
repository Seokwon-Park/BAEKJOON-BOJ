#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for (auto c : s)
	{
		int tmp = c;
		int sum = 0;
		while (tmp)
		{
			sum += tmp % 10;
			tmp /= 10;
		}
		for (int i = 0; i < sum; i++)
		{
			cout << c;
		}
		cout << '\n';
	}


	return 0;
}

