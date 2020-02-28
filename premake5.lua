outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

includeDir = {}
workspace "uavOS"
	startproject "source"
	location "workspace"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	pchheader "include/pch.hpp"
	pchsource "src/pch.cpp"

	filter "configurations:Dist"
		postbuildcommands{
			"{COPY} bin/"..outputdir.."/* builds"
		}

	filter "system:windows"
		defines "UAV_WINDOWS"

	filter "system:linux"
		defines "UAV_LINUX" 

	filter "system:macosx"
		defines "UAV_OSX"

	filter "configurations:Debug"
		defines "UAV_DEBUG"
		symbols "On"
	filter "configurations:Dist"
		defines "UAV_DIST"
		optimize "On"
	filter "configurations:Release"
		defines "UAV_RELEASE"
		optimize "On"
project "Source"
	cppdialect "C++17"
	location "workspace/source"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	files{
		"src/**.h",
		"src/**.hpp",
		"src/**.c",
		"src/**.cpp"
	}
	includedirs{
		"src",
		"include"
	}
project "Test"
	cppdialect "C++17"
	location "workspace/test"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	links{
		"Source"
	}

	files{
		"test/**.h",
		"test/**.hpp",
		"test/**.c",
		"test/**.cpp",
		"include/test/**.h",
		"include/test/**.hpp",
		"include/test/**.c",
		"include/test/**.cpp"
	}
	includedirs{
		"src",
		"include",
		"include/test"
	}