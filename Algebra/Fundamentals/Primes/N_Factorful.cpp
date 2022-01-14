/**
 * SPOJ - N-Factorful
 * https://www.spoj.com/problems/NFACTOR/
 * https://vjudge.net/problem/SPOJ-NFACTOR
 *
 * 模拟解法会超时, 需要使用动态规划：
 * f(i, j)表示小于i的只有j质因数的数的个数。
 * i = 1时，f(i, j) = 0;
 * 如果i有j个质因数，f(i, j) = f(i - 1, j) + 1；
 * 否则，f(i, j) = f(i - 1, j)。
 * 因此最后的答案是： f(b, n) - f(a - 1, n)
 *
 * @File:   N_Factorful.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-04
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 0xAC;
const int K = 11;

vector<int> no_of_factors(N, 0);
vector <vector<int>> ans(N, vector<int>(K, 0));

// 初始化状态转移矩阵
void precompute_prime_factors()
{
	for (long long i = 2; i < N; i++) {
		if (no_of_factors[i] == 0) {
			for(long long j = i; j < N; j += i)
				no_of_factors[j]++;
		}
	}

	ans[0][0] = 0;
	for (int i = 1; i < N; i++) {
		for(int j = 1; j < K; j++)  // 先假设i是质数
			ans[i][j] = ans[i - 1][j];
		ans[i][no_of_factors[i]]++; // i不是质数，则对应的状态+1
		ans[i][0] = 1;  // 1 没有质因数
	}
}

int main(void)
{
	int t;

	precompute_prime_factors();
	cin >> t;
	while (t--) {
		int a, b, n;

		cin >> a >> b >> n;
		cout <<  ans[b][n] - ans[a - 1][n] << '\n';
	}
	return 0;
}
