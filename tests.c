#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <math.h>
#include "libftprintf.h"
int main(int argc, char const *argv[])
{
	if (argc && argv)
		argc++;

	printf("LONG LONG TEST\n\n");

	printf("ft_printf:\n");
	ft_printf("%lld\n", LLONG_MAX);
	ft_printf("%lld\n", LLONG_MIN);

	printf("printf:\n");	
	printf("%lld\n", LLONG_MAX);
	printf("%lld\n", LLONG_MIN);
	
	printf("\nLONG TEST\n\n");

	printf("ft_printf:\n");
	ft_printf("%ld\n", LONG_MAX);
	ft_printf("%ld\n", LONG_MIN);

	printf("printf:\n");
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", LONG_MIN);

	printf("\nPADDING TEST\n\n");
	printf("_printf: |%-4d|\n", 42);
	ft_printf("fprintf: |%-4d|\n", 42);
	printf("_printf: %%-5d -42 == |%-5d|\n", -42);
	ft_printf("fprintf: %%-5d -42 == |%-5d|\n", -42);
	printf("_printf: |%3i|%-3i|\n", 42, 42);
	ft_printf("fprintf: |%3i|%-3i|\n", 42, 42);
	printf("_printf: %%-4i 42 == |%-4i|\n", 42);
	ft_printf("fprintf: %%-4i 42 == |%-4i|\n", 42);
	//%c tests
	printf("\nCHAR TESTS:\n\n");

	printf("ft_printf:\n");
	ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c", 'l');
	ft_printf("%c", 'y');
	ft_printf("%c", ' ');
	ft_printf("%c", 'e');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", ' ');
	ft_printf("%c", 'f');
	ft_printf("%c", 'a');
	ft_printf("%c", 'n');
	ft_printf("%c", 't');
	ft_printf("%c", 'a');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", 'i');
	ft_printf("%c", 'q');
	ft_printf("%c", 'u');
	ft_printf("%c", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');
	printf("printf:\n");
	printf("%c", 42);
	printf("Kashim a %c histoires à raconter", 1001);
	printf("Il fait au moins %c\n", -8000);
	printf("%c", -0);
	printf("%c", 0);
	printf("%c\n", INT_MAX);
	printf("%c\n", 'c');
	printf("%c\n", '\n');
	printf("%c", 'l');
	printf("%c", 'y');
	printf("%c", ' ');
	printf("%c", 'e');
	printf("%c", 's');
	printf("%c", 't');
	printf("%c", ' ');
	printf("%c", 'f');
	printf("%c", 'a');
	printf("%c", 'n');
	printf("%c", 't');
	printf("%c", 'a');
	printf("%c", 's');
	printf("%c", 't');
	printf("%c", 'i');
	printf("%c", 'q');
	printf("%c", 'u');
	printf("%c", 'e');
	printf("%c\n", '!');
	printf("%c\n", '\r');
	printf("%c\n", '\t');

// 	//%d tests
	printf("ft_printf d tests\n");
	ft_printf("%d", 42);
	ft_printf("Kashim a %d histoires à raconter", 1001);
	ft_printf("Il fait au moins %d\n", -8000);
	ft_printf("%d", -0);
	ft_printf("%d", 0);
	ft_printf("%d", INT_MAX);
	ft_printf("%d", INT_MIN);
	ft_printf("%d", INT_MIN - 1);
	ft_printf("%d", INT_MAX + 1);
	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	ft_printf("%%d \t == |%d|\n", '\t');
	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	printf("\nprintf %%d tests\n");
	printf("%d", 42);
	printf("Kashim a %d histoires à raconter", 1001);
	printf("Il fait au moins %d\n", -8000);
	printf("%d", -0);
	printf("%d", 0);
	printf("%d", INT_MAX);
	printf("%d", INT_MIN);
	printf("%d", INT_MIN - 1);
	printf("%d", INT_MAX + 1);
	printf("%%d 0000042 == |%d|\n", 0000042);
	printf("%%d \t == |%d|\n", '\t');
	printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	
// // // char tests
	char		*str = NULL;
	printf("%%s tests ft_printf\n");
	ft_printf("%s", "pouet");
	ft_printf(" pouet %s !!\n", "camembert");
	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	ft_printf("%s!\n", str);

	printf("\n%%s tests printf\n");
	printf("%s", "pouet");
	printf(" pouet %s !!\n", "camembert");
	printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	printf("%s!\n", str);

// // %u tests
	printf("\n%%u tests ft_printf\n");
	ft_printf("%u", 42);
	ft_printf("Kashim a %u histoires à raconter", 1001);
	ft_printf("Il fait au moins %u\n", -8000);
	ft_printf("%u", -0);
	ft_printf("%u", 0);
	ft_printf("%u", INT_MAX);
	ft_printf("%u", INT_MIN);
	ft_printf("%u", INT_MIN - 1);
	ft_printf("%u", INT_MAX + 1);
	ft_printf("%%u 0000042 == |%u|\n", 0000042);
	ft_printf("%%u \t == |%u|\n", '\t');
	ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
	printf("\n%%u tests printf\n");
	printf("%u", 42);
	printf("Kashim a %u histoires à raconter", 1001);
	printf("Il fait au moins %u\n", -8000);
	printf("%u", -0);
	printf("%u", 0);
	printf("%u", INT_MAX);
	printf("%u", INT_MIN);
	printf("%u", INT_MIN - 1);
	printf("%u", INT_MAX + 1);
	printf("%%u 0000042 == |%u|\n", 0000042);
	printf("%%u \t == |%u|\n", '\t');
	printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

// %o tests
	printf("\n%%o tests ft_printf\n");
	ft_printf("%o", 42);
	ft_printf("Kashim a %o histoires à raconter", 1001);
	ft_printf("Il fait au moins %o\n", -8000);
	ft_printf("%o", -0);
	ft_printf("%o", 0);
	ft_printf("%o", INT_MAX);
	ft_printf("%o", INT_MIN);
	ft_printf("%o", INT_MIN - 1);
	ft_printf("%o", INT_MAX + 1);
	ft_printf("%%o 0000042 == |%o|\n", 0000042);
	ft_printf("%%o \t == |%o|\n", '\t');
	ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	printf("\n%%o tests printf\n");
	printf("%o", 42);
	printf("Kashim a %o histoires à raconter", 1001);
	printf("Il fait au moins %o\n", -8000);
	printf("%o", -0);
	printf("%o", 0);
	printf("%o", INT_MAX);
	printf("%o", INT_MIN);
	printf("%o", INT_MIN - 1);
	printf("%o", INT_MAX + 1);
	printf("%%o 0000042 == |%o|\n", 0000042);
	printf("%%o \t == |%o|\n", '\t');
	printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	
	//%x tests
	printf("\n%%x tests ft_printf\n");
	ft_printf("%x", 42);
	ft_printf("Kashim a %x histoires à raconter", 1001);
	ft_printf("Il fait au moins %x\n", -8000);
	ft_printf("%x", -0);
	ft_printf("%x", 0);
	ft_printf("%x", INT_MAX);
	ft_printf("%x", INT_MIN);
	ft_printf("%x", INT_MIN - 1);
	ft_printf("%x", INT_MAX + 1);
	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	ft_printf("%%x \t == |%x|\n", '\t');
	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	printf("\n%%x tests printf\n");
	printf("%x", 42);
	printf("Kashim a %x histoires à raconter", 1001);
	printf("Il fait au moins %x\n", -8000);
	printf("%x", -0);
	printf("%x", 0);
	printf("%x", INT_MAX);
	printf("%x", INT_MIN);
	printf("%x", INT_MIN - 1);
	printf("%x", INT_MAX + 1);
	printf("%%x 0000042 == |%x|\n", 0000042);
	printf("%%x \t == |%x|\n", '\t');
	printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

	//plus test
	printf("\nPlus test ft_printf\n");
	ft_printf("%%+i 42 == %+i\n", 42);
	ft_printf("%%+d 42 == %+d\n", INT_MAX);
	ft_printf("%%+i -42 == %+i\n", -42);
	ft_printf("%0+04d\n", 42);
	printf("\nPlus test printf\n");
	printf("%%+i 42 == %+i\n", 42);
	printf("%%+d 42 == %+d\n", INT_MAX);
	printf("%%+i -42 == %+i\n", -42);
	printf("%0+04d\n", 42);

	// // //zero tests
	printf("\nzero tests\n");
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);
	printf("\nzero tests\n");
	printf("%%04i 42 == |%04i|\n", 42);
	printf("%%05i 42 == |%05i|\n", 42);
	printf("%%0i 42 == |%0i|\n", 42);
	printf("%%0d 0000042 == |%0d|\n", 0000042);

	// // //space
	printf("\nspace test\n");
	ft_printf("%%      i 42 == |%      i|\n", 42);
	ft_printf("%% i -42 == |% i|\n", -42);
	ft_printf("|% 4i|\n", 42);
	printf("\nspace test\n");
	printf("%%      i 42 == |%      i|\n", 42);
	printf("%% i -42 == |% i|\n", -42);
	printf("|% 4i|\n", 42);

	// // //alt mode
	printf("\nalt mode test\n");
	ft_printf("%%#X 42 ==  %#X\n", 42);
	ft_printf("%%X 42 ==  %X\n", 42);
	ft_printf("%%#o 0 ==  %#o\n", 0);
	ft_printf("%%o 0 ==  %o\n", 0);
	ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
	ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
	ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
	ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);
	printf("\nalt mode test\n");
	printf("%%#X 42 ==  %#X\n", 42);
	printf("%%X 42 ==  %X\n", 42);
	printf("%%#o 0 ==  %#o\n", 0);
	printf("%%o 0 ==  %o\n", 0);
	printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	printf("%%o INT_MAX ==  %o\n", INT_MAX);
	printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	printf("%%o INT_MIN ==  %o\n", INT_MIN);
	printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	printf("%%X INT_MIN ==  %X\n", INT_MIN);
	printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	printf("%%X INT_MAX ==  %X\n", INT_MAX);

	// // precision tests
	// ft_printf("\nprecision tests ft_printf\n");
	// ft_printf("ft%%04.5i 42 == |%04.5i|\n", 42);
	// ft_printf("ft%%04.3i 42 == |%04.3i|\n", 42);
	// ft_printf("ft%%04.2i 42 == |%04.2i|\n", 42);
	printf("\nprecision tests printf\n");
	printf("ft%%04.5i 42 == |%04.5i|\n", 42);
	printf("ft%%04.3i 42 == |%04.3i|\n", 42);
	printf("ft%%04.2i 42 == |%04.2i|\n", 42);

	// // //double tests
	printf("\ndouble tests ft_printf\n");
	ft_printf("%f\n", (double)42);
	ft_printf("Kashim a %f histoires à raconter\n", (double)1001);
	ft_printf("Il fait au moins %f\n", (double)-8000);
	ft_printf("%f\n", (double)-0);
	ft_printf("%f\n", (double)0);
	ft_printf("%f\n", (double)INT_MAX);
	ft_printf("%f\n", (double)INT_MIN);
	ft_printf("%f\n", (double)INT_MIN - 1);
	ft_printf("%f", (double)INT_MAX + 1);
	ft_printf("%%f 0000042 == |%f|\n", (double)0000042);
	ft_printf("%%f \t == |%f|\n", (double)'\t');
	ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%f 42.42 == |%f|\n", 42.42);
	printf("\ndouble tests printf\n");
	printf("%f\n", (double)42);
	printf("Kashim a %f histoires à raconter\n", (double)1001);
	printf("Il fait au moins %f\n", (double)-8000);
	printf("%f\n", (double)-0);
	printf("%f\n", (double)0);
	printf("%f\n", (double)INT_MAX);
	printf("%f\n", (double)INT_MIN);
	printf("%f\n", (double)INT_MIN - 1);
	printf("%f", (double)INT_MAX + 1);
	printf("%%f 0000042 == |%f|\n", (double)0000042);
	printf("%%f \t == |%f|\n", (double)'\t');
	printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	printf("%%f 42.42 == |%f|\n", 42.42);

	// //PASSSED

	unsigned char a = -125;
	unsigned int b = -125;
	unsigned long c = -125;
	unsigned short d = -125;
	size_t e = -125;
	uintmax_t f = -125;
	unsigned long long	g = -125;

	unsigned char h = 0;
	unsigned int i = 0;
	unsigned long j = 0;
	unsigned short k = 0;
	size_t l = 0;
	uintmax_t m = 0;
	unsigned long long n = 0;

	unsigned char o = (unsigned char)~0U>>1;
	unsigned int p = ~0U>>1;
	unsigned long q = ~0U>>1;
	unsigned short r = (short)~0U>>1;
	size_t s = (size_t)~0U>>1;
	uintmax_t t = (uintmax_t)~0U>>1;
	unsigned long long u = (unsigned long long)~0U>>1;

	unsigned char v = -m-1;
	unsigned int w = -n-1;
	unsigned long x = -o-1;
	unsigned short y = -p-1;
	unsigned long z = -q-1;
	uintmax_t zz = -r-1;
	unsigned long long aa = -r-1;

	printf("\nllstuf\n");
	ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	ft_printf("unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	ft_printf("unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	ft_printf("unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	ft_printf("size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	ft_printf("uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));

	ft_printf("unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	ft_printf("unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	ft_printf("unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	ft_printf("unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	ft_printf("size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	ft_printf("uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	ft_printf("unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));

	ft_printf("unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	ft_printf("unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	ft_printf("unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	ft_printf("unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	ft_printf("size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	ft_printf("uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	ft_printf("unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));

	ft_printf("unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	ft_printf("unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	ft_printf("unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	ft_printf("unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	ft_printf("size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	ft_printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));


	printf("\nllstuf\n");
	printf("unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	printf("unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	printf("unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	printf("unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	printf("size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	printf("uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	printf("unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));

	printf("unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	printf("unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	printf("unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	printf("unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	printf("size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	printf("uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	printf("unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));

	printf("unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	printf("unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	printf("unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	printf("unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	printf("size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	printf("uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	printf("unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));

	printf("unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	printf("unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	printf("unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	printf("unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	printf("size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));
}