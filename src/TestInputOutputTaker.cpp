//
// Created by xMellox on 04-Aug-20.
//

#include "TestInputOutputTaker.h"
#include <fstream>
#include <test_folder_define.h>
#include "exist_file.h"


std::string TestInputOutputTaker::TestDir;

void TestInputOutputTaker::SetTestDir(const std::string& NewTestDir)
{
	TestDir = NewTestDir;
}

void TestInputOutputTaker::SetInput(test_input &input)
{
    std::ifstream TestDirFile;
    std::size_t i{};
    std::string test_in = GetInTestFile(i);

    while(exist_file(test_in))
    {
        TestDirFile.open(test_in);
        std::vector<std::string> v_lines;

        std::string in_line;
        while(std::getline(TestDirFile,in_line ))
        {
            v_lines.push_back(std::move(in_line));
        }

        input.push_back(std::move(v_lines));
        TestDirFile.close();

        ++i;
        test_in = GetInTestFile(i);
    }
}

void TestInputOutputTaker::SetOutput(test_output &output)
{
    std::ifstream TestDirFile;
    std::size_t i{};

    std::string test_out = GetOutTestFile(i);

    while(exist_file(test_out))
    {
        TestDirFile.open(test_out);
        std::string out_line;
        std::getline(TestDirFile, out_line);

        output.push_back(std::move(out_line));
        TestDirFile.close();

        ++i;
        test_out = GetOutTestFile(i);
    }

}

std::string TestInputOutputTaker::GetTestFile(std::size_t id, const std::string &conclude_with)
{
    std::string r{TESTS_FOLDER};
    r += "/";
    r += TestDir;
    r += "/test.";
    r += std::to_string(id);
    r += "." + conclude_with;

    return r;
}

std::string TestInputOutputTaker::GetInTestFile(std::size_t id)
{
  return GetTestFile(id, "in");
}

std::string TestInputOutputTaker::GetOutTestFile(std::size_t id)
{
    return GetTestFile(id, "out");
}

bool TestInputOutputTaker::DoesTestDirExist(const std::string& TestNameDir) noexcept
{
	std::ifstream TestDirFile;
	std::string TestFolder{TESTS_FOLDER};
	TestFolder += "/" + TestNameDir;
	TestDirFile.open(TestFolder);
	
	return TestDirFile.is_open();	
}

