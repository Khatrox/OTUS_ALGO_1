//
// Created by xMellox on 11-Aug-20.
//

#ifndef TESTTASK_TASKFACTORY_H
#define TESTTASK_TASKFACTORY_H
#include "Task.h"
#include <memory>
#include <map>

struct TaskFactory
{

    static TaskFactory& Instance();
    std::unique_ptr<ITask> CreateTask(const std::string& TaskName);

private:
    std::map<std::string, ITask*> TaskMap;
    TaskFactory();
    ~TaskFactory();
};


#endif //TESTTASK_TASKFACTORY_H
