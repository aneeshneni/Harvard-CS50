#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {
            int x = round(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed / 3);
            image[i][j].rgbtBlue = x;
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtRed = x;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {
            int ogred = image[i][j].rgbtRed;
            int ogblue = image[i][j].rgbtBlue;
            int oggreen = image[i][j].rgbtGreen;


            if (round(.393 * ogred + .769 * oggreen + .189 * ogblue) > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = round(.393 * ogred + .769 * oggreen + .189 * ogblue);
            if (round(.272 * ogred + .534 * oggreen + .131 * ogblue) > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = round(.272 * ogred + .534 * oggreen + .131 * ogblue);
            if (round(.349 * ogred + .686 * oggreen + .168 * ogblue) > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = round(.349 * ogred + .686 * oggreen + .168 * ogblue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) {

        for (int j = 0; j <= width/2; j ++) {

            int tempred = image[i][j].rgbtRed;
            int tempblue = image[i][j].rgbtBlue;
            int tempgreen = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][width-1 - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width-1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width-1 - j].rgbtGreen;

            image[i][width-1 - j].rgbtRed = tempred;
            image[i][width-1 - j].rgbtBlue = tempblue;
            image[i][width-1 - j].rgbtGreen = tempgreen;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++) {

        for (int j = 0; j < width; j ++) {
            int count = 1;
            bool topavailable = false;
            bool bottomavailable = false;
            bool leftavailable = false;
            bool rightavailable = false;
            int sumr = image[i][j].rgbtRed;
            int sumg = image[i][j].rgbtGreen;
            int sumb = image[i][j].rgbtBlue;
            if (i-1 >= 0) {
                sumr += image[i-1][j].rgbtRed;
                sumg += image[i-1][j].rgbtGreen;
                sumb += image[i-1][j].rgbtBlue;
                topavailable = true;
                count++;
            }
            if (i+1 < height) {
                sumr += image[i+1][j].rgbtRed;
                sumg += image[i+1][j].rgbtGreen;
                sumb += image[i+1][j].rgbtBlue;
                bottomavailable = true;
                count++;
            }
            if (j-1 >= 0) {
                sumr += image[i][j-1].rgbtRed;
                sumg += image[i][j-1].rgbtGreen;
                sumb += image[i][j-1].rgbtBlue;
                leftavailable = true;
                count++;
            }
            if (j+1 < width) {
                sumr += image[i][j+1].rgbtRed;
                sumg += image[i][j+1].rgbtGreen;
                sumb += image[i][j+1].rgbtBlue;
                rightavailable = true;
                count++;
            }
            if (topavailable && leftavailable) {
                sumr += image[i-1][j-1].rgbtRed;
                sumg += image[i-1][j-1].rgbtGreen;
                sumb += image[i-1][j-1].rgbtBlue;
                count++;
            }
            if (topavailable && rightavailable) {
                sumr += image[i-1][j+1].rgbtRed;
                sumg += image[i-1][j+1].rgbtGreen;
                sumb += image[i-1][j+1].rgbtBlue;
                count++;
            }
            if (bottomavailable && leftavailable) {
                sumr += image[i+1][j-1].rgbtRed;
                sumg += image[i+1][j-1].rgbtGreen;
                sumb += image[i+1][j-1].rgbtBlue;
                count++;
            }
            if (bottomavailable && rightavailable) {
                sumr += image[i+1][j+1].rgbtRed;
                sumg += image[i+1][j+1].rgbtGreen;
                sumb += image[i+1][j+1].rgbtBlue;
                count++;
            }
            image[i][j].rgbtRed = round(sumr/count);
            image[i][j].rgbtGreen = round(sumg/count);
            image[i][j].rgbtBlue = round(sumb/count);
        }
    }
    return;
}
