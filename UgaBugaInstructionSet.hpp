/*
Copyright 2017 Igor Santarek

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef UGABUGA_INSTRUCTIONSET_H
#define UGABUGA_INSTRUCTIONSET_H

#include <map>
#include <string>
#include "UgaBugaInstructions.hpp"

using namespace std;

// abstract factory.

class UgaBugaInstructionSet {
	map<string, UgaBugaInstruction*> instructions;

public:
	UgaBugaInstructionSet() {
		instructions["Uga"] = new UgaBugaOutputInstruction();
		instructions["Buga"] = new UgaBugaInputInstruction();
		instructions["UgaBuga"] = new UgaBugaIncrementInstruction();
		instructions["BugaBuga"] = new UgaBugaDecrementInstruction();
	}

	~UgaBugaInstructionSet() {
		delete instructions["Uga"];
		delete instructions["Buga"];
		delete instructions["UgaBuga"];
		delete instructions["BugaBuga"];
	}

	UgaBugaInstruction* getInstruction(string& key) {
		auto it = instructions.find(key);
		if(it != instructions.end()) {
			return it->second;
		}
		throw exception();
	}
};

#endif