#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	
	vector<string> res;
	string tmp = "";
	if (n == 1 || n == 3)
	{
		for (auto c : s)
		{
			if (c <= 'Z' && c >= 'A')
			{
				if (!tmp.empty())
					res.push_back(tmp);
				// tmp = "" + c; //""라는 문자열 리터럴 주소에 c값 만큼 더한 주소에 있는 문자열을 tmp로 가져와서 이상해짐 ㅋ;;
				tmp = "";
				tmp += tolower(c);
			}
			else
			{
				tmp += c;
			}
		}
		res.push_back(tmp);
	}
	else if (n == 2)
	{
		istringstream iss(s);
		while (getline(iss, tmp, '_'))
			res.push_back(tmp);
	}

	cout << res[0];
	for (int i = 1; i < res.size(); i++)
	{
		tmp = res[i];
		tmp[0] = toupper(tmp[0]);
		cout << tmp;
	}
	cout << '\n';
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << '_';
	}
	cout << '\n';
	for (int i = 0; i < res.size(); i++)
	{
		tmp = res[i];
		tmp[0] = toupper(tmp[0]);
		cout << tmp;
	}


	return 0;
}