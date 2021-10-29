#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    string ans;
    for(char c : s) {
        int res;
        char r;
        if(c >= 'a' && c <= 'z') {
            res = (c - 'a' + k) % 26;
            r = res + 'a';
        }
        else if(c >= 'A' && c <= 'Z') {
            res = (c - 'A' + k) % 26;
            r = res + 'A';  
        }
        else {
        	ans += c;
        	continue;
        }
        ans += r;
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    cout << result << "\n";

    return 0;
}

