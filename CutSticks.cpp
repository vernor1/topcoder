#include <algorithm>
#include <functional>
#include <vector>

const auto kMaxLength = 1e9;
const auto kMaxAttempts = 1e3;
const auto kTolerance = 1e-9;

using namespace std;

size_t CountSticks(const vector<int>& sticks, double target_length, size_t allowed_cuts) {
  size_t n_sticks = 0;
  for (auto stick : sticks) {
    if (stick < target_length) {
      continue;
    }
    size_t n_parts = stick / target_length;
    size_t n_cuts = min(n_parts - 1, allowed_cuts);
    n_sticks += n_cuts + 1;
    allowed_cuts -= n_cuts;
  }
  return n_sticks;
}

class CutSticks {
public:
  double maxKth(vector<int> sticks, int c, int k) {
    sort(sticks.begin(), sticks.end(), greater<int>());
    auto min = 0.;
    auto max = kMaxLength;
    auto mid = (min + max) / 2.;
    size_t n_attempts = kMaxAttempts;
    while (max - min > kTolerance && n_attempts > 0) {
      if (CountSticks(sticks, mid, c) >= k) {
        min = mid;
      } else {
        max = mid;
      }
      mid = (min + max) / 2.;
      --n_attempts;
    }
    return mid;
  }
};

// BEGIN CUT HERE
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
		cout << "Testing CutSticks (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1512699128;
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
		CutSticks _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 1;
				_expected = 8.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 1:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 2;
				_expected = 5.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 2:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 3;
				_expected = 4.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 3:
			{
				int sticks[] = {1000000000, 1000000000, 1};
				int C = 2;
				int K = 5;
				_expected = 1.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 4:
			{
				int sticks[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
				int C = 789;
				int K = 456;
				_expected = 34.92;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			/*case 5:
			{
				int sticks[] = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}*/
			/*case 6:
			{
				int sticks[] = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}*/
			/*case 7:
			{
				int sticks[] = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
