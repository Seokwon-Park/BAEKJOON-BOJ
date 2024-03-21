#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int board[1005][6]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vec<set<int>> frs(n + 1);
	for(int i = 1; i<= n; i++)
		for (int j = 1; j <= 5; j++)
		{
			cin >> board[i][j];
		}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i != k && board[i][j] == board[k][j])
				{
					frs[i].insert(k);
				}
			}
		}
	}

	int ans = 0;
	int mx = INT_MIN;
	for (int i = 1; i<=n;i++)
	{
		if ((int)frs[i].size() > mx)
		{
			mx = frs[i].size();
			ans = i;
		}
	}

	cout << ans;
	
	return 0;
}