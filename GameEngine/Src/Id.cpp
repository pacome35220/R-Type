/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Id.cpp
*/

#include "Id.hpp"

/**
 * @brief Generate a static id (start at 0 obviously)
 */
std::size_t Id::idGen = 0;

Id::Id(): id(idGen++) {}

std::size_t Id::getId() const {
    return id;
}

void Id::setId(size_t _id) {
    this->id = _id;
}
