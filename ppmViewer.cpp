#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    //RGB PPM format.
    //http://netpbm.sourceforge.net/doc/ppm.html
    //Create this sample output.

    //------SAMPLE OUTPUT--------
    //P3
    //# feep.ppm
    //4 4
    //15
    // 0  0  0    0  0  0    0  0  0   15  0 15
    // 0  0  0    0 15  7    0  0  0    0  0  0
    // 0  0  0    0  0  0    0 15  7    0  0  0
    //15  0 15    0  0  0    0  0  0    0  0  0
    //...

    // 0-255 0-255 0-255 = 1 pixel.

    std::setw(3);
    std::setfill('0');
    
    int width = 200;
    int height = 100;
    int range = 255;

    std::ofstream outfile("ppmTest.ppm");

    outfile << "P3\n" << width << " " << height << "\n" << range << std::endl;

    for(int i = 0; i <= height - 1; i = i + 1) {
        for(int j = 0; j <= width - 1; j = j + 1) {
            float scalarR = (float) i / (float) height;
            float scalarG = (float) j / (float) width;
            float scalarB = .5;
            int r = static_cast<int>(scalarR * range);
            int g = static_cast<int>(scalarG * range);
            int b = static_cast<int>(scalarB * range);
            outfile << r << "  " << g << "  " << b << "    " << std::flush;
        }
        outfile << std::endl;
    }
    outfile.close();
}