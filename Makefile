CXX = g++
CXXFLAGS = -Wall -Iinclude -Iengine
CXXFLAGSD = -g
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp)) $(patsubst %.cpp,%.o,$(wildcard engine/*.cpp))
SRC := $(patsubst %.o,%.cpp,$(OBJS))

ifeq ($(OS),Windows_NT)
    LIBS = -static-libstdc++ -lallegro_monolith -llua
		EXE_SUFFIX = .exe
else
    # Linux or MacOS specific settings 
    LIBS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -lallegro_audio -lallegro_acodec -lfreetype -llua
		EXE_SUFFIX =
endif

LIBSD = -lallegro-debug -lallegro_primitives-debug -lallegro_font-debug -lallegro_image-debug -lallegro_audio-debug -lallegro_acodec-debug -llua
NAME = gxeruntime
OUTPATH = .

build: $(OBJS)
	$(CXX) -o $(OUTPATH)/$(NAME)$(EXE_SUFFIX) $(OBJS) $(LIBS)
clean:
	rm -f $(OBJS)
run:
	$(OUTPATH)/$(NAME)$(EXE_SUFFIX)

