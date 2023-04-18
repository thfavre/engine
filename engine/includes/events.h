#ifndef EVENTS_H
# define EVENTS_H

// # include "X11/X.h" // TODO check if it works on MAC, if yes the defines below are useless

/* Input Event Masks. Used as event-mask window attribute and as arguments
   to Grab requests.  Not to be confused with event names.  */

# define NoEventMask				0L
# define KeyPressMask				(1L<<0)
# define KeyReleaseMask				(1L<<1)
# define ButtonPressMask			(1L<<2)
# define ButtonReleaseMask			(1L<<3)
# define EnterWindowMask			(1L<<4)
# define LeaveWindowMask			(1L<<5)
# define PointerMotionMask			(1L<<6)
# define PointerMotionHintMask		(1L<<7)
# define Button1MotionMask			(1L<<8)
# define Button2MotionMask			(1L<<9)
# define Button3MotionMask			(1L<<10)
# define Button4MotionMask			(1L<<11)
# define Button5MotionMask			(1L<<12)
# define ButtonMotionMask			(1L<<13)
# define KeymapStateMask			(1L<<14)
# define ExposureMask				(1L<<15)
# define VisibilityChangeMask		(1L<<16)
# define StructureNotifyMask		(1L<<17)
# define ResizeRedirectMask			(1L<<18)
# define SubstructureNotifyMask		(1L<<19)
# define SubstructureRedirectMask	(1L<<20)
# define FocusChangeMask			(1L<<21)
# define PropertyChangeMask			(1L<<22)
# define ColormapChangeMask			(1L<<23)
# define OwnerGrabButtonMask		(1L<<24)

/* Event names.  Used in "type" field in XEvent structures.  Not to be
confused with event masks above.  They start from 2 because 0 and 1
are reserved in the protocol for errors and replies. */

# define KeyPress			2
# define KeyRelease			3
# define ButtonPress		4
# define ButtonRelease		5
# define MotionNotify		6
# define EnterNotify		7
# define LeaveNotify		8
# define FocusIn			9
# define FocusOut			10
# define KeymapNotify		11
# define Expose				12
# define GraphicsExpose		13
# define NoExpose			14
# define VisibilityNotify	15
# define CreateNotify		16
# define DestroyNotify		17
# define UnmapNotify		18
# define MapNotify			19
# define MapRequest			20
# define ReparentNotify		21
# define ConfigureNotify	22
# define ConfigureRequest	23
# define GravityNotify		24
# define ResizeRequest		25
# define CirculateNotify	26
# define CirculateRequest	27
# define PropertyNotify		28
# define SelectionClear		29
# define SelectionRequest	30
# define SelectionNotify	31
# define ColormapNotify		32
# define ClientMessage		33
# define MappingNotify		34
# define GenericEvent		35
# define LASTEvent			36	/* must be bigger than any event # */


#endif
