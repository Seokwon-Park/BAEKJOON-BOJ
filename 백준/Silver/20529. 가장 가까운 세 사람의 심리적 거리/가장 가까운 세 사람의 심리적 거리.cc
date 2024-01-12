#include <bits/stdc++.h>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<string> mbti;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			mbti.push_back(str);
		}
		if (n > 32)
		{
			cout << 0 << '\n';
			continue;
		}
		int answer = INT_MAX;
		int val;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
				{
					val = 0;
					for (int l = 0; l < 4; l++)
					{
						if (mbti[i][l] != mbti[j][l]) val++;
						if (mbti[j][l] != mbti[k][l]) val++;
						if (mbti[k][l] != mbti[i][l]) val++;
					}
					answer = min(val, answer);
				}

		cout << answer << '\n';
	}

	return 0;
}