#include "dstring.h"

int main(int argc, char* argv)
{
    str_t* hello_world = string_dup("hello_world");
    print_string(hello_world, stdout);

    fprintf(stdout, "\n length = %d", string_lenght(hello_world));

    str_t* concated = string_concatenate(hello_world, hello_world);
    print_string(concated, stdout);

    string_free(concated);
    string_free(hello_world);

    system("PAUSE");
    return 0;
}
