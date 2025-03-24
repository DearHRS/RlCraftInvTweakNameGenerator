#include "XMLGenerator.h"

std::string XMLGenerator::GetMod(std::vector<std::string>& rawData)
{
	for (int i = 0; i < rawData.size(); i++) {

	}

	return nullptr;
}

XMLGenerator::XMLGenerator(std::vector<std::string> rawFileData)
{

}

void XMLGenerator::Generate(std::vector<std::string>& weapons, std::vector<std::string>& tiers)
{
	/*for (int i = 0; i < weapons.size(); i++) {
		std::cout << "<" << weapons[i] << ">\n";
		
		for (int j = 0; j < tiers.size(); j++) {
			std::vector<std::string> modTier = SeparateModTier(tiers[j]);

			std::cout << "    <" << weapons[i] << CamelCase(modTier[1]) <<
				" id=\"" << modTier[0] << weapons[i] << "_" << modTier[1] << "\"/>\n";
		}

		std::cout << "</" << weapons[i] << ">\n";
	}*/
}
