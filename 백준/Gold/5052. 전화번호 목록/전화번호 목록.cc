#include<bits/stdc++.h>
using namespace std;

const int MX = 10 * 10000 + 5;
const int root = 1;
int unused = 2;
int nxt[MX][10];
bool chk[MX];

int c2i(char c)
{
	return c - '0';
}

void insert(string& s)
{
	int cur = root;
	for (auto c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			nxt[cur][c2i(c)] = unused++;
		}
		cur = nxt[cur][c2i(c)];
		chk[cur] = true;
	}
}

bool find(string& s)
{
	int cur = root;
	for (auto c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			return false;
		}
		cur = nxt[cur][c2i(c)];
	}
	return chk[cur];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		//init trie
		bool is_prefix = false;
		for (int i = 0; i < MX; i++)
		{
			fill(nxt[i], nxt[i] + 10, -1);
		}
		fill(chk, chk + MX, false);
		unused = 2;
		//////////////////////

		int n;
		cin >> n;
		vector<string> nums(n);

		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end(), [](const auto& a, const auto& b)
			{
				return a.length() > b.length();
			});

		for (auto s : nums)
		{
			if (!find(s))
				insert(s);
			else
			{
				is_prefix = true;
				break;
			}
		}

		if (is_prefix)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}