//
// Created by xMellox on 04-Aug-20.
//

#ifndef TESTTASK_TESTTASK_H
#define TESTTASK_TESTTASK_H

#include <string>
#include <memory>
#include <sys/stat.h>
#include "Task.h"

using test_input = std::vector<std::vector<std::string>>;
using test_output = std::vector<std::string>;

struct TestInputOutputTaker
{
    static void SetTaskName(const std::string& NewTaskName);
    static void SetInput(test_input& input);
    static void SetOutput(test_output& output);

private:
    
    static std::string GetTestFile(std::size_t id, const std::string& conclude_with);
    static std::string GetInTestFile(std::size_t id);
    static std::string GetOutTestFile(std::size_t id);
    static std::string TaskName;
};

#endif //TESTTASK_TESTTASK_H
