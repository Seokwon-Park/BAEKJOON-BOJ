#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool isDefeat[25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> cand(n + 1);
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		getline(cin, cand[i]);
	}

	vector<vector<int>> vote;

	string s;
	while (getline(cin, s))
	{
		istringstream iss(s);
		vector<int> res;
		string tmp;
		while (getline(iss, tmp, ' '))
		{
			res.push_back(stoi(tmp));
		}
		vote.push_back(res);
	}

	int left = n;
	//최대 n번 재투표를 할 수 있음 아마도
	for (int i = 0; i < n; i++)
	{
		vector<int> voteres(n + 1);
		for (int j = 0; j < vote.size(); j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (isDefeat[vote[j][k]])continue;
				voteres[vote[j][k]]++;
				break;
			}
		}

		int mx = 0;
		for (int j = 1; j <= n; j++)
		{
			if (isDefeat[j]) continue;
			mx = max(mx, voteres[j]);
		}

		if (count(voteres.begin() + 1, voteres.end(), mx) == left)//모든 후보가 동점일때
		{
			for (int j = 1; j <= n; j++)
			{
				if (isDefeat[j]) continue;
				cout << cand[j] << '\n';
			}
			return 0;
		}
		else if (mx >= (vote.size() + 1) / 2)
		{
			for (int j = 1; j <= n; j++)
			{
				if (mx == voteres[j])
				{
					cout << cand[j] << '\n';
					return 0;
				}
			}
		}



		int mn = INF;
		for (int j = 1; j <= n; j++)
		{
			if (isDefeat[j]) continue;
			mn = min(mn, voteres[j]);
		}

		for (int j = 1; j <= n; j++)
		{
			if (mn == voteres[j])
			{
				isDefeat[j] = true;
				left--;
			}
		}
	}



	return 0;
}