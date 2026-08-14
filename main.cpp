#include <console.hpp>
#include <arguments.hpp>

int main(int argc, char **argv)
{
    Arguments args(argc, argv);
    for (ReadOnly<string> a : args)
        INFO(a);
    return 0;
}
