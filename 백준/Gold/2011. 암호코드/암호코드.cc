#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000

int dp[5005][27]; // i자리 수일때 끝자리가 j번째 알파벳인 경우의 가지수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	str.insert(0, " ");

	for (int i = 1; i < str.length(); i++) // 일단 숫자가 아니면 올바른 암호가 아님.
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			cout << 0;
			return 0;
		}
	}

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1; // ABCDE FGHIJ 까지. 한자리 수일때 나올 수 있는 경우의 수는 1개
	}

	for (int i = 2; i < str.length(); i++)
	{
		int prev = str[i - 1] - '0'; //현재 위치에서 이전 문자열
		int cur = str[i] - '0';
		//dp[i][cur] = dp[i - 1][prev];
		if (cur == 0) // 이 경우에는 무조건 2자리수인 경우만 가능함.
		{
			if (prev * 10 + cur <= 26 && prev != 0) // 두개가 합쳐지려면 -> 앞이 1이거나 2여야 한다. 0은 안된다.
				//dp[i][11]이나 dp[i][23] 이런식으로 두자릿수로 센 경우는 안됨. 그래서 prev(한자릿수)로 끝난 경우와 같은 경우의 수를 갖게 될것
			{
				dp[i][prev * 10 + cur] = dp[i - 1][prev];
			}
		}
		else
		{
			if (prev * 10 + cur <= 26 && prev > 0) // 두개가 합쳐지려면 -> 앞이 1이거나 2여야 한다. 0은 안된다.
				//dp[i][11]이나 dp[i][23] 이런식으로 두자릿수로 센 경우는 안됨. 그래서 prev(한자릿수)로 끝난 경우와 같은 경우의 수를 갖게 될것
			{
				dp[i][prev * 10 + cur] = dp[i - 1][prev];
			}
			for (int j = 1; j <= 26; j++) // 만약 이전 자리수가 5라면 5, 15, 25번째에 대해 모두 cur번째 알파벳을 붙이는 경우가 될 수 있다.
			{
				if (j % 10 != prev) continue;
				dp[i][cur] += dp[i - 1][j];
				dp[i][cur] %= MOD;
			}
		}
	}

	int answer = 0;
	//같은 논리로 dp에서 마지막 알파벳이 2자리수로 끝난 경우, 1자리수로 끝난 경우를 더해준다.
	int prev = str[str.length() - 2] - '0';
	int cur = str[str.length() - 1] - '0';
	if (prev * 10 + cur <= 26 && prev > 0)
	{
		answer += dp[str.length() - 1][prev * 10 + cur];
		dp[str.length() - 1][cur] %= MOD;
	}
	answer += dp[str.length() - 1][cur];
	cout << answer % MOD;

	return 0;
}