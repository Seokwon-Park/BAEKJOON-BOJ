#include <bits/stdc++.h>

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
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ed = k - 1;
	vector<int> state(3);
	for (int i = 0; i <= ed; i++)
	{
		state[v[i]]++;
	}
	int t = 0;
	while (state[1] != 0 || state[2] != 0)
	{
		if (state[1] > 0 && state[2] > 0)
		{
			state[1]--;
			state[2]--;
			if (ed != n - 1)
			{
				int newed = min(ed + 2, n - 1);
				for (int i = ed + 1; i <= newed; i++)
				{
					state[v[i]]++;
				}
				ed = newed;
			}
		}
		else if (state[1] > 0)
		{
			state[1]--;
			if (ed != n - 1)
			{
				int newed = ed + 1;
				state[v[newed]]++;
				ed = newed;

			}
		}
		else if (state[2] > 0)
		{
			state[2]--;
			if (ed != n - 1)
			{
				int newed = ed + 1;
				state[v[newed]]++;
				ed = newed;

			}
		}
		t++;
	}

	cout << t;
		
	return 0;
}