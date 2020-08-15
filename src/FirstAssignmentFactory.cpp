//
// Created by xMellox on 11-Aug-20.
//

#include "FirstAssignmentFactory.h"
#include "StringLength.h"
#include "LuckyTickets.h"

std::unique_ptr<ITask> FirstAssignmentFactory::CreateTask(const std::string &TaskName)
{
    std::unique_ptr<ITask> r{};
    
    if(TaskName == "String")
    {
    	r = std::make_unique<StringLength>();
    }
    else if(TaskName == "LuckyTickets")
    {
    	r = std::make_unique<LuckyTickets>();
    }

    return r;
}

