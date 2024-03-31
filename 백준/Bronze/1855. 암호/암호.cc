#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w;
	cin >> w;
	string s;
	cin >> s;
	int h = s.size() / w;
	
	vector<string> b(h);
	for (int i = 0; i < h; i++)
	{
		if (i % 2)
		{
			string tmp = s.substr(i * w, w);
			b[i] = string(tmp.rbegin(), tmp.rend());
		}
		else
		{
			b[i] = s.substr(i * w, w);
		}
	}
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			cout << b[j][i];
		}
	}

	return 0;
}