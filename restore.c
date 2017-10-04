/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open \n");
        return 2;
    }
    
    uint8_t flag = 0;
    FILE* outptr = fopen("000.jpg", "w");
    outptr = NULL;
    char* buff = malloc(512);
    int filename=0;
    char fname[16]; 
    uint32_t hdr1 = 0, hdr2=0;
    while(!feof(inptr)){
        fread(buff, 1, 512, inptr);
        //{printf("0x%x%x%x%x\n",(uint8_t)buff[0],(uint8_t)buff[1],(uint8_t)buff[2],(uint8_t)buff[3]);}
        hdr2=hdr1;
        hdr1 = ((uint8_t)buff[0]<<24)+((uint8_t)buff[1]<<16)+((uint8_t)buff[2]<<8)+(uint8_t)buff[3];
        if(hdr1 == 0xffd8ffe1 || hdr1 == 0xffd8ffe0){
            //new file
            flag=1;
            printf("new file\n");
            //write prev file
            //if(hdr2!=0){fwrite(buff, 512, 1, outptr);fclose(outptr);}
            //determine file name
            sprintf(fname, "%.3d.jpg",filename++);
            //create new out file
            outptr = fopen(fname, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                printf( "Could not create\n");
                return 3;
            }
            fwrite(buff, 1, 512, outptr);
    
        }else if(hdr2!=0 && flag!=0){
            fwrite(buff, 1, 512, outptr);
        }else{
        continue;
        }
        
        
        }
        
        
        
        
        
        
        
  fclose(inptr);
  return 0;  
}



