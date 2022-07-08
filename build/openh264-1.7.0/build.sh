INSTALL_DIR=`pwd`/../../install/openh264
make PREFIX=$INSTALL_DIR DEBUGSYMBOLS=True install-static -j8
cp libopenh264_debug_symbols.a $INSTALL_DIR/lib/libopenh264d.a
