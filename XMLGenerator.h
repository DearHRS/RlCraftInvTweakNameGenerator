#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "TextEditor.h"

class XMLGenerator
{
	struct Category {
		std::string mod;
		std::vector<std::string> items;
		std::vector<std::string> tiers;
	};

private:
	std::vector<Category> categories;

public:
	XMLGenerator(std::vector<std::string> rawFileData);

	/*
	generates xml entires
	mod as category
	itemTier as item name
	*/
	std::vector<std::string> Generate();
};

