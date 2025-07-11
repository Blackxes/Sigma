#pragma once

#include <Sigma/Core/LayerBase.h>

class ExampleLayer : public Sigma::LayerBase
{
public:
    ExampleLayer();
    virtual ~ExampleLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate(const float delta) override;
    virtual void OnEvent() override;
};

