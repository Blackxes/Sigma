project "GLFW"
	kind "StaticLib"
	language "C"
	staticruntime "Off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files { "include/GLFW/glfw3.h" }

	includedirs { "include" }

	libdirs { "lib-vs2022" }
    
	filter "system:windows"
        pic "On"
		systemversion "latest"
		
		-- postbuildcommands 
		-- {
		-- 	"{COPYFILE} %{prj.location}lib-vs2022/glfw3.lib %{wks.location}bin/" .. outputdir .. "/GLFW/glfw.lib"
		-- }
	
	filter "configurations:Debug"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
        runtime "Release"
		optimize "On"
