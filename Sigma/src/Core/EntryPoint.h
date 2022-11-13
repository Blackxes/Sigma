#pragma once

#include "sgpch.h"
#include "Application.h"

extern Sigma::Application* Sigma::CreateApplication(Sigma::ApplicationCommandArgs commandArgs);

int main(int argc, char** argv)
{
	// Create the application from the client
	Sigma::Application* app = Sigma::CreateApplication({ argc, argv });

	// Main lifecycle
	app->run();

	// Shutdown the application and close the window
	delete app;

	return 0;
}