workspace "Denocat"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Denocat/vendor/GLFW/include"
IncludeDir["Glad"] = "Denocat/vendor/Glad/include"
IncludeDir["ImGui"] = "Denocat/vendor/imgui"
IncludeDir["glm"] = "Denocat/vendor/glm"
IncludeDir["stb_image"] = "Denocat/vendor/stb_image"

group "Dependencies"
	include "Denocat/vendor/GLFW"
	include "Denocat/vendor/Glad"
	include "Denocat/vendor/imgui"

group ""

project "Denocat"
	location "Denocat"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vspch.h"
	pchsource "Denocat/src/vspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
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
		"Denocat/vendor/spdlog/include",
		"Denocat/src",
		"Denocat/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Denocat"
	}

	filter "system:windows"
		systemversion "latest"
		
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
