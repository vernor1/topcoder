#include <string>
#include <vector>

using namespace std;

class StringFragmentation {
public:
  int largestFontSize(string text, int width, int height) {
    vector<int> ws;
    for (int i = 0; i < text.size(); ++i) {
      if (text[i] == ' ') {
        ws.push_back(i);
      }
    }
    ws.push_back(text.size());
    int font_size = 7;
    bool fit = true;
    while (fit) {
      ++font_size;
      int line_start = 0;
      int n_lines = 1;
      for (auto it = ws.begin(); it != ws.end(); ++it) {
        if ((*it - line_start) * (font_size + 2) <= width) {
          continue;
        }
        if (it == ws.begin() || *--it + 1 == line_start) {
          fit = false;
          break;
        }
        ++n_lines;
        line_start = *it + 1;
      }
      if (fit) {
        fit = n_lines * 2 * font_size <= height;
      }
    }
    --font_size;
    return font_size > 7 ? font_size : -1;
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
		cout << "Testing StringFragmentation (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517277339;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StringFragmentation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "ONE TWO THREE FOUR FIVE";
				int width = 150;
				int height = 40;
				_expected = 9;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			case 1:
			{
				string text = "ONE TWO THREE FOUR FIVE";
				int width = 150;
				int height = 60;
				_expected = 10;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			case 2:
			{
				string text = "ONE TWO THREE FOUR FIVE";
				int width = 150;
				int height = 10000;
				_expected = 28;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			case 3:
			{
				string text = "ONE TWO THREE FOUR FIVE";
				int width = 10000;
				int height = 10000;
				_expected = 1250;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			case 4:
			{
				string text = "ONE TWO THREE FOUR FIVE";
				int width = 50;
				int height = 50;
				_expected = -1;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			case 5:
			{
				string text = "A";
				int width = 9;
				int height = 14;
				_expected = -1;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			case 6:
			{
				string text = "QWERTYUIOPQWERTYUIOPQWERT YUIOPQWRTYUIOPQWERTYUIOP";
				int width = 1000;
				int height = 300;
				_expected = 38;
				_received = _obj.largestFontSize(text, width, height); break;
			}
			/*case 7:
			{
				string text = ;
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.largestFontSize(text, width, height); break;
			}*/
			/*case 8:
			{
				string text = ;
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.largestFontSize(text, width, height); break;
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
