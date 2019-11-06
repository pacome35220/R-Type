#include <iostream>
#include "Server.hpp"
#include "Error.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return EXIT_FAILURE;
    try {
        Server::start(std::atoi(argv[1]));
    }
    catch (Error error) {
        std::cerr << error.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
