#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ans[7] = {
	"Never gonna give you up",
	"Never gonna let you down",
	"Never gonna run around and desert you",
	"Never gonna make you cry",
	"Never gonna say goodbye",
	"Never gonna tell a lie and hurt you",
	"Never gonna stop"
	};

	int tc;
	cin >> tc;
	bool chk = false;
	cin.ignore();
	while (tc--)
	{
		string str;
		getline(cin, str);
		if (find(ans, ans + 7, str) - ans == 7)
			chk = true;
	}
	if (chk)
		cout << "Yes";
	else
		cout << "No";



	return 0;
}