/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** HaveId.cpp
*/

#include "HaveId.hpp"

HaveId::HaveId()
    : id(idGen++)
{
}

HaveId::HaveId(const size_t &_id)
    : id(_id)
{
    //idGen = id + 1; // ??
}

const size_t &HaveId::getId() const
{
    return id;
}
