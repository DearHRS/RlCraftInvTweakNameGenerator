#include "TextEditor.h"

std::string TextEditor::CamelCase(std::string givenString)
{
	std::string returnString = "";
	returnString += char(int(givenString[0]) - 32);

	for (int i = 1; i < givenString.size(); i++) {
		if (givenString[i] == '_') {
			i++;
			givenString[i] = char(int(givenString[i]) - 32);
		}

		returnString += givenString[i];
	}
	return returnString;
}

std::vector<std::string> TextEditor::SeparateModTier(std::string givenString)
{
	std::vector<std::string> returnVector{ "", "" };
	bool isModName = true;

	for (int i = 0; i < givenString.size(); i++) {
		if (isModName) {
			returnVector[0] += givenString[i];
		}
		else {
			returnVector[1] += givenString[i];
		}

		if (givenString[i] == ':') {
			isModName = !isModName;
		}
	}

	return returnVector;
}

std::string TextEditor::GetParameterValue(std::vector<std::string> rawSet, std::string parameter)
{
	for (int i = 0; i < rawSet.size(); i++) {
		if (!rawSet[i].substr(0, parameter.size()).compare(parameter)) {
			return rawSet[i].substr(parameter.size(), rawSet[i].size() - parameter.size());
		}
	}

	return "failedRead";
}

std::vector<std::string> TextEditor::GetVector(std::string givenString, char delimiter)
{
	std::vector<std::string> returnVector;
	int elementHeaderPos = 0;

	givenString = RemoveChar(givenString, ' ');

	for (int currentPos = 0; currentPos < givenString.size(); currentPos++) {
		if (givenString[currentPos] == delimiter) {
			returnVector.push_back(givenString.substr(elementHeaderPos, currentPos - elementHeaderPos));
			elementHeaderPos = currentPos + 1;
		}
	}

	returnVector.push_back(givenString.substr(elementHeaderPos, givenString.size() - elementHeaderPos));
	return returnVector;
}

std::string TextEditor::RemoveChar(std::string givenString, char ignoreChar)
{
	std::string returnString = "";

	for (int i = 0; i < givenString.size(); i++) {
		if (givenString[i] != ignoreChar) {
			returnString += givenString[i];
		}
	}

	return returnString;
}

std::vector<std::vector<int>> TextEditor::GetCategoriesPosition(std::vector<std::string>& rawFileData)
{
	std::vector<std::vector<int>> posVector;
	int openPos;
	bool isCategoryOpen = false;

	for (int i = 0; i < rawFileData.size(); i++) {
		if (!isCategoryOpen && rawFileData[i][0] == '{') {
			openPos = i + 1;
			isCategoryOpen = true;
		}
		if (isCategoryOpen && rawFileData[i][0] == '}') {
			posVector.push_back(std::vector<int>{openPos, i - 1});
			isCategoryOpen = false;
		}
	}

	return posVector;
}

std::string TextEditor::GetLowerCase(std::string givenString)
{
	std::string lowerCased = "";

	for (int i = 0; i < givenString.size(); i++) {
		char currentChar = givenString[i];

		if ((currentChar >= 65) && (currentChar <= 90)) {
			currentChar += 32;
		}

		lowerCased += currentChar;
	}

	return lowerCased;
}

std::string TextEditor::GetShortForm(std::string givenString)
{
	std::string shortForm = "";

	for (int i = 0; i < givenString.size(); i++) {
		if ((givenString[i] >= 65) && (givenString[i] <= 90)) {
			shortForm += givenString[i];
		}
	}

	return shortForm;
}
