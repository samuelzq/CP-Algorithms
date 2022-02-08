/**
 * Codeforces 622F - The Sum of the k-th Powers
 * http://codeforces.com/problemset/problem/622/F
 * https://vjudge.net/problem/CodeForces-622F
 *
 * @File:   kth_power.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-07
 *
 **/
#include <bits/stdc++.h>
using namespace std;

// A global array to store factorials
const int MAX_K = 1e6;
const int MOD = 1e9 + 7;
long long fac[MAX_K + 1];
long long fac_inv[MAX_K + 1];
long long arr[MAX_K + 1];


int bpower(int a, int b)
{
	int ret = 1;
	long long t = 1LL * a;

	while (b) {
		if (b & 1)
			ret = ret * t % MOD;
		b >>= 1;
		t = t * t % MOD;
	}
	return ret;
}

// Function to calculate the factorials
// of all the numbers upto k
void factorial(int k)
{
	fac[0] = 1;
	for (int i = 1; i <= k + 1; i++) {
		fac[i] = (i * fac[i - 1]) % MOD;
	}

	fac_inv[k + 1] = bpower(fac[k + 1], MOD - 2);
	for (int i = k; i >= 0; i--)
		fac_inv[i] = fac_inv[i + 1] * (i + 1) % MOD;
}

// Function to return the binomial coefficient
long long unsigned int bin(int a, int b)
{
 
	// nCr = (n! * (n - r)!) / r!
	long long unsigned int ans =
		fac[a] * (fac_inv[a - b] * fac_inv[b] % MOD) % MOD;
	return ans;
}

// Function to return the sum of kth powers of
// n natural numbers
long int sumofn(int n, int k)
{
	int p = 0;

	if (k == 0)
		return n;
	long long unsigned int num1, temp;
	for (int j = 1; j <= k; j++) {

		// When j is unity
		if (j == 1) {
			num1 = (1LL * n * (n + 1)) % MOD * bpower(2, MOD - 2) % MOD;

			// Calculating sum(n^1) of unity powers
			// of n; storing sum(n^1) for sum(n^2)
			arr[p++] = num1;

			// If k = 1 then temp is the result
			temp = num1;
		}
		else {
			temp = (bpower(n + 1, j + 1) - 1 - n + MOD) % MOD ;

			// For finding sum(n^k) removing 1 and
			// n * kCk from (n + 1)^k
			for (int s = 1; s < j; s++) {

				// Removing all kC2 * sum(n^(k - 2))
				// + ... + kCk - 1 * (sum(n^(k - (k - 1))
				temp = temp -
					(arr[j - s - 1] * bin(j + 1, s + 1) % MOD);
				temp = (temp + MOD) % MOD; 
			}
			temp = temp * bpower(j + 1, MOD - 2) % MOD;

			// Storing the result for next sum of
			// next powers of k
			arr[p++] = temp;
		}
	}
	temp = arr[p - 1];
	return temp;
}

// Driver code
int main()
{
	int n = 5, k = 2;
	cin >> n >> k;
	factorial(MAX_K);
	cout << sumofn(n, k) << "\n";
	return 0;
}
