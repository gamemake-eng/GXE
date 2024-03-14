CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -Iengine
CXXFLAGSD = -g
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp)) $(patsubst %.cpp,%.o,$(wildcard engine/*.cpp))
SRC := $(patsubst %.o,%.cpp,$(OBJS))
LIBS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -lallegro_audio -lallegro_acodec -lfreetype -llua
#LIBS = -lallegro_ -llua
LIBSD = -lallegro-debug -lallegro_primitives-debug -lallegro_font-debug -lallegro_image-debug -lallegro_audio-debug -lallegro_acodec-debug -llua
NAME = gxeruntime
OUTPATH = .
build: $(OBJS)
	$(CXX) -o $(OUTPATH)/$(NAME) $(OBJS) $(LIBS)
clean:
	rm -f $(OBJS)
run:
	$(OUTPATH)/$(NAME)

