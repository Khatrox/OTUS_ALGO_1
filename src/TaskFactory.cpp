//
// Created by xMellox on 11-Aug-20.
//

#include "TaskFactory.h"

std::unique_ptr<ITask> TaskFactory::CreateTask(const std::string &TaskName)
{
    std::unique_ptr<ITask> r{};
    auto it = TaskMap.find(TaskName);

    if(it != std::end(TaskMap))
    {
       auto Task = (*it).second;
       r = Task->Clone();
    }

    return r;
}

TaskFactory::TaskFactory()
{
    TaskMap.insert(std::make_pair("String", new StringLength()));
    TaskMap.insert(std::make_pair("LuckyTickets", new LuckyTickets()));
}

TaskFactory::~TaskFactory()
{
    for(const auto & i : TaskMap)
    {
        delete i.second;
    }
}

TaskFactory &TaskFactory::Instance()
{
    static TaskFactory taskFactory;

    return taskFactory;
}
