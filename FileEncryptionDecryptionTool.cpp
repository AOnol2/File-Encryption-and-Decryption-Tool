#include <iostream>
#include <fstream>
using namespace std;

void encryptFile(const string& filename, int shift) {
    ifstream infile(filename);
    ofstream outfile(filename + ".enc");

    char ch;
    while (infile.get(ch)) {
        ch += shift;  // Encrypt by shifting ASCII value
        outfile.put(ch);
    }

    infile.close();
    outfile.close();
    cout << "File encrypted as " << filename << ".enc\n";
}

void decryptFile(const string& filename, int shift) {
    ifstream infile(filename);
    ofstream outfile("decrypted_" + filename);

    char ch;
    while (infile.get(ch)) {
        ch -= shift;  // Decrypt by reversing the shift
        outfile.put(ch);
    }

    infile.close();
    outfile.close();
    cout << "File decrypted as decrypted_" << filename << "\n";
}

int main() {
    string filename;
    int shift;
    char option;

    cout << "Enter file name: ";
    cin >> filename;
    cout << "Enter shift value for encryption/decryption: ";
    cin >> shift;

    cout << "Encrypt or Decrypt? (e/d): ";
    cin >> option;

    if (option == 'e') {
        encryptFile(filename, shift);
    } else if (option == 'd') {
        decryptFile(filename, shift);
    } else {
        cout << "Invalid option\n";
    }

    return 0;
}