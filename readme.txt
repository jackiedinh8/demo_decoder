# Original source code
wget https://github.com/cisco/openh264/archive/refs/tags/v1.7.0.tar.gz
wget https://github.com/FFmpeg/FFmpeg/archive/refs/tags/n3.3.3.tar.gz

# Prerequisite for building openh264
sudo apt install nasm

# Build libraries:
#  Go to build/FFmpeg-n3.3.3 and build/openh264-1.7.0 folders and execute build.sh
#  to build ffmpeg and openh264 libs.

#Execute run.sh at the root folder to reproduce the issue.
Output on Ubuntu 20.04.3 LTS, nvidia-driver 515.48.07, cuda 11.4, nvidia card A10
  [h264_cuvid @ 0x558bb9fa3ea0] Invalid pkt_timebase, passing timestamps as-is
  Created decoder succesfully
Output on Ubuntu 20.04.3 LTS, nvidia-driver 515.48.07, cuda 11.4, nvidia card A30
  [h264_cuvid @ 0x561fe81efea0] ctx->cvdl->cuvidCreateDecoder(&cudec, &cuinfo) failed -> CUDA_ERROR_OUT_OF_MEMORY: out of memory 
  Failed to open decoder context! error - Generic error in an external library
