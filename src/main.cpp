#include <iostream>
#include "TestTask.h"
#include "Task.h"
#include <gtest/gtest.h>

namespace Test
{
    TestTask testTask;
}

struct TestTaskFixture : testing::TestWithParam<std::vector<std::string>>
{
    static void SetUpTestSuite()
    {
        std::string s = __argv[2];

        if(s == "String")
        {
            task = std::make_unique<StringLength>();
        }
        else if( s == "LuckyTickets")
        {
            task = std::make_unique<LuckyTickets>();
        }

        v_output_it = ::Test::testTask.out_begin();
    }

    std::string RunTask()
    {
        return task->Run(GetParam());
    }

    std::string GetOutput() const
    {

        std::string r = *v_output_it;
        ++v_output_it;

        return r;
    }

private:

    static std::unique_ptr<ITask> task;
    static std::vector<std::string>::iterator v_output_it;

};

std::unique_ptr<ITask> TestTaskFixture::task = nullptr;
std::vector<std::string>::iterator TestTaskFixture::v_output_it;


INSTANTIATE_TEST_SUITE_P(TestInstantiation,
                         TestTaskFixture,
                         testing::ValuesIn(::Test::testTask.in_begin(),::Test::testTask.in_end())
);

TEST_P(TestTaskFixture, CheckTask)
{
    auto output = RunTask();

    ASSERT_STREQ(output.c_str(), GetOutput().c_str());
}

int main(int argc, char** argv)
{

    if(argc < 3)
    {
        return EXIT_FAILURE;
    }
 
    ::Test::testTask.SetTestDir(argv[1]);
    testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}