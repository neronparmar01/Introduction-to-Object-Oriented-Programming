/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// tester program
//
// File: TextFile.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date    7/15/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"

using namespace std;
namespace sdds {

	TextFile::Line::operator const char* () const {
		return (const char*)m_value;
	}

	TextFile::Line& TextFile::Line::operator=(const char* lineContent) {
		delete[] m_value;
		m_value = new char[strLen(lineContent) + 1];
		strCpy(m_value, lineContent);
		return *this;
	}

	TextFile::Line::~Line() {
		delete[] m_value;
	}

	void TextFile::setEmpty() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy) {
		// setEmpty();
		if (fname == nullptr || fname[0] == '\0')
			return;
		else if (!isCopy) {
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else {
			m_filename = new char[strLen(fname) + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines() {
		std::ifstream file(m_filename);
		if (file.is_open()) {
			m_noOfLines = 0;
			char ch;
			while (file.get(ch)) {
				if (ch == '\n')
					m_noOfLines++;
			}
			if (m_noOfLines > 0)
				m_noOfLines++;
			file.close();
		}
		else {
			m_noOfLines = 0;
			setEmpty();
		}
	}

	void TextFile::loadText() {
		if (!*this)
			return;

		if (m_textLines != nullptr) {
			delete[] m_textLines;
			m_textLines = nullptr;
		}

		m_textLines = new Line[m_noOfLines];
		ifstream fileObject;
		fileObject.open(m_filename);
		if (fileObject.is_open()) {
			string line;
			int i = 0;
			while (getline(fileObject, line)) {
				m_textLines[i] = line.c_str();
				i++;
			}
			m_noOfLines = i;
			fileObject.close();
		}
	}

	void TextFile::saveAs(const char* fileName) const {
		ofstream fileOutputObject;
		fileOutputObject.open(fileName);
		if (fileOutputObject.is_open()) {
			for (unsigned i = 0; i < m_noOfLines; i++) {
				fileOutputObject << (const char*)m_textLines[i] << endl;
			}
			fileOutputObject.close();
		}
	}

	TextFile::TextFile(unsigned pageSize) {
		m_pageSize = pageSize;
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) : TextFile(pageSize) {
		if (filename != nullptr) {
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const TextFile& other) : TextFile(other.m_pageSize) {
		if (other) {
			this->setFilename(other.m_filename, true);
			other.saveAs(this->m_filename);
			this->setNoOfLines();
			this->loadText();
		}
	}

	TextFile& TextFile::operator=(const TextFile& other) {
		if (this != &other) {
			delete[] m_textLines;
			m_textLines = nullptr;
			setFilename(other.m_filename, false);
			setNoOfLines();
			loadText();
		}
		return *this;
	}

	TextFile::~TextFile() {
		setEmpty();
	}

	std::ostream& TextFile::view(std::ostream& ostr) const {
		if (*this) {
			ostr << m_filename << endl;
			for (unsigned i = 0; i < strLen(m_filename); i++) {
				ostr << '=';
			}
			ostr << endl;
			unsigned count = 0;
			while (count < m_noOfLines) {
				for (unsigned i = 0; i < m_pageSize && count < m_noOfLines; i++) {
					ostr << (const char*)m_textLines[count] << endl;
					count++;
				}

				if (count < m_noOfLines) {
					string fake;
					ostr << "Hit ENTER to continue...";
					getline(cin, fake);
				}
			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr) {
		string fileName;
		getline(istr, fileName);
		setFilename(fileName.c_str());
		setNoOfLines();
		loadText();

		return istr;
	}

	TextFile::operator bool() const {
		return m_filename != nullptr && m_noOfLines > 0;
	}

	unsigned TextFile::lines() const {
		return m_noOfLines;
	}

	const char* TextFile::name() const {
		return (const char*)m_filename;
	}

	const char* TextFile::operator[](unsigned index) const {
		return *this ? (const char*)m_textLines[index % m_noOfLines] : nullptr;
	}

	ostream& operator<<(ostream& ostr, const TextFile& text) {
		return text.view(ostr);
	}

	istream& operator>>(istream& istr, TextFile& text) {
		return text.getFile(istr);
	}
}
