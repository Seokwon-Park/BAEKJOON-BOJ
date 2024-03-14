//https://codeforces.com/blog/entry/43499 Tutorial on FFT/NTT를 읽고 작성
#include <bits/stdc++.h>

using namespace std;

using cp = complex<double>;
using cpvec = vector<cp>;
const double PI = acos(-1.0); // y= cos (x) => x = acos (y)
// cos (PI) = -1.0  => PI = acos(-1.0);

// coefficient Representation
//  A(x) = a0 + a1 * x^1 + ... an-1 * x^n-1
//  =>  [ a0, a1, a2....] ( 0차항 계수부터 나타내는 것 )
// s.size() = n이라고 하자
// 일단 s를 숫자라고 보면 x=10 인 다항식으로 생각할 수 있다.
// s = s[0]*10^n-1 + s[1] *10^n-2..
// n-1차항부터 나오므로 coef rep를 하기 위해서는 순서를 뒤집어야 한다..
cpvec strToCp(string& s)
{
	int n = s.size();
	cpvec res;
	for (int i = n - 1; i >= 0; i--)
		res.push_back({ double(s[i] - '0'), 0 });
	return res;
}

cpvec FFT(cpvec cv)
{
	int n = cv.size();
	if (n == 1) return cv; // 기저 조건
	cp wn(cos(2 * PI / n), sin(2 * PI / n));
	cp w(1, 0);
	cpvec even;
	cpvec odd;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			even.push_back(cv[i]);
		else
			odd.push_back(cv[i]);
	}

	cpvec even_res = FFT(even);
	cpvec odd_res = FFT(odd);
	cpvec res(n);

	for (int k = 0; k < (n / 2); k++)
	{
		res[k] = even_res[k] + w * odd_res[k];
		res[k + n / 2] = even_res[k] - w * odd_res[k];
		w *= wn;
	}

	return res;
}

// 더 간단하게 만들 수 있을듯
cpvec InvFFT(cpvec cv)
{
	int n = cv.size();
	if (n == 1) return cv; // 기저 조건
	// 짝수항 홀수항으로 나눌것이기 때문에 크기를 절반(앞에서 크기를 2의 거듭제곱으로 만듦)
	cp wn(cos(-2 * PI / n), sin(-2 * PI / n));
	cp w(1, 0);
	cpvec even;
	cpvec odd;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			even.push_back(cv[i]);
		else
			odd.push_back(cv[i]);
	}

	cpvec even_res = InvFFT(even);
	cpvec odd_res = InvFFT(odd);
	cpvec res(n);

	for (int k = 0; k <= (n / 2 - 1); k++)
	{
		res[k] = even_res[k] + w * odd_res[k];
		res[k + n / 2] = even_res[k] - w * odd_res[k];
		w *= wn;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string astr, bstr;
	cin >> astr >> bstr;
	if (astr == "0" || bstr == "0") // 0곱하면 뭘해도 0 처리
	{
		cout << 0;
		return 0;
	}
	cpvec a(strToCp(astr)), b(strToCp(bstr));

	int n = 1;
	int N = max(a.size(), b.size());
	while (n < N) n = n << 1;
	n = n << 1; // 2n차항의 다항식을 구해야하므로 
	a.resize(n, 0);
	b.resize(n, 0);

	a = FFT(a); 
	b = FFT(b);

	cpvec c(n);
	for (int i = 0; i <= (n - 1); i++)
		c[i] = a[i] * b[i];

	c = InvFFT(c);
	for (int k = 0; k <= (n - 1); k++) // 역행렬에 1/n을 곱해줘야한다.
		c[k] /= n;


	vector <int> res(n);
	for (int i = 0; i < n; i++)
	{
		res[i] = round(c[i].real()); // 실수오차 반올림이 필요하다.
	}

	for (int i = 0; i + 1 < n; i++)
	{
		res[i + 1] += res[i] / 10; // 계수가 1의 자리를 넘어가면 다음 계수로 넘김
		res[i] = res[i] % 10;
	}

	// FFT를 위해 차수를 뒤집었으므로 다시 뒤집어야 한다.
	reverse(res.begin(), res.end());
	
	//계수가 0이면 10의 몇제곱이던 0이기 때문에 스킵한다.
	int ix = 0;
	while (res[ix] == 0)
	{
		ix++;
	}
	for (int i = ix; i < res.size(); i++)
	{
		cout << res[i];
	}

	return 0;
}