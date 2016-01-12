#include <iostream>
#include <string>
#include<vector>
#include<map>


using namespace std;

struct operation {
	vector<string> targets;
	vector<string> actions;
};
void(*adf)(int);
map<const string, void(*)(int)>dictionary = {
	{"ouvrir",fct},
	{"fermer",adf}
};


void checkWord(operation* op, string word) {
	if (word.at(0) == 'a') { 
		(*op).actions.push_back(word);
	}
	else if (word.at(0) == 't') {
		(*op).targets.push_back(word);
	}
	else {
		cout << "Uknown word: " << word;
	}

}

void fct(int n) {

}

void processOperation(operation* op) {
	for (std::vector<string>::iterator i = (*op).actions.begin(); i != (*op).actions.end(); i++) {
		string targs;
		for (std::vector<string>::iterator t = (*op).targets.begin(); t != (*op).targets.end();t++) {
			targs += (*t);
			if (t < (*op).targets.end()-1) {
				targs += " and ";
			}
		}
		cout << "Action "<< (*i) << " will be applied to " << targs <<".\n";
	}
}

int main(int argc, char ** argv) {
	string word = "";
	operation * op = new operation;

	cout << "Progam begin.";
	while (word != "OVR") {
		cout << "\n";
		cin >> word;

		checkWord(op,word);
				
		
			
		

	}
	cout << "\nProgram over.\n";
	processOperation(op);
	system("PAUSE");

	delete op;
}