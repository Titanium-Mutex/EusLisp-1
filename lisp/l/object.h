static pointer CLO4447();
static pointer (*ftab[7])();

#define QUOTE_STRINGS_SIZE 94
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    "name",
    "vars",
    "\"#<~A #X~x\"",
    "\" ~A\"",
    "\">\"",
    "warn",
    "send",
    ":warning",
    "\"err: \"",
    "reploop",
    "\"\"",
    "cadr",
    ":all-method-names",
    ":super",
    ":cdr",
    ":put",
    ":name",
    ":get",
    "delete",
    "send-message",
    "super",
    ":prin1",
    "assoc",
    "\"\"",
    "string",
    "string-upcase",
    ":all-methods",
    "\"\"",
    ":method-names",
    ":sub",
    ":hierarchy",
    "symbol-name",
    "substringp",
    "\"\\\"\"",
    "\"\\\"\"",
    "\"@(#)$Id: object.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $\"",
    "\"LISP\"",
    "\"LISP\"",
    "*package*",
    "\"no such package\"",
    "(metaclass-name metaclass-vars)",
    "metaclass-name",
    "\"(x)\"",
    "metaclass-vars",
    "\"(x)\"",
    "object",
    "\"(self class &optional (strm t) &rest msgs)\"",
    "\"(self class format &rest mesgs)\"",
    ":error",
    "\"(self class &rest mesgs)\"",
    ":slots",
    "\"(self class)\"",
    ":methods",
    "\"(self class &optional (pattern \\\"\\\"))\nReturns the list of all methods callable by the object. If pattern is given, returns only methods with names that include pattern.\"",
    "\"(self class)\"",
    ":get-val",
    "\"(self class s)\"",
    ":set-val",
    "\"(self class s v)\"",
    ":plist",
    "propertied-object",
    "\"(self class &optional p)\"",
    "\"(self class tag)\"",
    "\"(self class tag val)\"",
    "\"(self class &optional n)\"",
    ":remprop",
    "\"(self class attr)\"",
    "\"(self class &optional (strm t) &rest msg &aux (name (send self :name)))\"",
    ":new",
    "metaclass",
    "\"(self class)\"",
    "\"(self class)\"",
    "\"(self class)\"",
    ":method",
    "\"(self class selector)\"",
    "\"(self class &optional (pat \\\"\\\"))\"",
    "\"(self class)\"",
    "\"(self class &optional (pattern \\\"\\\"))\"",
    "\"(self class)\"",
    "\"(self class)\"",
    ":cid",
    "\"(self class)\"",
    ":cix",
    "\"(self class)\"",
    "\"(self class)\"",
    ":subclasses",
    "\"(self class)\"",
    "\"(self class)\"",
    ":superclasses",
    "\"(self class)\"",
    ":add-method",
    "\"(self class new-method)\"",
    "load-module",
    "\"(self class &optional (strm t) &rest msgs)\"",
  };