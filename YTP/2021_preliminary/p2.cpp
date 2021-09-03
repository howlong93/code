#include <bits/stdc++.h>

using namespace std;

int main() {
	string input;
	char c;
	stringstream ss;
	double v1, v2, thf, betf, th, thnew, bet, betnew, s, t, v1new, v2new, snew;
	
	cin >> input;
	ss << input;
	ss >> v1 >> c >> v2 >> c >> thf >> c >> betf;
	
	s = sqrt (v1*v1 + 1);
	th = atan (v1);
   	bet = atan (v2/s);
	t = sqrt (v1*v1 + v2*v2 + 1);
	
	thnew = th + thf;
	betnew = bet + betf;
	snew = t * cos (betnew);
	v2new = t * sin (betnew);
	v1new = snew * sin (thnew);

	printf ("%.2f,%.2f,%.2f\n", t, v1new, v2new);

	return 0;
}
