///////////////////////////////////////////////
// SIGNALINO: a bioamplifier
// firmware for controlling a ADS1299-based shield for Arduino Due
//
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA  02110-1301, USA.
//
// This software has been inspired by the work of many people:
// Chris Rorden (original ADS1298 driver), see http://www.mccauslandcenter.sc.edu/crnl/open-source-eegecgemg 
// Adam Feuer (Author of HackEEGShield), see https://github.com/adamfeuer 
// People of the Open-BCI project
// JA Barios, ILSB technologies, Spain.
// And, of course, the Arduino team
//
// This file is part of project: SIGNALINO, a ADS1299-based bioamplifier
//
/*
* Author: JA Barios, ILSB technologies, Spain., agosto 2016 - enero 2017 - ...
* Modified: 
* Company: ILSB technologies, Spain. 
* ---------------------------------------------
*/


#include <SPI.h>  // include the SPI library:
#include "signalino.h"

#define BOARD_DUE
//#define BOARD_TS3x2



#define INTERVALO_LEESERIAL 1*16



//gtestSignal=false;
int modo_salida=1; //6


unsigned long tick=0;


void setup(){
 inicia_signalino(gtestCONTINUO,gtestSignal);
  
}


void loop()
{
  // la lectura de datos se hace por interrupciones
  if(gHayLectura && gtestCONTINUO && isRDATAC ){
         gHayLectura=0;
         tick++;    
         if(tick%1==0)imprimeSerial_signalino(modo_salida);
         if(tick%(INTERVALO_LEESERIAL)==0)leeSerial_signalino();
  }
  
//If you know x to be non-negative, and b to be a power of two, you can use x & (b - 1)     
}
