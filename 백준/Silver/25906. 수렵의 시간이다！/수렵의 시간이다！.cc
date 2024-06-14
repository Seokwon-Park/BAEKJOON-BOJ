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
	
	int t, k;
	cin >> t >> k;
	vector<vector<int>> skillInfo(5);
	for (int i = 0; i < 5; i++)
	{
		int l;
		cin >> l;
		skillInfo[i].push_back(0);
		for (int j = 1; j <= l; j++)
		{
			int a;
			cin >> a;
			skillInfo[i].push_back(a);
		}
	}
	int h;
	cin >> h;
	vector<int> head(h+1, 0);
	for (int i = 0; i < h; i++)
	{
		cin >> head[i];
	}
	
	vector<vector<int>> hinfo(h+1, vector<int>(5, 0));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> hinfo[i][j];
		}
	}

	int b;
	cin >> b;
	vector<int> body(b+1);
	for (int i = 0; i < b; i++)
	{
		cin >> body[i];
	}

	vector<vector<int>> binfo(b+1, vector<int>(5, 0));

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> binfo[i][j];
		}
	}

	int p;
	cin >> p;
	vector<int> pants(p+1);
	for (int i = 0; i < p; i++)
	{
		cin >> pants[i];
	}

	vector<vector<int>> pinfo(p+1, vector<int>(5, 0));

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> pinfo[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i <= h; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			for (int x = 0; x <= p; x++)
			{
				int cur = t;
				int cost = head[i] + body[j] + pants[x];
				if (cost > cur)	continue;
				cur -= cost;
				vector<int> total(5, 0);
				int atk = 0;
				for (int s = 0; s < 5; s++)
				{
					total[s] += hinfo[i][s];
					total[s] += binfo[j][s];
					total[s] += pinfo[x][s];
					int lv = min((int)skillInfo[s].size()-1, total[s]);
					atk += skillInfo[s][lv];
					//total[s] = min((int)skillInfo[s].size(), total[s]);
				}
				ans = max(ans, atk);
				if (cur < k) continue;
				// ii-- jj++;
				for (int ii = 0; ii < 5; ii++)
				{
					for (int jj = 0; jj < 5; jj++)
					{
						atk = 0;
						if (ii == jj)continue;
						if (total[ii] == 0) continue;
						total[ii]--;
						total[jj]++;
						for (int s = 0; s < 5; s++)
						{
							int lv = min((int)skillInfo[s].size() - 1, total[s]);
							atk += skillInfo[s][lv];
							//total[s] = min((int)skillInfo[s].size(), total[s]);
						}
						total[ii]++;
						total[jj]--;
						ans = max(ans, atk);
					}
				}
			}
		}
	}
	cout << ans;

	


		
	return 0;
}