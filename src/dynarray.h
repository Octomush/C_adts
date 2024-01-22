//
// dynarray.h:	a minimal dynamic generic array that can grow.
//

// Make the dynarray element type easy to change, even though all of
// this code will only currently work with void *'s.  This could help
// if cloning and modifying a specialised version of this that was
// going to be a dynarray of a builtin type like int or double..
//
#define DA_ELEMENT void *

// macro funcName(params) body
#define COPYNAME(dst,src) do { int len = strlen(src);\
	strncpy( dst, src, NAMELEN-1 );\
	if( len >= NAMELEN ) (dst)[NAMELEN-1] = '\0';\
	} while( 0 )

// "print an element" function pointer type
typedef void (*dynarray_printf)( FILE *out, DA_ELEMENT el, int pos );

// "free an element" function pointer type
typedef void (*dynarray_freef)( DA_ELEMENT el );

// "process an element" function pointer type (for "foreach")
typedef void (*dynarray_foreachf)( DA_ELEMENT el, int pos, void *stateptr );

struct dynarray
{
  DA_ELEMENT *data;    // single malloc()ed chunk of generic pointers
  int cap;	       // current allocated size of chunk (the capacity)
  int len;	       // how many elements stored in chunk (len <= cap)
  dynarray_freef fef;  // how to free an element (function pointer)
  dynarray_printf pef; // how to print an element
};

typedef struct dynarray *dynarray;		// our ADT

// Prototypes

extern dynarray dynarray_create( int cap, dynarray_printf pef, dynarray_freef fef );
extern int dynarray_len( dynarray d );
extern void * dynarray_data( dynarray d );
extern void dynarray_push( dynarray d, DA_ELEMENT element );
extern void dynarray_foreach( dynarray d, dynarray_foreachf cb, void * stateptr );
extern void dynarray_print( dynarray d, FILE * out );
extern void dynarray_free( dynarray d );
