#pragma once

#include "Base.h"

namespace Sigma
{
    class LayerBase
    {
    public:
        DEBUG_CODE(
            LayerBase(std::string name): m_name(name) {}
        )

        LayerBase() {}
        ~LayerBase() {}

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(const float delta) {}
        virtual void OnEvent() {}

    private:
        DEBUG_CODE(
            std::string m_name = "";
        )
    };
}
