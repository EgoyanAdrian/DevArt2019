cmake_minimum_required(VERSION 3.1)

project(da)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

set(HEADERS
	include/conversion.hpp
	include/genererNomPays.hpp
	include/fonctionAleatoire.hpp
	include/Interface.hpp
	include/BoutonEnvoyer.hpp
	include/Bouton.hpp
	)

set(SOURCES
	src/conversion.cpp
	src/genererNomPays.cpp
	src/fonctionAleatoire.cpp
	src/Interface.cpp
	src/BoutonEnvoyer.cpp
	src/Bouton.cpp
	src/main.cpp
	)

include_directories(include/lib/SFML)

add_executable(da ${SOURCES} ${HEADERS})
target_link_libraries(da sfml-graphics)
target_link_libraries(da sfml-system)
target_link_libraries(da sfml-window)
target_include_directories(da PRIVATE ${CMAKE_SOURCE_DIR}/include)