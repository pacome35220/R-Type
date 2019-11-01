/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** HaveId.hpp
*/

#pragma once

#include <cstddef> // for size_t

class HaveId
{
public:
    HaveId();
    HaveId(const size_t &_id);
    const size_t &getId() const;

protected:
    const size_t id;

private:
    static size_t idGen;
};
