workspace "GermEngine"
    architecture "x64"
    toolset "clang"
    language "C++"
    cppdialect "C++17"
    characterset ("Unicode")
    buildoptions ("-MP")
    configurations{"Debug","Release"}

    startproject "GermLib"
    startproject "Examples"

  
   

OutputDir = "%{cfg.build}/%{cfg.system}/%{cfg.architecture}"
include "GermLib"
include "Examples"