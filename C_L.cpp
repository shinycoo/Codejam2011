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
#define formn(i, n) for (int i = (int)(n)-1; i >= 0; i--)
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
		int bag_n = 0;
		int min = 1000000;
		int p_sum = 0;
		int s_sum = 0;
		in >> bag_n;
		forn(j, bag_n) {
			int bag = 0;
			in >> bag;
			p_sum = p_sum ^ bag;
			s_sum += bag;
			min = (min > bag) ? bag : min;
		}

		out << "Case #" << i + 1 << ": ";
		if(p_sum) 
			out << "NO";
		else
			out << (s_sum-min);
		out << "\n";
	}
	in.close();
	out.close();

	return 0;
}