
#include <iostream>

#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
    : Sigma::LayerBase()
{
    std::cout << "[ExampleLayer::Constructor]" << std::endl;
}

ExampleLayer::~ExampleLayer()
{
    std::cout << "[ExampleLayer::Destructor]" << std::endl;
}

void ExampleLayer::OnAttach()
{
    std::cout << "[ExampleLayer::OnAttach]: OnAttach" << std::endl;
    
    return;
}

void ExampleLayer::OnDetach()
{
    std::cout << "[ExampleLayer::OnDetach]: OnDetach" << std::endl;

    return;
}

void ExampleLayer::OnUpdate(const float delta)
{
    std::cout << "[ExampleLayer::OnUpdate]: OnUpdate: " << printf("%.8f", delta) << std::endl;

    return;
}

void ExampleLayer::OnEvent()
{
    std::cout << "[ExampleLayer::OnEvent]: OnEvent" << std::endl;

    return;
}

