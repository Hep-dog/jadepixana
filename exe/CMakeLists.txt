include_directories(../core/include)

add_executable(OptionTest src/OptionTest.cxx)
target_link_libraries(OptionTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS OptionTest)

add_executable(ThreadTest src/ThreadTest.cxx)
target_link_libraries(ThreadTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS ThreadTest)

add_executable(RunTest src/RunTest.cxx)
target_link_libraries(RunTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS RunTest)

add_executable(AddTest src/AddTest.cxx)
target_link_libraries(AddTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS AddTest)

add_executable(HistTest src/HistTest.cxx)
target_link_libraries(HistTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS HistTest)

add_executable(GenTest src/GenTest.cxx)
target_link_libraries(GenTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS GenTest)

add_executable(ProjectTest src/ProjectTest.cxx)
target_link_libraries(ProjectTest ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS ProjectTest)

add_executable(ProjectNPixel src/ProjectNPixel.cxx)
target_link_libraries(ProjectNPixel ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS ProjectNPixel)

add_executable(FitPeaks src/FitPeaks.cxx)
target_link_libraries(FitPeaks ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FitPeaks)

add_executable(FitMultiplePeaks src/FitMultiplePeaks.cxx)
target_link_libraries(FitMultiplePeaks ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FitMultiplePeaks)

add_executable(FitTwoPeaks src/FitTwoPeaks.cxx)
target_link_libraries(FitTwoPeaks ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FitTwoPeaks)

add_executable(GetFits src/GetFits.cxx)
target_link_libraries(GetFits ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS GetFits)

add_executable(FindNoise src/FindNoise.cxx)
target_link_libraries(FindNoise ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FindNoise)

add_executable(GenNoise src/GenNoise.cxx)
target_link_libraries(GenNoise ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS GenNoise)

add_executable(GenRaw src/GenRaw.cxx)
target_link_libraries(GenRaw ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS GenRaw)

add_executable(FitSim src/FitSim.cxx)
target_link_libraries(FitSim ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FitSim)

install(TARGETS ${INSTALL_TARGETS}
  DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

