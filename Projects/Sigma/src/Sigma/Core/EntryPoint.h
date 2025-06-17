
#include "Bootstrap.h"

int main(int argc, char** argv)
{
    // @todo Profiling
    auto app = Sigma::CreateApplication({ 0, {} });

    // @todo Profiling
    app->Init();

    // @todo Profiling
    app->Run();

    return 0;
}