#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

static void Abort (char *fmt,...)
{
  va_list args;
  va_start (args, fmt);
  vfprintf (stderr, fmt, args);
  va_end (args);
  exit (1);
}

int main (int argc, char **argv)
{
  FILE  *inFile;
  FILE  *outFile = stdout;
  time_t now     = time (NULL);
  int    ch, i;

  if (argc != 2)
     Abort ("Usage: %s bin-file [> result]", argv[0]);

  if ((inFile = fopen(argv[1],"rb")) == NULL)
     Abort ("Cannot open %s\n", argv[1]);

  fprintf (outFile,
           "/* data statements for file %s at %.24s */\n"
           "/* Generated by BIN2C, G.Vanem 1995 */\n",
           argv[1], ctime(&now));

  i = 0;
  while ((ch = fgetc(inFile)) != EOF)
  {
    if (i++ % 12 == 0)
       fputs ("\n  ", outFile);
    fprintf (outFile, "0x%02X,", ch);
  }
  fputc ('\n', outFile);
  fclose (inFile);
  return (0);
}
