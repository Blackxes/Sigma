os.execute("cmake -S . -B build")
os.execute("cd build")
os.execute("cmake --build .")

project "GLFW"
    kind "StaticLib"
    
    defines { "GLFW_INCLUDE_NONE" }

    filter "system:linux"
        systemversion "latest"
        staticruntime "On"

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"
        defines { "_GLFW_WIN32", "_CRT_SECURE_NO_WARNINGS" }
        links { "gdi32", "user32", "kernel32" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"