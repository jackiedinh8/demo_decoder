OPENH264_DIR=`pwd`/../../install/openh264
PKG_CONFIG_PATH=$OPENH264_DIR/lib/pkgconfig ./configure --prefix=`pwd`/../../install/ffmpeg --disable-static --enable-shared --disable-gpl --disable-nonfree --enable-libopenh264 --disable-ffplay --disable-ffprobe --disable-ffserver --disable-doc --disable-debug --disable-vaapi --disable-vdpau --disable-zlib --disable-bzlib --disable-lzma --disable-sdl --disable-libxcb --disable-libxcb-shm --disable-libxcb-xfixes --disable-libxcb-shape --disable-indevs --disable-outdevs --enable-indev=v4l2 --extra-cflags="-I$OPENH264_DIR/include" --extra-ldflags="-L$OPENH264_DIR/lib" --extra-ldexeflags='-Wl,-rpath=XORIGIN/../lib' --extra-ldlibflags='-Wl,-rpath=XORIGIN'
make -j8
make install
