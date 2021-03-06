/***************************************************************************
  *  Copyright S. V. Paulauskas 2012-2014                                  *
  *                                                                        *
  *  This program is free software: you can redistribute it and/or modify  *
  *  it under the terms of the GNU General Public License as published by  *
  *  the Free Software Foundation, version 3.0 License.                    *
  *                                                                        *
  *  This program is distributed in the hope that it will be useful,       *
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
  *  GNU General Public License for more details.                          *
  *                                                                        *
  *  You should have received a copy of the GNU General Public License     *
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>. *
  **************************************************************************
*/

/** \example sig.cpp
 * \brief A simple example.
 * 
 * The example generates a simple function, a compound function, 
 * and finally a custom function.  It will then output these 
 * functions into separate data files.  
 */
#include <fstream>
#include <iostream>

#include "SignalGenerator.hpp"

using namespace std;

/// The main function, to set/get the different stuff for the example.
int main(int argc, char* argv[])
{
   double res = 0.01, length = 10., period = 1., amp = 5.;

   //Set a standard signal type
   SignalGenerator standard;
   standard.SetSignalLength(length);
   standard.SetSignalResolution(res);
   standard.SetPeriod(period);
   standard.SetAmplitude(amp);
   standard.SetSignalType("triangle");

   //Set Noise Information
   standard.SetNoise(false);
   standard.SetNoiseAmplitude(0.5);

   //Generate and Get Signal
   standard.GenerateSignal();
   vector<double> *stdSignal = standard.GetSignal();

   ofstream stdSig;
   stdSig.open("example-triangle.dat");
   for(unsigned int i = 0; i < stdSignal->size(); i++)
      stdSig << i*res << " " << stdSignal->at(i) << endl;
   stdSig.close();


   //Set a compound signal
   SignalGenerator compound;
   compound.SetSignalLength(length);
   compound.SetSignalResolution(res);
   compound.SetPeriod(period);
   compound.SetAmplitude(amp);
   compound.SetSignalType("sawtooth", "cosine");
   
   //Set Noise Information
   compound.SetNoise(false);
   compound.SetNoiseAmplitude(0.5);

   //Generate and Get Signal
   compound.GenerateSignal();
   vector<double> *compSignal = compound.GetSignal();

   ofstream compSig;
   compSig.open("example-compound.dat");
   for(unsigned int i = 0; i < compSignal->size(); i++)
      compSig << i*res << " " << compSignal->at(i) << endl;
   compSig.close();

   //Set a custom signal
   SignalGenerator custom;
   custom.SetSignalType("custom");
   custom.SetFileName("example-input.dat");
   
   //Generate and Get Signal
   custom.GenerateSignal();
   vector<double> *customSignal = compound.GetSignal();

   ofstream customSig;
   customSig.open("example-custom.dat");
   for(unsigned int i = 0; i < customSignal->size(); i++)
      customSig << i << " " << customSignal->at(i) << endl;
   customSig.close();
}
