#pragma once
#pragma warning(disable: 4251)

#include "Base.h"
#include "LayerBase.h"

namespace Sigma
{
    class LayerBase;

    class SIGMA_API LayerCollection
    {
    public:
        LayerCollection() = default;
        virtual ~LayerCollection();

        void pushLayer(std::shared_ptr<LayerBase> layer);
        void activateLayer(const std::shared_ptr<LayerBase> layer);
        void deactivateLayer(const std::shared_ptr<LayerBase> layer);
        bool hasLayer(const std::shared_ptr<LayerBase> layer);

        std::vector<std::shared_ptr<LayerBase>>::iterator begin() { return this->m_layers.begin(); }
        std::vector<std::shared_ptr<LayerBase>>::iterator end() { return this->m_layers.end(); }
        std::vector<std::shared_ptr<LayerBase>>::const_iterator begin() const { return this->m_layers.begin(); }
        std::vector<std::shared_ptr<LayerBase>>::const_iterator end()	const { return this->m_layers.end(); }

        std::vector<std::shared_ptr<LayerBase>>::reverse_iterator rbegin() { return this->m_layers.rbegin(); }
        std::vector<std::shared_ptr<LayerBase>>::reverse_iterator rend() { return this->m_layers.rend(); }
        std::vector<std::shared_ptr<LayerBase>>::const_reverse_iterator rbegin() const { return this->m_layers.rbegin(); }
        std::vector<std::shared_ptr<LayerBase>>::const_reverse_iterator rend() const { return this->m_layers.rend(); }

    private:
        std::vector<std::shared_ptr<LayerBase>> m_layers;
    };
}