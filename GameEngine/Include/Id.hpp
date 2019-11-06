/**
 * @file      Id.hpp
 * @brief     This is the Id class
 * @details   This class will be used to generate a static id for each entities.
 */

#pragma once

#include <cstddef>

/**
 * @class Id Id.hpp "Include/Id.hpp"
 */
class Id
{
public:
    Id();
    const size_t &getId() const;

protected:
    const size_t id;

private:
    static size_t idGen;
};
