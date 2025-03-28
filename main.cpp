#include <iostream>
#include "XMLGenerator.h"
#include "FileReadWriter.h"

int main()
{
    /*
    to do:

    text parser 
        + ignore comments, 
        + get category,
        + get mod, 
        + get item, 
        + get tier,

    +actually generate data
    +have that data show up in file
    */

    std::vector<std::string> rawFileData = FileReadWriter::GetFile("xmlOutput.txt");
    XMLGenerator xmlData(rawFileData);
    std::vector<std::string> generatedData = xmlData.Generate();
    FileReadWriter::WriteFile("xmlOutput.txt", generatedData);
}
