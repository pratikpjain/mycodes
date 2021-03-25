/*

	Date-Time: 25-03-2021 13:57:14
	author: Pratik Jain

*/

#include <bits/stdc++.h>
using namespace std;

/***********************competetive programming setup*******************************/

#define INF 1e9
#define all(v) v.begin() , v.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define test(t) int t; cin>>t; while(t--)
#define lower(str) transform(str.begin() , str.end() , str.begin() , ::tolower)
#define upper(str) transform(str.begin() , str.end() , str.begin() , ::toupper)
#define loop(i , startloop , endloop) for(i = startloop ; i < endloop ; i++)
#define rloop(i , startloop , endloop) for(i = startloop ; i > endloop ; i--)
#define SMALL(c) c >= 'a' && c <= 'z'
#define CAP(c) c >= 'A' && c <= 'Z'
#define DIGIT(c) c >= '0' && c <= '9'
#define sz(v) v.size()
#define SORT(v) sort(v.begin() , v.end())
#define is_vowel(c) c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
#define YN(var) if(var) cout << "YES"; else cout << "NO";
#define ln cout << '\n'
#define set_bits(n) __builtin_popcount(n)
#define trail_zero(n) __builtin_ctz(n)
#define lead_zero(n) __builtin_clz(n)

void input_output() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
}
/* competetive programming setup */

// check whether a number is prime
bool is_prime(int n) {
	if (n < 2) return false;
	int i;
	loop(i , 2 , (int)sqrt(n) + 1) {
		if (n % i == 0)
			return false;
	}
	return true;
}

//check whether a string is a palindrome
bool is_palindrome(string s) {
	int i;
	loop(i , 0 , s.size() / 2) {
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

// sieve of eratosthenes
int no_of_primes = 20;
vector<bool> prime(no_of_primes + 1 , true);
vi prime_nums;
void sieve_of_erat() {
	prime[0] = false;
	prime[1] = false;
	int i , j;
	loop(i , 2 , (int)sqrt(no_of_primes) + 1) {
		if (prime[i] == false) continue;
		j = 2 * i;
		while (j <= no_of_primes) {
			prime[j] = false;
			j += i;
		}
	}
	loop(i , 0 , no_of_primes + 1) {
		if (prime[i] == true)
			prime_nums.pb(i);
	}
}
// bfs with adj matrix
vector<vector<int> > adj;
vector<bool> visited;
int bfs(int si , int n) {
	vi dist(n + 1 , -1);
	dist[si] = 0;
	queue<int> q;
	q.push(si);
	int i;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (i = 0 ; i < adj[temp].size() ; i++) {
			if (!visited[adj[temp][i]]) {
				q.push(adj[temp][i]);
				dist[adj[temp][i]] = dist[temp] + 1;
				visited[adj[temp][i]] = true;
			}
		}
	}
	int ans = 0;
	loop(i , 0 , n + 1) if (dist[i] != -1) ans++;
	return ans;
}
// swap two numbers
void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}
//sort array in reverse order
bool sort_rev(int a , int b) {
	return a > b;
}
/***********************competetive programming setup*******************************/

// "<<" is "left" shift(increase value)
// ">>" is "right" shift(decrease value)

// this is 'solve' function where main logic is written //
void solve() {
	string s;
	cin >> s;
	int i , j;
	int n = sz(s);
	i = n - 1;
	while (i >= n / 2) {
		if (s[i] > s[(n - 1) - i]) {
			s[i] = s[(n - 1) - i];
			j = i - 1;
			bool flag = true;
			while (j >= 0 && flag) {
				if (s[j] == '9' && flag) {
					s[j] = '0';
				}
				else if (flag) {
					flag = false;
					s[j]++;
				}
				--j;
			}
		}
		else if (s[i] < s[(n - 1) - i]) {
			s[i] = s[(n - 1) - i];
		}
		--i;
	}
	i = n - 1;
	while (i >= n / 2) {
		s[i] = s[(n - 1) - i];
		--i;
	}
	cout << s;
	ln;
}

int main() {
	// comment below line while submitting the code //
	input_output();
	// sieve_of_erat();
	test(t)
	solve();
}


