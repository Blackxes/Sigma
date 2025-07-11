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

        void PushLayer(std::shared_ptr<LayerBase> layer);
        void ActivateLayer(const std::shared_ptr<LayerBase> layer);
        void DeactivateLayer(const std::shared_ptr<LayerBase> layer);
        bool HasLayer(const std::shared_ptr<LayerBase> layer);

        std::vector<std::shared_ptr<LayerBase>>::iterator begin() { return m_layers.begin(); }
        std::vector<std::shared_ptr<LayerBase>>::iterator end() { return m_layers.end(); }
        std::vector<std::shared_ptr<LayerBase>>::const_iterator begin() const { return m_layers.begin(); }
        std::vector<std::shared_ptr<LayerBase>>::const_iterator end()	const { return m_layers.end(); }

        std::vector<std::shared_ptr<LayerBase>>::reverse_iterator rbegin() { return m_layers.rbegin(); }
        std::vector<std::shared_ptr<LayerBase>>::reverse_iterator rend() { return m_layers.rend(); }
        std::vector<std::shared_ptr<LayerBase>>::const_reverse_iterator rbegin() const { return m_layers.rbegin(); }
        std::vector<std::shared_ptr<LayerBase>>::const_reverse_iterator rend() const { return m_layers.rend(); }

    private:
        std::vector<std::shared_ptr<LayerBase>> m_layers;
    };
}