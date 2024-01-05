#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int tc;
	cin >> tc;
	while (tc--)
	{
		unordered_map <string, int> hsh;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			hsh[b]++;
		}

		int answer = 1;
		for (auto h : hsh)
		{
			answer *= h.second + 1; //해당 종류의 의상가짓수 + 해당 종류를 안입는 경우
		}
		
		cout << answer - 1 << '\n'; //모든 종류를 입지 않는 경우 1을 빼준다.
	}


	return 0;
}