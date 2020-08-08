//
// Created by xMellox on 04-Aug-20.
//

#ifndef TESTTASK_TESTTASK_H
#define TESTTASK_TESTTASK_H

#include <string>
#include <memory>
#include <sys/stat.h>
#include "Task.h"
#include <get_cmake_source_dir.h>

struct TestTask
{
    using in = std::vector<std::vector<std::string>>;
    using out = std::vector<std::string>;

    TestTask() = default;
    ~TestTask() = default;

    TestTask(const TestTask&) = delete;
    TestTask& operator=(const TestTask&) = delete;

    TestTask(TestTask&&) noexcept = delete;
    TestTask& operator=(TestTask&&) noexcept = delete;

    void SetTestDir(const std::string& Path);
    
    in::iterator in_begin()
    {
        return TaskIn.begin();
    }

    in::iterator in_end()
    {
        return TaskIn.end();
    }

    out::iterator out_begin()
    {
        return TaskOutput.begin();
    }

private:

    std::string TestDir;

    std::vector<std::vector<std::string>> TaskIn;
    std::vector<std::string> TaskOutput;

    std::string GetTestFile(std::size_t id, const std::string& conclude_with) const;
    std::string GetInTestFile(std::size_t id) const;
    std::string GetOutTestFile(std::size_t id) const;

};

#endif //TESTTASK_TESTTASK_H
