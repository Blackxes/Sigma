workspace "SigmaSolution"
    cppdialect "C++23"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"

include "Paths.lua"

group "Dependencies"
    include "Projects/Sigma/vendor/GLFW"
group ""

group "Core"
    include "Projects/Sigma"
group ""

group "Testing"
    include "Projects/Sandbox"
group ""
