/*
 * Author: Lucas Dekker
 * Version: 0.1
 * date: 26-5-2021
 * 
 * written with the arduino pro micro in mind, but should work on any old arduino.
 * change the typing tempo with the UNIT define, and change the BN define to whatever pin your botton is connected to.
 * 
 * only letter characters for the time being
 */

//------------------------------------------------------------------//
//                   define/ include/ prototypes                    //
//------------------------------------------------------------------//
#define UNIT 1000 // one unit of time in Morse
#define BN 2 // the pin the button is connected to


void process(struct letter currentL)

//------------------------------------------------------------------//
//                   All keyboard character structs                 //
//------------------------------------------------------------------//
/*
struct letter{
  char character;
  struct letter *next;
  
} a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,x,y,z;
*/
//------------------------------------------------------------------//
//                   main();                                        //
//------------------------------------------------------------------//

void setup() {
  pinMode(BN, INPUT_PULLUP);
  

}

void loop() {
  
  if (digitalRead(BN)){
    process();
  }
}




//------------------------------------------------------------------//
//                       other functions                            //
//------------------------------------------------------------------//


void funcEnT(struct letter currentL) {
  // first we have to wait out the first unit.
  delay(UNIT); // unit 1

  // now we determine wether the button is still pressed down.
  if (digitalRead(BN)) {
    // if the button is still pressed down after unit 1
    // this bit is problably a dash(-), we have to make sure though.
    delay(UNIT); // unit 2
    
    if (digitalRead(BN)) {
      // if the button is not pressed down anymore
      delay(UNIT); // unit 3
      // this bit is a dash
      keyboard.write('t');
      keyboard.write(' ');
    } else {
      //TODO
    }
    
  } else {
    // if the button isn't pressed down anymore after unit 1
    // we have to wait 1 unit, to see if the character has ended, or there is more to come
    delay(UNIT); // unit 2
    
    if (digitalRead(BN)) {
      // it seems there is more to come, considering we have to start at a morse dot again, we go to the i()[. .   ] function.
      // this part is entered when the letter has another dot or dash, thus we enter the next letter's process.
      //TODO
      i();
      break;
      
    }else {
      //this bit is a dot.
      delay(UNIT); // unit 3
      // if the button isn't pressed down in units 2,3 and 4, the character has ended.
      // this means we can write the current char to the computer.
      keyboard.write('e');
      keyboard.write(' ');
    }
  }
}
