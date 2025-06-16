#pragma once
#pragma warning(disable: 4251)

#include "Base.h"
#include "LayerCollection.h"

namespace Sigma
{
    class LayerCollection;

    class SIGMA_API LayerBase
    {
    public:
        LayerBase(const std::string& name = "Unnamed Layer") : m_name(name.c_str()) {}
        ~LayerBase() {}

        const std::string GetName() { return this->m_name; }

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(const float delta) {}
        virtual void OnEvent() {}

        // Make friends with collection it has control over active status
        friend class LayerCollection;

    private:
        void activateLayer() { this->m_active = true; }
        void deactivateLayer() { this->m_active = false; }

    private:
        bool m_active = false;
        std::string m_name;
    };
}