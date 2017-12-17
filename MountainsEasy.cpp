#include <string>
#include <vector>

enum { kMod = 1000000009 };

using namespace std;

class MountainsEasy {
public:
  // The implementation below is suboptimal, it fails test cases 9 and 10.
  int countPlacements(const vector<string>& picture, int n) {
    // Get number of pixels and unique mountains.
    int n_pixels = 0;
    int n_unique_mtns = 0;
    int width = picture.front().size();
    vector<vector<bool>> mtn_pixels(picture.size(), vector<bool>(width));
    int y = picture.size();
    for (const auto& s : picture) {
      --y;
      for (int x = 0; x < width; ++x) {
        if (s.at(x) == 'X') {
          if (!mtn_pixels.at(y).at(x)) {
            ++n_unique_mtns;
            for (int ym = y; ym >= 0; --ym) {
              for (int xm = max(0, x - y + ym); xm <= min(x + y - ym, width - 1); ++xm) {
                mtn_pixels.at(ym).at(xm) = true;
              }
            }
          }
          ++n_pixels;
        }
      }
    }
    // Count combinations.
    vector<int> decrements(n - n_unique_mtns);
    unsigned long count = 0;
    CountCombinations(decrements, n_pixels, n_unique_mtns, 0, count);
    // count * n_unique_mtns!
    for (int i = 1; i <= n_unique_mtns; ++i) {
      count *= i;
      if (count > kMod) {
        count %= kMod;
      }
    }
    return count;
  }

private:
  void CountCombinations(vector<int>& decrements, int n_pixels, int prev_mtn, int mtn_idx, unsigned long& count) {
    if (decrements.empty()) {
      count = 1;
    } else {
      unsigned long long combo_count = 1;
      for (auto d : decrements) {
        combo_count *= n_pixels - d;
        if (combo_count > kMod) {
          combo_count %= kMod;
        }
      }
      count += combo_count;
    }
    if (mtn_idx >= decrements.size()) {
      // Last bit processed.
      return;
    }
    // Recursion.
    while (decrements[mtn_idx] < prev_mtn) {
      CountCombinations(decrements, n_pixels, ++decrements[mtn_idx], mtn_idx + 1, count);
    }
    // Reset the decrement counter when it reaches prev_mtn.
    decrements[mtn_idx] = 0;
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
		cout << "Testing MountainsEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1512934557;
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
		MountainsEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string picture[] = {"X.",
				                    "XX"};
				int N = 1;
				_expected = 1;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 1:
			{
				string picture[] = {"X.",
				                    "XX"};
				int N = 2;
				_expected = 5;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 2:
			{
				string picture[] = {"X.X",
				                    "XXX"};
				int N = 2;
				_expected = 2;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 3:
			{
				string picture[] = {"X.X",
				                    "XXX"};
				int N = 3;
				_expected = 24;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 4:
			{
				string picture[] = {"......",
				                    "X..X..",
				                    "XXXXXX",
				                    "XXXXXX"};
				int N = 3;
				_expected = 6;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 5:
			{
				string picture[] = {"......",
				                    "X..X..",
				                    "XXXXXX",
				                    "XXXXXX"};
				int N = 4;
				_expected = 300;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 6:
			{
				string picture[] = {"....X...X..",
				                    "...XXX.XXX.",
				                    "XXXXXXXXXXX"};
				int N = 10;
				_expected = 764632413;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 7:
			{
				string picture[] = {"..",
                                                    "XX",
				                    "XX"};
				int N = 4;
				_expected = 110;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 8:
			{
				string picture[] = {"XX..",
                                                    "XXXX"};
				int N = 6;
				_expected = 11340;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 9:
			{
				string picture[] = {".....X...............X..X......X..X...XX.X....X...",
                                                    "....XXX...........X.XXXXXX.X..XXXXXXXXXXXXXX.XXX..",
                                                    "...XXXXXX........XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
                                                    "..XXXXXXXX.X....XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    ".XXXXXXXXXXXX..XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};
				int N = 30;
				_expected = 435784073;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
			}
			case 10:
			{
				string picture[] = {".................................",
                                                    "..X..........X...................",
                                                    ".XXX........XXX..................",
                                                    "XXXXX......XXXXXX................",
                                                    "XXXXXX.X..XXXXXXXX...............",
                                                    "XXXXXXXXXXXXXXXXXXXX.X....X.X....",
                                                    "XXXXXXXXXXXXXXXXXXXXXXX..XXXXX...",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX..",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                                                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};
				int N = 47;
				_expected = 294602080;
				_received = _obj.countPlacements(vector <string>(picture, picture+sizeof(picture)/sizeof(string)), N); break;
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
