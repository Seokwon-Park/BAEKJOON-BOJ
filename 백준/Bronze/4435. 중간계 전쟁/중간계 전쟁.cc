#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int gan[6] = { 1,2,3,3,4,10 };
int sau[7] = { 1,2,2,2,3,5,10 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int a = 0;
		int b = 0;
		for (int j = 0; j < 6; j++)
		{
			int n;
			cin >> n;
			a += n * gan[j];
		}

		for (int j = 0; j < 7; j++)
		{
			int n;
			cin >> n;
			b += n * sau[j];
		}
		cout << "Battle " << i << ": ";
		if (a > b)
		{
			cout << "Good triumphs over Evil";
		}
		else if (a < b)
		{
			cout << "Evil eradicates all trace of Good";
		}
		else
		{
			cout << "No victor on this battle field";
		}
		cout << '\n';
		
	}



	return 0;
}