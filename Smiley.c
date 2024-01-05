#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int J = 0; J < width; J++)
        {
            if (image[i][J].rgbtRed == 0 && image[i][J].rgbtGreen == 0 &&
                image[i][J].rgbtBlue == 0) // color codes for black so we can change the blacks
            {
                image[i][J].rgbtRed = 153;
                image[i][J].rgbtGreen = 204;
                image[i][J].rgbtBlue = 255;
            }
        }
    }
}
