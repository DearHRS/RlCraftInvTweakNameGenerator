#include "XMLGenerator.h"

XMLGenerator::XMLGenerator(std::vector<std::string> rawFileData)
{
	std::vector<std::vector<int>> categoriesPosition = TextEditor::GetCategoriesPosition(rawFileData);
	
	for (int a = 0; a < categoriesPosition.size(); a++) {
		std::vector<std::string> rawCategory = std::vector<std::string>(
			rawFileData.begin() + categoriesPosition[a][0],
			rawFileData.begin() + categoriesPosition[a][1] + 1
		);
		std::string itemValue = TextEditor::GetParameterValue(rawCategory, "itemName = ");
		std::string tierValue = TextEditor::GetParameterValue(rawCategory, "tier = ");
		categories.push_back(
			{
				TextEditor::GetParameterValue(rawCategory, "mod = "),
				TextEditor::GetVector(itemValue.substr(1, itemValue.size() - 2), ','),
				TextEditor::GetVector(tierValue.substr(1, tierValue.size() - 2), ',')
			}
		);
	}
}

std::vector<std::string> XMLGenerator::Generate()
{
	std::vector<std::string> returnVector;

	for (int a = 0; a < categories.size(); a++) {
		returnVector.push_back("<" + categories[a].mod + ">");

		for (int b = 0; b < categories[a].items.size(); b++) {
			returnVector.push_back("\t<" + categories[a].items[b] + ">");

			for (int c = 0; c < categories[a].tiers.size(); c++) {
				returnVector.push_back(
					"\t\t<" + 
					categories[a].items[b] + categories[a].tiers[c] +
					" id=\"" + categories[a].mod + ":" + categories[a].items[b] +
					"_" + categories[a].tiers[c] +
					"\"/>"
				);
			}

			returnVector.push_back("\t</" + categories[a].items[b] + ">");
		}

		returnVector.push_back("</" + categories[a].mod + ">");
	}

	return returnVector;
}
