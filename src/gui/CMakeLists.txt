aux_source_directory(. SRC_LIST)

file(GLOB HEADER_LIST "*.h")
QT4_WRAP_CPP(HEADERS_MOC ${HEADER_LIST})

add_library(gui ${SRC_LIST} ${HEADERS_MOC})
