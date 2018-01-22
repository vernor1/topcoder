#include <memory>
#include <string>
#include <vector>

using namespace std;

class HuffmanDecoding {
public:
  string decode(const string& archive, const vector<string>& dictionary) {
    shared_ptr<Node> n;
    LoadDict(dictionary, n);
    return Decode(n, archive);
  }
private:
  struct Node {
    shared_ptr<Node> l;
    shared_ptr<Node> r;
    int v;
    Node() : v(-1) {}
  };

  void LoadDict(const vector<string>& d, shared_ptr<Node>& n) {
    if (!n) {
      n.reset(new Node);
    }
    for (int i = 0; i < d.size(); ++i) {
      auto m = n;
      const string& s = d[i];
      for (auto c : s) {
        if (c == '0') {
          if (!m->l) {
            m->l = shared_ptr<Node>(new Node);
          }
          m = m->l;
        } else {
          if (!m->r) {
            m->r = shared_ptr<Node>(new Node);
          }
          m = m->r;
        }
      }
      m->v = i;
    }
  }
  string Decode(shared_ptr<Node> n, string s) {
    string result;
    auto m = n;
    for (auto c : s) {
      if (c == '0') {
        m = m->l;
      } else {
        m = m->r;
      }
      if (m->v != -1) {
        result.push_back('A' + m->v);
        m = n;
      }
    }
    return result;
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
		cout << "Testing HuffmanDecoding (200.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516054991;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 200.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HuffmanDecoding _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string archive = "101101";
				string dictionary[] = {"00","10","01","11"};
				_expected = "BDC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 1:
			{
				string archive = "10111010";
				string dictionary[] = {"0","111","10"};
				_expected = "CBAC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 2:
			{
				string archive = "0001001100100111001";
				string dictionary[] = {"1","0"};
				_expected = "BBBABBAABBABBAAABBA";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 3:
			{
				string archive = "111011011000100110";
				string dictionary[] = {"010","00","0110","0111","11","100","101"};
				_expected = "EGGFAC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 4:
			{
				string archive = "001101100101100110111101011001011001010";
				string dictionary[] = {"110","011","10","0011","00011","111","00010","0010","010","0000"};
				_expected = "DBHABBACAIAIC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			/*case 5:
			{
				string archive = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string archive = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string archive = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
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
