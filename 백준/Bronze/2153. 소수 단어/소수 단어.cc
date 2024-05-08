#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int res = 0;
	for (auto c : s)
	{
		if (c <= 'z' && c >= 'a')
		{
			res += (c - 'a' + 1);
		}
		else
		{
			res += (c - 'A' + 27);
		}
	}
		
	for (int i = 2; i * i <= res; i++)
	{
		if (res % i == 0)
		{
			cout << "It is not a prime word.";
			return 0;
		}
	}
	cout << "It is a prime word.";

	return 0;
}