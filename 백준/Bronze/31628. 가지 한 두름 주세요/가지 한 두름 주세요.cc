#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

string v[10][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		bool isAns = true;
		string first = v[i][0];
		for (int j = 1; j < 10; j++)
		{
			if (first != v[i][j])
			{
				isAns = false;
				break;
			}
		}
		if (isAns)
		{
			cout << 1;
			return 0;
		}
		isAns = true;
		first = v[0][i];
		for (int j = 1; j < 10; j++)
		{
			if (first != v[j][i])
			{
				isAns = false;
				break;
			}
		}
		if (isAns)
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}