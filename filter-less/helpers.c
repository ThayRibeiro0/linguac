#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int a, b, vm, red, green, blue;
    //put column
    for (a = 0; a < height; a++)
    {
        //put row
        for (b = 0; b < width; b++)
        {
            //have the value from the colors
            red = image[a][b].rgbtRed;
            green = image[a][b].rgbtGreen;
            blue = image[a][b].rgbtBlue;

            //rounding the middle value
            vm = round(((float)red + (float)green + (float)blue) / 3);

            //new value
            image[a][b].rgbtRed = image[a][b].rgbtGreen = image[a][b].rgbtBlue = vm;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int a, b, red, green, blue, colorsepiar, colorsepiag, colorsepiab;

    for (a = 0; a < height; a++)
    {
        for (b = 0; b < width; b++)
        {
            red = image[a][b].rgbtRed;
            green = image[a][b].rgbtGreen;
            blue = image[a][b].rgbtBlue;

//new filter sepia
            colorsepiar = round(0.393 * red + 0.189 * blue + 0.769 * green);
            if (colorsepiar > 255)
            {
                image[a][b].rgbtRed = 255;
            }
            else
            {
                image[a][b].rgbtRed = colorsepiar;
            }

            colorsepiag = round(0.349 * red + 0.168 * blue + 0.686 * green);
            if (colorsepiag > 255)
            {
                image[a][b].rgbtGreen = 255;
            }
            else
            {
                image[a][b].rgbtGreen = colorsepiag;
            }

            colorsepiab = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (colorsepiab > 255)
            {
                image[a][b].rgbtBlue = 255;
            }
            else
            {
                image[a][b].rgbtBlue = colorsepiab;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int a, b;

    for (a = 0; a < height; a++)
    {
        //use array until the average
        for (b = 0; b < (width / 2); b++)
        {
            RGBTRIPLE temp = image[a][b];
            image[a][b] = image[a][width - (b + 1)];
            image[a][width - (b + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int a, b, sum_blue, sum_green, sum_red;
    float counter;

    //file temporary
    RGBTRIPLE temp[height][width];

    for (a = 0; a < height; a++)
    {
        for (b = 0; b < width; b++)
        {
            temp[a][b] = image[a][b];
        }
    }

    for (a = 0; a < height; a++)
    {
        for (b = 0; b < width; b++)
        {
            sum_blue = sum_green = sum_red = counter = 0;

            //corners - bottom right
            if (a >= 0 && b >= 0)
            {
                sum_red += temp[a][b].rgbtRed;
                sum_green += temp[a][b].rgbtGreen;
                sum_blue += temp[a][b].rgbtBlue;
                counter++;
            }
            // bottom left
            if (a >= 0 && b - 1 >= 0)
            {
                sum_red += temp[a][b - 1].rgbtRed;
                sum_green += temp[a][b - 1].rgbtGreen;
                sum_blue += temp[a][b - 1].rgbtBlue;
                counter++;
            }
            // top left
            if (a - 1 >= 0 && b >= 0)
            {
                sum_red += temp[a - 1][b].rgbtRed;
                sum_green += temp[a - 1][b].rgbtGreen;
                sum_blue += temp[a - 1][b].rgbtBlue;
                counter++;
            }
            // top right
            if (a - 1 >= 0 && b - 1 >= 0)
            {
                sum_red += temp[a - 1][b - 1].rgbtRed;
                sum_green += temp[a - 1][b - 1].rgbtGreen;
                sum_blue += temp[a - 1][b - 1].rgbtBlue;
                counter++;
            }
            //edges - bottom edge
            if ((a >= 0 && b + 1 >= 0) && (a >= 0 && b + 1 < width))
            {
                sum_red += temp[a][b + 1].rgbtRed;
                sum_green += temp[a][b + 1].rgbtGreen;
                sum_blue += temp[a][b + 1].rgbtBlue;
                counter++;
            }
            // top edge
            if ((a - 1 >= 0 && b + 1 >= 0) && (a - 1 >= 0 && b + 1 < width))
            {
                sum_red += temp[a - 1][b + 1].rgbtRed;
                sum_green += temp[a - 1][b + 1].rgbtGreen;
                sum_blue += temp[a - 1][b + 1].rgbtBlue;
                counter++;
            }
            // left edge
            if ((a + 1 >= 0 && b >= 0) && (a + 1 < height && b >= 0))
            {
                sum_red += temp[a + 1][b].rgbtRed;
                sum_green += temp[a + 1][b].rgbtGreen;
                sum_blue += temp[a + 1][b].rgbtBlue;
                counter++;
            }
            // right edge
            if ((a + 1 >= 0 && b - 1 >= 0) && (a + 1 < height && b - 1 >= 0))
            {
                sum_red += temp[a + 1][b - 1].rgbtRed;
                sum_green += temp[a + 1][b - 1].rgbtGreen;
                sum_blue += temp[a + 1][b - 1].rgbtBlue;
                counter++;
            }

            //midle pixels
            if ((a + 1 >= 0 && b + 1 >= 0) && (a + 1 < height && b + 1 < width))
            {
                sum_red += temp[a + 1][b + 1].rgbtRed;
                sum_green += temp[a + 1][b + 1].rgbtGreen;
                sum_blue += temp[a + 1][b + 1].rgbtBlue;
                counter++;
            }
            // midle color
            image[a][b].rgbtRed = round(sum_red / counter);
            image[a][b].rgbtGreen = round(sum_green / counter);
            image[a][b].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}