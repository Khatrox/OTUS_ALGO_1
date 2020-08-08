//
// Created by xMellox on 04-Aug-20.
//

#include "TestTask.h"
#include <fstream>
#include "exist_file.h"

void TestTask::SetTestDir(const std::string& Path)
{

    TestDir = Path;
    if(TestDir.back() != '/')
    {
        TestDir += '/';
    }

    std::ifstream TestDirFile;
    std::size_t i{};

    std::string test_in = GetInTestFile(i);
    std::string test_out = GetOutTestFile(i);

    while(exist_file(test_in))
    {
        TestDirFile.open(test_in);
        std::vector<std::string> v_lines;

        std::string in_line;
        while(std::getline(TestDirFile,in_line ))
        {
            v_lines.push_back(std::move(in_line));
        }
        
        TaskIn.push_back(std::move(v_lines));

        TestDirFile.close();

        TestDirFile.open(test_out);
        std::string out_line;
        std::getline(TestDirFile, out_line);

        TaskOutput.push_back(std::move(out_line));
        TestDirFile.close();

        ++i;
        test_in = GetInTestFile(i);
        test_out = GetOutTestFile(i);
    }

}


std::string TestTask::GetTestFile(std::size_t id, const std::string &conclude_with) const
{
    std::string r{TestDir};
    r += "test.";
    r += std::to_string(id);
    r += "." + conclude_with;

    return r;
}

std::string TestTask::GetInTestFile(std::size_t id) const
{
  return GetTestFile(id, "in");
}

std::string TestTask::GetOutTestFile(std::size_t id) const
{
    return GetTestFile(id, "out");
}

