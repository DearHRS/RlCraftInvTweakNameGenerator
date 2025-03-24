#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include "TextEditor.h"

#include <iostream>

class FileReadWriter
{
private:

public:
	static std::vector<std::string> GetFile(std::string filePath);
	static void WriteFile(std::string filePath, std::vector<std::string>& uploadData);
};

