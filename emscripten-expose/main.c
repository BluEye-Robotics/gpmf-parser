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
  //printf("argc: %d\n", argc);
  //printf("Hello World\n");


  //for (int i = 0; i < argc; ++i)
  //{
  //  printf("argv[%d]: %s\n", i, argv[i]);
  //}

  long bufsize;
  if (argc != 2) {
    fputs("Need 1 argument\n", stderr);
    return (EXIT_FAILURE);
  }

  unsigned char *source = NULL;
  FILE *fp = fopen(argv[1], "rb");
  if (fp != NULL) {
      /* Go to the end of the file. */
      if (fseek(fp, 0L, SEEK_END) == 0) {
          /* Get the size of the file. */
          bufsize = ftell(fp);
          if (bufsize == -1) { fputs("Couldn't get size\n", stderr); return (EXIT_FAILURE); }
  
          /* Allocate our buffer to that size. */
          source = malloc(sizeof(char) * (bufsize + 1));
          if (source == NULL) { fputs("Couldn't allocate\n", stderr); return (EXIT_FAILURE); }
  
          /* Go back to the start of the file. */
          if (fseek(fp, 0L, SEEK_SET) == -1) { fputs("Couldn't seek\n", stderr); return (EXIT_FAILURE); }
  
          /* Read the entire file into memory. */
          size_t newLen = fread(source, sizeof(char), bufsize, fp);
          if (newLen == 0) {
              fputs("Error reading file\n", stderr);
              //return (EXIT_FAILURE);
          } else {
              source[++newLen] = '\0'; /* Just to be safe. */
          }
      } else {
        fputs("Couldn't seek to end\n", stderr);
        return (EXIT_FAILURE);
      }
      fclose(fp);
  } else {
    fputs("Couldn't open\n", stderr);
    return (EXIT_FAILURE);
  }

  printf("%d\n", (uint32_t)bufsize);
  //printf("%d\n", (uint32_t) adler32(source, bufsize));
  
  free(source); /* Don't forget to call free() later! */

  return (EXIT_SUCCESS);
}

void
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
myFunction(int argc, char ** argv)
{
  printf("MyFunction Called\n");
  //EM_ASM(
  //      FS.writeFile("testfile", "a=1\nb=2\n");
  //      FS.writeFile("testfile", new Uint8Array([99, 61, 51]) /* c=3 */, { flags: "a" });
  //  );
  FILE *fp;
  fp = fopen("testfile", "r");

  if (fp == NULL)
   {
      printf("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

  char ch;
  while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);


	//size_t mp4 = OpenMP4Source("tmp", MOV_GPMF_TRAK_TYPE, MOV_GPMF_TRAK_SUBTYPE);
  //GPMF_Init(NULL, NULL, 10);
  //exit(1);
}
