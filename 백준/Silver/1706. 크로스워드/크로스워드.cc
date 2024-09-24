#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

char b[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
		}
	}

	set<string> st;
	//가로 단어
	for (int i = 0; i < r; i++)
	{
		int cnt = 0;
		string s = "";
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == '#')
			{
				if (cnt > 1)
				{
					st.insert(s);
				}
				s = "";
				cnt = 0;
			}
			else
			{
				cnt++;
				s += b[i][j];
			}
		}
		if (cnt > 1)
		{
			st.insert(s);
		}
	}

	for (int i = 0; i < c; i++)
	{
		int cnt = 0;
		string s = "";
		for (int j = 0; j < r; j++)
		{
			if (b[j][i] == '#')
			{
				if (cnt > 1)
				{
					st.insert(s);
				}
				s = "";
				cnt = 0;
			}
			else
			{
				cnt++;
				s += b[j][i];
			}
		}
		if (cnt > 1)
		{
			st.insert(s);
		}
	}

	cout << *st.begin();
	

	return 0;
}

