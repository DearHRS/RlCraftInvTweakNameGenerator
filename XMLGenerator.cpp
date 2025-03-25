#include "XMLGenerator.h"

XMLGenerator::XMLGenerator(std::vector<std::string> rawFileData)
{
	std::vector<std::vector<int>> categoriesPosition = TextEditor::GetCategoriesPosition(rawFileData);
	
	for (int a = 0; a < categoriesPosition.size(); a++) {
		std::vector<std::string> rawCategory = std::vector<std::string>(
			rawFileData.begin() + categoriesPosition[a][0],
			rawFileData.begin() + categoriesPosition[a][1] + 1
		);
		categories.push_back(
			{
				TextEditor::GetParameterValue(rawCategory, "mod = "),
				TextEditor::GetVector(TextEditor::GetParameterValue(rawCategory, "items = "), ','),
				TextEditor::GetVector(TextEditor::GetParameterValue(rawCategory, "tiers = "), ',')
			}
		);
	}
}

std::vector<std::string> XMLGenerator::Generate()
{
	std::vector<std::string> returnVector;

	for (int a = 0; a < categories.size(); a++) {
		std::string currentMod = categories[a].mod;
		returnVector.push_back("<" + currentMod + ">");

		for (int b = 0; b < categories[a].items.size(); b++) {
			std::string currentItem = categories[a].items[b];
			returnVector.push_back("\t<" + currentItem + ">");

			for (int c = 0; c < categories[a].tiers.size(); c++) {
				std::string currentTier = categories[a].tiers[c];

				returnVector.push_back(
					"\t\t<" + currentItem + 
					TextEditor::RemoveChar(currentTier, '_') + TextEditor::GetShortForm(currentMod) +
					" id=\"" + TextEditor::GetLowerCase(currentMod) + ":" + 
					TextEditor::GetLowerCase(currentItem) + "_" + TextEditor::GetLowerCase(currentTier) +
					"\"/>"
				);
			}

			returnVector.push_back("\t</" + currentItem + ">");
		}

		returnVector.push_back("</" + currentMod + ">");
	}

	return returnVector;
}
