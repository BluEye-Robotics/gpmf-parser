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


const int MOD_ADLER = 65521;
 
uint64_t adler32(unsigned char *data, int32_t len) /* where data is the location of the data in physical memory and 
                                                       len is the length of the data in bytes */
{
    uint64_t a = 1, b = 0;
    int32_t index;
 
    /* Process each byte of the data in order */
    for (index = 0; index < len; ++index)
    {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
 
    return (b << 16) | a;
}

int main(int argc, char ** argv)
{
  printf("Hello World\n");
  printf("argc: %d\n", argc);
  for (int i = 0; i < argc; ++i)
  {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  return 0;
}

void
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
myFunction(char *buf, int length)
{
  printf("MyFunction Called\n");
  printf("%d, %d\n", buf, length);
  //for (int i = 0; i < 10; ++i)
  //  printf("%02x", buf[i]);
  //printf("\n");


	//size_t mp4 = OpenMP4Source("tmp", MOV_GPMF_TRAK_TYPE, MOV_GPMF_TRAK_SUBTYPE);
  //GPMF_Init(NULL, NULL, 10);
  //exit(1);
}
