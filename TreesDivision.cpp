#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

class TreesDivision {
public:
  int minDifference(const vector<int>& x, const vector<int>& y, const vector<int>& income) {
    x_ = x;
    y_ = y;
    income_ = income;
    min_diff_ = accumulate(income.begin(), income.end(), 0);
    for (size_t i = 0; i < x.size(); ++i) {
      // Vertical.
      auto xb = x[i];
      auto yb = y[i] == 0 ? 1 : 0;
      UpdateMin(x[i], y[i], xb, yb);
      // Horizontal.
      xb = x[i] == 0 ? 1 : 0;
      yb = y[i];
      UpdateMin(x[i], y[i], xb, yb);
      // Each pair.
      for (size_t j = 0; j < x.size(); ++j) {
        if (i == j) {
          continue;
        }
        UpdateMin(x[i], y[i], x[j], y[j]);
      }
    }
    return min_diff_;
  }
private:
  vector<int> x_;
  vector<int> y_;
  vector<int> income_;
  int min_diff_;

  void UpdateMin(int xa, int ya, int xb, int yb) {
    int same_line = 0;
    int one_side = 0;
    int other_side = 0;
    for (size_t i = 0; i < x_.size(); ++i) {
      auto loc = (yb - ya) * (x_[i] - xb) - (y_[i] - yb) * (xb - xa);
      if (loc > 0) {
        one_side += income_[i];
      } else if (loc < 0) {
        other_side += income_[i];
      } else {
        same_line += income_[i];
      }
    }
    if (one_side < other_side) {
      one_side += same_line;
    } else {
      other_side += same_line;
    }
    auto min_diff = abs(one_side - other_side);
    min_diff_ = min(min_diff_, min_diff);
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
		cout << "Testing TreesDivision (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1512699886;
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
		TreesDivision _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,2};
				int y[] = {2,3};
				int income[] = {10,20};
				_expected = 10;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,1,2,3};
				int y[] = {1,1,1,1};
				int income[] = {1,1,1,1};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0,0,0,0,0};
				int y[] = {1,2,3,4,5};
				int income[] = {1,2,3,4,1000};
				_expected = 990;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0,0,1,1};
				int y[] = {0,1,1,0};
				int income[] = {1,2,4,8};
				_expected = 1;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {4,2,4,2,3,6,3,5};
				int y[] = {1,2,4,3,3,2,4,5};
				int income[] = {4,5,2,6,7,4,2,4};
				_expected = 2;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {1,2,3};
				int y[] = {3,2,1};
				int income[] = {1,1000000,1};
				_expected = 1000000;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {1,1,1,1};
				int y[] = {0,1,2,3};
				int income[] = {1,1,1,1};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {1,1,3,3,2};
				int y[] = {1,3,3,1,2};
				int income[] = {2,2,3,3,2};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {3,3,2,3,4,5,2,3};
				int y[] = {5,4,3,3,3,3,2,2};
				int income[] = {3,1,3,1,1,3,3,3};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 9:
			{
				int x[] = {3,4,0,1,2,3};
				int y[] = {2,2,1,1,1,1};
				int income[] = {1,1,4,4,5,5};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 10:
			{
				int x[] = {3,2,3,4,3};
				int y[] = {3,2,2,2,1};
				int income[] = {3,3,2,2,2};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
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
