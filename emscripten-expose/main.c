#include <emscripten/emscripten.h>

#include <stdint.h> 
#include <stddef.h> 
#include <stdio.h> 

#include "../GPMF_parser.h"
#include "../demo/GPMF_mp4reader.h"

int main(int argc, char ** argv)
{
  printf("Hello World\n");
}

void EMSCRIPTEN_KEEPALIVE myFunction(int argc, char ** argv)
{
  printf("MyFunction Called\n");
	//size_t mp4 = OpenMP4Source(argv[1], MOV_GPMF_TRAK_TYPE, MOV_GPMF_TRAK_SUBTYPE);
}
