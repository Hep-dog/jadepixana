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

add_executable(FitPeaks src/FitPeaks.cxx)
target_link_libraries(FitPeaks ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FitPeaks)

add_executable(FitTwoPeaks src/FitTwoPeaks.cxx)
target_link_libraries(FitTwoPeaks ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FitTwoPeaks)

add_executable(FindNoise src/FindNoise.cxx)
target_link_libraries(FindNoise ${JADE_CORE_LIBRARY})
list(APPEND INSTALL_TARGETS FindNoise)

install(TARGETS ${INSTALL_TARGETS}
  DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

