//
// Created by xMellox on 11-Aug-20.
//

#ifndef TESTTASK_TASKFACTORY_H
#define TESTTASK_TASKFACTORY_H
#include "Task.h"
#include <memory>

struct ITaskFactory
{
    virtual ~ITaskFactory() = default;
    virtual std::unique_ptr<ITask> CreateTask(const std::string& TaskName) = 0;
};
#endif //TESTTASK_TASKFACTORY_H
