g++ -I./install/ffmpeg/include demo.cpp -o demo -L./install/ffmpeg/lib -lavutil -lavcodec -lswresample -lavformat && LD_LIBRARY_PATH=./install/ffmpeg/lib ./demo
