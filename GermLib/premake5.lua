project "GermLib"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir("../Bin".. OutputDir.. "/%{prj.name}")
    objdir("../Bin-int".. OutputDir.. "/%{prj.name}")

    files{
        "Source/**.cpp",
        "Source/**.h",
    }

    defines{
        "WINDOWS"
    }

    includedirs{

    }

    libdirs{

    }

    links{

    }

    filter{"configurations:Debug"}
        runtime "Debug"
        symbols "on"
        staticruntime "off"

    filter{"configurations:Release"}
        optimize "on"
        runtime "Release"
