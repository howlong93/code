#include <iostream>
#include <climits>
#include <algorithm>

#define nullptr NULL

using namespace std;

struct Treap {
	bool rev;
	int value, pri;
	int sz, mn, add;
	long long sum;
	struct Treap *l, *r;
	Treap (int _key): rev (0), value (_key), pri(rand()), sz (1), mn (_key), add(0), sum(_key), l(nullptr), r(nullptr){}
};

int size (Treap *t) {
	if (t == nullptr) return 0;
	return t -> sz;
}

long long get_sum (Treap *t) {
	if (t == nullptr) return 0;
	return t -> sum;
}

int get_min (Treap *t) {
	if (t == nullptr) return INT_MAX;
	return t -> mn;
}

void pull (Treap *t) {
	t -> sz = size (t -> l) + size (t -> r) + 1;
	t -> mn = min (get_min (t -> l), min(get_min (t -> r), t -> value));
	t -> sum = get_sum (t -> l) + get_sum (t -> r) + t -> value;
}

void push (Treap *t) {
	if (t -> rev) {
		swap (t -> l, t -> r);
		t -> rev = false;
		if (t -> l) t -> l -> rev ^= 1;
		if (t -> r) t -> r -> rev ^= 1;
	}
	if (t -> add) {
		if (t -> l) {
			t -> l -> value += t -> add;
			t -> l -> add += t -> add;
			t -> l -> mn += t -> add;
			t -> l -> sum += t -> l -> sz * t -> add;
		}
		if (t -> r) {
			t -> r -> value += t -> add;
			t -> r -> add += t -> add;
			t -> r -> mn += t -> add;
			t -> r -> sum += t -> r -> sz * t -> add;
		}
		t -> add = 0;
	}
}

Treap* merge (Treap *a, Treap *b) {
	if (!a || !b) return a?a:b;
	if (a -> pri > b -> pri) {
		push (a);
		a -> r = merge (a -> r, b);
		pull (a);
		return a;
	}
	else {
		push (b);
		b -> l = merge (a, b -> l);
		pull (b);
		return b;
	}
}

void split (Treap *t, int x, Treap *&a, Treap *&b) {                            
    if (!t) {                                                                   
        a = b = nullptr;                                                        
        return;                                                               
    }                                                                           
    
	push (t);	
    if (size(t -> l) < x) {                                                        
        a = t;		
        split (t -> r, x-size(t -> l)-1, a -> r, b);                                           
        pull (a);                                                               
    }                                                                           
    else {                                                                      
        b = t;                                                                  
        split (t -> l, x, a, b -> l);                                           
        pull (b);                                                               
    }                                                                           
}

int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);

	Treap *root = nullptr;
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		root = merge (root, new Treap (input));
	}

	int m;
	string option;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> option;
		if (option == "INSERT") {
			Treap *a, *b;
			int pos, val;
			cin >> pos >> val;
			split (root, pos, a, b);
			a = merge (a, new Treap (val));
			root = merge (a, b);
		}
		else if (option == "DELETE") {
			Treap *a, *b, *c;
			int pos;
			cin >> pos;
			split (root, pos-1, a, b);
			split (b, 1, b, c);
			root = merge (a, c);
		}
		else if (option == "MIN") {
			int left, right;
			cin >> left >> right;
			Treap *a, *b, *c;

			split (root, left-1, a, b);
			split (b, right-left+1, b, c);

			cout << b -> mn << '\n';

			a = merge (a, b);
			root = merge (a, c);
		}
		else if (option == "REVOLVE") {
			int l, r, mv;
			cin >> l >> r >> mv;
			Treap *a, *b, *c, *d;

			mv %= (r-l+1);
			split (root, l-1, a, b);
			split (b, r-l+1-mv, b, c);
			split (c, mv, c, d);

			a = merge (a, c);
			a = merge (a, b);
			root = merge (a, d);
		}
		else if (option == "REVERSE") {
			int left, right;
			cin >> left >> right;
			Treap *a, *b, *c;

			split (root, left-1, a, b);
			split (b, right-left+1, b, c);
			b -> rev ^= 1;

			a = merge (a, b);
			root = merge (a, c);
		}
		else if (option == "ADD") {
			int l, r, add;
			Treap *a, *b, *c;
			cin >> l >> r >> add;

			split (root, l-1, a, b);
			split (b, r-l+1, b, c);

			b -> value += add;
			b -> add += add;
			b -> mn += add;
			b -> sum += add * b -> sz;

			a = merge (a, b);
			root = merge (a, c);
		}
		else if (option == "SUM") {
			int left, right;
            cin >> left >> right;
            Treap *a, *b, *c;

            split (root, left-1, a, b);
            split (b, right-left+1, b, c);

            cout << b -> sum << '\n';

            a = merge (a, b);
            root = merge (a, c);
		}
	}
	return 0;
}
