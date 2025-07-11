project "Sigma"
    kind "SharedLib"
    language "C++"
    cppdialect "C++23"
    staticruntime "Off"

    targetdir(getOutputPath())
    objdir(getIntermediatePath())

    files {
        ProjectPaths["Sigma"] .. "**.cpp",
        ProjectPaths["Sigma"] .. "**.h",
        ProjectPaths["stb_image"] .. "stb_image.cpp",
        ProjectPaths["Glad"] .. "glad.c"
    }

    includedirs {
        IncludePaths["Sigma"],
        IncludePaths["Glad"],
        IncludePaths["GLFW"],
        IncludePaths["stb_image"],
    }

    links { "glfw3.lib", "opengl32.lib" }

    defines { "GLFW_INCLUDE_NONE", "SIGMA_BUILD_DLL" }

    pchheader "sigmapch.h"
    pchsource (IncludePaths["Sigma"] .. "sigmapch.cpp")

    -- Disabling pch for glad will make is sad
    filter "files:*/**/glad.c"
        flags { "NoPCH" }

    filter "files:*/**/stb_image.cpp"
        flags { "NoPCH" }
	
	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines { "SIGMA_DEBUG" }
		symbols "On"
        runtime "Debug"
        
        libdirs { OutputPaths["GLFW"]["Debug"] }

        postbuildcommands {
            "{COPY} " .. getOutputPath("Sigma", "Debug") .. "/*.dll " .. getOutputPath("Sandbox", "Debug")
        }

	filter "configurations:Release"
		defines { "SIGMA_RELEASE" }
		optimize "On"
        runtime "Release"

        libdirs { OutputPaths["GLFW"]["Release"] }

        postbuildcommands {
            "{COPY} " .. getOutputPath("Sigma", "Release") .. "/*.dll " .. getOutputPath("Sandbox", "Release")
        }