#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


void PrintB(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 5; j++)
		{
			cout << '@';
		}
		cout << '\n';
	}
}

void PrintA(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << '@';
		}
		for (int j = 0; j < n * 3; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < n; j++)
		{
			cout << '@';
		}
		cout << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	PrintA(n);
	PrintB(n);
	PrintA(n);
	PrintB(n);
	PrintA(n);

	return 0;
}