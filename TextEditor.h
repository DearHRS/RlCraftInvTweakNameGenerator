#pragma once
#include <vector>
#include <string>

/*
has very specific functions to edit text or get vector out of them
*/
class TextEditor
{
private:
	
public:
	/*removes underscore and capitalises next letter, underscore can not be last char*/
	static std::string CamelCase(std::string givenString);
	
	/*
	return vector of size 2
	mod is 0
	name is 1
	everything before : is 'mod' everything else is 'name'
	*/
	static std::vector<std::string> SeparateModTier(std::string givenString);
	
	/*return everything in 'rawSet' inside of 'parameter', if 'parameter' doesn't exist returns 'failedRead'*/
	static std::string GetParameterValue(std::vector<std::string> rawSet, std::string parameter);
	
	/*returns string vector separated by given delimiter*/
	static std::vector<std::string> GetVector(std::string givenString, char delimiter);
	
	/*returns string by ignoring given ignoreChar*/
	static std::string RemoveChar(std::string givenString, char ignoreChar);

	/*returns position between {}*/
	static std::vector<std::vector<int>> GetCategoriesPosition(std::vector<std::string>& rawFileData);

	/*returns lower cased string*/
	static std::string GetLowerCase(std::string givenString);

	/*returns capital letters*/
	static std::string GetShortForm(std::string givenString);
};

