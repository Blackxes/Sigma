
#include "ExampleLayer.h"

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
    std::cout << "[ExampleLayer::OnUpdate]: OnUpdate" << std::endl;

    return;
}

void ExampleLayer::OnEvent()
{
    std::cout << "[ExampleLayer::OnEvent]: OnEvent" << std::endl;

    return;
}

