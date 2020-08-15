//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <memory>

struct ITask
{
    virtual std::string Run(const std::vector<std::string>& In) = 0;
    virtual ~ITask() = default;
    virtual std::unique_ptr<ITask> Clone() = 0;
};

