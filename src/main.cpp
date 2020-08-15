#include <iostream>
#include "TestInputOutputTaker.h"
#include "Task.h"
#include "TaskFactory.h"
#include <gtest/gtest.h>

namespace GoogleTestIn
{
    test_input testInput;
}

struct TestTaskFixture : testing::TestWithParam<std::vector<std::string>>
{
    static void SetUpTestSuite()
    {
        task = TaskFactory::Instance().CreateTask(TaskName);
        TestInputOutputTaker::SetOutput(testOutput);
        v_output_it = testOutput.begin();
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
    
    static void SetTaskName(const std::string& NewTaskName)
    {
    	TaskName = NewTaskName;
    }

private:

    static std::unique_ptr<ITask> task;
    static test_output testOutput;
    static std::vector<std::string>::iterator v_output_it;
    static std::string TaskName;
};

std::unique_ptr<ITask> TestTaskFixture::task = nullptr;
test_output TestTaskFixture::testOutput;
std::vector<std::string>::iterator TestTaskFixture::v_output_it;
std::string TestTaskFixture::TaskName;

INSTANTIATE_TEST_SUITE_P(TestInstantiation,
                         TestTaskFixture,
                         testing::ValuesIn
                         (::GoogleTestIn::testInput.begin(),
                                 ::GoogleTestIn::testInput.end())
);

TEST_P(TestTaskFixture, CheckTask)
{
    auto output = RunTask();

    ASSERT_STREQ(output.c_str(), GetOutput().c_str());
}

bool DoesTaskExist(const std::string& TaskName)
{
    return (TaskFactory::Instance().CreateTask(TaskName)) != nullptr;
}

int main(int argc, char** argv)
{

    if(argc < 2)
    {
        std::cout << "You forgot pass TaskName\n";

        return EXIT_FAILURE;
    }

    if(!DoesTaskExist(argv[1]))
    {
        std::cout << "Invalid task.\n";
        std::cout << "For now available TaskNames are:\n";
        std::cout << "1.String\n";
        std::cout << "2.LuckyTickets\n";
        return EXIT_FAILURE;
    }

    TestTaskFixture::SetTaskName(argv[1]);
    TestInputOutputTaker::SetTaskName(argv[1]);
    TestInputOutputTaker::SetInput(GoogleTestIn::testInput);
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
