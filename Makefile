EXEC = ReBound.exe
OUTDIR = bin
CC = g++
DLL_PATHS = C:\mingw\win-builds\bin
INCLUDE_PATHS = -LC:\mingw\win-builds\include\SDL2
LIBRARY_PATHS = -LC:\mingw\win-builds\lib64
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image
OBJS = src/ReBound.cpp src/ReBound_GameObject.cpp src/ReBound_OnCleanup.cpp src/ReBound_OnEvent.cpp src/ReBound_OnInit.cpp src/ReBound_OnLoop.cpp src/ReBound_OnRender.cpp src/ReBound_Paddle.cpp src/ReBound_Ball.cpp src/ReBound_Graphics.cpp src/ReBound_Assets.cpp

all: exec
	cp -r ./res $(OUTDIR)
	cp $(DLL_PATHS)/libfreetype-6.dll $(OUTDIR)
	cp $(DLL_PATHS)/libpng16-16.dll $(OUTDIR)
	cp $(DLL_PATHS)/SDL2.dll $(OUTDIR)
	cp $(DLL_PATHS)/SDL2_image.dll $(OUTDIR)
	cp $(DLL_PATHS)/SDL2_ttf.dll $(OUTDIR)
	cp $(DLL_PATHS)/zlib1.dll $(OUTDIR)

exec: 
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -std=gnu++11 -o $(OUTDIR)/$(EXEC) 
	
clean:
	rm $(OUTDIR)/*