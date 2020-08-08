//
// Created by xMellox on 04-Aug-20.
//

#ifndef TESTTASK_EXIST_FILE_H
#define TESTTASK_EXIST_FILE_H

#include <string>
#include <sys/stat.h>

bool exist_file(const std::string& name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

#endif //TESTTASK_EXIST_FILE_H
