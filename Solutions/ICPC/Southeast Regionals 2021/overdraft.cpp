#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int val = 0;
    int sb = 0;

    while (n--) {
        int a;
        cin >> a;
        val += a;

        if (val < 0) {
            sb -= val;
            val = 0;
        }
    }

    cout << sb << endl;
}