/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {

  return ~(~x | ~y);
}
/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
  
  return (~(x & ~y))&(~(~x & y));
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {

  return ~x & ~y;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

  return ~((~(x & ~y))&(~(~x & y)));
}
//2
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {

  int m8 = 0x55;
  int m16 = m8 | (m8 << 8);
  int m32 = m16 | (m16 << 16);

  return !~(x | m32);
}
/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {

  int m8 = 0x55;
  int m16 = m8 | (m8 << 8);
  int m32 = m16 | (m16 << 16);

  return !!(x & m32);
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  
  int mascara = 0xff;
  int n_bits = n << 3; //cantidad de bits que se debe desplazar x
  int m_bits = m << 3; //cantidad de bits que se debe desplazar x
  int desplazo_der_n = x >> n_bits; //desplazo el byte n, n_bits a la derecha
  int desplazo_der_m = x >> m_bits;
  int desplazamiento = (desplazo_der_n ^ desplazo_der_m) & mascara; 
  int posicion_n = desplazamiento << n_bits; //obtengo la nueva posicion (m) del byte n
  int posicion_m = desplazamiento << m_bits; //obtengo la nueva posicion (n) del byte m
  
  return (x ^ posicion_n) ^ posicion_m; //"ubico" los bytes en sus nuevas posiciones
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {

  int n_negado = (~n + 1); //cambia el signo de n, ya que no se puede usar '-'
  int desplazamiento = 32 + n_negado; 

  return !(x ^ (x << desplazamiento >> desplazamiento));//Devuelve 0 si se ha perdido algún bit con el desplazamiento.
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {

  return (~x+1);
}
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {

  int es_cero = !(!x); //devuelve 0 si y solo si x es igual a cero
  int signo_neg = ~0; //toma el signo negativo
  int signo_x = x >> 31;
  int mismo_signo = (signo_x & signo_neg); //devuelve -1 si x es negativo, 0 si es positivo

  return (es_cero | mismo_signo);
}
//3
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {

  int sig_x = (x >> 31);//signo x
  int sig_y = (y >> 31);//signo y
  int sig_s = ((x + y) >> 31);//signo suma
  int distinto_xy = (sig_x ^ sig_y);
  int igual_xy = (sig_x & sig_y);
  //Si 'x' e 'y' son de distnto signo da 1
  // o si 'x' e 'y' son del mismo signo y su suma es de igual signo que 'x' e 'y' entonces da 1,
  return ((distinto_xy & 0x1) | ((~(igual_xy ^ sig_s)) & 0x1));
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {

  int mff = ~0x0 ; //mascara de 0xFFFFFFFF
  int high = (mff << (highbit))<<1; //crea una mascara para el tamaño largo
  int low = mff << (lowbit);//crea una mascara para el tamaño corto

  return (low & ~high);//compara las dos mascaras creando la pedida
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  
  int m = ((!x) << 31)>>31; // crea una mascara de 0 si x = 0 o una mascara 0xFFFFFFFF si x != 0.

  return ((~m & y) | (m & z)); //Si la mascara es 0xFFFFFFFF devuelve a z si la mascara es 0 devuelve a y.
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

  int m = ((0x1<<31)>>25); 
  int lim_menor = ~(~0x30|x); 
  int lim_mayor = (m & (x+ 0x6));

  return !((m & x) | lim_menor | lim_mayor);

}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {

  int x_mayor = (x + ~y)>>31; //Si 'y' es mayor a 'x' devuelve 0
  int signo_x = x>>31 ; //Toma el signo de x. 
  int signo_y = y>>31 ; //Toma el signo de y. 
  int dif_signos = signo_x ^ signo_y; // Devuelve 1 si 'x' e 'y' son de signos distintos.

  return !((x_mayor & !dif_signos) | (signo_x & !signo_y )); // Si 'y' es mayor que 'x' y son de signos distintos, o si x es negativo e 'y' positivo devuelve 0, de lo contrario devuelve 1.

}

/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  
  int m = c<<(n << 3);
  int mp = 0xFF<<(n << 3);

  return (m | (~mp & x) );
}
//4
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {

  int signo_neg = ~0; //toma el signo negativo
  int signo_x = x >> 31;
  int mismo_signo = (signo_x & signo_neg); //devuelve -1 si x es negativo, 0 si es positivo
  int suma_si_neg = (signo_x & 1); //devuelve 1 si x es negativo, 0 si es positivo

  return (x ^ mismo_signo) + suma_si_neg;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {

  int m = (~x + 1); //m va a ser 0 si y solo si x es 0.

  return (~((x | m)>> 31) & 1);

}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {

  int es_cero = (~x +1); //si es 0 da 0

  return (0x1 & ((x | (es_cero))>>31));
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {

  int m = (~x + 1); //m va a ser 0 si y solo si x es 0.

  return (~((x | m)>> 31) & 1);
}
//float
/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {

  unsigned valor_abs;
  unsigned mascara_sin_signo = 0x7FFFFFFF;		
  unsigned exponente_max = 0x7F800000;
  unsigned sin_signo = uf & mascara_sin_signo;	
    
  if (sin_signo > exponente_max)
    valor_abs = uf;
  else
    valor_abs = sin_signo;
  return valor_abs;
}
/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {

  unsigned uf_sin_signo = (uf & 0x7FFFFFFF);
  unsigned ug_sin_signo = (ug & 0x7FFFFFFF);
  unsigned exponente_max = 0x7F800000;
  unsigned caso_00 = !(uf_sin_signo|ug_sin_signo);
  unsigned margen_uf = uf_sin_signo <= exponente_max;
  unsigned margen_ug = ug_sin_signo <= exponente_max; 
  unsigned salida = 0;
  if (uf == ug){
    if (margen_uf){
      if (margen_ug){
        salida = 1;
      }
    }
  }
  if (caso_00){
    if (margen_uf){
      if (margen_ug){
        salida = 1;
      }
    }
  }
  
  return salida;
}
/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
 unsigned floatNegate(unsigned uf) {

  unsigned mascara_sin_signo = 0x7FFFFFFF;		
  unsigned exponente_max = 0x7F800000;
  int es_NaN = (uf & mascara_sin_signo) > exponente_max;
  int equivalente = es_NaN ? uf : uf ^ 0x80000000;

  return equivalente;
}
/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
  
  int uf_signo = uf >> 31;
  int ug_signo = ug >> 31;
  int uf_sin_signo = (uf & 0x7FFFFFFF);
  int ug_sin_signo = (ug & 0x7FFFFFFF);
  int exponente_max = 0x7F800000;
  int caso_00 = (uf_sin_signo|ug_sin_signo);
  int es_menor = 0;
  if (uf_sin_signo > exponente_max)
    es_menor = 0;

  else if (ug_sin_signo > exponente_max)
    es_menor = 0;

  else if (!caso_00)
    es_menor = 0;    
     
  else if (uf_signo > ug_signo)
    es_menor = 1;
    
  else if (ug_signo == uf_signo){
    if (ug_signo){
      if (ug < uf)
        es_menor = 1;
    } 
      
    else if (!ug_signo){
      if (uf < ug)
        es_menor = 1;
    } 
      
  }
  else es_menor = 0;  
    
  return es_menor;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {

  int signo = uf >> 31;
  int exponente = (uf >> 23) & 0xFF;
  int fraccion = uf & 0x7FFFFF;
  int bias = 127;
  int salida = 0, valor = 0;
  int largo_fraccion = 23;

  // Por enunciado, si esta fuera de rango el exponente, devuelve 0x80000000.
  if (exponente == 0xFF || exponente > bias + 31)
      salida = 0x80000000;

  // Si el exponente esta dentro del rango...
  else if (exponente >= bias) {
      int exponente_sesgado = exponente - bias;
      if (exponente_sesgado <= largo_fraccion)
          fraccion = fraccion >> (largo_fraccion - exponente_sesgado);
      else
          fraccion = fraccion << (exponente_sesgado - largo_fraccion);
      valor = (1 << exponente_sesgado) | fraccion;
      salida = signo ? -valor : valor;
  }

  return salida;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {

  unsigned INF = 0x7F800000;
   int valor = 127 + x;
   //Si es muy chico
   if (x < 0)
     return 0;
   //Si es muy grande
   if (valor>=255)
     return INF;
   //Si está dentro del margen
   
   return valor << 23;
}
