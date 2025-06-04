workspace "Sigma"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "Sigma"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["Glad"] = "%{wks.location}/Sigma/vendor/Glad/include"
IncludeDir["glfw"] = "%{wks.location}/Sigma/vendor/glfw/include"

project "Sigma"
	location "Sigma"
	kind "SharedLib"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/Glad/src/glad.c"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glfw}"
	}

	filter "files:glad.c"
    	flags {"NoPCH"}

	libdirs { "%{prj.name}/vendor/glfw/lib-vc2022" }

	pchheader "sgpch.h"
	pchsource "Sigma/src/sgpch.cpp"
	
	filter "system:windows"
		cppdialect "C++23"
		systemversion "latest"
		staticruntime "Off"

		defines { "SG_PLATFORM_WINDOWS", "SG_BUILD_DLL" }

		postbuildcommands 
		{
			"{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
		}
	
	filter "configurations:Debug"
		defines "SG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

		links
		{
			"glfw3.lib",
			"opengl32.lib"
		}

	filter "configurations:Release"
		defines "SG_RELEASE"
		buildoptions "/MDd"
		optimize "On"

		links
		{
			"glfw3.lib",
			"opengl32.lib"
		}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{wks.location}/Sigma/src"
	}

	links { "Sigma" }

	libdirs { "%{prj.name}/vendor/glfw/lib-vc2022" }
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

		defines { "SG_PLATFORM_WINDOWS" }
	
	filter "configurations:Debug"
		defines "SG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

		links
		{
			"glfw3.lib",
			"opengl32.lib"
		}

	filter "configurations:Release"
		defines { "SG_RELEASE" }
		buildoptions "/MDd"
		optimize "On"

		links
		{
			"glfw3.lib",
			"opengl32.lib"
		}