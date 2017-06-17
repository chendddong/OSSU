/**
 * Copies a BMP piece by piece, just because.
 */
 
 
// // 1. Implement your program in a file called whodunit.c in a directory called whodunit.

// // 2. Your program should accept exactly two command-line arguments: the name of an input
// file to open for reading followed by the name of an output file to open for writing.

// // 3. If your program is executed with fewer or more than two command-line arguments, it 
// should remind the user of correct usage, as with fprintf (to stderr), and main should 
// return 1.

// // 4. If the input file cannot be opened for reading, your program should inform the user
// as much, as with fprintf (to stderr), and main should return 2.

// // 5. If the output file cannot be opened for writing, your program should inform the 
// user as much, as with fprintf (to stderr), and main should return 3.

// // 6. If the input file is not a 24-bit uncompressed BMP 4.0, your program should inform 
// the user as much, as with fprintf (to stderr), and main should return 4.

// 7. Upon success, main should 0.'s '


/* 
    Todo
    1. open file
    2. update header's info for outfile
    3. read clue's scanline, pixel by pixel
    4. change pixel's color as necessary
    5. write verdict's scanline, pixel by pixel
*/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage -- argument must be 3
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

////////////////////////////////////////////////////////////////////////////////////////
// 1. open file ////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
// 2. update header's info for outfile /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

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

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
// 3. read clue's scanline, pixel by pixel /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
////////////////////////////////////////////////////////////////////////////////////////    

////////////////////////////////////////////////////////////////////////////////////////
// 4. change pixel's color as necessary ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

            // 0000ff -> ffffff --- change full red to white
            if (triple.rgbtRed == 0xff) {
                triple.rgbtRed = 0xff;
                triple.rgbtGreen = 0xff;
                triple.rgbtBlue = 0xff;
            }
            
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
// 5. write verdict's scanline, pixel by pixel /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

////////////////////////////////////////////////////////////////////////////////////////

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}







