#include <iostream> // cout
#include <fstream> // ifstream
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    ifstream input;
    input.open("test.txt");

    string line;
    while(!input.eof()) {
        getline(input, line);
        cout << line << endl;
    }
    input.close();

    ofstream output;
    output.open("abc.txt");
    output << "1234" << line << endl;

    return 0;
}
