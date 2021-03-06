static pointer (*ftab[5])();

#define QUOTE_STRINGS_SIZE 65
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    "#(:parent :height :handle)",
    ":height",
    "send-message",
    "super",
    ":create",
    ":border-width",
    ":event-mask",
    ":parent",
    ":width",
    ":move",
    ":draw-pattern",
    ":move-handle",
    ":line",
    ":resize",
    ":flush",
    ":clear-area",
    ":y",
    ":x",
    ":fill-rectangle",
    "*gray75-gc*",
    "xflush",
    "event",
    "event-x",
    "event-y",
    ":outside",
    ":up-arrow",
    ":up-screen",
    ":handle",
    ":down-screen",
    ":down-arrow",
    ":hit-region",
    ":scroll",
    ":win-row-max",
    ":scroll-fraction",
    "#(:parent :width)",
    ":horizontal-scroll",
    ":win-col-max",
    ":horizontal-scroll-fraction",
    "\"X\"",
    "\"X\"",
    "*package*",
    "\"no such package\"",
    ":xdecl",
    "\"Xdecl.l\"",
    "require",
    "xscroll-bar",
    "\"(self class &rest args &key parent ((:height h)) handle &allow-other-keys)\"",
    "\"(self class)\"",
    "\"(self class w h)\"",
    "\"(self class &optional (newpos 0.0) (handle-size 0.1))\"",
    "\"(self class event)\"",
    ":buttonpress",
    "\"(self class event)\"",
    ":motionnotify",
    "\"(self class event)\"",
    ":buttonrelease",
    "\"(self class event)\"",
    "xhorizontal-scroll-bar",
    "\"(self class &rest args &key (parent) ((:width w)) &allow-other-keys)\"",
    "\"(self class)\"",
    "\"(self class event)\"",
    "\"(self class event)\"",
    ":xscroll",
    "\"@(#)$Id: Xscroll.l,v 1.1.1.1 2003/11/20 07:46:35 eus Exp $\"",
    "provide",
  };
