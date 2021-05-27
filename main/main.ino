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
//                   define/ include's                              //
//------------------------------------------------------------------//
#define UNIT 1000 // one unit of time in Morse
#define BN 2 // the pin the button is connected to




//------------------------------------------------------------------//
//                   All keyboard character structs                 //
//------------------------------------------------------------------//
/*
struct letter{
  char letter;
  struct letter *next;
  
} a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,x,y,z;
*/
//------------------------------------------------------------------//
//                   main();                                        //
//------------------------------------------------------------------//

void setup() {
  // put your setup code here, to run once:
  pinMode(BN, INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BN)){
    //e();
  }
}




//------------------------------------------------------------------//
//                       other functions                            //
//------------------------------------------------------------------//


void e() {
  /* precondition: the botton was clicked(1)
   *  first we have to wait a unit
   *  now that the unit is over, we can check the button again,
   *  
   *  if BN is 1{ 
   *    since the button has been pushed down 2 units, the letter starts with a dash.
   *    these take however take 3 units, so we wait another unit.
   *    
   *    now that 3 units are over since the begin of the button press, the button should be 0.
   *    IF BN is 1
   *      
   *    ELSE IF bn is 0
   *      
   *  
   *  }
   *  
   *  ELSE IF bn is 0 
   *    the letter starts with a 
   *  
   *  
   */

  // first we have to wait out the first unit.
  delay(UNIT); // unit 1

  // now we determine wether the button is still pressed down.
  if (digitalRead(BN)) {
    // if the button is still pressed down after unit 1
    
    delay(UNIT); // unit 2
    if (digitalRead(BN)) {
      t();
    } else {
      
    }
    
  } else {
    // if the button isn't pressed down anymore after unit 1
    // we have to wait 1 unit, to see if the character has ended, or there is more to come
    delay(UNIT);
    
    if (digitalRead(BN)) {
      // it seems there is more to come, considering we have to start at a morse dot again, we go to the i()[. .   ] function.
      // this part is entered when the letter has another dot or dash, thus we enter the next letter's process.
      
      i();
      break;
      
    }else {
      
      delay(UNIT);
      // if the button isn't pressed down in units 2,3 and 4, the character has ended.
      // this means we can write the current char to the computer.
      keyboard.write('e');
      keyboard.write(' ');
    }
  }
  
}
