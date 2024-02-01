#include<bits/stdc++.h>
using namespace std;

vector<int> failure(string& s)
{
	vector<int> f(s.size());
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string str;
		cin >> str;
		if (str == ".") break;

		int ans = 1;
		vector<int> f = failure(str); // 실패함수 구하기.
		int len = str.size() - *f.rbegin(); // 반복되어야 하는 접두사의 길이의 최댓값..?  
		if (str.size() % len == 0)
		{
			cout << str.size() / len << '\n';
		}
		else
		{
			cout << 1 << '\n';
		}
	}

	return 0;
}
