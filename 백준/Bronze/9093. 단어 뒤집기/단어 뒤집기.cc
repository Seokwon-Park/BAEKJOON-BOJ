#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);

		istringstream iss(str);
		string token;
		vector<string> answer;

		while (getline(iss, token, ' '))
		{
			reverse(token.begin(), token.end());
			answer.push_back(token);
		}

		for (string s : answer)
		{
			cout << s << ' ';
		}
		cout << '\n';
	}
	return 0;
}
