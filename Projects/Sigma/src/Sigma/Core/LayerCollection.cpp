
#include "LayerCollection.h"

namespace Sigma
{
    LayerCollection::~LayerCollection()
    {
        //this->m_layers.clear();
    }

    void LayerCollection::pushLayer(std::shared_ptr<LayerBase> layer)
    {
        if (this->hasLayer(layer)) {
            return;
        }

        m_layers.push_back(layer);
    }

    void LayerCollection::activateLayer(const std::shared_ptr<LayerBase> layer)
    {
        if (!this->hasLayer(layer)) {
            return;
        }

        layer->activateLayer();
    }

    void LayerCollection::deactivateLayer(const std::shared_ptr<LayerBase> layer)
    {
        if (!this->hasLayer(layer)) {
            return;
        }

        layer->deactivateLayer();
    }

    bool LayerCollection::hasLayer(std::shared_ptr<LayerBase> layer)
    {
        auto it = std::find(this->m_layers.begin(), this->m_layers.end(), layer);

        return it != this->m_layers.end();
    }
}