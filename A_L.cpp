#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

int main()
{
	ifstream in("C:\\input.txt");
	ofstream out("C:\\output.txt");

	if (!in)  {
		cout << "C' file" << endl;
		return 0;
	}
	if (!out) {
		cout << "c' file" << endl;
		return 0;
	}

	int n = 0;
	in >> n;
	forn(i, n) {
		int n1 = 0;
		in >> n1;
		int tt = 0;
		int po = 1, pb = 1, pdt = 0;
		char ch, pi = '-';
		forn(j, n1) {
			int bt = 0, tpdt = 0;
			in >> ch;
			in >> bt;
			//printf("%c %d\n", ch, bt);
			tpdt = pdt;
			pdt = (pi == ch ? 0 : pdt);
			int dt = (abs(bt - ((ch == 'O') ? po : pb))-pdt) +1;
			dt = (dt <= 0) ? 1 : dt;
			po = (ch == 'O' ? bt : po);
			pb = (ch == 'B' ? bt : pb);

			tt += dt;
			pdt = ((pi == ch) ? (dt + tpdt) : dt);
			pi = ch;
			//printf("dt: %d tt: %d pdt: %d pi: %c\n",dt, tt,pdt,pi);
		}
		//printf("Case : %d\n",tt);
		out << "Case #" << i+1 << ": " << tt << "\n";
	}
	in.close();
	out.close();

	return 0;
}