
local ws = "%{!wks.location}/";

function getOutputPath(projectName, buildConfig)
    projectName = projectName or "%{prj.name}"
    buildConfig = buildConfig or "%{cfg.buildcfg}"
    return ws .. "bin/" .. buildConfig .. "-%{cfg.system}-%{cfg.architecture}/" .. projectName .. "/"
end

function getIntermediatePath(projectName, buildConfig)
    projectName = projectName or "%{prj.name}"
    buildConfig = buildConfig or "%{cfg.buildcfg}"
    return ws .. "bin-int/" .. buildConfig .. "-%{cfg.system}-%{cfg.architecture}/" .. projectName .. "/"
end

ProjectPaths = {
    ["Sigma"] = ws .. "Projects/Sigma/src/",
    ["Glad"] = ws .. "Projects/Sigma/vendor/Glad/src/",
    ["stb_image"] = ws .. "Projects/Sigma/vendor/stb_image/src/",
    ["Sandbox"] = ws .. "Projects/Sandbox/src/"
}

IncludePaths = {
    ["Sigma"] = ws .. "Projects/Sigma/src/",
    ["Glad"] = ws .. "Projects/Sigma/vendor/Glad/include/",
    ["GLFW"] = ws .. "Projects/Sigma/vendor/GLFW/include/",
    ["stb_image"] = ws .. "Projects/Sigma/vendor/stb_image/include/",
    ["Sandbox"] = ws .. "Projects/Sandbox/src/"
}

OutputPaths = {}
-- GLFW is external therefore different lib dir
OutputPaths["GLFW"] = {
    ["Debug"] = ws .. "Projects/Sigma/vendor/GLFW/build/src/Debug/",
    ["Release"] = ws .. "Projects/Sigma/vendor/GLFW/build/src/Release/"
}
OutputPaths["Sigma"] = {
    ["Debug"] = getOutputPath("Sigma", "Debug"),
    ["Release"] = getOutputPath("Sigma", "Release")
}
OutputPaths["Sandbox"] = {
    ["Debug"] = getIntermediatePath("Sandbox", "Debug"),
    ["Release"] = getIntermediatePath("Sandbox", "Release")
}
