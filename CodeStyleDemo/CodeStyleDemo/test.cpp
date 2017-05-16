

// cpp/av.h
/*
   2) There seems to be a problem handling .h-files compared to .cpp-files.
   The following problem only occurs in header-files, in source-files the
   output is as desired.
 */

static inline void foo(){
// BEFORE:
    if (cond) {
        callFunc();
    }
// DESIRED:
    if (cond) {
        callFunc();
    }
// AFTER:
    if (cond) {
        callFunc();
    }


/*
   3) The spacing around pointer stars is not always maintained as desired.
 */
// BEFORE:
    Buffer<T> *buffer;
// AFTER:
    Buffer<T> *buffer;


/*
   4) Inside of casts the types are not formatted as outside.
 */
// BEFORE:
    T *t = dynamic_cast<T*>(obj);
// AFTER:
    T *t = dynamic_cast<T*>(obj);

/*
   5) Inside some template-stuff the spacing goes weird. Multiple spaces
   are inserted, although the configuration (should) say otherwise.
 */
// BEFORE:
    for (std::map<Key, Value*>::iterator it = map.begin(); it != map.end(); it++) {
        bar(it);
    }
// AFTER:
    for (std::map < Key, Value* > ::iterator it = map.begin(); it != map.end(); it++) {
        bar(it);
    }
}

// cpp/bug_670.h
// 3456789=123456789=123456789=123456789=123456789=123456789=12
std::map<int, std::string> FOO::foo(int key, std::string value);


// cpp/bug_671.h
#define FOO_MAX 10

bool foo[FOO_MAX];

void
    foo_bar(int a,
            int *b,
            bool foo[FOO_MAX]);


// cpp/bug_i_682.h
void foo(){
    return [ = ](T * t){  };
}

// cpp/bug_i_938.h

void function(void);


// cpp/class-addr.h
class C {
public:
    A        *B;
    C       & D;
    const C & D;
    static C& D;
    public C& D;
    E = c & D;
};


// cpp/class.h
#ifndef _FOO_BAR_H_INCLUDED_
    #define _FOO_BAR_H_INCLUDED_

class CFooBarDlg : public CDialog {
// Construction
public:
    CFooBarDlg(CFooBar *pDataMan,
               CWnd *pParent = NULL);
    virtual ~CFooBarDlg();

    void Initialize(BYTE nDelay = 100);

    UINT GetCount(){ return (m_nCount); }

    void SetCount(int count = 1){
        if ((count > 0) && (count < MAX_COUNT)) {
            m_nCount = count;
        }
    }

    // Dialog Data
    // {{AFX_DATA(CATCSMgrDlg)
    enum { IDD = IDD_ATCS_MGR_DLG };
    // }}AFX_DATA

protected:
    int m_nCount;

// Overrides
// ClassWizard generated virtual function overrides
// {{AFX_VIRTUAL(CATCSMgrDlg)
protected:
    virtual void DoDataExchange(CDataExchange *pDX);   // DDX/DDV support
    // }}AFX_VIRTUAL

// Implementation

    // Generated message map functions
    // {{AFX_MSG(CATCSMgrDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnTimer(UINT nIDEvent);
    afx_msg void OnBtnSendFooBar();
    afx_msg void OnSelchangeFooBarCombo();
    // }}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#endif /* _FOO_BAR_H_INCLUDED_ */


// cpp/cmt_indent_pp.h
class MyClass : public BaseClass {
    // @{ BaseClass interface
    #if VERY_LONG_AND_COMPLICATED_DEFINE
    void foo();
    #endif // VERY_LONG_AND_COMPLICATED_DEFINE
           // @}
};

// cpp/enum_class.h
enum class A {
    a,
    b
} class B {
private:
    int x;
}
enum C {
    a,
    b
}
// cpp/enum_comma.h

void function(int a, int b, int c);

enum Test {
    A, B
    , C,
    D, E
}
// cpp/Example.h
class Example {
    Example()
        : member(0)
    {}

    int member;
};


// cpp/extern_c.h
#ifndef cRecordMarking_HEADER
    #define cRecordMarking_HEADER

    #include "DIS/cPduSnapshot.h"

typedef void*disConnectionH;

    #ifdef __cplusplus
extern "C"
    #endif // ifdef __cplusplus
{
    disConnectionH createDisConnection();

    void           setAddressAndPort_DisConnect(disConnectionH record, const char *addr);

    /* Open network connection */
    int open_DisConnect(disConnectionH record);

    /* Close network connection */
    void close_DisConnect(disConnectionH record);

    /* Send one pdu */
    int sendPdu_DisConnect(disConnectionH record, pduSnapshotH pdu);

    /* Receive one pdu */
    int  recvPdu_DisConnect(disConnectionH record, pduSnapshotH pdu);

    void FreeDisConnection(disConnectionH connection);
}
#endif // ifndef cRecordMarking_HEADER


// cpp/func_class.h
void MD5::reverse_u32(UINT8 *buf, int n_u32);

MD5::MD5();

class AlignStack {
public:
    bool m_skip_first;

    AlignStack();


    ~AlignStack();

    void End();
};


// cpp/indent_braces_no.h


class MyClass {
public:

    struct something {
        int one;
        int two;
    } MyClass(){
    }

    void oneFunction(){
        if (1 == 0) {
            instructions;
        }
    }
};


// cpp/indent_namespace.h
namespace ns1
{
void bar1(void);

class foo1 {
    int i1;
};
}

namespace ns2
{
void bar2(void);

class foo2 {
    int i2;
};
}

namespace
{
void bar3(void);
class foo3 {
    int i3;
};
}


// cpp/indent_namespace2.h
namespace ns1
{
namespace ns2
{
namespace ns3
{
using namespace foo::os;

class foo2 {
    int i2;
};
}
}
}


// cpp/init_align.h
struct file_lang languages[] =
{
    { ".c", "C", LANG_C },
    { ".cpp", "CPP", LANG_CPP },
    { ".d", "D", LANG_D },
    { ".cs", "CS", LANG_CS },
    { ".vala", "VALA", LANG_VALA },
    { ".java", "JAVA", LANG_JAVA },
    { ".pawn", "PAWN", LANG_PAWN },
    { ".p", "", LANG_PAWN },
    { ".sma", "", LANG_PAWN },
    { ".inl", "", LANG_PAWN },
    { ".h", "", LANG_CPP },
    { ".cxx", "", LANG_CPP },
    { ".hpp", "", LANG_CPP },
    { ".hxx", "", LANG_CPP },
    { ".cc", "", LANG_CPP },
    { ".di", "", LANG_D },
    { ".m", "OC", LANG_OC },
    { ".sqc", "", LANG_C }, // embedded SQL
};


// cpp/nl-class.h
#ifndef NL_CLASS_H_INCLUDED
    #define NL_CLASS_H_INCLUDED

    #include <string>

namespace example
{
class IStreamable;
class InStream;
class OutStream;

/**
 * Timestamp is a timestamp with nanosecond resolution.
 */
class Inher
    : public IStreamable {
public:
    Inher();
    virtual ~Inher();
};

/**
 * Timestamp is a timestamp with nanosecond resolution.
 */
class Inher2
    : public IStreamable {
public:

    Inher2();
    Inher2(long sec, unsigned long nsec);
};

class Simple {
public:

    Simple();
    virtual ~Simple();
};

class Simple2 {
public:

    Simple2();
    virtual ~Simple2();
};
} // namespace

#endif   // NL_CLASS_H_INCLUDED


// cpp/nl-namespace.h
namespace ns1
{
void* foo(void);
void bar(void);
}

namespace ns2
{
void* foo(void);
void bar(void);
}


// cpp/nl_before_after.h
namespace A
{
namespace S
{
class C {
public:
    virtual ~C(){
    }

    virtual void addSearch(const int &col) = 0;

    virtual void removeSearch(int id) = 0;
};
}   // namespace S
} // namespace A


// cpp/sf.3315874.h
#undef dot
#undef cross

extern "C" {
#include "data_types.h"
}
vec_ operator+ (const vec_&, const vec_&);            /* v = v1 + v2   */
vec_ operator- (const vec_&, const vec_&);            /* v = v1 - v2    */
mat_ operator+ (const mat_&, const mat_&);            /* m = m1 + m2    */
mat_ operator- (const mat_&, const mat_&);            /* m = m1 - m2    */
vec_& operator+= (vec_&, const vec_&);                /* v += v2    */
mat_& operator+= (mat_&, const mat_&);                /* m += m2    */
vec_& operator-= (vec_&, const vec_&);                /* v -= v2    */
mat_& operator-= (mat_&, const mat_&);                /* m -= m2    */
vec_ operator* (double, const vec_&);                 /* v = a * v1     */
mat_ operator* (double, const mat_&);                 /* m = a * m1     */
vec_ operator* (const vec_&, double);                 /* v = v1 * a    */
mat_ operator* (const mat_&, double);                 /* m = m1 * a    */
vec_ operator/ (const vec_&, double);                 /* v = v1 / a    */
mat_ operator/ (const mat_&, double);                 /* m = m1 / a  */
vec_ operator*= (vec_&, const double a);              /* v *= a     */
vec_ operator/= (vec_&, const double a);              /* v /= a       */
vec_ operator* (const mat_&, const vec_&);            /* v = m1 * v1  */
mat_ operator* (const mat_&, const mat_&);            /* m = m1 * m2  */
quat_ operator* (const quat_&, const quat_&);         /* q = q1 * q2  */
quat_ operator* (double, const quat_&);               /* q = a * q1  */
quat_ operator* (const quat_&, double);               /* q = q1 * a  */
quat_ operator/ (const quat_&, double);               /* q = q1 / a  */
vec_ operator- (const vec_&);                         /* v = - v1    */
vec_ operator+ (const vec_&);                         /* v = + v1    */
mat_ operator- (const mat_&);                         /* m = - m1    */
mat_ operator+ (const mat_&);                         /* m = + m1    */
quat_ operator+ (const quat_&);                       /* q = + q    */
quat_ operator- (const quat_&);                       /* q = - q    */
quat_& operator*= (quat_&, const quat_&);             /* q1 *= q2;  */
quat_& operator+= (quat_&, const quat_&);             /* q1 += q2;  */
quat_& operator*= (quat_&, const double a);           /* q1 *= a;   */
quat_ operator+ (const quat_& q1, const quat_& q2);   /* q3  = q1 + q2  */
vec_   unit(const vec_&);                             /* unitize vec    */
quat_  unit(const quat_&);                            /* unitize quat   */
mat_   trans(const mat_&);                            /* transpose matrix  */
quat_  trans(const quat_&);                           /* transpose quat   */
double dot(const vec_, const vec_);                   /* vector dot product  */
vec_   cross(const vec_, const vec_);               /* vector cross product  */


// cpp/sim.h
namespace ns
{
template<typename T, template<typename> class TOtherClass> class Example {
    int foo;
}
}

template<class T> class Example {
    T getValue() const;

    /** A pointer to a T returning function in the software environment */
    T (FunctionProvider::*pF)();
};


#if !defined(EVERYTHING_OK)
    #error Define EVERYTHING_OK if you would like to compile your code \
    or not if you would like to stop!
#endif // if !defined(EVERYTHING_OK)


template <class V>
class Example {
    Vector2<V>()
        : x(1),
        y(1)
    {}

    Vector2<double>()
        : x(1.0),
        y(1.0)
    {}

    Vector2<float>()
        : x(1.0f),
        y(1.0f)
    {}

    V x;
    V y;
};


// cpp/static.h
#ifndef AKONADISERVER_H
    #define AKONADISERVER_H

    #include <QtCore/QPointer>
    #include <QtCore/QVector>

    #include <QtNetwork/QLocalServer>

class QProcess;

namespace Akonadi
{
namespace Server
{
class AkonadiServer : public QLocalServer {
    Q_OBJECT

public:
    ~AkonadiServer();
    static AkonadiServer* instance();
};
}   // namespace Server
} // namespace Akonadi
#endif // ifndef AKONADISERVER_H


// cpp/templ_class.h
template<typename T, template<typename> class SpecialClass>
class Example {
    // Copy constructor with other variants of Example
    template<template<typename> class OtherSpecialClass>
    Example(const Example<T, OtherSpecialClass>& other){
        // do something useful here
    }

    /** The normal member var based on the template arguments */
    SpecialClass<T> memberVar;
};


// cpp/Timestamp.h
/**
 * @file Timestamp.h
 * Definition of class example::Timestamp.
 */

#ifndef __Timestamp_h_
    #define __Timestamp_h_

    #include <string>

namespace example
{
class IStreamable;
class InStream;
class OutStream;

/**
 * Timestamp is a timestamp with nanosecond resolution.
 */
class Timestamp
    : public IStreamable {
public:

    /**
     * Default constructor.
     */
    Timestamp();

    /**
     * Constructor.
     *
     * @param sec   The seconds
     * @param nsec  The nanoseconds
     */
    Timestamp(long sec, unsigned long nsec);

    /**
     * Destructor.
     */
    virtual ~Timestamp();

    /**
     * Adds two timestamps.
     *
     * @param rhs The other timestamp
     * @return The resulting timestamp
     */
    Timestamp operator+ (const Timestamp& rhs) const;

    /**
     * Substracts two timestamps.
     *
     * @param rhs The other timestamp
     * @return The resulting timestamp
     */
    Timestamp operator- (const Timestamp& rhs) const;

    /**
     * Compares two timestamps.
     *
     * @param rhs The other timestamp
     * @return true if timestamp is smaller than the given timestamp
     */
    bool operator< (const Timestamp& rhs) const;

    /**
     * Compares two timestamps.
     *
     * @param rhs The other timestamp
     * @return true if timestamp is greater than the given timestamp
     */
    bool operator> (const Timestamp& rhs) const;

    /**
     * Compares two timestamps.
     *
     * @param rhs The other timestamp
     * @return true if timestamp is equal to the given timestamp
     */
    bool operator== (const Timestamp& rhs) const;

    /**
     * Compares two timestamps.
     *
     * @param rhs The other timestamp
     * @return true if timestamp is not equal to the given timestamp
     */
    bool operator!= (const Timestamp& rhs) const;

    /**
     * Adds an other timestamp.
     *
     * @param rhs The other timestamp
     */
    void operator+= (const Timestamp& rhs);

    /**
     * Adds milliseconds.
     *
     * @param ms The milliseconds
     * @return The resulting timestamp
     */
    Timestamp addMilliseconds(unsigned long ms) const;

    /**
     * Adds nanoseconds.
     *
     * @param ns The nanoseconds
     * @return The resulting timestamp
     */
    Timestamp addNanoseconds(unsigned long ns) const;

    /**
     * Checks if this timestamp is zero.
     *
     * @return true if timestamp is zero
     */
    bool isZero() const;

    /**
     * Gets the milliseconds.
     * @attention Negativ timestamp return zero
     *
     * @return The milliseconds
     */
    unsigned long getMilliseconds() const;

    /**
     * Divide timestamps by two.
     *
     * @return The resulting timestamp
     */
    Timestamp divideByTwo();

    /**
     * Gets the string-representation.
     *
     * @return The string representation
     */
    std::string getString() const;

    /**
     * Gets the string-representation in milliseconds.
     *
     * @return The string representation
     */
    std::string getStringMilliseconds() const;

    /**
     * Resets the timestamp.
     */
    void reset();

    /** The seconds */
    long sec;

    /** The nanoseconds */
    unsigned long nsec;

    InStream    & operator << (InStream& in);

    OutStream   & operator >> (OutStream& out) const;
};
} // namespace

#endif // __Timestamp_h_


// cpp/variadic-template.h
template<int __i, int ... _Indexes, typename _IdxHolder, typename ...
         _Elements>
struct __index_holder_impl<__i, __index_holder<_Indexes ...>,
                           _IdxHolder, _Elements ...>{
    typedef typename __index_holder_impl<__i + 1,
                                         __index_holder<_Indexes ...,
                                                        __i>,
                                         _Elements ...>::type type;
};
