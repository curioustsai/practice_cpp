project(ch4-Tree-Graph)

# If necessary, use the RELATIVE flag, otherwise each source file may be listed 
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file(GLOB APP_SOURCES *.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    get_filename_component(basename ${testsourcefile} NAME)
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".cpp" "" testname ${basename} )
    add_executable( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    # target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )
