/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


unsigned int to_int(RGBTRIPLE triple){
    //RGBTRIPLE tmp = triple;
    unsigned int x = triple.rgbtBlue+(triple.rgbtGreen<<8)+(triple.rgbtRed<<16);
    return x;
}



int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int oldpadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biWidth*=n;
    bi.biHeight*=n;
    
    bi.biSizeImage-=oldpadding*abs(bi.biHeight/n);
    bi.biSizeImage*=(n*n);
    int newpadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage+=newpadding*abs(bi.biHeight);
    
    bf.bfSize = (bi.biSizeImage+54);
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    
    RGBTRIPLE image[abs(bi.biHeight)/n][bi.biWidth/n];
    int rcnt=0;
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight)/n; i < biHeight; i++)
    {
    
        
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth/n; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            //if(triple.rgbtRed>100){
            //triple.rgbtBlue = triple.rgbtRed;
            //triple.rgbtGreen = triple.rgbtRed;
            //}
            //triple.rgbtRed = triple.rgbtBlue;
            image[i][j] = triple;
            rcnt++;
            // write RGB triple to outfile
            
            
        }
        fseek(inptr, oldpadding, SEEK_CUR);
        //rcnt+=oldpadding;
        // then add it back (to demonstrate how)
        
        }
        printf("rcnt %d, hg %d, wt %d\n", rcnt, abs(bi.biHeight),bi.biWidth);
        //TODO
        
        int count = 0;
        for(int i=0;i<abs(bi.biHeight)/n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<abs(bi.biWidth)/n;k++){
                    for(int l=0;l<n;l++){
                        fwrite(&(image[i][k]), sizeof(RGBTRIPLE), 1, outptr);
                        count+=3;
                        //printf("we on %dth pixel on %dth line origin and %d line and %d pixel of copy, pixel=%.6x\n", k+1, i+1,i*n+j+1, k*n+l+1,to_int(image[i][k]));
                    }
                    
                    
                    
                }
                for (int m = 0; m < newpadding; m++){fputc(0x00, outptr);count++;}
                //printf("wrote padding = %d\n", newpadding);
            }
            
        }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
    printf("%d, %d,\n",count, bi.biSizeImage);
    // that's all folks
    return 0;
}
