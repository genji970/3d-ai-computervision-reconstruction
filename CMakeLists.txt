cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(vision)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenCV 라이브러리 찾기
find_package(OpenCV REQUIRED)

# 실행 파일 추가
add_executable(main main.cpp)

# OpenCV 라이브러리 연결
target_link_libraries(main ${OpenCV_LIBS})

# 디버그 메시지 출력 (구문 확인 완료)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include directories: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")


