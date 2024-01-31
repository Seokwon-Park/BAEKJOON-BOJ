#include<bits/stdc++.h>
using namespace std;

vector<int> failure(string& s)
{
	vector<int> f(s.length());
	int j = 0;
	for (int i = 1; i < s.length(); i++) // 어차피 f[0] 은 자명하게 0이다.
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1]; // 일치 안하면 이전 실패함수를 통해 j의 위치를 갱신
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string t, p;
	getline(cin, t, '\n');
	getline(cin, p, '\n');

	vector<int> f = failure(p);
	int j = 0;
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < t.length(); i++)
	{
		while (j > 0 && t[i] != p[j]) j = f[j - 1];
		if (t[i] == p[j]) j++;
		if (j == p.length())
		{
			cnt++;
			ans.push_back(i + 1 - j + 1); // 1-based indexing(+1)/ t[i]까지 pattern에 포함됨  (탐색시작한 위치)<= 찾는 문자열 범위 <= i 이므로 (+1)
		}
	}

	cout << cnt << '\n';
	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}
