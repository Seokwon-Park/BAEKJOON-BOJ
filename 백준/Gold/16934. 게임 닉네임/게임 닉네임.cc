#include <bits/stdc++.h>

using namespace std;

const int root = 1;
int unused = 2;
const int MX = 100000 * 10+5;
int nxt[MX][26];
int chk[MX];

//insert, find, erase

int c2i(char c)
{
	return c - 'a';
}

string insert(string& s)
{
	int cur = root;
	bool chkNick = false;
	string nick = "";
	for (auto c : s)
	{
		if(!chkNick)
			nick += c;
		if (nxt[cur][c2i(c)] == -1)
		{
			nxt[cur][c2i(c)] = unused++;
			chkNick = true;
		}
		cur = nxt[cur][c2i(c)];
	}
	chk[cur]++;
	if (!chkNick && chk[cur] != 1)
	{
		nick += to_string(chk[cur]);
	}

	return nick;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < MX; i++)
	{
		fill(nxt[i], nxt[i] + 26, -1);
	}
	
	int n;
	cin >> n;
	vector<string> nicks;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		nicks.push_back(insert(input));
	}

	for (string n : nicks)
	{
		cout << n << '\n';
	}


	return 0;
}