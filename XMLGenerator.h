#pragma once
#include <iostream>
#include <string>
#include <vector>

class XMLGenerator
{
private:
	//std::vector<Category> categories;
	
	std::string GetMod(std::vector<std::string>& rawData);
	std::vector<std::string> GetItems(std::vector<std::string>& rawData);
	std::vector<std::string> GetTiers(std::vector<std::string>& rawData);

public:
	XMLGenerator(std::vector<std::string> rawFileData);
	void Generate(std::vector<std::string>& weapons, std::vector<std::string>& tiers);
};

struct Category{
	std::string mod;
	std::vector<std::string> tiers;
	std::vector<std::string> items;
};