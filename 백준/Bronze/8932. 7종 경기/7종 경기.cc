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

	vector<double> A = { 9.23076, 1.84523, 56.0211, 4.99087 ,0.188807 ,15.9803 ,0.11193 };
	vector<double> B = { 26.7, 75, 1.5, 42.5, 210, 3.8, 254 };
	vector<double> C = { 1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88 };
	vector<bool> type = { 0,1,1,0,1,1,0};

	int tc;
	cin >> tc;
	while (tc--)
	{
		int res = 0;
		for (int i = 0; i < 7; i++)
		{
			double input;
			cin >> input;
			if (type[i] == 0)
			{
				res += A[i] * pow((B[i] - input), C[i]);
			}
			else
			{
				res += A[i] * pow((input - B[i]), C[i]);
			}
		}
		cout << res << '\n';
	}


	return 0;
}