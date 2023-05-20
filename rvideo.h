// 
// Functions for extracting video frames into raylib textures
//
// 2023, Jonathan Tainer
//

#ifndef RVIDEO_H
#define RVIDEO_H

#include <raylib.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

typedef struct VideoStream {
	AVFormatContext* formatContext;
	AVCodecParameters* codecParameters;
	AVCodec* codec;
	AVCodecContext* codecContext;
	int videoStreamIndex;

	AVFrame* frame;
	AVFrame* scaledFrame;
	uint8_t* bufferRGB;
	struct SwsContext* scalerContext;

	AVPacket packet;

	int width, height;
} VideoStream;

VideoStream* OpenVideoStream(const char* filename);
Texture LoadTextureFromVideoStream(VideoStream* stream);
int UpdateTextureFromVideoStream(Texture* texture, VideoStream* stream);
void UnloadVideoStream(VideoStream* stream);

#endif
