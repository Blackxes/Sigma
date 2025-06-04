project "glfw"
	kind "StaticLib"
	language "C"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
        "%{prj.name}/include/GLFW/glfw3.h",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glfw}"
	}
    
	filter "system:windows"
        pic "On"
		systemversion "latest"
		staticruntime "On"

		defines { "SG_PLATFORM_WINDOWS", "SG_BUILD_DLL" }
	
	filter "configurations:Debug"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
        runtime "Release"
		optimize "On"