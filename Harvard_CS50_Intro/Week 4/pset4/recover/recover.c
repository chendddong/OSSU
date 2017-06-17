#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[]) {
    
    // ensure proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[1];

    // open input file 
    FILE *f = fopen(infile, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    // create buffer
    uint8_t buf[512];
    // count for the naming of jpg
    int counter = 0;
    // the wrting position
    FILE *fw = NULL;
    
    // Iterate over file contents
    while (fread(buf, BLOCK_SIZE, 1, f)) {
        // Check if the first four bytes are a JPEG signature
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff
            && (buf[3] == 0xe0 || buf[3] == 0xe1)) {
            // Close the file, if it is opened
            if (fw != NULL)
                fclose(fw);
            
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
                
            // Open a new JPEG file for writing
            fw = fopen(filename, "w");
            
            counter++;
        }
        
        if (fw != NULL)
            fwrite(buf, BLOCK_SIZE, 1, fw);
    }
    
    if (fw != NULL)
        fclose(fw);
    
    fclose(f);
 
    return 0;
} 
 
 //////////////////////////////////////////////// Bug free line ///////////////////////////////////////
