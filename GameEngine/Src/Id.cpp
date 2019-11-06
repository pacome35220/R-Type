/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Id
*/

#include "Id.hpp"

size_t Id::idGen = 0;

Id::Id() : id(idGen++)
{
}

const size_t &Id::getId() const
{
    return id;
}
