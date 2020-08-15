//
// Created by xMellox on 11-Aug-20.
//

#ifndef TESTTASK_FIRSTASSIGNMENTFACTORY_H
#define TESTTASK_FIRSTASSIGNMENTFACTORY_H

#include "TaskFactory.h"

struct FirstAssignmentFactory: public ITaskFactory
{
    std::unique_ptr<ITask> CreateTask(const std::string& TaskName) override;
};


#endif //TESTTASK_FIRSTASSIGNMENTFACTORY_H
