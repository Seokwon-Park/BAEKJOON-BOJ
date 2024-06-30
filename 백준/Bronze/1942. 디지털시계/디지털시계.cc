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
	
	vector<string> s(6);
	vector<vector<int>> hms(6);

	for(int i = 0; i< 6; i++)
	{
		cin >> s[i];
		istringstream iss(s[i]);
		string tmp;
		while (getline(iss, tmp, ':'))
		{
			hms[i].push_back(stoi(tmp));
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int stm = hms[i*2][0] * 60 + hms[i*2][1] + 1;
		int enm = hms[i*2 + 1][0] * 60 + hms[i*2 + 1][1];
		
		int sts = (stm-1) * 60 + hms[i*2][2];
		int ens = enm * 60 + hms[i*2+1][2];

		int ans = 0;
		if (sts > ens)
		{
			for (int j = hms[i * 2][2]; j < 60; j++)
			{
				if ((hms[i * 2][0] * 10000 + hms[i * 2][1] * 100 + j) % 3 == 0)
					ans++;
			}
			ans += ((24*60 - stm) + enm) * 20;
			for (int j = 0; j <= hms[i * 2 + 1][2]; j++)
			{
				if ((hms[i * 2 + 1][0] * 10000 + hms[i * 2 + 1][1] * 100 + j) % 3 == 0)
					ans++;
			}
		}
		else
		{
			for (int j = hms[i*2][2]; j < 60; j++)
			{
				if ((hms[i*2][0] * 10000 + hms[i*2][1] * 100 + j) % 3 == 0)
					ans++;
			}
			ans += (enm - stm) * 20;
			for (int j = 0; j <= hms[i*2+ 1][2]; j++)
			{
				if ((hms[i*2+1][0] * 10000 + hms[i*2+1][1] * 100 + j) % 3 == 0)
					ans++;
			}
		}
		cout << ans << '\n';
	}


	return 0;
}