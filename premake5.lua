workspace "Visionizer"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Visionizer/vendor/GLFW/include"
IncludeDir["Glad"] = "Visionizer/vendor/Glad/include"
IncludeDir["ImGui"] = "Visionizer/vendor/imgui"
IncludeDir["glm"] = "Visionizer/vendor/glm"

include "Visionizer/vendor/GLFW"
include "Visionizer/vendor/Glad"
include "Visionizer/vendor/imgui"

project "Visionizer"
	location "Visionizer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vspch.h"
	pchsource "Visionizer/src/vspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VS_PLATFORM_WINDOWS",
			"VS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "VS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VS_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Visionizer/vendor/spdlog/include",
		"Visionizer/src",
		"Visionizer/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Visionizer"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VS_DIST"
		runtime "Release"
		optimize "on"
