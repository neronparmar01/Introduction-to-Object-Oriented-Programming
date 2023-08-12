/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// tester program
//
// File: Label.cpp
//
// Revision History
// -----------------------------------------------------------
// Name     Neron Parmar     Date   6/11/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "cstring.h"
#include "Label.h"
#include <istream>

using namespace std; 
namespace sdds {

	Label::Label() {
		this->frame = nullptr;
		this->content = nullptr;
		char defaultChar[] = "+-+|+-+|";
		this->frame = new char[strLen(defaultChar) +1 ];
		strCpy(frame, defaultChar);
	}

	Label::Label(const char* frameArg) {
		this->frame = nullptr;
		this->content = nullptr;
		this->frame = new char[strLen(frameArg) + 1];
		strCpy(frame, frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {
		//copying the frame
		this->frame = nullptr;
		this->frame = new char[strLen(frameArg) + 1];
		strCpy(this->frame, frameArg);
		
		//copying the content
		this -> content = nullptr;
		this->content = new char[strLen(content) + 1];
		strCpy(this -> content, content);				// get the content copied
	}

	Label::~Label() {
		if (this->content || content != nullptr) {
			delete[] this->content;
			this->content = nullptr;
		}

		// deallocate frame
		if (this->frame || this->frame != nullptr) {
			delete[] this->frame;
			this->frame = nullptr;
		}
	}

	void Label::readLabel() {
		char content[71];
		cout << "> ";
		cin.getline(content, 71);
		if (this->content != nullptr) {
			delete[] this-> content;
		}
		this -> content = new char[strLen(content) + 1];
		strCpy(this->content, content);
	}

	std::ostream& Label::printLabel() const {
		int contentLength;
		int i = 0; 
		if (this->content != nullptr && this->content[0] != '\0') {
			cout << frame[0];
			contentLength = strLen(content);
			while (i < contentLength + 2) {
				cout << frame[1];
				i++;
			}
			
			i = 0;
			cout << frame[2] << endl;
			cout << frame[7];
			//creating space
			while (i < contentLength + 2) {
				cout << ' ';
				i++;
			}

			i = 0;
			cout << frame[3] << endl;
			cout << frame[7] << ' ' << this->content << ' ' << frame[3] << endl;
			cout << frame[7];
			while (i < contentLength + 2) {
				cout << ' ';
				i++;
			}

			i = 0;
			cout << frame[3] << endl;
			cout << frame[6];
			while (i < contentLength + 2) {
				cout << frame[5];
				i++;
			}

			cout << frame[4];
		}
		return cout;
	}
}