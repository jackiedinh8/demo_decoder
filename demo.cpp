#include <string>
#include <iostream>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/hwcontext.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
}

inline
std::string err2str(int errnum)
{
    char str[AV_ERROR_MAX_STRING_SIZE];
    memset(str, 0, sizeof(str));
    return av_make_error_string(str, AV_ERROR_MAX_STRING_SIZE, errnum);
}

void createDecoder() {
  int cudaDeviceId = 0;
  AVCodec* decoder;
  AVCodecContext* decoderCtx;

  decoder = avcodec_find_decoder_by_name("h264_cuvid");

  decoderCtx = avcodec_alloc_context3(decoder);
  if (decoder->capabilities & AV_CODEC_CAP_TRUNCATED) {
    decoderCtx->flags |= AV_CODEC_CAP_TRUNCATED;
  }
  decoderCtx->flags2 |= AV_CODEC_FLAG2_CHUNKS;
  decoderCtx->thread_count = 2;


  av_opt_set(decoderCtx->priv_data, "gpu", std::to_string(cudaDeviceId).c_str(), 0);
  av_opt_set_int(decoderCtx->priv_data, "surfaces", 16, 0);
  int error = avcodec_open2(decoderCtx, decoder, nullptr);
  if (error < 0)
  {
     std::cout << "Failed to open decoder context! error - "
	       << err2str(error) << std::endl;
     exit(-1);
  }
  std::cout << "Created decoder succesfully." << std::endl;
}

int main() {
   av_register_all();
   createDecoder();
}
