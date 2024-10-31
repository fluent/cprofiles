set(src
  cprofiles.c
  cprof_profile.c
  cprof_sample.c
  )

set(src
  ${src}

  )

# Static Library
add_library(cprofiles-static STATIC ${src})
target_link_libraries(cprofiles-static mpack-static cfl-static fluent-otel-proto)

# Install Library
if(MSVC)
  # Rename the output for Windows environment to avoid naming issues
  set_target_properties(cprofiles-static PROPERTIES OUTPUT_NAME libcprofiles)
else()
  set_target_properties(cprofiles-static PROPERTIES OUTPUT_NAME cprofiles)
endif(MSVC)

install(TARGETS cprofiles-static
  RUNTIME DESTINATION ${CPROF_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CPROF_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CPROF_INSTALL_LIBDIR}
  COMPONENT library)
