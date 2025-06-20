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

	int tc;
	cin >> tc;
	for(int ix = 1; ix <= tc; ix++)
	{
		int M, N, P;
		cin >> M >> N >> P;
		vector<vector<int>> correct(P + 5, vector<int>(M + 5));
		vector<vector<int>> wrong(P + 5, vector<int>(M + 5));

		vector<vector<int>> v(P, vector<int>(3, 0));
		for (int i = 0; i < P; i++)
		{
			v[i][0] = i + 1;
		}

		for (int i = 0; i < N; i++)
		{
			int p,m, t, j;
			char ch;
			cin >> p >> ch >> t >> j;
			m = ch - 'A';
			if (j == 1)
			{
				if (correct[p][m] == false)
				{
					correct[p][m] = true;
					v[p - 1][2] += t + wrong[p][m] * 20;
					v[p - 1][1]++;
				}
				else
				{
					continue;
				}
			}
			else
			{
				wrong[p][m]++;
			}
		}
		sort(v.begin(), v.end(), [](auto& a, auto& b)
			{
				if (a[1] == b[1])
				{
					return a[2] < b[2];
				}
				return a[1] > b[1];
			});

		cout << "Data Set " << ix << ":\n";
		for (int i = 0; i < P; i++)
		{
			cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << '\n';
		}
		cout << '\n';
		
	}



	return 0;
}