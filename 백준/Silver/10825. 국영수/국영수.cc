#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<tuple<string, int, int, int>> score;
	for (int i = 0; i < n; i++)
	{
		string str;
		int k, e, m;
		cin >> str >> k >> e >> m;
		score.push_back(tie(str, k, e, m));
	}

	sort(score.begin(), score.end(), [](const auto& a, const auto& b)
		{
			string as, bs;
			int ak, ae, am;
			tie(as, ak, ae, am) = a;
			int bk, be, bm;
			tie(bs, bk, be, bm) = b;
			if (ak == bk)
			{
				if (ae == be)
				{
					if (am == bm)
						return as < bs;
					return am > bm;
				}
				return ae < be;
			}
			return ak > bk;
		});


	for (auto tup : score)
	{
		cout << get<0>(tup) << '\n';
	}

	return 0;
}