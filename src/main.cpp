#include <iostream>
#include "TestInputOutputTaker.h"
#include "Task.h"
#include "TaskFactory.h"
#include <gtest/gtest.h>
#include "FirstAssignmentFactory.h"

namespace GoogleTestIn
{
    test_input testInput;
}

struct TestTaskFixture : testing::TestWithParam<std::vector<std::string>>
{
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
    
    static void Init(std::unique_ptr<ITask> ParamTask)
    {
    	 task = std::move(ParamTask);
        TestInputOutputTaker::SetOutput(testOutput);
        v_output_it = testOutput.begin();
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

bool DoesTaskExist(ITaskFactory* TaskFactory, const std::string& TaskName)
{
    return (TaskFactory->CreateTask(TaskName)) != nullptr;
}

int RunTestMachine(std::unique_ptr<ITaskFactory> TaskFactory, int argc, char** argv)
{
    
    if(argc < 3)
    {
        std::cout << "Here is write template [TaskName] [TestDirName]\n";

        return EXIT_FAILURE;
    }

    if(!DoesTaskExist(TaskFactory.get(),argv[1]))
    {
        std::cout << "Invalid task.\n";
        return EXIT_FAILURE;
    }
    
    if(!TestInputOutputTaker::DoesTestDirExist(argv[2]))
    {
    	std::cout << "Invalid dir.\n";
    	return EXIT_FAILURE;
    }
    
    TestInputOutputTaker::SetTestDir(argv[2]);
    TestInputOutputTaker::SetInput(GoogleTestIn::testInput);
    
    auto Task = TaskFactory->CreateTask(argv[1]);
    TestTaskFixture::Init(std::move(Task));
    
    testing::InitGoogleTest(&argc, argv);
    
    return  RUN_ALL_TESTS();
}

int main(int argc, char** argv)
{

   auto Factory = std::make_unique<FirstAssignmentFactory>();
   
   return RunTestMachine(std::move(Factory),argc, argv);
}
