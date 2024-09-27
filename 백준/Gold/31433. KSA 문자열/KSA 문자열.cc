#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	string p = "KSA";

	int ans = INF;
	for (int i = 0; i < p.size(); i++)
	{
		int res = i; // 앞에 붙인 값의 길이 "", "K", "KS"
		string str = p.substr(0, i) + s; // 붙인 문자열
		int pix = 0; // 패턴의 시작 위치
		int remove = 0; // KSA 순으로 탐색했을때 삭제해야할 문자 개수
		for (int j = 0; j < str.size(); j++)
		{
			if (p[pix] != str[j])
			{
				remove++;
			}
			else
			{
				pix = (pix + 1) % 3;
			}
		}
		int resLen = str.size() - remove;// 삭제할거 다지우면 길이 얼마임?
		int needToModify = abs((int)s.size() - resLen);
		ans = min(ans, res + remove + needToModify);

	}
	cout << ans;

	return 0;
}

