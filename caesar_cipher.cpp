// Andrew Chin https://github.com/4ndrewchin
// Encrypt a message using a simple caesar cipher

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main(int argc, char** argv) {
    const int ALPHABET = 26;
    const int ASCII_A = 65;
    const int ASCII_Z = 90;
    const int ASCII_a = 97;
    const int ASCII_z = 122;
    int shift = 0;
    string msg = "";
    cout << "Enter your message to encrypt: ";
    getline(cin, msg);
    cout << "Enter a shift value: ";
    cin >> shift;
    while (!cin) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "A valid shift must be an integer value.\nEnter a shift value: ";
        cin >> shift;
    }
    cout << shift << endl;
    for (int i = 0; i < msg.length(); ++i) {
        unsigned char curr = msg.at(i);
        if (isalpha(curr)) {
            unsigned char before_shift = curr;
            curr += (shift % ALPHABET);
            if ( (islower(before_shift) && curr > ASCII_z) || (isupper(before_shift) && curr > ASCII_Z) ) {
                curr -= ALPHABET;
            }
            else if ( (islower(before_shift) && curr < ASCII_a) || (isupper(before_shift) && curr < ASCII_A) ){
                curr += ALPHABET;
            }
            msg.at(i) = curr;
        }
    }
    cout << "Encrypted message: " << msg << endl;
}
