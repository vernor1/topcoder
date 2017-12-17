#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class ABC {
public:
  string createString(int n, int k) {
    // The solution is suboptimal, it takes too long to pass test case 4.
    n_ = n;
    k_ = k;
    memset(s_, 0, 32);
    auto found = getString(1, 0, 1, 0);
    if (found) {
      s_[0] = 'A';
    } else {
      found = getString(1, 0, 0, 1);
      if (found) {
        s_[0] = 'B';
      } else {
        found = getString(1, 0, 0, 0);
        if (found) {
          s_[0] = 'C';
        }
      }
    }
    string s(s_);
    if (found) {
      if (s.length() < n_) {
        s.append(n - s.length(), 'A');
      }
    }
    return s;
  }

private:
  int n_;
  int k_;
  char s_[32];

  bool getString(int l, int n_k, int n_a, int n_b) {
    if (n_k == k_) {
      return true;
    }
    if (l == n_) {
      return false;
    }
    auto next_l = l + 1;
    auto found = getString(next_l, n_k, n_a + 1, n_b);
    if (found) {
      s_[l] = 'A';
    } else {
      found = getString(next_l, n_k + n_a, n_a, n_b + 1);
      if (found) {
        s_[l] = 'B';
      } else {
        found = getString(next_l, n_k + n_a + n_b, n_a, n_b);
        if (found) {
                s_[l] = 'C';
        }
      }
    }
    return found;
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
		cout << "Testing ABC (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513548895;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ABC _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 3;
				_expected = "ABC";
				_received = _obj.createString(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 0;
				_expected = "CBA";
				_received = _obj.createString(N, K); break;
			}
			case 2:
			{
				int N = 5;
				int K = 10;
				_expected = "";
				_received = _obj.createString(N, K); break;
			}
			case 3:
			{
				int N = 15;
				int K = 36;
				_expected = "CABBACCBAABCBBB";
				_received = _obj.createString(N, K); break;
			}
			case 4:
			{
				int N = 30;
				int K = 300;
				_expected = "AAAAAAAAAABBBBBBBBBBCCCCCCCCCC";
				_received = _obj.createString(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.createString(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.createString(N, K); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
