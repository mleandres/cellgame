#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit|ios::badbit);
  string cmd;
  Grid g;
  int moves = 0;

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        if (!(cin >> n)) throw;
        // create nxn grid
        g.init(n);
      }
      else if (cmd == "init") {
        // loop to get initial conditions to start (turn on cells)
        while (true) {
          int r = 0, c = 0;
          if (!(cin >> r >> c)) throw;
          if (r == -1 && c == -1) break;
          g.turnOn(r, c);
        }
        //cout << g
      }
      else if (cmd == "game") {
        cin >> moves;
        cout << moves << " moves left" << endl;
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r, c);
        // cout << g;
        --moves;
        cout << moves << (moves == 1 ? " move left" : " moves left") << endl;
        if (g.isWon()) {
          cout << "Won" << endl;
          break;
        }
        if (moves == 0) {
          cout << "Lost" << endl;
          break;
        }
      }
    }
  }
  catch (ios::failure &) {
  }
}
