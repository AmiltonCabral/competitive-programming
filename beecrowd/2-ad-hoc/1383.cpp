#include <iostream>
 
using namespace std;

//Test
bool verifySudo(int sudo[][9]) {

    bool sqrA[9];
    bool sqrB[9];
    bool sqrC[9];

    for (int i = 0; i < 9; i++) {
        bool row[]  = {false, false, false, false, false, false, false, false, false};
        bool col[]  = {false, false, false, false, false, false, false, false, false};

        // reset all squares values
        if (i % 3 == 0) { 
            for (int j = 0; j < 9; j++) {
                sqrA[j] = false;
                sqrB[j] = false;
                sqrC[j] = false;
            }
        }

        for (int j = 0; j < 9; j++) {
            // verify row and column
            if (row[sudo[i][j] -1] == true) return false;
            if (col[sudo[j][i] -1] == true) return false;
            row[sudo[i][j] -1] = true;
            col[sudo[j][i] -1] = true;
            
            // verify squares
            if (j < 3) {
                if (sqrA[sudo[i][j] -1] == true) return false;
                sqrA[sudo[i][j] -1] = true;
            } else if (j < 6) {
                if (sqrB[sudo[i][j] -1] == true) return false;
                sqrB[sudo[i][j] -1] = true;
            } else {
                if (sqrC[sudo[i][j] -1] == true) return false;
                sqrC[sudo[i][j] -1] = true;
            }

        }
    }

    return true;
}

 
int main() {

    int N, instc;
    cin >> N;

    for (instc = 1; instc <= N; instc++)
    {
        // create sudo matriz
        int sudo[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> sudo[i][j];
            }
        }

        // verify sudo vality
        if (verifySudo(sudo)) {
            cout << "Instancia " << instc << endl;
            cout << "SIM" << endl << endl;
        } else {
            cout << "Instancia " << instc << endl;
            cout << "NAO" << endl << endl;
        }

    } 

    return 0;
}
