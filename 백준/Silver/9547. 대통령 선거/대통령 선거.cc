#include<bits/stdc++.h>

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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int c, v;
		cin >> c >> v;
		vector<int> poll1(c);
		vector<vector<int>> pref(v, vector<int>(c));
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> pref[i][j];
			}
		}
		for (int i = 0; i < v; i++)
		{
			poll1[pref[i][0] - 1]++;
		}
		
		vector<pii> sorted(c);
		for (int i = 0; i < c; i++)
		{
			sorted[i] = { poll1[i], i+1 };
		}
		sort(sorted.begin(), sorted.end(), greater<pii>());
		// 가장 많은 표를 받은 후보 찾기
		
		if (sorted[0].first * 2 > v)
		{
			cout << sorted[0].second << ' ' << 1 << '\n';
			continue;
		}
		// 후보 2명 뽑기
		int cand1 = sorted[0].second;
		int cand2 = sorted[1].second;
		// 2회차 투표
		vector<int> poll2(c);
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (pref[i][j] == cand1 || pref[i][j] == cand2)
				{
					poll2[pref[i][j]-1]++;
					break;
				}
			}
		}
		cout << max_element(poll2.begin(), poll2.end()) - poll2.begin() + 1 << ' ' << 2 << '\n';
	}

	return 0;
}

