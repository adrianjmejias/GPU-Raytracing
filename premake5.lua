-- premake5.lua
-- https://git-scm.com/book/en/v2/Git-Tools-Submodules
workspace "PressF"
   architecture "x64"
   startproject "PressF"
   configurations { "Debug", "Release", "Dist"}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glm"] = "dependencies/glm"
IncludeDir["spdlog"] = "dependencies/spdlog/include"
IncludeDir["Glad"] = "dependencies/Glad/include"
IncludeDir["microui"] = "dependencies/microui/src"
IncludeDir["SDL"] = "dependencies/SDL/include"
IncludeDir["stb"] = "dependencies/stb"
IncludeDir["obj"] = "dependencies/OBJ-Loader"
IncludeDir["ImGui"] = "dependencies/imgui/"


group "Dependencies"
	include "dependencies/Glad"
	include "dependencies/imgui"
group ""

project "PressF"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17" --StaticLib
   pchheader "types.h"
   pchsource "types.cpp"
   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
   
   files { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
      "dependencies/glm/glm/**.hpp",
      "dependencies/glm/glm/**.inl",
      -- "dependencies/nuklear/src/**.h",
      -- "dependencies/nuklear/src/**.c"
   }

   includedirs {
      -- internal 
      "%{prj.name}/src",

      -- dependencies
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.nuklear}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.SDL}",
		"%{IncludeDir.obj}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.microui}",
		"%{IncludeDir.ImGui}"
   }

   libdirs
   {
      "SDL2" ,"dependencies/SDL/lib/**"
   }

   links {
      "Glad",
      "SDL2",
      "ImGui",
      -- "nuklear"
   }

   -- linkoptions { "``" }
   -- prebuildcommands { "MyTool --dosomething" }
   filter "system:windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "_CRT_SECURE_NO_WARNINGS", "DEBUG"}
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"