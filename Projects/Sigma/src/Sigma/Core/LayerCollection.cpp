
#include "sigmapch.h"
#include "LayerCollection.h"

namespace Sigma
{
	LayerCollection::~LayerCollection()
	{
		m_layers.clear();
	}

	void LayerCollection::PushLayer(std::shared_ptr<LayerBase> layer)
	{
		if (HasLayer(layer))
			return;

		m_layers.push_back(layer);
	}

	void LayerCollection::ActivateLayer(const std::shared_ptr<LayerBase> layer)
	{
		if (!HasLayer(layer))
			return;

		layer->activateLayer();
	}

	void LayerCollection::DeactivateLayer(const std::shared_ptr<LayerBase> layer)
	{
		if (!HasLayer(layer))
			return;

		layer->deactivateLayer();
	}

	bool LayerCollection::HasLayer(std::shared_ptr<LayerBase> layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);

		return it != this->m_layers.end();
	}
}