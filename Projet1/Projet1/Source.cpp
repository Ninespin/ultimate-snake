#include <iostream>
#include <string>

using namespace std;

int main(int argc, char ** argv) {
	string word = "";

	cout << "Progam begin.";
	while (word != "OVR") {
		cout << "\n";
		cin >> word;
		if (word == "Hello") {
			cout << "Hello there.";
		}
		else {
			cout << "Uknown word: "<< word;
		}

	}
	cout << "Program over.\n";
	system("PAUSE");
}