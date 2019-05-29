#include <iostream>
#include <fstream>

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
    
    int width = 200;
    int height = 100;
    int range = 255;

    std::ofstream outfile("ppmTest.ppm");

    outfile << "P3\n" << width << " " << height << "\n" << range << std::endl;

    for(int i = 0; i >= height - 1; i++) {
        for(int j = 0; j >= width - 1; j++) {
            float scalerR = i/height;
            float scalerG = j/width;
            float scalerB = .2;
            int r = static_cast<int>(scalerR * range);
            int g = static_cast<int>(scalerG * range);
            int b = static_cast<int>(scalerB * range);
            outfile << r << "  " << g << "  " << b << "    ";
        }
        outfile << "\n";
    }
    outfile.close();
}