#pragma once
#include <vector>
#include <string>

class TextEditor
{
private:
	
public:
	static std::string CamelCase(std::string givenString);
	static std::vector<std::string> SeparateModTier(std::string givenString);
	static bool IsEqualString(std::string baseString, std::string comparedString);
};

