#include "CLI11.hpp"
#include <iostream>

int main(int argc, char **argv) {
    CLI::App app{"App desc"};
    
    int p = 0;
    app.add_option("-p", p, "Parameter");
    CLI11_PARSE(app, argc, argv);

    std::cout << "Value: " << p << std::endl;

    return 0;
}
