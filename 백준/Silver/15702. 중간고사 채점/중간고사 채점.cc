#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	map<int,int> score;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		score[num] = 0;
		for (int j = 0; j < n; j++)
		{
			char res;
			cin >> res;
			if (res == 'O')
			{
				score[num] += v[j];
			}
		}
	}

	auto mx = max_element(score.begin(), score.end(), [](auto a, auto b) 
		{
			if (a.second == b.second)
			{
				return a.first > b.first;
			}
			return a.second < b.second;
		});

	cout << mx->first << ' ' << mx->second;

	return 0;
}