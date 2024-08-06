#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string sk;
	cin >> sk;
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		bool skip = false;
		for (int st = 0; st < s.size(); st++) // 시작점.
		{
			for (int off = 1; st + off * (sk.size() - 1) < s.size(); off++) // 간격
			{
				bool isFind = true; // st에서 시작해서 간격이 off 단위로 sk 문자열을 탐색해본다.
				for (int j = 0; j < sk.size(); j++)
				{
					if (sk[j] != s[st + j * off])
					{
						isFind = false;
						break;
					}
				}
				if (isFind)
				{
					ans++;
					skip = true;
					break;
				}
			}
			if (skip)
				break;
		}
	}
	cout << ans;

	return 0;
}