#include "WeaponNameGenerator.h"

WeaponNameGenerator::WeaponNameGenerator()
{
}

void WeaponNameGenerator::Generate(std::vector<std::string>& weapons, std::vector<std::string>& tiers)
{
	for (int i = 0; i < weapons.size(); i++) {
		std::cout << "<" << weapons[i] << ">\n";
		
		for (int j = 0; j < tiers.size(); j++) {
			std::vector<std::string> modTier = SeparateModTier(tiers[j]);

			std::cout << "    <" << weapons[i] << CamelCase(modTier[1]) <<
				" id=\"" << modTier[0] << weapons[i] << "_" << modTier[1] << "\"/>\n";
		}

		std::cout << "</" << weapons[i] << ">\n";
	}
}

void WeaponNameGenerator::GenerateMelee()
{
	Generate(meleeWeaponType, tiers);
}

void WeaponNameGenerator::GenerateRanged()
{
	Generate(rangedWeaponType, tiers);
}

std::string WeaponNameGenerator::CamelCase(std::string givenString)
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

std::vector<std::string> WeaponNameGenerator::SeparateModTier(std::string givenString)
{
	std::vector<std::string> returnVector{"", ""};
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
