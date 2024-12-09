#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// 내가 틀린 부분. 승리한 녀석에 대해 체크할때 '.'인 경우도 else에 포함된다는 점을 놓침.
bool CheckIsEnd(string s)
{
	//일단 X가 이겼는지 Y가 이겼는지 검사한다.
	int o = 0;
	int x = 0;
	for (auto c : s)
	{
		if (c == 'O')
			o++;
		else if (c == 'X')
			x++;
	}
	bool IsOWin = false;
	bool IsXWin = false;
	for (int i = 0; i < 3; i++)
	{
		if (s[i * 3] == s[i * 3 + 1] && s[i * 3 + 1] == s[i * 3 + 2])
		{
			if (s[i * 3] == 'O')
				IsOWin = true;
			else if(s[i * 3] == 'X')
				IsXWin = true;
			
		}
		if (s[i] == s[3 + i] && s[3 + i] == s[6 + i])
		{
			if (s[i] == 'O')
				IsOWin = true;
			else if(s[i] == 'X')
				IsXWin = true;
		}
	}
	if (s[0] == s[4] && s[4] == s[8])
	{
		if (s[0] == 'O')
			IsOWin = true;
		else if(s[0] == 'X')
			IsXWin = true;
	}
	if (s[2] == s[4] && s[4] == s[6])
	{
		if (s[2] == 'O')
			IsOWin = true;
		else if (s[2] == 'X')
			IsXWin = true;
	}

	//둘다 이기는 경우는 없어.
	if (IsOWin && IsXWin)
		return false;
	else if (IsOWin) // O가 이겼을 때는 O와 x의 수가 같아야 한다.
	{
		if (o != x)
		{
			return false;
		}
	}
	else if (IsXWin) // X가 이겼을 때는 O보다 X의 수가 하나 더 많아야 한다.
	{
		if (o+1 != x)
		{
			return false;
		}
	}
	else
	{
		if (x + o != 9 || o + 1 != x)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	vector<string> ans;
	while(cin >> s)
	{
		if (s == "end") break;
		if (CheckIsEnd(s) == false)
		{
			ans.push_back("invalid");
		}
		else
		{
			ans.push_back("valid");
		}
	}
	for (auto str : ans)
	{
		cout << str;
		cout << '\n';
	}

	return 0;
}