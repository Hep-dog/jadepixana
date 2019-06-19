include_directories(../core/include)

file( GLOB APP_SOURCE src/*.cxx )

foreach( cppsourcefile ${APP_SOURCE} )
    get_filename_component( baresourcefile ${cppsourcefile} NAME )
    string( REPLACE ".cxx" "" baretarget ${baresourcefile} )
    message( ${baresourcefile} " <---------------- the bare name of each target" )
    add_executable( ${baretarget} src/${baresourcefile})
    target_link_libraries( ${baretarget} ${JADE_CORE_LIBRARY} )
    list( APPEND INSTALL_TARGETS ${baretarget} )
endforeach( cppsourcefile ${APP_SOURCE} )


install(TARGETS ${INSTALL_TARGETS}
  DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

