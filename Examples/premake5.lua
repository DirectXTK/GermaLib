project "Examples"
    kind "ConsoleApp"
    toolset "clang"
    language"C++"
    cppdialect "C++17"
    targetdir("../Bin".. OutputDir.. "/%{prj.name}")
    objdir("../Bin-int".. OutputDir.. "/%{prj.name}")
    PostBuildCommandSh = "%{!cfg.buildtarget.abspath}"


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
    postbuildcommands {
        {"%{!prj.location}/PostBuildCommands.sh %{PostBuildCommandSh} &"},
    }
   


    filter{"configurations:Debug"}
        runtime"Debug"
        symbols"on"
        staticruntime"off"
    filter{"configurations:Release"}
        optimize"on"
        runtime"Release"