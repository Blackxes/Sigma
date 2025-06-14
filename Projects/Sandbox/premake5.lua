project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    staticruntime "On"

    targetdir(getOutputPath())
    objdir(getIntermediatePath())
    
    files {
        IncludePaths["Sandbox"] .. "/**.cpp",
        IncludePaths["Sandbox"] .. "/**.h"
    }

    includedirs { IncludePaths["Sigma"] }
    links { "Sigma" }

	filter "system:windows"
		systemversion "latest"
		defines { "SIGMA_PLATFORM_WINDOWS" }
	
	filter "configurations:Debug"
		defines { "SIGMA_DEBUG" }

        libdirs { getOutputPath("Sigma", "Debug") }
        
    filter "configurations:Release"
		defines { "SIGMA_RELEASE" }
		optimize "On"

        libdirs { getOutputPath("Sigma", "Release") }