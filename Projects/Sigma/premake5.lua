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
	
	filter "system:windows"
		systemversion "latest"
        symbols "Off"

		defines { "SIGMA_PLATFORM_WINDOWS" }
	
	filter "configurations:Debug"
		defines { "SIGMA_DEBUG" }
		symbols "On"
        
        libdirs { OutputPaths["GLFW"]["Debug"] }

        postbuildcommands {
            "{COPY} " .. getOutputPath("Sigma", "Debug") .. "/*.dll " .. getOutputPath("Sandbox", "Debug")
        }

	filter "configurations:Release"
		defines { "SIGMA_RELEASE" }
		optimize "On"

        libdirs { OutputPaths["GLFW"]["Release"] }

        postbuildcommands {
            "{COPY} " .. getOutputPath("Sigma", "Release") .. "/*.dll " .. getOutputPath("Sandbox", "Release")
        }