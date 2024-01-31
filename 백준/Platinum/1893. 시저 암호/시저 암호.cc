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

	int tc;
	cin >> tc;

	while (tc--)
	{
		string a, w, s;
		cin >> a >> w >> s;
		vector<int> f = failure(w);

		unordered_map<char, char> nxt;

		for (int i = 0; i < a.length(); i++)
		{
			nxt[a[i]] = a[(i + 1) % a.length()];
		}
				
		
		vector<int> ans;
		for (int shift = 0; shift < a.length(); shift++) 
			// 국어를 잘해야 하는 것 같다.
			// 1번 shift 했는데 암호화방법을 찾았다
			// 그러면 암호문을 최대 shift 길이 - 1번 만큼 shift 해야 해당 암호문으로 암호화 할 수 있다는 뜻.
			// 근데 여기서는 일단 shift=0일 때부터 암호문을 shift하기 때문에 실제 암호문에 대해 shift한 횟수는 (shift + 1)/a.length()
			// (shift + 1)/a.length()의 값을 구하면 실제로는 암호문에서 shift 횟수 만큼 역 shift를 해줘야 얼마나 shift했는지 알 수 있음
			// 사실 그냥 w를 계속 바꿔주도록 푸는게 더 이해하기 쉬운 것 같다.
		{
			string ns = "";
			for (int j = 0; j < s.length(); j++)
			{
				ns += nxt[s[j]];
			}
			s = ns;
			//cout << ns << '\n';

			int cnt = 0;
			int j = 0;
			for (int i = 0; i < ns.length(); i++)
			{
				while (j > 0 && ns[i] != w[j]) j = f[j - 1];
				if (ns[i] == w[j]) j++;
				if (w.length() == j)
				{
					cnt++;
					j = f[j - 1];
				}
			}
			if (cnt == 1)
			{
				ans.push_back(a.length() - (shift+1));
			}
		}

		sort(ans.begin(), ans.end());
		if (ans.empty())
		{
			cout << "no solution\n";
		}
		else if (ans.size() == 1)
		{
			cout << "unique: " << ans[0];
			cout << '\n';
		}
		else
		{
			cout << "ambiguous: ";
			for (auto s : ans)
			{
				cout << s << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
