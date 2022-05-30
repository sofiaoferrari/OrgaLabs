#line 145 "bits.c"
int bitAnd(int x, int y) {

  return ~(~x | ~y);
#line 31 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 148 "bits.c"
}
#line 157
int bitMatch(int x, int y) {

  return (~(x & ~y))&(~(~x & y));
}
#line 168
int bitNor(int x, int y) {

  return ~x & ~y;
}
#line 179
int bitXor(int x, int y) {

  return ~((~(x & ~y))&(~(~x & y)));
}
#line 192
int allOddBits(int x) {

  int m8=  0x55;
  int m16=  m8 |( m8 << 8);
  int m32=  m16 |( m16 << 16);

  return !~(x | m32);
}
#line 208
int anyEvenBit(int x) {

  int m8=  0x55;
  int m16=  m8 |( m8 << 8);
  int m32=  m16 |( m16 << 16);

  return !!(x & m32);
}
#line 225
int byteSwap(int x, int n, int m) {

  int mascara=  0xff;
  int n_bits=  n << 3;
  int m_bits=  m << 3;
  int desplazo_der_n=  x >> n_bits;
  int desplazo_der_m=  x >> m_bits;
  int desplazamiento=(  desplazo_der_n ^ desplazo_der_m) & mascara;
  int posicion_n=  desplazamiento << n_bits;
  int posicion_m=  desplazamiento << m_bits;

  return (x ^ posicion_n) ^ posicion_m;
}
#line 247
int fitsBits(int x, int n) {

  int n_negado=(  ~n + 1);
  int desplazamiento=  32 + n_negado;

  return !(x ^( x << desplazamiento >> desplazamiento));
}
#line 261
int negate(int x) {

  return (~x+1);
}
#line 273
int sign(int x) {

  int es_cero=  !(!x);
  int signo_neg=  ~0;
  int signo_x=  x >> 31;
  int mismo_signo=(  signo_x & signo_neg);

  return (es_cero | mismo_signo);
}
#line 291
int addOK(int x, int y) {

  int sig_x=(  x >> 31);
  int sig_y=(  y >> 31);
  int sig_s=((  x + y) >> 31);
  int distinto_xy=(  sig_x ^ sig_y);
  int igual_xy=(  sig_x & sig_y);


  return ((distinto_xy & 0x1) |(( ~(igual_xy ^ sig_s)) & 0x1));
}
#line 312
int bitMask(int highbit, int lowbit) {

  int mff=  ~0x0;
  int high=(  mff <<( highbit))<<1;
  int low=  mff <<( lowbit);

  return (low & ~high);
}
#line 327
int conditional(int x, int y, int z) {

  int m=((  !x) << 31)>>31;

  return ((~m & y) |( m & z));
}
#line 342
int isAsciiDigit(int x) {

  int m=((  0x1<<31)>>25);
  int lim_menor=  ~(~0x30|x);
  int lim_mayor=(  m &( x+ 0x6));

  return !((m & x) | lim_menor | lim_mayor);

}
#line 358
int isGreater(int x, int y) {

  int x_mayor=(  x + ~y)>>31;
  int signo_x=  x>>31;
  int signo_y=  y>>31;
  int dif_signos=  signo_x ^ signo_y;

  return !((x_mayor & !dif_signos) |( signo_x & !signo_y));

}
#line 378
int replaceByte(int x, int n, int c) {

  int m=  c<<(n << 3);
  int mp=  0xFF<<(n << 3);

  return (m |( ~mp & x));
}
#line 394
int absVal(int x) {

  int signo_neg=  ~0;
  int signo_x=  x >> 31;
  int mismo_signo=(  signo_x & signo_neg);
  int suma_si_neg=(  signo_x & 1);

  return (x ^ mismo_signo) + suma_si_neg;
}
#line 410
int bang(int x) {

  int m=(  ~x + 1);

  return (~((x | m)>> 31) & 1);

}
#line 425
int isNonZero(int x) {

  int es_cero=(  ~x +1);

  return (0x1 &(( x |( es_cero))>>31));
}
#line 439
int logicalNeg(int x) {

  int m=(  ~x + 1);

  return (~((x | m)>> 31) & 1);
}
#line 457
unsigned floatAbsVal(unsigned uf) {

  unsigned valor_abs;
  unsigned mascara_sin_signo=  0x7FFFFFFF;
  unsigned exponente_max=  0x7F800000;
  unsigned sin_signo=  uf & mascara_sin_signo;

  if (sin_signo > exponente_max) 
    valor_abs = uf;
  else 
    valor_abs = sin_signo;
  return valor_abs;
}
#line 481
int floatIsEqual(unsigned uf, unsigned ug) {

  unsigned uf_sin_signo=(  uf & 0x7FFFFFFF);
  unsigned ug_sin_signo=(  ug & 0x7FFFFFFF);
  unsigned exponente_max=  0x7F800000;
  unsigned caso_00=  !(uf_sin_signo|ug_sin_signo);
  unsigned margen_uf=  uf_sin_signo <= exponente_max;
  unsigned margen_ug=  ug_sin_signo <= exponente_max;
  unsigned salida=  0;
  if (uf == ug) {
    if (margen_uf) {
      if (margen_ug) {
        salida = 1;
      }
    }
  }
  if (caso_00) {
    if (margen_uf) {
      if (margen_ug) {
        salida = 1;
      }
    }
  }

  return salida;
}
#line 518
 unsigned floatNegate(unsigned uf) {

  unsigned mascara_sin_signo=  0x7FFFFFFF;
  unsigned exponente_max=  0x7F800000;
  int es_NaN=(  uf & mascara_sin_signo) > exponente_max;
  int equivalente=  es_NaN ? uf : uf ^ 0x80000000;

  return equivalente;
}
#line 538
int floatIsLess(unsigned uf, unsigned ug) {

  int uf_signo=  uf >> 31;
  int ug_signo=  ug >> 31;
  int uf_sin_signo=(  uf & 0x7FFFFFFF);
  int ug_sin_signo=(  ug & 0x7FFFFFFF);
  int exponente_max=  0x7F800000;
  int caso_00=(  uf_sin_signo|ug_sin_signo);
  int es_menor=  0;
  if (uf_sin_signo > exponente_max) 
    es_menor = 0;

  else if (ug_sin_signo > exponente_max) 
    es_menor = 0;

  else if (!caso_00) 
    es_menor = 0;

  else if (uf_signo > ug_signo) 
    es_menor = 1;

  else if (ug_signo == uf_signo) {
    if (ug_signo) {
      if (ug < uf) 
        es_menor = 1;
    }

    else if (!ug_signo) {
      if (uf < ug) 
        es_menor = 1;
    }

  }
  else es_menor = 0;

  return es_menor;
}
#line 587
int floatFloat2Int(unsigned uf) {

  int signo=  uf >> 31;
  int exponente=(  uf >> 23) & 0xFF;
  int fraccion=  uf & 0x7FFFFF;
  int bias=  127;
  int salida=  0;int valor=0;
  int largo_fraccion=  23;


  if (exponente == 0xFF || exponente > bias + 31) 
      salida = 0x80000000;


  else if (exponente >= bias) {
      int exponente_sesgado=  exponente - bias;
      if (exponente_sesgado <= largo_fraccion) 
          fraccion = fraccion >>( largo_fraccion - exponente_sesgado);
      else 
          fraccion = fraccion <<( exponente_sesgado - largo_fraccion);
      valor =( 1 << exponente_sesgado) | fraccion;
      salida = signo ? -valor : valor;
  }

  return salida;
}
#line 626
unsigned floatPower2(int x) {

  unsigned INF=  0x7F800000;
   int valor=  127 + x;

   if (x < 0) 
     return 0;

   if (valor>=255) 
     return INF;


   return valor << 23;
}
