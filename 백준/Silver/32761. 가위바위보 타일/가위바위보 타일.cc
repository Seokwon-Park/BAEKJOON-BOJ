#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	//RSP순서로 반복되도록 하되, 맨앞과 맨 끝도 이어져야 하는듯
	map<char, int> m;
	string p = "RSP";
	for (int i = 0; i < p.size(); i++)
	{
		m[p[i]] = i;
	}
	int ans = INF;
	for (int st = 0; st < p.size(); st++)
	{
		int scur = 0;
		int pcur = st;
		string tmp;
		while (scur < s.size())
		{
			if (s[scur] != p[pcur])
			{
				scur++;
			}
			else
			{
				tmp += s[scur];
				pcur = (pcur + 1) % 3;
				scur++;
			}
		}
		while (!tmp.empty() && (m[tmp.back()] + 1) % 3 != m[tmp.front()])
		{
			tmp.pop_back();
		}
		ans = min(ans, (int)(s.size() - tmp.size()));
	}
	cout << ans;

}