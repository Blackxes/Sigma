/**
 * @File This file is part of the Sigma game engine
 */

#pragma once

//#include "Core/Base.h"

namespace Sigma
{
	/*
	enum class SIGMA_API RenderApi
	{
		OpenGL = 1
	};

	struct SIGMA_API RenderWindowCreationOptions
	{
		const char* title = "Wupp wupp!";
		int width = 0;
		int height = 0;
		bool fullscreen = false;
		bool openConsole = false;
	};

	class SIGMA_API RenderWindow
	{
	public:
		RenderWindow(const RenderWindowCreationOptions& creationOptions) { this->Init(); }
		RenderWindow(const RenderWindow& rhs) = delete;
		virtual ~RenderWindow() { this->Shutdown(); }

		virtual bool Init() = 0;
		virtual bool Shutdown() = 0;
		virtual bool Create() = 0;
		virtual bool CloseWindow() = 0;
		virtual bool CreateConsole() = 0;

		template<class T>
		T* GetWindowHandle()
		{
			return (T*) this->GetTypeExplicitRenderWindowHandle();
		}

	protected:
		RenderWindowCreationOptions m_creationOptions;

		virtual void* GetTypeExplicitRenderWindowHandle() = 0;
	};
	*/
}