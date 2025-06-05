project "Sigma"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sgpch.h"
	pchsource "src/sgpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
        "vendor/stb_image/**.h",
        "vendor/stb_image/**.cpp",
	}

	includedirs
	{
        "src",
        "%{Dependencies.Glad}",
        "%{Dependencies.GLFW}",
        "%{Dependencies.stb_image}",
	}

    links
    {
        "Glad",
		"GLFW",
        "opengl32"
    }

    defines { "GLFW_INCLUDE_NONE" }
	
	filter "system:windows"
		cppdialect "C++23"
		systemversion "latest"

		defines { "SG_PLATFORM_WINDOWS", "SG_BUILD_DLL" }
	
	filter "configurations:Debug"
		defines "SG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SG_RELEASE"
		optimize "On"