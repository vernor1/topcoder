#include <algorithm>
#include <limits>

using namespace std;

class TheEquation {
public:
  int leastSum(int X, int Y, int P) {
    int m = numeric_limits<int>::max();
    for (int a = 1; a <= P; ++a) {
      for (int b = 1; b <= P; ++b) {
        if ((a * X + b * Y) % P == 0) {
          m = min(m, a + b);
        }
      }
    }
    return m;
  }
};

// BEGIN CUT HERE
// Unit Tests                                                                                                
// ----------------------------------------------------------------------------
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing TheEquation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517276699;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheEquation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X = 2;
				int Y = 6;
				int P = 5;
				_expected = 3;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 1:
			{
				int X = 5;
				int Y = 5;
				int P = 5;
				_expected = 2;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 2:
			{
				int X = 998;
				int Y = 999;
				int P = 1000;
				_expected = 501;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 3:
			{
				int X = 1;
				int Y = 1;
				int P = 1000;
				_expected = 1000;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 4:
			{
				int X = 347;
				int Y = 873;
				int P = 1000;
				_expected = 34;
				_received = _obj.leastSum(X, Y, P); break;
			}
			/*case 5:
			{
				int X = ;
				int Y = ;
				int P = ;
				_expected = ;
				_received = _obj.leastSum(X, Y, P); break;
			}*/
			/*case 6:
			{
				int X = ;
				int Y = ;
				int P = ;
				_expected = ;
				_received = _obj.leastSum(X, Y, P); break;
			}*/
			/*case 7:
			{
				int X = ;
				int Y = ;
				int P = ;
				_expected = ;
				_received = _obj.leastSum(X, Y, P); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
