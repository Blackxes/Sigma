project "Sigma"
	kind "StaticLib"
	language "C++"

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
        "Sigma.licenseheader"
	}

	includedirs
	{
        "src",
        "%{Dependencies.GLFW}",
        "%{Dependencies.Glad}",
        "%{Dependencies.stb_image}",
	}

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    defines { "GLFW_INCLUDE_NONE" }

	libdirs { "%{prj.name}/vendor/GLFW/lib-vc2022" }
	
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
		symbols "On"

	filter "configurations:Release"
		defines "SG_RELEASE"
		optimize "On"