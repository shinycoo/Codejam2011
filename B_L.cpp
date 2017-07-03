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
		char elems[100];
		memset(elems, 0, sizeof(char)*10);
		int f_ele_n = 0;
		int com_n, opp_n, ele_n;
		char com_elem[26][26], opp_elem[26][26];
		
		forn(j, 26) {
			memset(com_elem[j], 0, sizeof(char)*26);
			memset(opp_elem[j], 0, sizeof(char)*26);
		}

		in >> com_n;
		forn(j, com_n) {
			char a, b;
			in >> a;
			in >> b;
			//printf("%c, %c  ", a, b);
			in >> com_elem[a -'A'][b -'A'];
			com_elem[b -'A'][a -'A'] = com_elem[a -'A'][b -'A'];
			//printf("COM: %c\n",com_elem[b -'A'][a -'A']);
		}
		in >> opp_n;
		forn(j, opp_n) {
			char a, b;
			in >> a;
			in >> b;
			opp_elem[a - 'A'][b - 'A'] = 1;
			opp_elem[b - 'A'][a - 'A'] = 1;
			//printf("OPP: %d\n",opp_elem[b -'A'][a -'A']);
		}

		in >> ele_n;

		forn(j, ele_n) {
			in >> elems[f_ele_n];
			if (f_ele_n > 0) {
				if (com_elem[elems[f_ele_n-1] - 'A'][elems[f_ele_n] - 'A'] > 0){
					//printf("---%c\n",com_elem[elems[f_ele_n-1] - 'A'][elems[f_ele_n] - 'A']);
					elems[f_ele_n-1] = com_elem[elems[f_ele_n-1] - 'A'][elems[f_ele_n] - 'A'];
					elems[f_ele_n] = 0;
					f_ele_n--;
				} else {
					int f_id = -1;
					formn(k, f_ele_n) {
						if(opp_elem[elems[f_ele_n] - 'A'][elems[k] - 'A'] == 1) {
							f_id = k;
							break; 
						}
					}
					if (f_id >= 0) {
						//f_ele_n -= (f_ele_n - f_id);
						//f_ele_n --;
						f_ele_n = -1;
					}
				}
			}
			f_ele_n++;
		}

		out << "Case #" << i + 1 << ": [";
		forn(j, f_ele_n) {
			out << elems[j];
			if (j != f_ele_n-1)
				out << ", ";
		}
		out << "]\n";
	}
	in.close();
	out.close();

	return 0;
}