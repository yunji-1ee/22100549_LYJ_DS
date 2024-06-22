# 컴파일러 및 컴파일 옵션
CXX = g++
CXXFLAGS = -std=c++11

# 실행 파일 목록
EXECUTABLES = DS101 DS102 DS103 DS104 DS105 DS106 DS107 DS108 DS109 DS110

# 각 실행 파일에 대응하는 소스 파일
SOURCES = DS101.cpp DS102.cpp DS103.cpp DS104.cpp DS105.cpp DS106.cpp DS107.cpp DS108.cpp DS109.cpp DS110.cpp

# 디폴트 타겟: 모든 실행 파일을 생성
all: $(EXECUTABLES)

# 각 실행 파일을 생성하기 위한 규칙
DS101: DS101.cpp
	$(CXX) $(CXXFLAGS) -o DS101 DS101.cpp

DS102: DS102.cpp
	$(CXX) $(CXXFLAGS) -o DS102 DS102.cpp

DS103: DS103.cpp
	$(CXX) $(CXXFLAGS) -o DS103 DS103.cpp

DS104: DS104.cpp
	$(CXX) $(CXXFLAGS) -o DS104 DS104.cpp

DS105: DS105.cpp
	$(CXX) $(CXXFLAGS) -o DS105 DS105.cpp

DS106: DS106.cpp
	$(CXX) $(CXXFLAGS) -o DS106 DS106.cpp

DS107: DS107.cpp
	$(CXX) $(CXXFLAGS) -o DS107 DS107.cpp

DS108: DS108.cpp
	$(CXX) $(CXXFLAGS) -o DS108 DS108.cpp

DS109: DS109.cpp
	$(CXX) $(CXXFLAGS) -o DS109 DS109.cpp

DS110: DS110.cpp
	$(CXX) $(CXXFLAGS) -o DS110 DS110.cpp

# 정리: 생성된 모든 실행 파일을 제거
clean:
	rm -f $(EXECUTABLES)
