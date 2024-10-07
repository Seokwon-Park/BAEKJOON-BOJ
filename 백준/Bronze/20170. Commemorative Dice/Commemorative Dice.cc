#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int total = 36;
	vector<int> dice1, dice2;
	for (int i = 0; i < 6; i++)
	{
		int m;
		cin >> m;
		dice1.push_back(m);
	}

	for (int i = 0; i < 6; i++)
	{
		int m;
		cin >> m;
		dice2.push_back(m);
	}

	int wins = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (dice1[i] > dice2[j])wins++;
		}
	}

	int g = gcd(wins, total);

	cout << wins / g << '/' << total / g;

	return 0;
}

