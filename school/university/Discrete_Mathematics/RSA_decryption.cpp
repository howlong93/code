#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>                                                          
                                                                                
void output (const vi&);                                                        
                                                                                
vi num_to_vec (long long x) {                                                   
    vi ret;                                                                     
    while (x) {                                                                 
        ret.push_back (x%10);                                                   
        x /= 10;                                                                
    }                                                                           
    return ret;                                                                 
}                                                                               
                                                                                
bool check (const vi &n) {                                                      
    for (size_t i = 0; i < n.size(); i++)                                       
        if (n[i] != 0) return true;                                             
                                                                                      
    return false;                                                               
}                                                                               
                                                                                
bool compare (const vi &a, const vi &b) {                                       
    if (a.size() < b.size()) return false;                                      
    if (a.size() > b.size()) return true;                                       
    for (size_t i = 0; i < a.size(); i++) {                                     
        if (a[i] < b[i]) return false;                                          
        if (a[i] > b[i]) return true;                                           
    }                                                                           
    return true;                                                                
}                                                                               
                                                                                
vi multi (const vi &a, const vi &b) {                                           
	vi ans = vi (a.size() + b.size(), 0);                                       
                                                                                
    for (size_t i = 0; i < a.size(); i++) {                                     
        for (size_t j = 0; j < b.size(); j++) {                                 
            ans[i+j] += a[i] * b[j];                                            
            if (ans[i+j] >= 10) {                                               
                ans[i+j+1] += ans[i+j] / 10;                                    
                ans[i+j] = ans[i+j] % 10;                                       
            }                                                                   
        }                                                                       
    }                                                                           
                                                                                
    if (ans[ans.size()-1] == 0) ans.pop_back();                                 
                                                                                
    return ans;                                                                 
}                                                                               
                                                                                
long long div (const vi &a, long long b, vi &c) {                               
//  cout << "running division\n";                                               
    long long r = 0;                                                            
    for (int i = a.size()-1; i >= 0; i--) {                                     
        r = r * 10 + a[i];                                                      
        c.push_back (r/b);                                                      
        r %= b;                                                                 
    }                                                                           
    reverse (c.begin(), c.end());                                               
    while (c.size() && c[c.size()-1] == 0) c.pop_back();                        
                                                                                
    return r;                                                                   
}

long long fast_pow (vi m, long long e, long long n) {                           
//  cout << "running power function\n";                                         
    vi ret = {1};                                                               
    long long ans;                                                              
                                                                                
    while (e) {                                                                 
        vi temp;                                                                
        if (e & 1) {                                                            
            ret = multi(ret, m);                                                
            ans = div (ret, n, temp);                                           
            ret = num_to_vec (ans);                                             
        }                                                                       
        m = multi (m, m);                                                       
        long long remain = div (m, n, temp);                                    
        m = num_to_vec (remain);                                                
                                                                                
        e >>= 1;                                                                
    }                                                                           
    return ans;                                                                 
} 

long long gcd_reverse (long long x, long long y) { //y is the larger one
	vector<long long> quot, rem;
	long long a = y, b = x, keep = 0;

	rem.push_back (y);
	rem.push_back (x);

	while (b != 1) {
		rem.push_back (a%b);
		quot.push_back (a/b);
		keep = a%b;
		a = b;
		b = keep;
	}

	long long kl = 0, kr = 0;
	if (quot.size() % 2) kl = 1;
	else kr = 1;

	for (long long j = quot.size()-1; j >= 0; j--) {
		if (j%2 == 0) kr += -(kl * quot[j]);
		else kl += -(quot[j] * kr);
	}

	if (kr < 0) kr += y;

	return kr;
}

int main() {
	long long n, e;
	string s;
	cin >> n >> e;

	long long p, q, phi;
	for (p = 2; p*p <=n; p++) {
		if (n%p == 0) {
			q = n/p;
			break;
		}
	}
	phi = (p-1) * (q-1);

	long long pv_key = gcd_reverse (e, phi);

	char c;
	long long message;
	vi temp;
	while (cin >> message >> c) {
		temp = num_to_vec (message);
		cout << (char)fast_pow (temp, pv_key, n);
	}
	temp = num_to_vec (message);
	cout << (char)fast_pow (temp, pv_key, n);

	return 0;
}
