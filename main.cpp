
#include <iostream>
#include <console.hpp>

using namespace std;
int main(int argc, char** argv)
{
    LOG("Hello world");
    TRACE("trace");
    DEBUG("debug");
    INFO("info");
    WARN("warn");
    ERROR("error");
    FATAL("fatal");
    return 0;
}
