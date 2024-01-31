#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "testutils.h"

#include "dynarray.h"

#define NAMELEN 25

// a person structure
struct person
{
  char firstname[NAMELEN];
  char lastname[NAMELEN];
  int age;
};

typedef struct person *person;

// cond ? if true execute here : if not, execute here
#define ABS_DIFF(a, b) ((a) > (b) ? (a-b) : (b-a))
#define MINIMAL(a, b) ((a) >= (b) ? (b) : (a))


static person person_make( char *first, char *last, int age ) {
  person p = malloc( sizeof(struct person) );
  assert( p != NULL );

  COPYNAME( p->firstname, first );
  COPYNAME( p->lastname, last );
  p->age = age;

  return p;
}


static void person_print( FILE *out, DA_ELEMENT el, int pos ) {
  person p = el;
  fprintf( out, "%s %s (age %d)", p->firstname, p->lastname, p->age );
}


// DA_ELEMENT was a typedef for void *
// [person1, person2, person3]
// DA_ELEMENT = person
static void psumagecb( DA_ELEMENT el, int pos, void *stateptr ) {
  // dummy struct person * to reference the same data in el.
  person p = el;
  int *total = stateptr;
  *total += p->age;
}

static void str_print( FILE *out, DA_ELEMENT el, int pos ) {
  fputs( (char *)el, out );
}

// DA_ELEMENT = string
// strlen(char *s)
static void ssumlengthcb( DA_ELEMENT el, int pos, void *stateptr ) {
  char *p = el;
  int *total = stateptr;
  *total += strlen(p);
}

// toupper(*s) returns an upper character, given a character
// YEOEUN
// use for loop!
static void puppercasecb( DA_ELEMENT el, int pos, void *stateptr ) {
  person p = el;
  char *firstname = p->firstname;
  char *lastname = p->lastname;

  // cast the return type of the toupper (int) to a (char)
  // firstname[i] is a type char
  size_t a = strlen(firstname);
  for(int i = 0; i < a; i++){
    firstname[i] = (char) toupper(firstname[i]);
    break;
  }
  size_t b = strlen(lastname);
  for(int i = 0; i < b; i++){
    lastname[i] = (char) toupper(lastname[i]);
    break;
  }

//
//  for (char *s = p->firstname; *s; s++) {
//      *s = toupper(*s);
//  }

};


int main( void ) {
  dynarray d = dynarray_create( 10, &person_print, &free );

  int n = dynarray_len( d );
  testint( n, 0, "empty dynarray should have 0 members" );

  dynarray_push( d, person_make("duncan", "white", 45) );
  n = dynarray_len( d );
  testint( n, 1, "pda(dcw).members" );

  dynarray_push( d, person_make("will", "knottenbelt", 35) );
  n = dynarray_len( d );
  testint( n, 2, "pda(dcw,will).members" );

  fputs( "pda(dcw,will): prints as ", stdout );
  dynarray_print( d, stdout );
  putchar( '\n' );

  person *p = dynarray_data( d );
  teststring( p[0]->firstname, "duncan", "pda(d,w).data[0].firstname" );
  teststring( p[1]->lastname, "knottenbelt", "pda(d,w).data[1].lastname" );

  int totalage = 0;
  dynarray_foreach( d, &psumagecb, &totalage );
  testint( totalage, 80, "pda(dcw,will).totalage" );

  dynarray_foreach( d, &puppercasecb, NULL );
  teststring( p[0]->firstname, "Duncan", "pda(d,w).data[0].firstname" );
  teststring( p[1]->lastname, "Knottenbelt", "pda(d,w).data[1].lastname" );

  dynarray_free( d );

  // now let's create a dynarray of string literals..
  d = dynarray_create( 10, &str_print, NULL );

  n = dynarray_len( d );
  testint( n, 0, "empty sda should have 0 members" );

  dynarray_push( d, "duncan" );
  n = dynarray_len( d );
  testint( n, 1, "sda(dcw).members" );

  dynarray_push( d, "will" );
  n = dynarray_len( d );
  testint( n, 2, "sda(dcw,will).members" );

  char **sp = dynarray_data( d );
  teststring( *sp, "duncan", "sda(d,w).data[0]" );
  teststring( sp[1], "will", "sda(d,w).data[1]" );

  int totallen = 0;
  dynarray_foreach( d, &ssumlengthcb, &totallen );
  testint( totallen, 10, "sda(dcw,will).totallen" );

  dynarray_free( d );

  return 0;
}
