#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern void fb_display(unsigned char *rgbbuff, unsigned int x_size, int unsigned y_size, unsigned int x_pan, unsigned int y_pan, int x_offs, int y_offs);
extern int openFB(const char *name);
extern void closeFB(int fh);
extern char *dev;

#define X_BUFFER	(320)
#define Y_BUFFER	(320)

//int main(void)
int main(int argc, char *argv[])
{
    float i,j,z,k;
    unsigned char *buffer;
    int flag=0;
    int  Width,Height;
    if(argc == 3)
    {
        Width =atoi(argv[1]);
        Height=atoi(argv[2]);
    }else
    {
      Width=X_BUFFER;
      Height=Y_BUFFER;
     }

    buffer = (unsigned char *) malloc(Width * Height * 3 * sizeof(unsigned char));
    z=20.0;

   while(1)
   {
	   if(z>500.0)
	   {
		   flag=0;
	   }else if(z<50.0)
	   {
		   flag=1;
	   }

	   if(flag)
	   {
		   z++;
	   }else
	   {
		   z--;
	   }
#if 1
	   for(j=0.0; j<Height; j++)
		   for(i=0.0; i<Width; i++)
		   {
			   buffer[(int)((i+j*Width)*3)] = (unsigned char)((float)i * (float)z / (float)Width);
			   buffer[(int)((i+j*Width)*3+1)] = (unsigned char)((float)(Width-i) * (float)z / (float)Width);
			   buffer[(int)((i+j*Width)*3+2)] = (unsigned char)((float)j * (float)z / (float)Height);
		   }
#else
		 memset(buffer,0xff/i,Width * Height*3);
#endif
		fb_display(buffer, Width, Height, 0, 0, 50, 50);
        //for (k=0; k < 11000000; k++);
fb_display(buffer, Width, Height, 0, 0, 0, 0);
   }
   free(buffer);
   return 0;
}
