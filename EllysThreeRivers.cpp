#include <cmath>
#include <limits>
#include <vector>

double TOLERANCE = 1e-9;
enum { SAMPLE_RATE = 2 };

using namespace std;

class EllysThreeRivers {
public:
  double getMin(int length, int walk, const vector<int>& width, const vector<int>& swim) {
    double min_time = numeric_limits<double>::max();
    double l0_opt = -1;
    double l0_min = -1;
    double l0_max = -1;
    double l1_opt = -1;
    double l1_min = -1;
    double l1_max = -1;
    double l2_opt = -1;
    double l2_min = -1;
    double l2_max = -1;
    size_t sample_rate = SAMPLE_RATE;
    double sample_length = static_cast<double>(length) / sample_rate;
    bool min_found = false;
    while (sample_length > TOLERANCE) {
      min_found = false;
      for (double l0 = l0_min < 0 ? 0 : l0_min;
                  l0 <= (l0_max < 0 || l0_max > length ? length : l0_max);
                  l0 += sample_length) {
        // First river.
        double t0 = hypot(l0, width[0]) / swim[0];
        for (double l1 = l1_min < 0 ? 0 : l1_min;
                    l1 <= (l1_max < 0 || l1_max > length - l0 ? length - l0 : l1_max);
                    l1 += sample_length) {
          // Second river.
          double t1 = hypot(l1, width[1]) / swim[1];
          for (double l2 = l2_min < 0 ? 0 : l2_min;
                      l2 <= (l2_max < 0 || l2_max > length - l0 - l1 ? length - l0 - l1 : l2_max);
                      l2 += sample_length) {
            // Third river.
            double t2 = hypot(l2, width[2]) / swim[2];
            double t3 = (length - l0 - l1 - l2) / walk;
            double time = t0 + t1 + t2 + t3;
            if (time < min_time) {
              min_found = true;
              min_time = time;
              l0_opt = l0;
              l1_opt = l1;
              l2_opt = l2;
              l0_min = l0_opt - sample_length;
              l0_max = l0_opt + sample_length;
              l1_min = l1_opt - sample_length;
              l1_max = l1_opt + sample_length;
              l2_min = l2_opt - sample_length;
              l2_max = l2_opt + sample_length;
            }
          }
        }
      }
      sample_rate *= SAMPLE_RATE;
      sample_length = static_cast<double>(length) / sample_rate;
      if (!min_found) {
        // Narrow search.
        l0_min = l0_opt - sample_length;
        l0_max = l0_opt + sample_length;
        l1_min = l1_opt - sample_length;
        l1_max = l1_opt + sample_length;
        l2_min = l2_opt - sample_length;
        l2_max = l2_opt + sample_length;
      }
    }
    return min_time;
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
		cout << "Testing EllysThreeRivers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513535256;
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
		EllysThreeRivers _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 10;
				int walk = 8;
				int width[] = {5, 2, 3};
				int swim[] = {5, 2, 7};
				_expected = 3.2063518370413364;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}
			case 1:
			{
				int length = 1000;
				int walk = 100;
				int width[] = {91, 911, 85};
				int swim[] = {28, 97, 19};
				_expected = 21.549321613601297;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}
			case 2:
			{
				int length = 666;
				int walk = 4;
				int width[] = {777, 888, 999};
				int swim[] = {11, 12, 13};
				_expected = 228.26633673141083;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}
			case 3:
			{
				int length = 6;
				int walk = 100;
				int width[] = {2, 3, 4};
				int swim[] = {77, 88, 99};
				_expected = 0.12049782476139667;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}
			case 4:
			{
				int length = 873;
				int walk = 54;
				int width[] = {444, 588, 263};
				int swim[] = {67, 97, 26};
				_expected = 26.365540023205206;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}
			case 5:
			{
				int length = 1000;
				int walk = 100;
				int width[] = {1, 1, 1};
				int swim[] = {1, 1, 1};
				_expected = 12.999849996249809;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}
			/*case 6:
			{
				int length = ;
				int walk = ;
				int width[] = ;
				int swim[] = ;
				_expected = ;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int length = ;
				int walk = ;
				int width[] = ;
				int swim[] = ;
				_expected = ;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(swim, swim+sizeof(swim)/sizeof(int))); break;
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
