#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class StrangeParticles {
private:
  size_t rank_;
  map<size_t, size_t> ranks_;
  unordered_set<size_t> seen_;
  unordered_map<size_t, size_t> leaders_;
  size_t n_killed_;
  void FindScc(const vector<string>& g, size_t i) {
    if (seen_.find(i) != seen_.end()) {
      return;
    }
    seen_.insert(i);
    for (size_t j = 0; j < g[i].size(); ++j) {
      if (g[i][j] == '+') {
        FindScc(g, j);
      }
    }
    ranks_[rank_++] = i;
  }
  void ContractScc(vector<string>& g, size_t leader, size_t i) {
    if (seen_.find(i) != seen_.end()) {
      return;
    }
    seen_.insert(i);
    leaders_[i] = leader;
    for (size_t j = 0; j < g[i].size(); ++j) {
      if (g[i][j] == '-') {
        ContractScc(g, leader, j);
      }
    }
    if (i == leader) {
      return;
    }
    for (size_t j = 0; j < g[i].size(); ++j) {
      if (j != leader) {
        if (g[i][j] == '-') {
          g[leader][j] = '-';
          g[j][leader] = '+';
        } else if (g[i][j] == '+') {
          g[leader][j] = '+';
          g[j][leader] = '-';
        }
      }
      g[i][j] = '0';
      g[j][i] = '0';
    }
    ++n_killed_;
  }
public:
  int remain(vector<string> interacts) {
    // Find SCCs.
    rank_ = 0;
    ranks_.clear();
    seen_.clear();
    for (size_t i = 0; i < interacts.size(); ++i) {
      FindScc(interacts, i);
    }
    // Contract SCCs.
    seen_.clear();
    n_killed_ = 0;
    for (auto r = ranks_.rbegin(); r != ranks_.rend(); ++r) {
      ContractScc(interacts, r->second, r->second);
    }
    // Collide the rest of particles.
  	for (;;) {
      auto min_n_kills = -1;
      auto harmless_i = -1;
      for (size_t i = 0; i < interacts.size(); ++i) {
        if (interacts[i].find('+') != string::npos) {
          auto n_kills = count(interacts[i].begin(), interacts[i].end(), '-');
          if (n_kills < min_n_kills || min_n_kills == -1) {
            min_n_kills = n_kills;
            harmless_i = i;
          }
        }
      }
      if (harmless_i < 0) {
        break;
      }
      for (size_t j = 0; j < interacts[harmless_i].size(); ++j) {
        interacts[harmless_i][j] = '0';
        interacts[j][harmless_i] = '0';
      }
      ++n_killed_;
    }
    return interacts.size() - n_killed_;  
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
		cout << "Testing StrangeParticles (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513548702;
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
		StrangeParticles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string interacts[] = {"0+-","-0+","+-0"};
				_expected = 1;
				_received = _obj.remain(vector <string>(interacts, interacts+sizeof(interacts)/sizeof(string))); break;
			}
			case 1:
			{
				string interacts[] = {"000","000","000"};
				_expected = 3;
				_received = _obj.remain(vector <string>(interacts, interacts+sizeof(interacts)/sizeof(string))); break;
			}
			case 2:
			{
				string interacts[] = {"0++++++++++++++",
				                      "-0+++++++++++++",
				                      "--0++++++++++++",
				                      "---0+++++++++++",
				                      "----0++++++++++",
				                      "-----0+++++++++",
				                      "------0++++++++",
				                      "-------0+++++++",
				                      "--------0++++++",
				                      "---------0+++++",
				                      "----------0++++",
				                      "-----------0+++",
				                      "------------0++",
				                      "-------------0+",
				                      "--------------0"};
				_expected = 1;
				_received = _obj.remain(vector <string>(interacts, interacts+sizeof(interacts)/sizeof(string))); break;
			}
			/*case 3:
			{
				string interacts[] = ;
				_expected = ;
				_received = _obj.remain(vector <string>(interacts, interacts+sizeof(interacts)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string interacts[] = ;
				_expected = ;
				_received = _obj.remain(vector <string>(interacts, interacts+sizeof(interacts)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string interacts[] = ;
				_expected = ;
				_received = _obj.remain(vector <string>(interacts, interacts+sizeof(interacts)/sizeof(string))); break;
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
