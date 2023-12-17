#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int answer = 1; //길이가 제일 길면 접두어가 될 수 없당

	vector<string> strs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strs[i];
	}

	sort(strs.begin(), strs.end(), [](string a, string b) {return a.length() < b.length(); });

	for (int i = 0; i < n - 1; i++)
	{
		string cmp = strs[i];
		bool isPrefix = false;
		for (int j = i + 1; j < n; j++)
		{
			string tmp = strs[j].substr(0,cmp.length());
			if (tmp == cmp)
			{
				isPrefix = true;
				break;
			}
		}
		if (!isPrefix)
		{
			answer++;
		}
	}

	cout << answer;
	


	return 0;
}