#cmake_minimum_required(VERSION 3.2)

#project(bilogis)

cmake_minimum_required(VERSION 3.5)

# Nom du projet
project(bilogis VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Spécifiez le chemin vers Qt
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5") # Remplace avec ton chemin Qt

# Trouver les modules Qt requis
find_package(Qt5 REQUIRED COMPONENTS Widgets SerialPort Core)  # Ajouter SerialPort ici

# Ajouter les fichiers sources
set(SOURCES
    mainFrontEnd.cpp
    #essai_jumperxy.cpp
    NandFront.cpp
    NotFront.cpp
    AndFront.cpp
    OrFront.cpp
    PortesFront.cpp
    CircuitFront.cpp
    MainWindow.cpp
    apk_window.cpp
    win_new_project.cpp
    Circuit.cpp
    S_AND.cpp
    S_OR.cpp
    S_NOT.cpp
    Portes.cpp
    XAND.cpp
    XOR.cpp
    XNAND.cpp
    XNOR.cpp
    NAND.cpp
    NOR.cpp
    curs_pos.cpp
    try_connexion.cpp
    JumperXY.cpp
    Wire.cpp
    Fil.cpp
    # Ajoutez ici d'autres fichiers source si nécessaire
)

# Ajouter l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier les bibliothèques Qt nécessaires
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::SerialPort Qt5::Core)  # Ajouter Qt5::SerialPort ici

# Activer le support des fichiers .ui
#qt_standard_project_setup()

# Spécifier la version du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
