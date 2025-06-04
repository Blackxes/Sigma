
include "Dependencies.lua"

workspace "Sigma"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "Sigma"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Sigma/vendor/Glad"
	include "Sigma/vendor/GLFW"
group ""

group "Core"
	include "Sigma"
group ""

group "Tools"
group ""

group "Testing"
	include "Sandbox"
group ""