workspace "Hazel" 
    architecture "x64" 
	startproject "HazelBox" 
	configurations {
		"Debug",
		"Release"
	}
	flags {
		"MultiProcessorCompile" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--定义子项目的位置
IncludeDirs = {}
IncludeDirs["GLFW"] = "HazelBox/include/GLFW"
IncludeDirs["GLAD"] = "HazelBox/include/GLAD"


include "HazelBox/include/"
--include "include/imgui"

project "HazelBox"
	location "HazelBox"
	kind "ConsoleApp" 
	language "C++"
	cppdialect "C++17" 
    
	targetdir ("./build/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("./build//bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c",
	}

	includedirs {
		"%{prj.name}/src",
		"%{IncludeDirs.GLFW}/include",
		"%{IncludeDirs.GLAD}/include",
		-- "vendor/imgui",
		-- "vendor/glm",
		-- "vendor/stb_image"
	}
	
	
	links {
		"GLAD",
		"GLFW",
		"opengl32.lib",
		-- "ImGui"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"