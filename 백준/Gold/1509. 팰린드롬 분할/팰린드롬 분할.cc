//풀이를 참고함
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

bool isPelin[2505][2505]; // [a][b] a-b 까지가 펠린드롬인가?
int dp[2505]; // [x] x길이일때 펠린드롬 분할 최솟값

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	// 각 문자 1개는 무조건 펠린드롬
	for (int i = 1; i <= s.size(); i++)
	{
		isPelin[i][i] = true;
	}

	// 붙어있는 둘이 같으면 펠린드롬 AA, BB
	for (int i = 1; i <= s.size() - 1; i++)
	{
		if (s[i-1] == s[i])
		{
			isPelin[i][i + 1] = true;
		}
	}

	// 펠린드롬인 값의 양옆이 같으면 펠린드롬(길이 3부터)
	for (int len = 1; len <= s.size()-1; len++)
	{
		for (int st = 1; st + len + 1 <= s.size(); st++)
		{
			if (isPelin[st + 1][st + len] && s[st-1] == s[st + len])
			{
				isPelin[st][st + len + 1] = true;
			}
		}
	}

	for (int en = 1; en <= s.size(); en++)
	{
		// dp[en]을 아주 큰값으로 설정
		dp[en] = INF;
		for (int st = 1; st <= en; st++)
		{
			//st-en까지가 펠린드롬이면 그 앞까지의 dp값에 1을 더하고 최솟값 갱신
			if (isPelin[st][en] == true)
			{
				dp[en] = min(dp[en], dp[st - 1] + 1);
			}
		}
	}

	cout << dp[s.size()];

	return 0;
}