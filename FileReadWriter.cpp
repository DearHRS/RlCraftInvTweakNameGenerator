#include "FileReadWriter.h"

/*reads given file and return string vector*/
std::vector<std::string> FileReadWriter::GetFile(std::string filePath)
{
    std::fstream givenFile(filePath);
    std::string currentLine;
    std::vector<std::string> fileData;
    bool isComment = false;

    while (std::getline(givenFile, currentLine))
    {
        if ((currentLine.size() >= 2)) {
            if (!currentLine.substr(0, 2).compare("/*")) {
                isComment = true;
            }
            if (!currentLine.substr(currentLine.length() - 2, 2).compare("*/")) {
                isComment = false;
                continue;
            }
        }

        if (!isComment && (currentLine.size() > 0)) {
            fileData.push_back(currentLine);
        }
    }

    givenFile.close();
    return fileData;
}

/*writes all content of given string vector into file with time of execution*/
void FileReadWriter::WriteFile(std::string filePath, std::vector<std::string>& uploadData)
{
    std::fstream givenFile(filePath, std::ios::app);
    struct tm timeStruct;
    time_t t;
    t = time(NULL);
    localtime_s(&timeStruct, &t);

    givenFile << "/* data generated at " << timeStruct.tm_hour << ":" << timeStruct.tm_min << " " << 
        timeStruct.tm_mday + timeStruct.tm_isdst << " " << timeStruct.tm_mon + 1 << " " << 
        timeStruct.tm_year + 1900 << "\n";
    
    for (int i = 0; i < uploadData.size(); i++) {
        givenFile << uploadData[i] << "\n";
    }

    givenFile << "*/";
    givenFile.close();
}
