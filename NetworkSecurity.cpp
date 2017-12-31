#include <algorithm>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

class NetworkSecurity {
public:
  int secureNetwork(const vector<string>& clientCable, const vector<string>& serverCable) {
    int n_gates = 0;
    for (int s = 0; s < serverCable.front().size(); ++s) {
      list<set<int>> trees;
      for (int c = 0; c < serverCable.size(); ++c) {
        if (serverCable.at(c).at(s) == 'Y') {
          set<int> tree;
          // Traverse.
          BuildTree(clientCable, c, tree);
          // Check the tree.
          bool is_supertree = true;
          auto it = trees.begin();
          while (it != trees.end()) {
            if (includes(it->begin(), it->end(), tree.begin(), tree.end())) {
              // This tree is subtree of other tree.
              is_supertree = false;
              break;
            }
            if (includes(tree.begin(), tree.end(), it->begin(), it->end())) {
              // Other tree is subtree of this tree.
              it = trees.erase(it);
              continue;
            }
            ++it;
          }
          if (is_supertree) {
            trees.push_back(tree);
          }
        }
      }
      n_gates += trees.size();
    }
    return n_gates;
  }

private:
  void BuildTree(const vector<string>& client_cable, int c, set<int>& tree) {
    if (tree.find(c) != tree.end()) {
      return;
    }
    tree.insert(c);
    for (int i = 0; i < client_cable.size(); ++i) {
      if (client_cable.at(i).at(c) == 'Y') {
        // There's a connection from client i to c.
        BuildTree(client_cable, i, tree);
      }
    }
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
		cout << "Testing NetworkSecurity (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1514672859;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		NetworkSecurity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string clientCable[] = {"NYN"
				                       ,"NNN"
				                       ,"NYN"};
				string serverCable[] = {"YN"
				                       ,"YN"
				                       ,"NY"};
				_expected = 2;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 1:
			{
				string clientCable[] = {"NN"
				                       ,"NN"};
				string serverCable[] = {"NNN"
				                       ,"NNN"};
				_expected = 0;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 2:
			{
				string clientCable[] = {"NYNN"
				                       ,"NNNN"
				                       ,"NNNY"
				                       ,"NNNN"};
				string serverCable[] = {"YYN"
				                       ,"NNN"
				                       ,"NNY"
				                       ,"NNN"};
				_expected = 3;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 3:
			{
				string clientCable[] = {"NYNY"
				                       ,"NNYN"
				                       ,"NNNN"
				                       ,"NNYN"};
				string serverCable[] = {"Y"
				                       ,"N"
				                       ,"Y"
				                       ,"N"};
				_expected = 1;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 4:
			{
				string clientCable[] = {"NYY"
				                       ,"NNN"
				                       ,"NNN"};
				string serverCable[] = {"N"
				                       ,"Y"
				                       ,"Y"};
				_expected = 2;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			/*case 5:
			{
				string clientCable[] = ;
				string serverCable[] = ;
				_expected = ;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
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
