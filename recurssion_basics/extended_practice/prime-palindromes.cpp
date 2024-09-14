/*

Prime Palindromes

Description
A number which is both a prime number as well as palindrome is called a Prime Palindrome. 
151 is a prime as well as a palindrome, hence 151 is a prime palindrome.
Your task is to find the count of Prime Palindromes belonging to the given range [a, b].

Input Format
The only line of input contains two space-separated numbers: a and b.

Output Format
Print the count to Prime Palindromes in-between the range [a, b].

Constraints
2 ≤ a ≤ b ≤ 109

Sample Input 1
5 500
Sample Output 1
12

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll a, b;
ll ans = 0;

bool isPrime(ll x) {
	for(ll i = 2; i * i <= x; i++) {
		if(x % i == 0) 
			return false;
	}
	return true;
}

void solve(ll cur, ll totalLen, ll curLen) {
	if(curLen == (totalLen + 1) / 2) {
		vector<int> d;
		ll temp = cur;
		while(temp) {
			d.push_back(temp % 10);
			temp /= 10;
		}
		temp = cur;
		for(int i = (totalLen % 2); i < (int)d.size(); i++) {
			temp *= 10;
			temp += d[i];
		}
		if(temp <= b && temp >= a && isPrime(temp)) {
			ans++;
		}
		return;
	}

	for(ll i = 0; i < 10; i++) {
		cur *= 10; cur += i;
		solve(cur, totalLen, curLen + 1);
		cur /= 10;
	}
	return;
} 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> a >> b;

    ll len = 0, temp = b;
    while(temp) {
    	len++;
    	temp /= 10;
    }

    for(ll i = 1; i <= len; i++) {
    	for(ll j = 1; j < 10; j++) {
    		solve(j, i, 1LL);
    	}
    }

    cout << ans << "\n";

    return 0;
}