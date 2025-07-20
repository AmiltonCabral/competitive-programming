#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        string pathAux = "";

        // remove duplicated slashs
        for (int i = 0; i < path.size(); ++i) {
            while (path[i] == '/' && i + 1 < path.size() &&
                   path[i + 1] == '/') {
                ++i;
            }
            pathAux += path[i];
        }
        path = "";  // empty memory
        if (pathAux.back() == '/' && pathAux != "/") {
            pathAux.pop_back();
        }

        // split dirs in a vector
        vector<string> dirs;
        string dir = "";
        for (int i = 0; i < pathAux.size(); ++i) {
            // new dir found
            if (pathAux[i] == '/') {
                if (!dir.empty()) dirs.push_back(dir);
                dir = "";
            }
            dir += pathAux[i];
        }
        dirs.push_back(dir);

        // debug with prints
        // for (string dir : dirs) {
        //     cout << dir << endl;
        // }

        vector<string> dirs2;
        for (string dir : dirs) {
            // removes /.
            if (dir == "/.") continue;

            // removes /..
            if (dir == "/..") {
                if (dirs2.size() != 0) {
                    dirs2.pop_back();
                }
                continue;
            }

            dirs2.push_back(dir);
        }

        if (dirs2.size() == 0) {
            return "/";
        }

        for (string dir : dirs2) {
            path += dir;
        }

        return path;
    }
};

//        /a/b/c/d/../../..
//        /a

//        /home/..
//        /home

//        /..
//        /