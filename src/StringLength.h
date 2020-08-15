//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include "Task.h"


struct StringLength: ITask
{
    std::string Run(const std::vector<std::string>& v) override
    {
        return std::to_string(v[0].size());
    }

    std::unique_ptr<ITask> Clone() override
    {
        return std::make_unique<StringLength>();
    }
};
