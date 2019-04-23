#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include <stdint.h> 
#include <stddef.h> 
#include <stdio.h> 
#include <stdlib.h>

#include "../GPMF_parser.h"
#include "../demo/GPMF_mp4reader.h"

extern void PrintGPMF(GPMF_stream *ms);

int main(int argc, char ** argv)
{
  printf("Hello World\n");
}

void
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
myFunction(int argc, char ** argv)
{
  printf("MyFunction Called\n");
	//size_t mp4 = OpenMP4Source("tmp", MOV_GPMF_TRAK_TYPE, MOV_GPMF_TRAK_SUBTYPE);
  //GPMF_Init(NULL, NULL, 10);
  //exit(1);
}
