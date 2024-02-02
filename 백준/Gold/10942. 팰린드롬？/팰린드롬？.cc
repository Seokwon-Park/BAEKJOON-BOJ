#include<bits/stdc++.h>
using namespace std;

bool dp[2005][2005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) // s, e의 차이
	{
		for (int j = 1; j+i <= n; j++)
		{
			int s = j;
			int e = j + i;
			if (e == s) // 같으면 펠린드롬
			{
				dp[s][e] = 1;
			}
			else if (e - s == 1) // 1칸 떨어져 있으면 둘이 같으면 펠린드롬.
			{
				dp[s][e] = arr[s] == arr[e];
			}
			else // 같지도 않고 한칸 떨어져 있지도 않을때는 양쪽에서 한칸씩 땡긴 구간이 펠린드롬일때, s, e에 있는 값도 같으면 이 구간도 펠린드롬이다.
			{
				if (dp[s + 1][e - 1])
				{
					dp[s][e] = arr[s] == arr[e];
				}
				else
				{
					continue;
				}
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}


	return 0;
}