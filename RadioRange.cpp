#include <cmath>
#include <list>
#include <vector>

using namespace std;

class RadioRange {
public:
  double RadiusProbability(const vector<int>& X, const vector<int>& Y, const vector<int>& R, int Z) {
    list<pair<double, double>> bads;
    for (int i = 0; i < X.size(); ++i) {
      double off = hypot(X[i], Y[i]);
      double b1 = off - R[i];
      if (b1 < 0) {
        b1 = 0;
      } else if (b1 > Z) {
        continue;
      }
      double b2 = off + R[i];
      if (b2 > Z) {
        b2 = Z;
      }
      auto it = bads.begin();
      while (it != bads.end()) {
        if (b1 < it->first) {
          if (b2 < it->first) {
            ++it;
            continue;
          }
          b2 = max(b2, it->second);
          it = bads.erase(it);
        } else {
          if (b1 > it->second) {
            ++it;
            continue;
          }
          b1 = min(b1, it->first);
          b2 = max(b2, it->second);
          it = bads.erase(it);
        }
      }
      bads.push_back(make_pair(b1, b2));
    }
    double badAcc = 0;
    for (auto b : bads) {
      badAcc += b.second - b.first;
    }
    return (Z - badAcc) / Z;
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
		cout << "Testing RadioRange (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516755379;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RadioRange _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {0};
				int Y[] = {0};
				int R[] = {5};
				int Z = 10;
				_expected = 0.5;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 1:
			{
				int X[] = {0};
				int Y[] = {0};
				int R[] = {10};
				int Z = 10;
				_expected = 0.0;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 2:
			{
				int X[] = {10};
				int Y[] = {10};
				int R[] = {10};
				int Z = 10;
				_expected = 0.4142135623730951;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 3:
			{
				int X[] = {11, -11, 0, 0};
				int Y[] = {0, 0, 11, -11};
				int R[] = {10, 10, 10, 10};
				int Z = 31;
				_expected = 0.3548387096774194;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 4:
			{
				int X[] = {100};
				int Y[] = {100};
				int R[] = {1};
				int Z = 10;
				_expected = 1.0;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 5:
			{
				int X[] = {1000000000};
				int Y[] = {1000000000};
				int R[] = {1000000000};
				int Z = 1000000000;
				_expected = 0.41421356237309503;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 6:
			{
				int X[] = {20, -20, 0, 0};
				int Y[] = {0, 0, 20, -20};
				int R[] = {50, 50, 50, 50};
				int Z = 100;
				_expected = 0.3;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 7:
			{
				int X[] = {0, -60, -62, -60, 63, -97};
				int Y[] = {-72, 67, 61, -8, -32, 89};
				int R[] = {6, 7, 8, 7, 5, 6};
				int Z = 918;
				_expected = 0.9407071068962471;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 8:
			{
				int X[] = {-193, 424, 203, -128, -163, -917, -622, 334, 630, -573, -822, 980, 116, 530, -676, 921, 274, -731, -610, -253, -314, 911, 921, -808, 123, -115, -759};
                                int Y[] = {-155, -898, 132, -331, -822, 777, 463, -101, -850, -575, 350, -384, -425, -228, -833, 15, -242, 54, -175, -807, -371, -238, -350, -931, -754, -339, -381};
                                int R[] = {98, 30, 4, 73, 87, 50, 38, 74, 68, 93, 23, 53, 33, 82, 79, 63, 55, 3, 46, 99, 96, 13, 14, 27, 15, 33, 48};
				int Z = 5359;
				_expected = 0.7999809015544048;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			/*case 9:
			{
				int X[] = ;
				int Y[] = ;
				int R[] = ;
				int Z = ;
				_expected = ;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}*/
			/*case 10:
			{
				int X[] = ;
				int Y[] = ;
				int R[] = ;
				int Z = ;
				_expected = ;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
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
