project "Examples"
    kind "ConsoleApp"
    language"C++"
    cppdialect "C++17"
    targetdir("../Bin".. OutputDir.. "/%{prj.name}")
    objdir("../Bin-int".. OutputDir.. "/%{prj.name}")

    files{
        "Source/**.h",
        "Source/**.cpp",
    }
    defines{
        "WINDOWS"
    }
    links{

    }
    libdirs {

    }
    includedirs{
        "../GermLib/Source",
    }



    filter{"configurations:Debug"}
        runtime"Debug"
        symbols"on"
        staticruntime"off"
    filter{"configurations:Release"}
        optimize"on"
        runtime"Release"