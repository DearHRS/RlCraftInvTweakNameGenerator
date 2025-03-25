#include <iostream>
#include "XMLGenerator.h"
#include "FileReadWriter.h"

int main()
{
    /*to do:

    text parser 
        + ignore comments, 
        + get category,
        + get mod, 
        + get item, 
        + get tier,
        get formula
        actually generate data
        have that data show up in file

    run formula in xml generator*/

    std::vector<std::string> rawFileData = FileReadWriter::GetFile("xmlOutput.txt");
    XMLGenerator xmlData(rawFileData);
    std::vector<std::string> generatedData = xmlData.Generate();

    for (int i = 0; i < generatedData.size(); i++) {
        std::cout << generatedData[i];
    }

    FileReadWriter::WriteFile("xmlOutput.txt", generatedData);
}
