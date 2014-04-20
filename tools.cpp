#include <iostream>
#include <vector>
#include "tools.h"

using namespace std;

vector <string> parseCommand (string command){
	vector<string> result;

	string current = "";
	for (int i=0 ; i<command.length() ; i++) {
		if (command[i] == ' ') {
			if(current == "")
				continue;

			result.push_back(current);
			current = "";
		}
		else
			current += command[i];

	}
	if (current != "")
		result.push_back(current);

	return result;
} 
