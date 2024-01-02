#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	string part;
	getline(cin, str);
	getline(cin, part);
	
	int answer = 0;
	for (int i = 0; i < str.length();)
	{
		int loc =  str.find(part, i);
		if (loc != -1)
		{
			i = loc + part.length();
			answer++;
		}
		else
		{
			break;
		}
	}

	cout << answer;


	return 0;
}