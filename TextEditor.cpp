#include "TextEditor.h"

/*removes underscore and capitalises next letter, underscore can not be last char*/
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

/*everything before : is 'mod' everything else is 'name'*/
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
