// Helper functions for music
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // the first position (fraction[0]) of fraction is the "1" of 1/4 and the second position (fraction[2]) is the "4"
    if(fraction[0] == '1')
    {

        // 1 (return 1) : 1/8 is equilavent to 1/8 (one or more other eighth notes)
        if(fraction[2] == '8')
        {
            return 1;
        }

        // 2 (return 2), in this case, since 1/4 is equivalent to 2/8 (twice that of an eighth note)
        else if(fraction[2] == '4')
        {
            return 2;
        }

        // 4 (return 4) : 1/2 is equilavent to 4/8 (four times that of an eighth note)
        else if(fraction[2] == '2')
        {
            return 4;
        }

        // 8 (return 8) : 1/1 is equilavent to 8/8 (eight times that of an eighth note)
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    else if(fraction[0] == '3' && fraction[2] == '8') // 3 (return 3) : 3/8 (three times that of an eighth note)
    {
        return 3;
    }
    // Absence of note
    else
    {
        return 0;
    }
    return 0;
}

// Calculates frequency (in Hz) of a note formatted as XY,
// where X is any of A through G and Y is any of 0 through 8,
// or formatted as XYZ, where X is any of A through G, Y is # or b,
// and Z is any of 0 through 8


int f(string note);
    {

        // char note = note[0];
        int octave = note[strlen(note) - 1];
        octave -= 48; // Adjust Ascii to int value

        // Determine Frequency of note in the given octive
        double f = 0.0;

        /*Determine note letter
        The frequency, f, of some note is 2n/12 × 440, where n is the number of semitones from that note to A4
        where n is negative if that note is below and positive if that note is above*/

        switch(note[0])
        {
            //to change octaves
            case 'C' :
                f = 440.0 / (pow(2.0, (9.0 / 12.0))); // 9.0 is the number of semitones between C and A, to A3 to A4 there is 12 semitones, also to A4 to A5
                break;
            case 'D' :
                f = 440.0 / (pow(2.0, (7.0 / 12.0)));
                break;
            case 'E' :
                f = 440.0 / (pow(2.0, (5.0 / 12.0)));
                break;
            case 'F' :
                f = 440.0 / (pow(2.0, (4.0 / 12.0)));
                break;
            case 'G' :
                f = 440.0 / (pow(2.0, (2.0 / 12.0)));
                break;
            case 'A' :
                f = 440.0;
                break;
            case 'B' :
                f = 440.0 * (pow(2.0, (2.0 / 12.0)));
                break;
            default :
                return 0;
        }

        // For going from A3 to A4 or down
        if(octave > 4)
        {
            for(int i = 0; i < octave - 4; i++)
            {
                f *= 2.0;
            }
        }
        //for going from A4 to A5 or up
        else if(octave < 4)
        {
            for(int i = 0; i < 4 - octave; i++)
            {
                f /= 2.0;
            }
        }

        // Ajustment flat or sharp
        //Support Ab and A#
        if(note[1] == 'b')
        {
            f /= (pow(2.0, (1.0 / 12.0)));
        }
        else if(note[1] == '#')
        {
            f *= (pow(2.0, (1.0 / 12.0)));
        }

        // Return frequency value as an int
        int ret = round(f);
        return ret;

    }

// Determines whether a string represents a rest
bool is_rest(string s)
{

    if(strcmp(s,"")==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}