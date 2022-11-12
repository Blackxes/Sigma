workspace "Sigma"
	architecture "x64"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sigma"
	location "Sigma"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"vendor/SFML/include",
	}

	pchheader "sgpch.h"
	pchsource "Sigma/src/sgpch.cpp"

	cleancommands
	{
		"make clean %{cfg.buildcfg}"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "on"

		defines { "SG_PLATFORM_WINDOWS", "SG_BUILD_DLL", "SFML_STATIC" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines { "SG_DEBUG" }
		symbols "On"

		links
		{
			"sfml-main-d.lib",
			"sfml-window-s-d.lib",
			"sfml-graphics-s-d.lib",
			"sfml-audio-s-d.lib",
			"sfml-network-s-d.lib",
			"sfml-system-s-d.lib",
			"opengl32.lib"
		}

	filter "configurations:Release"
		defines { "SG_RELEASE" }
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Sigma/src",
		"vendor/SFML/include"
	}

	links { "Sigma" }
	
	cleancommands
	{
		"make clean %{cfg.buildcfg}"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "SG_PLATFORM_WINDOWS" }
	
	filter "configurations:debug"
		defines { "SG_DEBUG" }

	filter "configurations:release"
		defines { "SG_RELEASE" }
		optimize "On"