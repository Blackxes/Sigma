project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "Off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}
	
	includedirs
	{
		"%{wks.location}/Sigma/src",
		"%{wks.location}/Sigma/vendor",
	}

	links { "Sigma.dll" }
	libdirs { "Sigma" }

	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines { "SG_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "SG_RELEASE" }
		optimize "On"