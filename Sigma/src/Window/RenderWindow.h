/**
 * @File This file is part of the Sigma game engine
 */

#include "Sigma.h"

namespace Sigma
{
	class RenderWindow
	{
	public:
		struct Specification
		{
			std::string title = "My First Renderwindow";
			int width = 1280;
			int height = 720;
		};

		RenderWindow();
		bool Init(Specification);
		bool CreateWindow();

	private:
		GLFWwindow* window = nullptr;
	};
}