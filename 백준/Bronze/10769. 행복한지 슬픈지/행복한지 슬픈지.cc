#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	getline(cin, s);
	int happy = 0;
	int sad = 0;
	for (int i = 0; i < s.size() - 2; i++)
	{
		if (s[i] == ':' && s[i+1] == '-')
		{
			if (s[i + 2] == ')')
			{
				happy++;
				i += 2;
			}
			else if (s[i + 2] == '(')
			{
				sad++;
				i += 2;
			}
		}
	}

	if (happy == 0 && sad == 0)
		cout << "none";
	else if (happy == sad)
		cout << "unsure";
	else if (happy < sad)
		cout << "sad";
	else
		cout << "happy";

	return 0;
}