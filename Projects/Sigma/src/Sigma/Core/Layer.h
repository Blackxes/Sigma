#pragma once

namespace Sigma
{
    class Layer
    {
    public:
        bool Init();
        bool Update(const float delta);
        bool HandleEvents();
        bool Shutdown();
    };
}
