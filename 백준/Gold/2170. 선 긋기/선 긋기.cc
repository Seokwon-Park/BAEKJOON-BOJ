#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<long long, long long>> lines;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		lines.push_back({ s,e });
	}

	sort(lines.begin(), lines.end());
	long long ptst = INT_MIN;
	long long pted = INT_MIN;
	long long answer = 0;
	for (auto [st, ed]: lines)
	{
		if (pted < st)
		{
			answer+= pted - ptst;
			ptst = st;
			pted = ed;
		}
		else
		{
			if (pted < ed)
			{
				pted = ed;
			}
		}
	}
	answer += pted - ptst;

	cout << answer;
	return 0;
}
