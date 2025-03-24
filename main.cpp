#include <iostream>
#include "XMLGenerator.h"
#include "FileReadWriter.h"

int main()
{
    /*to do:

    text parser 
        + ignore comments, 
        get mod, 
        get item, 
        get tier, 
        get formula

    run formula in xml generator*/

    std::vector<std::string> fileData = FileReadWriter::GetFile("xmlOutput.txt");

    for (int i = 0; i < fileData.size(); i++) {
        std::cout << fileData[i] << "\n";
    }
}
