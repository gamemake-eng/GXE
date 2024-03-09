CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -Iengine
CXXFLAGSD = -g
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp)) $(patsubst %.cpp,%.o,$(wildcard engine/*.cpp))
SRC := $(patsubst %.o,%.cpp,$(OBJS))
LIBS = -lallegro.dll -lallegro_primitives.dll -lallegro_font.dll -lallegro_ttf.dll -lallegro_image.dll -lallegro_audio.dll -lallegro_acodec.dll -lfreetype.dll -llua
LIBSD = -lallegro-debug.dll -lallegro_primitives-debug.dll -lallegro_font-debug.dll -lallegro_image-debug.dll -lallegro_audio-debug.dll -lallegro_acodec-debug.dll -llua
NAME = gxeruntime
OUTPATH = .
build: $(OBJS)
	$(CXX) -w -Wl,-subsystem,windows  -o $(OUTPATH)\$(NAME).exe $(OBJS) -static-libstdc++ $(LIBS)
clean:
	del $(OBJS)
run:
	$(OUTPATH)\$(NAME).exe