workspace "Sigma"
	architecture "x64"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "%{wks.location}/Sigma/vendor/SFML/include"

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
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.SFML}"
	}

	libdirs { "%{prj.name}/vendor/SFML/lib" }

	pchheader "sgpch.h"
	pchsource "Sigma/src/sgpch.cpp"
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

		defines { "SG_PLATFORM_WINDOWS", "SG_BUILD_DLL", "SFML_STATIC" }

		postbuildcommands 
		{
			"{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
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
			"opengl32.lib",
			"freetype.lib",
			"winmm.lib",
			"gdi32.lib",
			"openal32.lib",
			"flac.lib",
			"vorbisenc.lib",
			"vorbisfile.lib",
			"vorbis.lib",
			"ogg.lib",
			"ws2_32.lib"
		}

	filter "configurations:Release"
		defines { "SG_RELEASE" }
		optimize "On"

		links
		{
			"sfml-main.lib",
			"sfml-window-s.lib",
			"sfml-graphics-s.lib",
			"sfml-audio-s.lib",
			"sfml-network-s.lib",
			"sfml-system-s.lib",
			"opengl32.lib",
			"freetype.lib",
			"winmm.lib",
			"gdi32.lib",
			"openal32.lib",
			"flac.lib",
			"vorbisenc.lib",
			"vorbisfile.lib",
			"vorbis.lib",
			"ogg.lib",
			"ws2_32.lib"
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
		"%{wks.location}/Sigma/src",
		"%{IncludeDir.SFML}"
	}

	links { "Sigma" }

	libdirs { "Sigma/vendor/SFML/lib" }
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

		defines { "SG_PLATFORM_WINDOWS" }
	
	filter "configurations:Debug"
		defines { "SG_DEBUG" }

		links
		{
			"sfml-main-d.lib",
			"sfml-window-s-d.lib",
			"sfml-graphics-s-d.lib",
			"sfml-audio-s-d.lib",
			"sfml-network-s-d.lib",
			"sfml-system-s-d.lib",
			"opengl32.lib",
			"freetype.lib",
			"winmm.lib",
			"gdi32.lib",
			"openal32.lib",
			"flac.lib",
			"vorbisenc.lib",
			"vorbisfile.lib",
			"vorbis.lib",
			"ogg.lib",
			"ws2_32.lib"
		}

	filter "configurations:Release"
		defines { "SG_RELEASE" }
		optimize "On"

		links
		{
			"sfml-main.lib",
			"sfml-window-s.lib",
			"sfml-graphics-s.lib",
			"sfml-audio-s.lib",
			"sfml-network-s.lib",
			"sfml-system-s.lib",
			"opengl32.lib",
			"freetype.lib",
			"winmm.lib",
			"gdi32.lib",
			"openal32.lib",
			"flac.lib",
			"vorbisenc.lib",
			"vorbisfile.lib",
			"vorbis.lib",
			"ogg.lib",
			"ws2_32.lib"
		}