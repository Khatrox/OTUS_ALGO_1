//
// Created by xMellox on 04-Aug-20.
//

#pragma once
#include <vector>
#include <string>
#include <cmath>

struct ITask
{
    virtual std::string Run(const std::vector<std::string>& In) = 0;
};

struct StringLength: public ITask
{
    std::string Run(const std::vector<std::string>& v) override
    {
        return std::to_string(v[0].size());
    }
};

struct LuckyTickets: public ITask
{
    std::string Run(const std::vector<std::string>& v) override
    {
        auto N = std::stoi(v[0]);
        return std::to_string(GetLuckyTickets(N));
    }

private:

    std::size_t GetSumOfDigitNumbers(std::size_t Digit)
    {
        std::size_t r{};
        while(Digit)
        {
            r += Digit % 10;
            Digit /= 10;
        }

        return r;
    }

    std::size_t GetLuckyTickets(std::size_t N)
    {
        auto check_part = static_cast<std::size_t>(std::pow(10,N));

        std::vector<std::size_t> v_sums;
        const std::size_t sums = (N * 9) + 1;
        v_sums.resize(sums);

        for(std::size_t i{}; i < check_part; ++i)
        {
            auto sum = GetSumOfDigitNumbers(i);

            ++v_sums[sum];
        }

        std::size_t r{};

        for(const auto i: v_sums)
        {
            r += (i * i);
        }

        return r;
    }

};