//
// dynarray.c:	a minimal dynamic generic array that can grow.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "dynarray.h"


// dynarray ds = dynarray_create( cap, pef, fef );
//   Create and return a new empty dynarray, with initial capacity cap,
//   print element function pef, and free element function fef
//
dynarray dynarray_create( int cap, dynarray_printf pef, dynarray_freef fef ) {
  dynarray new = malloc( sizeof(struct dynarray));
  assert( new != NULL );
  new->data = malloc(cap * sizeof(DA_ELEMENT));
  assert( new->data != NULL );
  new->len = 0;
  new->cap = cap;
  new->fef = fef;
  new->pef = pef;
  return new;
}


// int len = dynarray_len( d );
//   Return the length of dynarray d.
//
int dynarray_len( dynarray d ) {
  return d->len;
}


// data = dynarray_data( d );
//   Return the dynarray's data as a void * for typecast-free copying
//   to any pointer based type; note: not a copy, the actual data.
//
void *dynarray_data( dynarray d ) {
  return d->data;
}


// Helper to grow the dynarray if it's full
//
static void grow( dynarray d ) {
  if( d->len+1 >= d->cap ) {    // need more space?
    d->cap += 100;
    d->data = realloc( d->data, d->cap*sizeof(DA_ELEMENT) );
    assert( d->data != NULL );
  }
}


// dynarray_push( d, element );
//   append element onto the end of d's data
//
void dynarray_push( dynarray d, DA_ELEMENT element ) {
  grow( d );
  d->data[ d->len++ ] = element;
}


// dynarray_foreach( d, cb, stateptr );
//   iterator function: call cb( element, position, stateptr )
//   foreach element in d.
//
void dynarray_foreach( dynarray d, dynarray_foreachf cb, void *stateptr ) {
  assert( cb != NULL );
  for( int i=0; i<d->len; i++ ) {
    (*cb)( d->data[i], i, stateptr );
  }
}


// dynarray_print( d, out );
//   print function - print dynarray as comma-separated, []-delimited,
//   list of elements (using the print element callback to
//   print each element)
//
void dynarray_print( dynarray d, FILE *out ) {
  assert( d->pef != NULL );
  fputs( "[ ", out );
  for( int i=0; i<d->len; i++ ) {
    if( i>0 ) fputc( ',', out );
    (*d->pef)( out, d->data[i], i );
  }
  fputs( " ]", out );
}


// dynarray_free( d );
//   free the dynarray elements (using the free element callback),
//   the data chunk, and the dynarray
//
void dynarray_free( dynarray d ) {
  if( d->fef != NULL ) {
    for( int i=0; i<d->len; i++ ) {
      (*d->fef)( d->data[i] );
    }
  }
  free( d->data );
  free( d );
}
