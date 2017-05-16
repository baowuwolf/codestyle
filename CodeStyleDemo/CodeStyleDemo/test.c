

// c/add_long_comment.c
/**
 * trailing comments are added at 8 newlines in this test.
 *
 *
 */
void short_function(void){
    /* this is a 'short' function, so no added comment */
}

void long_function(void){
    /* this is a 'long' function, so a comment is added */
    switch (some_int_value()) {
        case 0:
            handle_zero();
            break;

        case 50:
            handle_fifty();
            break;

        case 127:
            handle_another_value();
            break;

        default:
            boy_do_i_lack_imagination();
            break;
    }

    /* call one last function... */
    one_last_func_call();
}

// c/align-equ.c

// note - set threshold to three
void foo(void){
    a      = 1;
    bb     = 2;
    ccc    = 3;
    dddd   = 4;
    eeeee  = 5;
    ffffff = 6;


    a       = 1;
    eeeeee  = 5;
    fffffff = 6;


    a      = 1;
    eeeee  = 5;
    ccc    = 3;
    ffffff = 6;


    a                  = 1;
    iiiiiiiiiiiiieeeee = 5;
    ccc                = 3;
    ffffff             = 6;
}

// c/align-proto-vars.c
int doStuff(int i,
            float f);

int doStuff(int i,
            float f);


MACRO_MODIFIER int doStuff(int i,
                           float f);

typedef void (*my_callback)(int id,
                            void *context);


// c/align-proto.c
unsigned int align_here();
int this_works(int x);
int bug(int); // BUG: left-aligned


// c/align-string.c

// note - set threshold to three
void foo(void){
    printf("This is the first line\n"
           "And this is the second.\n");

    fprintf(stderr, "This is the first line\n"
            "And this is the second.\n");

    fprintf(stderr, "Format string: %s", "This is the first line\n"
            "And this is the second.\n");
}

// c/align-struct-init.c

const char *token_names[] =
{
    [CT_POUND]        = "POUND",
    [CT_PREPROC]      = "PREPROC",
    [CT_PREPROC_BODY] = "PREPROC_BODY",
    [CT_PP]           = "PP",
    [CT_ELIPSIS]      = "ELIPSIS",
    [CT_NAMESPACE]    = "NAMESPACE",
    [CT_NEW]          = "NEW",
    [CT_OPERATOR]     = "OPERATOR",
    [CT_THROW]        = "THROW",
    [CT_TRY]          = "TRY",
    [CT_USING]        = "USING",
    [CT_PAREN_OPEN]   = "PAREN_OPEN",
};


int main(int argc, char *argv[]){
    struct junk a[] = {
        { "version", 0, 0, 0},
        {"file", 1, 150, 'f'},
        {"config", 1, 0, 'c'},
        {"parsed", 25, 0, 'p'},
        { NULL, 0, 0, 0}
    };
}

color_t      colors[] = {
    {"red", {255, 0, 0}}, {"blue", {0, 255, 0}},
    {"green", {0, 0, 255}}, {"purple", {255, 255, 0}},
};

struct foo_t bar = {
    .name = "bar",
    .age  = 21
};


struct foo_t bars[] = {
    [0] = { .name = "bar",
            .age  = 21 },
    [1] = { .name = "barley",
            .age  = 55 },
};


// c/align-typedef.c

typedef int MY_INT;
typedef int*MY_INTP;
typedef int (*foo_t)(void *bar);
typedef int (*somefunc_t)(void *barstool);
typedef int int8_t __attribute__((__mode__(__QI__)));
typedef int uint8_t;
typedef struct _IDirectFBSurface IDirectFBSurface;
typedef struct _IDirectFBPalette IDirectFBPalette;
typedef struct timezone*__restrict __timezone_ptr_t;


// c/align-var.c
struct foo1 {
    unsigned int d_ino;
    const char *d_reclen;
    unsigned short d_namlen;
    char d_name[1];
};

struct foo2 {
    unsigned int a : 1;
    unsigned int bcd : 3;
    unsigned int ef : 2;
    unsigned int : 2;

    unsigned short more;

    int fields;
};

typedef struct {
    bitfld a : 8;
    bitfld b : 16;
    bitfld : 8;
} type_t;

struct foo { int a; char *b };

static int           idx;
static const char  **tmp;

static char          buf[64];
static unsigned long how_long;
// comment
static int         **tmp;
static char          buf[64];


void bar(int someval,
         void *puser,
         const char *filename,
         struct willy *the_list,
         int list_len){
    int           idx;
    const char  **tmp;
    char          buf[64];

    unsigned long how_long;

    return(-1);
}

// c/align_attr.c

char                       test[3] _PREPROCESSOR_SOMETHING;
int numberThatIsReallyCool _PREPROCESSOR_SOMETHING;


// c/align_keep_extra.c
void f(){
    int x = 3;
    int b = 4;
}

// c/asm.c
void foo(void){
    asm __volatile__ (
        "subl %2,%0\n\t"
        "sbbl %3,%1"
        : "=a" (l), "=d" (h)
        : "g" (sl), "g" (sh),
        "0" (l), "1" (h));
}

// c/backslash-newline-lex.c
void f (){
    g ("\
");
    g ("\n", stdout);
}

// c/beautifier-off.c


#define FOO(bar) create_a_really_long_identifier name(some_function(bar1 + bar2), bar3, bar4);

/* *INDENT-OFF* */
   int foo[] = {
      1,   3,   5,
      3,   5,   7,
      5,   7,   9,
   };
/* *INDENT-ON* */

#define multilinemacro \
    do { (x + 5); } while (0); \
    printf("a multilinemacro"); \
    printf("a multilinemacro2");

int main(int argc, char *argv[]){
/* *INDENT-OFF* */

   int a, b;
a = 1; // stupid comment \
b = 2;

/* *INDENT-ON* */
    return(a + b);
}

/* *INDENT-OFF* */
int a;
/* *INDENT-ON* */


// c/bits.c
struct foo {
    unsigned long bar;
    u_int ndots : 4,
          nsort : 4,
    : 0;
};


// c/bool-pos.c
void foo(void){
    if ((a != 0) &&
        (b == 0) &&
        (c < 0) && (d > 0)) {
        printf("hi");
    }

    if (flag1
        #ifdef FLAG2
        || flag2
        #endif /* ifdef FLAG2 */
        ) {
        printf("yar");
    }

    if (flag1 &&
        #ifdef FLAG2
        flag2 &&
        #endif /* ifdef FLAG2 */
        flag3) {
        printf("bo");
    }

    if ((a != 0)
        && (b == 0)
        && (c < 0)) {
        printf("hi");
    }

    if ((a != 0)
        &&
        (b == 0)
        &&
        (c < 0)) {
        printf("hi");
    }

    if (!this->writeOwiFile () ||               // comment1
        broken () || !saveArchiveData ()        /* comment2 */
        || broken () || !deleteCentralArchive () // comment3
        || broken () || !copyArchivFiles ()     // comment4
        || broken () || !appendToPlanetDb ()) { // comment5
    }

    foobar(param1,
           param2, param3,
           param4);

    foobar2(param1
            , param2, param3
            , param4);
} /* foo */

// c/br_cmt.c
int main(){
    if (foo == bar) { /* this works */
        a;
    } else if (ranz != bar) { /* this works too */
        b;
    } else { /* this is broken */
        c;
    }
}

// c/brace-remove.c

void foo(void){
    int a = 0;
    while (a < 3) {
        a++;
    }

    while (b < a) {
        b++;
    }

    do {
        a--;
    } while (a > 0);

    for (a = 0; a < 10; a++) {
        printf("a=%d\n", a);
    }

    if (a == 10) {
        printf("a looks good\n");
    }

    if (state == ST_RUN) {
        if ((foo < bar) &&
            (bar > foo2)) {
            if (a < 5) {
                a *= a;
            }
        }
    }

    while (*ptr++ != ',') {
    }
}

// mod_full_brace_for = remove should not remove the braces in this example:
int main(){
    if (true) {    // indent=1
        for (int i = 0; i < 3; i++) {
            if (false) {
                continue; // indent=4
            }
        }
    } else {
        return;    // indent=2
    }
}

// mod_full_brace_if = remove should not remove the braces in this example:
int main(){
    if (true) {
        for (int i = 0; i < 3; i++) {
            if (false) {
                continue; // indent=4
            }
        }
    } else {
        return;    // indent=2
    }
}

int main(){
    while (1) {
        if (0) {
            break;
        }
        switch (1) {
            case 1:
                break;
        }
    }

    return 0;
}

// c/brace-remove2.c
/* else is tied to if(two) */
int main(){
    if (one) {
        if (two) {
            sleep (1);
        } else {
            sleep (2);
        }
    }

    if (three) {
        sleep(1);
    } else if (four) {
        sleep(2);
    }
}

/* else is tied to if(one) */
int main(){
    if (one) {
        if (two) {
            sleep (1);
        }
    } else {
        if (three) {
            sleep (2);
        }
    }
}

/* else.1 is tied to if(two), else.2 is tied to if(one) */
int main(){
    if (one) {
        if (two) {
            sleep (1);
        } else {
            if (three) {
                sleep (2);
            }
        }
    } else {
        sleep (3);
    }
}

int main(){
    if (read_write == I2C_SMBUS_READ) {
        msg[1].len = I2C_SMBUS_I2C_BLOCK_MAX;
    } else {
        msg[0].len = data->block[0] + 1;
    }
}

// c/brace-remove3.c
void foo(){
    if (myBoolean) {
        #ifdef DEBUG
        printf("ACK");
        #endif /* ifdef DEBUG */
    }

    return true;
}

void foo2(){
    if (m_errno == ERR_NONE) {
        function1(variables);
        function2(variables);
    } else {
        function1(varialbes);
    }
    // MyComment1
    // MyComment2
}

void foo3(){
    if (statment) {
        if (statment) {
            condition;

            return true;
        }
    }

    return false;
}

// c/brace.c


int function(int arg){
    int i;
    for (i = 0; i<5; i++) {
        /* Do something... */
    }
    if (i<0) {
        /*Do something else...*/  }

    return 0;
}

// c/braces-2.c
while (a >= 0) {
    if (b) {
        for (j = 0; j < 10; j++) {
            if (j == b) {
                return;
            }
            a++;
        }
    }
    b--;
}


// c/braces-3.c
{
    list_for_each(k){
        if (a) {
            if (b) {
                c++;
            }
        }
    }
}


// c/braces-4.c
int foo(int bar){
    #ifndef CONFIG_1
    bar -= 3;
    #else /* ifndef CONFIG_1 */
    for (j = 0; j < NR_CPUS; j++) {
        if (cpu_online(j)) {
            bar++;
        }
    }
    #endif /* ifndef CONFIG_1 */

    return 0;
}

// c/braces-5.c
/**
 * this is a really tough case - perhaps we shouldn't keep any #if crap
 * unless they all end with the same stack?
 */
void foo(void){
    int a;
    #ifdef CONFIG_BLK_DEV_INITRD
    if (initrd_start) {
        ROOT_DEV = Root_RAM0;
    }
    #elif defined(CONFIG_ROOT_NFS)
    ROOT_DEV = Root_NFS;
    #elif defined(CONFIG_BLK_DEV_IDEDISK)
    ROOT_DEV = Root_HDA1;
    #else /* ifdef CONFIG_BLK_DEV_INITRD */
    ROOT_DEV = Root_SDA1;
    #endif /* ifdef CONFIG_BLK_DEV_INITRD */
}

// c/braces.c

void foo(void){
    int a = 0;
    while (a < 3) {
        a++;
    }

    while (b < a) { // trailing C++ comment
        b++;
    }

    do { // trailing C++ comment
        a--;
    } while (a > 0);

    do {
        a--;
    } while (a > 0);

    for (a = 0; a < 10; a++) { // trailing C++ comment
        printf("a=%d\n", a);
    }

    if (a == 10) { // trailing C++ comment
        printf("a looks good\n");
    } else { // trailing C++ comment
        printf("not so good\n");
    }

    if (state == ST_RUN) {
        if ((foo < bar) &&
            (bar > foo2)) {
            if (a < 5) {
                a *= a;
            } else if (b != 0) {
                a /= b;
            } else { // trailing C++ comment
                a += b;
            }
        }
    }

    list_for_each(k){
        if (a) {
            if (b) {
                c++;
            }
        }
    }


    while (1) {
        /* hang forever */
    }
} /* foo */

void f(){
    if (buf[0] == '~' && strchr(tmp, '/') == NULL) {
        buf     = mallocstrcpy(buf, tmp);
        matches = username_tab_completion(tmp, &num_matches);
    }
    /* If we're in the middle of the original line, copy the string
       only up to the cursor position into buf, so tab completion
       will result in buf's containing only the tab-completed
       path/filename. */
    else if (strlen(buf) > strlen(tmp)) {
        buf = mallocstrcpy(buf, tmp);
    }
}

void f(){}
void g(){}


// c/bsnl.c
# define SOME_MACRO \
    bool has_err; \
    bool is_comp; \
    struct some_stream ostream


// c/bug_1041.c
void (*g_func_table[32])(void) = {
    [0 ... 31] = func_dummy,
    [0]        = func_0,
    [1]        = func_1,
    [2]        = func_2,
};


// c/bug_489.c
#define UHI_AOA \
    { \
        .install    = uhi_aoa_install, \
        .enable     = uhi_aoa_enable, \
        .uninstall  = uhi_aoa_uninstall, \
        .sof_notify = NULL, \
    }

// c/bug_671.c
#define FOO_MAX 10

bool foo[FOO_MAX];

void
foo_bar(int a,
        int *b,
        bool foo[FOO_MAX]);

void A(){
    int a;
    int *b;
    foo_bar(a, b, foo);
}

// c/bug_i_222.c
whatever* find_node_for_address(whatever2 *foo,
                                thingy *bar,
                                whatever3*(func_ptr)(
                                    whatever4 * foo2,
                                    thingy2 * bar2));
// 3456789=123456789=123456789=123456789=123456789=12


// c/bug_i_771.c
typedef struct Foo_s {
    int a;
    int *b;
    float **c;
    bool *******d;
    FooBar ***A;
    FoBar ***B;
}FooS;

typedef struct Foo_a {
    int a;
    int *b;
    float **c;
    bool *******d;
    FooBar ***A;
    FoBar ***B;
}FooA;


// c/bug_i_876.c
#define A 1


// c/bugs-1.c
int oldfoo(bar)
char bar;
{
    return bar - 2;
}

int i2c_use_client(struct i2c_client *client){
    int ret;

    ret = i2c_inc_use_client(client);
    if (ret) {
        return ret;
    }

    if ((client->flags & I2C_CLIENT_ALLOW_USE) || (a &&
                                                   something_else)) {
        if (client->flags & I2C_CLIENT_ALLOW_MULTIPLE_USE) {
            client->usage_count++;
        } else if (client->usage_count > 0) {
            goto busy;
        } else {
            client->usage_count++;
        }
    }

    return 0;
busy:
    i2c_dec_use_client(client);

    return -EBUSY;
}

void get_name(void){
    a = (int)5;

    if (a) {
        if (b) {
            b--;
        } else {
            a++;
        }
    }
    for (a = 0; a < 10; a++) {
        if (b) {
            b--;
        } else {
            a++;
        }
    }
}

// c/bugs-2.c
static void tcps_proc_server_msg(void *p_user, const ptc_msg_info_t *p_info){
    if (z) {
        if (a) {
            /* comment */
            a++;
        }
        /* comment */
        else if (b) {
            b++;
        }
        /* Comment */
        else {
            c++;
        }
    }
}

// c/bugs-3.c

#ifdef CRUD
    #define JUNK a
#endif /* ifdef CRUD */

#ifdef __QNX__
/**
 * Does all that QNX trickery to get the MAC address of the interface
 *
 * @param if_name The interface name: ie "en0" or "eth0"
 * @param mac     Pointer to a 6-byte array
 * @return        SUCCESS or FAILURE
 */
static INT32 socket_get_mac_qnx(const CHAR *if_name, UINT8 *mac){
    CHAR ionet_name[50];
    INT32 en_fd;
    #if QNX_RELEASE >= 630
    nic_config_t nic;
    INT32 dcmd = DCMD_IO_NET_GET_CONFIG;
    #else /* if QNX_RELEASE >= 630 */
    Nic_t nic;
    INT32 dcmd = DCMD_IO_NET_NICINFO;
    #endif /* if QNX_RELEASE >= 630 */
    INT32 ret_val = FAILURE;

    memset(mac, 0, 6);

    /* Build the full name */
    snprintf(ionet_name, sizeof(ionet_name), "/dev/io-net/%s", if_name);

    /* Open the device */
    en_fd = open(ionet_name, O_RDWR);
    if (en_fd >= 0) {
        /* Get the interface info */
        if (devctl(en_fd, dcmd, &nic, sizeof(nic), NULL) == EOK) {
            memcpy(mac, nic.current_address, 6);
            ret_val = SUCCESS;
        }

        close(en_fd);
    }

    return(ret_val);
}

#endif /* ifdef __QNX__ */


// c/bugs-4.c

static void set_md_connected(CHAR *msg_data){
    UINT32 rd_idx = 0;
    CHAR mobile_device_id[MOBILE_DEVICE_NAME_LEN];
    CHAR ip_addr[IP_ADDRESS_LEN];
    CHAR mac_addr[MAC_ADDR_LEN];
    CHAR ap_name[AP_NAME_LEN];

    rdc_strz(msg_data, MAX_SIZE, &rd_idx, mobile_device_id, 0);
    rdc_strz(msg_data, MAX_SIZE, &rd_idx, ip_addr, 0);
    rdc_strz(msg_data, MAX_SIZE, &rd_idx, mac_addr, 0);
    rdc_strz(msg_data, MAX_SIZE, &rd_idx, ap_name, 0);

    #if defined (DB_MGR_ORACLE)
    (void)db_set_md_connected(mobile_device_id, ip_addr, mac_addr, ap_name);
    LOG(LFTR, "CONNECTED Loco %s, IP Addr %s,MAC Addr %s, AP Name %s",
        mobile_device_id, ip_addr, mac_addr, ap_name);
    #elif defined (DB_MGR_FILE)
    LOG(LFTR, "%s CONNECTED Loco %s, IP Addr %s,MAC Addr %s, AP Name %s",
        status_str, mobile_device_id, ip_addr, mac_addr, ap_name);
    #else /* if defined (DB_MGR_ORACLE) */
    #error Unknown device type must be DB_MGR_ORACLE or DB_MGR_FILE
    #endif /* if defined (DB_MGR_ORACLE) */
}

// c/bugs-5.c

static void log_roll_file(log_output_t *plo){
    INT32 retcode;
    const CHAR *name_save;
    const CHAR *name_temp;

    if (plo->pfile != NULL) {
    }
}

// c/bugs-6.c
/*=-------------------------------------------------------------------------=*\
*
|  FUNCTION NAME: mult2
|
|  DESCRIPTION:
|     Multiplies a number by two.
|
|  INPUTS/OUTPUTS:
|     val - the number to double
|
|  RETURNS:
|     val * 2
*
\*=-------------------------------------------------------------------------=*/
int mult2(int val){
    return val * 2;
}

// c/bugs-7.c

struct somestruct*
mult2(int val);

somestruct*
dumb_func(int val);


struct somestruct*
mult2(int val){
    int a;

    a = val + (foo * bar);

    a = val + (bar);

    a = val + (CFoo::bar_t)7;

    a = val + (myfoo.size);

    return NULL;
}

// c/bugs-8.c

void foo(void){
    p[0].x = x + (rx * cos(rs));
    p[0].y = y - (ry * sin(rs));
}

// c/bugs.c
typedef struct {
    int a;
    char b;
} foo_t;

s32 i2c_smbus_read_i2c_block_data(struct i2c_client *client, u8 command, u8 *values){
    union i2c_smbus_data data;
    int i;
    if (i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                       I2C_SMBUS_READ, command,
                       I2C_SMBUS_I2C_BLOCK_DATA, &data)) {
        return -1;
    } else {
        for (i = 1; i<=data.block[0]; i++) {
            values[i - 1] = data.block[i];
        }

        return data.block[0];
    }
}

void foo(void){
    adap->nr = id & MAX_ID_MASK;

    list_for_each(item, &drivers){
        driver = list_entry(item, struct i2c_driver, list);
        if (driver->detach_adapter) {
            if ((res = driver->detach_adapter(adap))) {
                dev_err(&adap->dev, "detach_adapter failed "
                        "for driver [%s]\n", driver->name);
                goto out_unlock;
            }
        }
    }
}

// c/case.c
void foo(void){
    switch (ch) {
        // handle 'a'
        case 'a': {
            handle_a();
            multiline(123,
                      345);
            break;
        }

        // handle 'b'
        case 'b':
            handle_b();
            multiline(123,
                      345);
            break;

        // handle 'c' and 'd'
        case 'c':
        case 'd':
            // c and d are really the same thing
            handle_cd();
            multiline(123,
                      345);
            break;

        case 'e': {
            handle_a();
            multiline(123,
                      345);
        }
        break;

        // case1
        case (case1): {
            // do stuff
            break;
        }

        case (case2): {
            // do stuff
            break;
        }

        case (case3):

            /*do stuff*/
            break;

        case (case3):
            statement();
            {
                another_statement();
            }
            break;

        // really should not get here
        default:
            handle_default();
            multiline(123,
                      345);
            break;
    } /* switch */
    multiline(123,
              345);
} /* foo */

// c/cast_brace.c
//
void disappearing_semicolon(void){
    r = (recordtypecast){a, b, c}; // <--
    p = Table_put(t, a, &r);
}

// c/casts.c

#define SOME_VAL1  ((MYINT)-1)
#define SOME_VAL2  (-2)
#define SOME_VAL3  -3
#define MULT(X, Y) (X)*(Y)
#define SOME_JUNK  /*lint -e123 */ (const mytype*)-1

typedef (*my_fcn_ptr_t)(char*, int);
typedef (my_fcn_t)(char*, int);

void foo(void){
    uint crc = crc32_calc_full((const UINT8*)"String", 6);

    crc = crc32_calc_full((const UINT8*)&crc, sizeof(crc));

    a = (b) - 4;

    a = (UINT)-4;
    a = (UINT)+4;
    a = (UINT) * 4;
    a = (UINT) & 4;

    a = (uint32_t)-pb;
    a = (uint32_t) + pb;
    a = (uint32_t)*pb;
    a = (uint32_t)&pb;

    a = (Uint) - 4;
    a = (Uint) + 4;
    a = (Uint) * 4;
    a = (Uint) & 4;

    a = b * (int)flt;
    a = b * ((int)flt);

    a = b * (int)flt;
    a = b * (INT8)flt;
    a = b * (Uint)flt;

    a = *(int)&b;
    a = *(CHAR)&b;
    a = *(Uint) & b;

    a = (int)*pb;
    a = (CHAR)*pb;
    a = (Uint) * pb;

    a = (int)'a';
    a = (UINT8)'a';
    a = (Uint)'a';

    a = (int)*'a';
    a = (UINT8) * 'a';
    a = (Uint) * 'a';

    a = (int)*5;
    a = (UINT) * 5;
    a = (Uint) * 5;

    a = (int)*ape;
    a = (UINT)*ape;
    a = (Uint) * ape;

    a = (int)ape;
    a = (UINT)ape;
    a = (Uint)ape;

    a = (int)sizeof(x);
    a = (INT16)sizeof(x);
    a = (Uint)sizeof(x);

    a = (int)foo(x);
    a = (CHAR)foo(x);
    a = (Uint)foo(x);

    a = (int)(x);
    a = (CHAR)(x);
    a = (Uint)(x);

    a = (int)*(x);
    a = (CHAR)*(x);
    a = (Uint) * (x);

    a = (unsigned int)(1 + 4);
    a = (int)(1 + 1);
    a = (void*)(&str);
} /* foo */

// c/cmt-align.c
#ifndef HAVE_FOO
void foo(void){
    if (bar) {
        call_some_function(); /* call the function */
        return(foo); /* comment */
    }      /* if (bar) */
}

#endif /* HAVE_FOO */
#ifndef HAVE_BAR /* bar isn't available on all HW */
void bar(void){
    if (foo) {
        call_some_function(); /* call the function */
        return(foo); /* comment */
    } /* if (foo) */
}

#endif /* HAVE_BAR */


// c/cmt_multi.c
/************************************************
* This is a multiline comment.
* The first and last lines are the same length
************************************************/

/****************************************************************************
    A multi-line comment that is broken in two parts.
*//**
    Second part
****************************************************************************/

/****************************************************************************
    A multi-line comment that is broken in two parts.
*/         /**
    Second part
****************************************************************************/


// c/cmt_multi_utf8.c
/* This is a multiline comment with a UTF8 character: á
 */


// c/cmt_nl_end.c
int do_this
(
    int x,
    int y
){
    x += y;             // x = x + y
    if (x == 3) {
        x++;    // x plus 1
    }

    return (x)
}

// c/cmt_right_align.c

int foo1(int bar){
    if (bar) {
        if (b) {
            if (a) {
                if (r) {
                    return(r);  /* cool */
                } else { /* if (r) */
                    return(bar); /* uncool */
                } /* if (r) */
            } /* if (a) */
        } /* if (b) */
    } /* if (bar) */

    return(-1);
} /* foo */

int foo2(int bar){
    if (bar) {
        if (b) {
            if (a) {
                if (r) {
                    return(r);
                } else {
                    return(bar);
                } /* if (r) */
            } /* if (a) */
        } /* if (b) */
    } /* if (bar) */

    return(-1);
} /* foo */

// c/code_width.c

static int short_function_name(struct device *dev, struct device_driver *drv);

/* Assuming a 60-column limit */
static int short_function_name(struct device *dev, struct device_driver *drv){
    this->translateLabels(labelID, completedLabelID, selectedLabelID, text, selectedText, completedText, fontId, selectedFontId, completedFontId);
    call_some_really_long_function.of_some_sort(some_long_parameter1, some_long_parameter2);

    abc = call_some_other_really_long_function.of_some_sort(some_long_parameter1, some_long_parameter2);

    abc.def.ghi = call_some_other_really_long_function.of_some_sort(some_long_parameter1, some_long_parameter2);

    abcdefghijklmnopqrstuvwxyz = abc + def + ghi + jkl + mno + prq + stu + vwx + yz;

    return 1;
}

typedef xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx yyyyyyyyyyyyyyyyyyyyyy;

typedef some_return_value (*some_function_type)(another_type parameter1, another_type parameter2);

typedef struct xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx {
    int yyyyyyyyyyyyyyyyyyyyyy;
} x_t;

static void some_really_long_function_name(struct device *dev, struct device_driver *drv){
    if ((some_variable_name && somefunction(param1, param2, param3))) {
        asdfghjk = asdfasdfasd.aasdfasd + (asdfasd.asdas * 1234.65);
    }

    for (struct something_really_really_excessive *a_long_ptr_name = get_first_item(); a_long_ptr_name != NULL; a_long_ptr_name = get_next_item(a_long_ptr_name)) {
    }

    for (a = get_first(); a != NULL; a = get_next(a)) {
    }

    for (a_ptr = get_first(); a_ptr != NULL; a_ptr = get_next(a)) {
    }

    register_clcmd("examine", "do_examine", -1, "-Allows a player to examine the health and armor of a teammate");
    register_clcmd("/examine", "do_examine", -1,
                   "-Allows a player to examine the health and armor of a teammate");
}

// c/colon-asm.c
static void
__marvel_access_rtc(void *info){
    struct marvel_rtc_access_info *rtc_access = info;

    register unsigned long __r0 __asm__("$0");
    register unsigned long __r16 __asm__("$16") = rtc_access->function;
    register unsigned long __r17 __asm__("$17") = rtc_access->index;
    register unsigned long __r18 __asm__("$18") = rtc_access->data;

    __asm__ __volatile__ (
        "call_pal %4 # cserve rtc"
        : "=r" (__r16), "=r" (__r17), "=r" (__r18), "=r" (__r0)
        : "i" (PAL_cserve), "0" (__r16), "1" (__r17), "2" (__r18)
        : "$1", "$22", "$23", "$24", "$25");

    rtc_access->data = __r0;
}

// c/comment-convert.c
// This is your typical header comment
int foo(int bar){
    int idx;
    int res = 0;     // trailing comment
                     // that spans two lines


    // Comment with embedded /* C comment */
    for (idx = 1; idx < bar; idx++) {
        /* comment in virtual braces */
        res += idx;
    }

    // Multi-line comment with embedded /* C comment */ and junk
    // afterwards
    res *= idx;       // some comment

    // almost continued, but a NL in between

// col1 comment in level 1

// second comment
    return(res);
}

// col1 comment in level 0
// and another


// c/comment-indent.c
/**
 * This is your typical header comment
 */
int foo(int bar){
    int idx;
    int res = 0;     // trailing comment
                     // that spans two lines
    for (idx = 1; idx < bar; idx++) {
        /* comment in virtual braces */
        res += idx;
    }

    res *= idx;       // some comment

    // almost continued, but a NL in between

// col1 comment in level 1

// second comment
    return(res);
}

// col1 comment in level 0
// and another

void foo(){
    if (bar) {
        foo();
    }
    /*else if( bar2 )
       {
       foo2();
       }
     */else if (bar3) {
        foo3();
    }
}

// c/cond.c

int foo1(bool b, int tv, int fv){
    return b?tv:fv;
}

int foo2(bool b, int tv, int fv){
    return b?tv:fv;
}

// c/custom_types_ssl.c
#ifndef  HEADER_CONF_H
    #define HEADER_CONF_H

    #ifdef  __cplusplus
extern "C"
    #endif /* ifdef  __cplusplus */
{
    typedef struct {
        char *section;
        char *name;
        char *value;
    } CONF_VALUE;

    DECLARE_STACK_OF(CONF_VALUE);
    DECLARE_LHASH_OF(CONF_VALUE);

    struct conf_st;
    struct conf_method_st;
    typedef struct conf_method_st CONF_METHOD;

    int CONF_set_default_method(CONF_METHOD *meth);
    void CONF_set_nconf(CONF *conf, LHASH_OF(CONF_VALUE) *hash);
    LHASH_OF(CONF_VALUE) * CONF_load(LHASH_OF(CONF_VALUE) * conf, const char *file,
                                     long *eline);
    #ifndef OPENSSL_NO_FP_API
    LHASH_OF(CONF_VALUE) * CONF_load_fp(LHASH_OF(CONF_VALUE) * conf, FILE * fp,
                                        long *eline);
    #endif /* ifndef OPENSSL_NO_FP_API */
    LHASH_OF(CONF_VALUE) * CONF_load_bio(LHASH_OF(CONF_VALUE) * conf, BIO * bp, long *eline);
    STACK_OF(CONF_VALUE) * CONF_get_section(LHASH_OF(CONF_VALUE) * conf,
                                            const char *section);
    char* CONF_get_string(LHASH_OF(CONF_VALUE) *conf, const char *group,
                          const char *name);
    long CONF_get_number(LHASH_OF(CONF_VALUE) *conf, const char *group,
                         const char *name);
    void CONF_free(LHASH_OF(CONF_VALUE) *conf);
    int CONF_dump_fp(LHASH_OF(CONF_VALUE) *conf, FILE *out);
    int CONF_dump_bio(LHASH_OF(CONF_VALUE) *conf, BIO *out);
}


void CONF_set_nconf(CONF *conf, LHASH_OF(CONF_VALUE) *hash){
    if (default_CONF_method == NULL) {
        default_CONF_method = NCONF_default();
    }

    default_CONF_method->init(conf);
    conf->data = hash;
}

LHASH_OF(CONF_VALUE) * CONF_load(LHASH_OF(CONF_VALUE) * conf, const char *file,
                                 long *eline){
    LHASH_OF(CONF_VALUE) * ltmp;
    BIO *in = NULL;

    #ifdef OPENSSL_SYS_VMS
    in = BIO_new_file(file, "r");
    #else /* ifdef OPENSSL_SYS_VMS */
    in = BIO_new_file(file, "rb");
    #endif /* ifdef OPENSSL_SYS_VMS */
    if (in == NULL) {
        CONFerr(CONF_F_CONF_LOAD, ERR_R_SYS_LIB);

        return NULL;
    }

    return ltmp;
}

    #ifndef OPENSSL_NO_FP_API
LHASH_OF(CONF_VALUE) * CONF_load_fp(LHASH_OF(CONF_VALUE) * conf, FILE * fp,
                                    long *eline){
    BIO *btmp;
    LHASH_OF(CONF_VALUE) * ltmp;
    if (!(btmp = BIO_new_fp(fp, BIO_NOCLOSE))) {
        CONFerr(CONF_F_CONF_LOAD_FP, ERR_R_BUF_LIB);

        return NULL;
    }
    ltmp = CONF_load_bio(conf, btmp, eline);
    BIO_free(btmp);

    return ltmp;
}
    #endif /* ifndef OPENSSL_NO_FP_API */

LHASH_OF(CONF_VALUE) * CONF_load_bio(LHASH_OF(CONF_VALUE) * conf, BIO * bp,
                                     long *eline){
    CONF ctmp;
    int ret;

    CONF_set_nconf(&ctmp, conf);

    ret = NCONF_load_bio(&ctmp, bp, eline);
    if (ret) {
        return ctmp.data;
    }

    return NULL;
}

STACK_OF(CONF_VALUE) * CONF_get_section(LHASH_OF(CONF_VALUE) * conf,
                                        const char *section){
    if (conf == NULL) {
        return NULL;
    } else {
        CONF ctmp;
        CONF_set_nconf(&ctmp, conf);

        return NCONF_get_section(&ctmp, section);
    }
}

char* CONF_get_string(LHASH_OF(CONF_VALUE) *conf, const char *group,
                      const char *name){
    if (conf == NULL) {
        return NCONF_get_string(NULL, group, name);
    } else {
        return NCONF_get_string(&ctmp, group, name);
    }
}

// c/define-if-indent.c

    #define foobar(x) \
    { \
        for (i = 0; i < x; i++) \
        { \
            junk(i, x); \
        } \
    }


// c/deref.c
void foo(int *pA, int *pB){
    *pB = some.arr[*pA];

    foo(sizeof bar / sizeof *bar, baz);
}

    #define MEM_READ_BYTE(phwi, addr, data)                   \
    *data = *((PUCHAR)((phwi)->m_pVirtualMemory + addr))

    #define MEM_WRITE_BYTE(phwi, addr, data)                  \
    *((PUCHAR)((phwi)->m_pVirtualMemory + addr)) = (UCHAR)(data)


// c/directfb.h
    # 1 "/usr/include/directfb/directfb.h"
    # 1 "<built-in>"
    # 1 "<command line>"
    # 1 "/usr/include/directfb/directfb.h"
    # 31 "/usr/include/directfb/directfb.h"
    # 1 "/usr/include/directfb/dfb_types.h" 1


    # 1 "/usr/include/sys/types.h" 1 3 4
    # 27 "/usr/include/sys/types.h" 3 4
    # 1 "/usr/include/features.h" 1 3 4
    # 308 "/usr/include/features.h" 3 4
    # 1 "/usr/include/sys/cdefs.h" 1 3 4
    # 309 "/usr/include/features.h" 2 3 4
    # 331 "/usr/include/features.h" 3 4
    # 1 "/usr/include/gnu/stubs.h" 1 3 4
    # 332 "/usr/include/features.h" 2 3 4
    # 28 "/usr/include/sys/types.h" 2 3 4


    # 1 "/usr/include/bits/types.h" 1 3 4
    # 28 "/usr/include/bits/types.h" 3 4
    # 1 "/usr/include/bits/wordsize.h" 1 3 4
    # 29 "/usr/include/bits/types.h" 2 3 4


    # 1 "/usr/lib/gcc/i486-linux-gnu/4.0.3/include/stddef.h" 1 3 4
    # 214 "/usr/lib/gcc/i486-linux-gnu/4.0.3/include/stddef.h" 3 4
typedef unsigned int size_t;
    # 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;


__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;


__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
    # 129 "/usr/include/bits/types.h" 3 4
    # 1 "/usr/include/bits/typesizes.h" 1 3 4
    # 130 "/usr/include/bits/types.h" 2 3 4


__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef int __timer_t;


__extension__ typedef long int __blksize_t;


__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;

__extension__ typedef int __ssize_t;


typedef __off64_t __loff_t;
typedef __quad_t*__qaddr_t;
typedef char*__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
    # 32 "/usr/include/sys/types.h" 2 3 4


typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;


typedef __ino_t ino_t;
    # 62 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;


typedef __gid_t gid_t;


typedef __mode_t mode_t;


typedef __nlink_t nlink_t;


typedef __uid_t uid_t;


typedef __off_t off_t;
    # 100 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;


typedef __id_t id_t;


typedef __ssize_t ssize_t;


typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;


typedef __key_t key_t;
    # 133 "/usr/include/sys/types.h" 3 4
    # 1 "/usr/include/time.h" 1 3 4
    # 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;


    # 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
    # 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
    # 134 "/usr/include/sys/types.h" 2 3 4
    # 147 "/usr/include/sys/types.h" 3 4
    # 1 "/usr/lib/gcc/i486-linux-gnu/4.0.3/include/stddef.h" 1 3 4
    # 148 "/usr/include/sys/types.h" 2 3 4


typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
    # 191 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
    # 213 "/usr/include/sys/types.h" 3 4
    # 1 "/usr/include/endian.h" 1 3 4
    # 37 "/usr/include/endian.h" 3 4
    # 1 "/usr/include/bits/endian.h" 1 3 4
    # 38 "/usr/include/endian.h" 2 3 4
    # 214 "/usr/include/sys/types.h" 2 3 4


    # 1 "/usr/include/sys/select.h" 1 3 4
    # 31 "/usr/include/sys/select.h" 3 4
    # 1 "/usr/include/bits/select.h" 1 3 4
    # 32 "/usr/include/sys/select.h" 2 3 4


    # 1 "/usr/include/bits/sigset.h" 1 3 4
    # 23 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;


typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
    # 35 "/usr/include/sys/select.h" 2 3 4


typedef __sigset_t sigset_t;


    # 1 "/usr/include/time.h" 1 3 4
    # 118 "/usr/include/time.h" 3 4
struct timespec {
    __time_t tv_sec;
    long int tv_nsec;
};
    # 45 "/usr/include/sys/select.h" 2 3 4

    # 1 "/usr/include/bits/time.h" 1 3 4
    # 69 "/usr/include/bits/time.h" 3 4
struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};
    # 47 "/usr/include/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;


typedef long int __fd_mask;
    # 67 "/usr/include/sys/select.h" 3 4
typedef struct {
    __fd_mask __fds_bits[1024 / (8 * sizeof(__fd_mask))];
} fd_set;


typedef __fd_mask fd_mask;
    # 99 "/usr/include/sys/select.h" 3 4

    # 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set*__restrict __readfds,
                   fd_set*__restrict __writefds,
                   fd_set*__restrict __exceptfds,
                   struct timeval*__restrict __timeout);
    # 128 "/usr/include/sys/select.h" 3 4

    # 217 "/usr/include/sys/types.h" 2 3 4


    # 1 "/usr/include/sys/sysmacros.h" 1 3 4
    # 29 "/usr/include/sys/sysmacros.h" 3 4
__extension__
extern __inline unsigned int gnu_dev_major (unsigned long long int __dev)
__attribute__ ((__nothrow__));
__extension__
extern __inline unsigned int gnu_dev_minor (unsigned long long int __dev)
__attribute__ ((__nothrow__));
__extension__
extern __inline unsigned long long int gnu_dev_makedev (unsigned int __major,
                                                        unsigned int __minor)
__attribute__ ((__nothrow__));


__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_major (unsigned long long int __dev){
    return ((__dev >> 8) & 0xfff) | ((unsigned int)(__dev >> 32) & ~0xfff);
}

__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_minor (unsigned long long int __dev){
    return (__dev & 0xff) | ((unsigned int)(__dev >> 12) & ~0xff);
}

__extension__ extern __inline unsigned long long int
__attribute__ ((__nothrow__)) gnu_dev_makedev (unsigned int __major, unsigned int __minor){
    return ((__minor & 0xff) | ((__major & 0xfff) << 8)
            | (((unsigned long long int)(__minor & ~0xff)) << 12)
            | (((unsigned long long int)(__major & ~0xfff)) << 32));
}

    # 220 "/usr/include/sys/types.h" 2 3 4
    # 231 "/usr/include/sys/types.h" 3 4
typedef __blkcnt_t blkcnt_t;


typedef __fsblkcnt_t fsblkcnt_t;


typedef __fsfilcnt_t fsfilcnt_t;
    # 266 "/usr/include/sys/types.h" 3 4
    # 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
    # 23 "/usr/include/bits/pthreadtypes.h" 3 4
    # 1 "/usr/include/bits/sched.h" 1 3 4
    # 83 "/usr/include/bits/sched.h" 3 4
struct __sched_param {
    int __sched_priority;
};
    # 24 "/usr/include/bits/pthreadtypes.h" 2 3 4

typedef int __atomic_lock_t;


struct _pthread_fastlock {
    long int __status;
    __atomic_lock_t __spinlock;
};


typedef struct _pthread_descr_struct*_pthread_descr;


typedef struct __pthread_attr_s {
    int __detachstate;
    int __schedpolicy;
    struct __sched_param __schedparam;
    int __inheritsched;
    int __scope;
    size_t __guardsize;
    int __stackaddr_set;
    void *__stackaddr;
    size_t __stacksize;
} pthread_attr_t;


__extension__ typedef long long __pthread_cond_align_t;


typedef struct {
    struct _pthread_fastlock __c_lock;
    _pthread_descr __c_waiting;
    char __padding[48 - sizeof(struct _pthread_fastlock)
                   - sizeof(_pthread_descr) - sizeof(__pthread_cond_align_t)];
    __pthread_cond_align_t __align;
} pthread_cond_t;


typedef struct {
    int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;


typedef struct {
    int __m_reserved;
    int __m_count;
    _pthread_descr __m_owner;
    int __m_kind;
    struct _pthread_fastlock __m_lock;
} pthread_mutex_t;


typedef struct {
    int __mutexkind;
} pthread_mutexattr_t;


typedef int pthread_once_t;
    # 152 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;
    # 267 "/usr/include/sys/types.h" 2 3 4


    # 5 "/usr/include/directfb/dfb_types.h" 2
    # 1 "/usr/include/linux/types.h" 1 3 4


    # 1 "/usr/include/linux/posix_types.h" 1 3 4


    # 1 "/usr/include/linux/stddef.h" 1 3 4
    # 5 "/usr/include/linux/posix_types.h" 2 3 4
    # 36 "/usr/include/linux/posix_types.h" 3 4
typedef struct {
    unsigned long fds_bits [(1024 / (8 * sizeof(unsigned long)))];
} __kernel_fd_set;


typedef void (*__kernel_sighandler_t)(int);


typedef int __kernel_key_t;
typedef int __kernel_mqd_t;

    # 1 "/usr/lib/gcc/i486-linux-gnu/4.0.3/include/asm/posix_types.h" 1 3 4
    # 14 "/usr/lib/gcc/i486-linux-gnu/4.0.3/include/asm/posix_types.h" 3 4
    # 1 "/usr/include/asm/posix_types.h" 1 3 4
    # 11 "/usr/include/asm/posix_types.h" 3 4
    # 1 "/usr/include/asm-i386/posix_types.h" 1 3 4
    # 10 "/usr/include/asm-i386/posix_types.h" 3 4
typedef unsigned long __kernel_ino_t;
typedef unsigned short __kernel_mode_t;
typedef unsigned short __kernel_nlink_t;
typedef long __kernel_off_t;
typedef int __kernel_pid_t;
typedef unsigned short __kernel_ipc_pid_t;
typedef unsigned short __kernel_uid_t;
typedef unsigned short __kernel_gid_t;
typedef unsigned int __kernel_size_t;
typedef int __kernel_ssize_t;
typedef int __kernel_ptrdiff_t;
typedef long __kernel_time_t;
typedef long __kernel_suseconds_t;
typedef long __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef int __kernel_daddr_t;
typedef char*__kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;

typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned short __kernel_old_dev_t;


typedef long long __kernel_loff_t;


typedef struct {
    int __val[2];
} __kernel_fsid_t;
    # 12 "/usr/include/asm/posix_types.h" 2 3 4
    # 15 "/usr/lib/gcc/i486-linux-gnu/4.0.3/include/asm/posix_types.h" 2 3 4
    # 48 "/usr/include/linux/posix_types.h" 2 3 4
    # 6 "/usr/include/linux/types.h" 2 3 4
    # 1 "/usr/include/asm/types.h" 1 3 4
    # 11 "/usr/include/asm/types.h" 3 4
    # 1 "/usr/include/asm-i386/types.h" 1 3 4


typedef unsigned short umode_t;


typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;


typedef __signed__ long long __s64;
typedef unsigned long long __u64;
    # 12 "/usr/include/asm/types.h" 2 3 4
    # 7 "/usr/include/linux/types.h" 2 3 4
    # 133 "/usr/include/linux/types.h" 3 4
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;


typedef __u64 __le64;
typedef __u64 __be64;
    # 6 "/usr/include/directfb/dfb_types.h" 2
    # 32 "/usr/include/directfb/directfb.h" 2
    # 1 "/usr/include/sys/time.h" 1 3 4
    # 26 "/usr/include/sys/time.h" 3 4
    # 1 "/usr/include/time.h" 1 3 4
    # 27 "/usr/include/sys/time.h" 2 3 4

    # 1 "/usr/include/bits/time.h" 1 3 4
    # 29 "/usr/include/sys/time.h" 2 3 4
    # 38 "/usr/include/sys/time.h" 3 4

    # 56 "/usr/include/sys/time.h" 3 4
struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

typedef struct timezone*__restrict __timezone_ptr_t;
    # 72 "/usr/include/sys/time.h" 3 4
extern int gettimeofday (struct timeval*__restrict __tv,
                         __timezone_ptr_t __tz) __attribute__ ((__nothrow__));


extern int settimeofday (__const struct timeval *__tv,
                         __const struct timezone *__tz) __attribute__ ((__nothrow__));


extern int adjtime (__const struct timeval *__delta,
                    struct timeval *__olddelta) __attribute__ ((__nothrow__));


enum __itimer_which {
    ITIMER_REAL = 0,


    ITIMER_VIRTUAL = 1,


    ITIMER_PROF = 2
};


struct itimerval {
    struct timeval it_interval;

    struct timeval it_value;
};


typedef int __itimer_which_t;


extern int getitimer (__itimer_which_t __which,
                      struct itimerval *__value) __attribute__ ((__nothrow__));


extern int setitimer (__itimer_which_t __which,
                      __const struct itimerval*__restrict __new,
                      struct itimerval*__restrict __old) __attribute__ ((__nothrow__));


extern int utimes (__const char *__file, __const struct timeval __tvp[2])
__attribute__ ((__nothrow__));


extern int lutimes (__const char *__file, __const struct timeval __tvp[2])
__attribute__ ((__nothrow__));


extern int futimes (int __fd, __const struct timeval __tvp[2]) __attribute__ ((__nothrow__));
    # 181 "/usr/include/sys/time.h" 3 4

    # 33 "/usr/include/directfb/directfb.h" 2

    # 1 "/usr/include/directfb/directfb_keyboard.h" 1
    # 40 "/usr/include/directfb/directfb_keyboard.h"
typedef enum {
    DIKT_UNICODE = 0x0000,

    DIKT_SPECIAL    = 0xF000,
    DIKT_FUNCTION   = 0xF100,
    DIKT_MODIFIER   = 0xF200,
    DIKT_LOCK       = 0xF300,
    DIKT_DEAD       = 0xF400,
    DIKT_CUSTOM     = 0xF500,
    DIKT_IDENTIFIER = 0xF600
} DFBInputDeviceKeyType;
    # 71 "/usr/include/directfb/directfb_keyboard.h"
typedef enum {
    DIMKI_SHIFT,
    DIMKI_CONTROL,
    DIMKI_ALT,
    DIMKI_ALTGR,
    DIMKI_META,
    DIMKI_SUPER,
    DIMKI_HYPER,

    DIMKI_FIRST = DIMKI_SHIFT,
    DIMKI_LAST  = DIMKI_HYPER
} DFBInputDeviceModifierKeyIdentifier;


typedef enum {
    DIKI_UNKNOWN = ((DIKT_IDENTIFIER) | (0)),

    DIKI_A,
    DIKI_B,
    DIKI_C,
    DIKI_D,
    DIKI_E,
    DIKI_F,
    DIKI_G,
    DIKI_H,
    DIKI_I,
    DIKI_J,
    DIKI_K,
    DIKI_L,
    DIKI_M,
    DIKI_N,
    DIKI_O,
    DIKI_P,
    DIKI_Q,
    DIKI_R,
    DIKI_S,
    DIKI_T,
    DIKI_U,
    DIKI_V,
    DIKI_W,
    DIKI_X,
    DIKI_Y,
    DIKI_Z,

    DIKI_0,
    DIKI_1,
    DIKI_2,
    DIKI_3,
    DIKI_4,
    DIKI_5,
    DIKI_6,
    DIKI_7,
    DIKI_8,
    DIKI_9,

    DIKI_F1,
    DIKI_F2,
    DIKI_F3,
    DIKI_F4,
    DIKI_F5,
    DIKI_F6,
    DIKI_F7,
    DIKI_F8,
    DIKI_F9,
    DIKI_F10,
    DIKI_F11,
    DIKI_F12,

    DIKI_SHIFT_L,
    DIKI_SHIFT_R,
    DIKI_CONTROL_L,
    DIKI_CONTROL_R,
    DIKI_ALT_L,
    DIKI_ALT_R,
    DIKI_ALTGR,
    DIKI_META_L,
    DIKI_META_R,
    DIKI_SUPER_L,
    DIKI_SUPER_R,
    DIKI_HYPER_L,
    DIKI_HYPER_R,

    DIKI_CAPS_LOCK,
    DIKI_NUM_LOCK,
    DIKI_SCROLL_LOCK,

    DIKI_ESCAPE,
    DIKI_LEFT,
    DIKI_RIGHT,
    DIKI_UP,
    DIKI_DOWN,
    DIKI_TAB,
    DIKI_ENTER,
    DIKI_SPACE,
    DIKI_BACKSPACE,
    DIKI_INSERT,
    DIKI_DELETE,
    DIKI_HOME,
    DIKI_END,
    DIKI_PAGE_UP,
    DIKI_PAGE_DOWN,
    DIKI_PRINT,
    DIKI_PAUSE,


    DIKI_QUOTE_LEFT,
    DIKI_MINUS_SIGN,
    DIKI_EQUALS_SIGN,
    DIKI_BRACKET_LEFT,
    DIKI_BRACKET_RIGHT,
    DIKI_BACKSLASH,
    DIKI_SEMICOLON,
    DIKI_QUOTE_RIGHT,
    DIKI_COMMA,
    DIKI_PERIOD,
    DIKI_SLASH,

    DIKI_LESS_SIGN,

    DIKI_KP_DIV,
    DIKI_KP_MULT,
    DIKI_KP_MINUS,
    DIKI_KP_PLUS,
    DIKI_KP_ENTER,
    DIKI_KP_SPACE,
    DIKI_KP_TAB,
    DIKI_KP_F1,
    DIKI_KP_F2,
    DIKI_KP_F3,
    DIKI_KP_F4,
    DIKI_KP_EQUAL,
    DIKI_KP_SEPARATOR,

    DIKI_KP_DECIMAL,
    DIKI_KP_0,
    DIKI_KP_1,
    DIKI_KP_2,
    DIKI_KP_3,
    DIKI_KP_4,
    DIKI_KP_5,
    DIKI_KP_6,
    DIKI_KP_7,
    DIKI_KP_8,
    DIKI_KP_9,

    DIKI_KEYDEF_END,
    DIKI_NUMBER_OF_KEYS = DIKI_KEYDEF_END - ((DIKT_IDENTIFIER) | (0))
} DFBInputDeviceKeyIdentifier;


typedef enum {
    DIKS_NULL                 = ((DIKT_UNICODE) | (0x00)),
    DIKS_BACKSPACE            = ((DIKT_UNICODE) | (0x08)),
    DIKS_TAB                  = ((DIKT_UNICODE) | (0x09)),
    DIKS_RETURN               = ((DIKT_UNICODE) | (0x0D)),
    DIKS_CANCEL               = ((DIKT_UNICODE) | (0x18)),
    DIKS_ESCAPE               = ((DIKT_UNICODE) | (0x1B)),
    DIKS_SPACE                = ((DIKT_UNICODE) | (0x20)),
    DIKS_EXCLAMATION_MARK     = ((DIKT_UNICODE) | (0x21)),
    DIKS_QUOTATION            = ((DIKT_UNICODE) | (0x22)),
    DIKS_NUMBER_SIGN          = ((DIKT_UNICODE) | (0x23)),
    DIKS_DOLLAR_SIGN          = ((DIKT_UNICODE) | (0x24)),
    DIKS_PERCENT_SIGN         = ((DIKT_UNICODE) | (0x25)),
    DIKS_AMPERSAND            = ((DIKT_UNICODE) | (0x26)),
    DIKS_APOSTROPHE           = ((DIKT_UNICODE) | (0x27)),
    DIKS_PARENTHESIS_LEFT     = ((DIKT_UNICODE) | (0x28)),
    DIKS_PARENTHESIS_RIGHT    = ((DIKT_UNICODE) | (0x29)),
    DIKS_ASTERISK             = ((DIKT_UNICODE) | (0x2A)),
    DIKS_PLUS_SIGN            = ((DIKT_UNICODE) | (0x2B)),
    DIKS_COMMA                = ((DIKT_UNICODE) | (0x2C)),
    DIKS_MINUS_SIGN           = ((DIKT_UNICODE) | (0x2D)),
    DIKS_PERIOD               = ((DIKT_UNICODE) | (0x2E)),
    DIKS_SLASH                = ((DIKT_UNICODE) | (0x2F)),
    DIKS_0                    = ((DIKT_UNICODE) | (0x30)),
    DIKS_1                    = ((DIKT_UNICODE) | (0x31)),
    DIKS_2                    = ((DIKT_UNICODE) | (0x32)),
    DIKS_3                    = ((DIKT_UNICODE) | (0x33)),
    DIKS_4                    = ((DIKT_UNICODE) | (0x34)),
    DIKS_5                    = ((DIKT_UNICODE) | (0x35)),
    DIKS_6                    = ((DIKT_UNICODE) | (0x36)),
    DIKS_7                    = ((DIKT_UNICODE) | (0x37)),
    DIKS_8                    = ((DIKT_UNICODE) | (0x38)),
    DIKS_9                    = ((DIKT_UNICODE) | (0x39)),
    DIKS_COLON                = ((DIKT_UNICODE) | (0x3A)),
    DIKS_SEMICOLON            = ((DIKT_UNICODE) | (0x3B)),
    DIKS_LESS_THAN_SIGN       = ((DIKT_UNICODE) | (0x3C)),
    DIKS_EQUALS_SIGN          = ((DIKT_UNICODE) | (0x3D)),
    DIKS_GREATER_THAN_SIGN    = ((DIKT_UNICODE) | (0x3E)),
    DIKS_QUESTION_MARK        = ((DIKT_UNICODE) | (0x3F)),
    DIKS_AT                   = ((DIKT_UNICODE) | (0x40)),
    DIKS_CAPITAL_A            = ((DIKT_UNICODE) | (0x41)),
    DIKS_CAPITAL_B            = ((DIKT_UNICODE) | (0x42)),
    DIKS_CAPITAL_C            = ((DIKT_UNICODE) | (0x43)),
    DIKS_CAPITAL_D            = ((DIKT_UNICODE) | (0x44)),
    DIKS_CAPITAL_E            = ((DIKT_UNICODE) | (0x45)),
    DIKS_CAPITAL_F            = ((DIKT_UNICODE) | (0x46)),
    DIKS_CAPITAL_G            = ((DIKT_UNICODE) | (0x47)),
    DIKS_CAPITAL_H            = ((DIKT_UNICODE) | (0x48)),
    DIKS_CAPITAL_I            = ((DIKT_UNICODE) | (0x49)),
    DIKS_CAPITAL_J            = ((DIKT_UNICODE) | (0x4A)),
    DIKS_CAPITAL_K            = ((DIKT_UNICODE) | (0x4B)),
    DIKS_CAPITAL_L            = ((DIKT_UNICODE) | (0x4C)),
    DIKS_CAPITAL_M            = ((DIKT_UNICODE) | (0x4D)),
    DIKS_CAPITAL_N            = ((DIKT_UNICODE) | (0x4E)),
    DIKS_CAPITAL_O            = ((DIKT_UNICODE) | (0x4F)),
    DIKS_CAPITAL_P            = ((DIKT_UNICODE) | (0x50)),
    DIKS_CAPITAL_Q            = ((DIKT_UNICODE) | (0x51)),
    DIKS_CAPITAL_R            = ((DIKT_UNICODE) | (0x52)),
    DIKS_CAPITAL_S            = ((DIKT_UNICODE) | (0x53)),
    DIKS_CAPITAL_T            = ((DIKT_UNICODE) | (0x54)),
    DIKS_CAPITAL_U            = ((DIKT_UNICODE) | (0x55)),
    DIKS_CAPITAL_V            = ((DIKT_UNICODE) | (0x56)),
    DIKS_CAPITAL_W            = ((DIKT_UNICODE) | (0x57)),
    DIKS_CAPITAL_X            = ((DIKT_UNICODE) | (0x58)),
    DIKS_CAPITAL_Y            = ((DIKT_UNICODE) | (0x59)),
    DIKS_CAPITAL_Z            = ((DIKT_UNICODE) | (0x5A)),
    DIKS_SQUARE_BRACKET_LEFT  = ((DIKT_UNICODE) | (0x5B)),
    DIKS_BACKSLASH            = ((DIKT_UNICODE) | (0x5C)),
    DIKS_SQUARE_BRACKET_RIGHT = ((DIKT_UNICODE) | (0x5D)),
    DIKS_CIRCUMFLEX_ACCENT    = ((DIKT_UNICODE) | (0x5E)),
    DIKS_UNDERSCORE           = ((DIKT_UNICODE) | (0x5F)),
    DIKS_GRAVE_ACCENT         = ((DIKT_UNICODE) | (0x60)),
    DIKS_SMALL_A              = ((DIKT_UNICODE) | (0x61)),
    DIKS_SMALL_B              = ((DIKT_UNICODE) | (0x62)),
    DIKS_SMALL_C              = ((DIKT_UNICODE) | (0x63)),
    DIKS_SMALL_D              = ((DIKT_UNICODE) | (0x64)),
    DIKS_SMALL_E              = ((DIKT_UNICODE) | (0x65)),
    DIKS_SMALL_F              = ((DIKT_UNICODE) | (0x66)),
    DIKS_SMALL_G              = ((DIKT_UNICODE) | (0x67)),
    DIKS_SMALL_H              = ((DIKT_UNICODE) | (0x68)),
    DIKS_SMALL_I              = ((DIKT_UNICODE) | (0x69)),
    DIKS_SMALL_J              = ((DIKT_UNICODE) | (0x6A)),
    DIKS_SMALL_K              = ((DIKT_UNICODE) | (0x6B)),
    DIKS_SMALL_L              = ((DIKT_UNICODE) | (0x6C)),
    DIKS_SMALL_M              = ((DIKT_UNICODE) | (0x6D)),
    DIKS_SMALL_N              = ((DIKT_UNICODE) | (0x6E)),
    DIKS_SMALL_O              = ((DIKT_UNICODE) | (0x6F)),
    DIKS_SMALL_P              = ((DIKT_UNICODE) | (0x70)),
    DIKS_SMALL_Q              = ((DIKT_UNICODE) | (0x71)),
    DIKS_SMALL_R              = ((DIKT_UNICODE) | (0x72)),
    DIKS_SMALL_S              = ((DIKT_UNICODE) | (0x73)),
    DIKS_SMALL_T              = ((DIKT_UNICODE) | (0x74)),
    DIKS_SMALL_U              = ((DIKT_UNICODE) | (0x75)),
    DIKS_SMALL_V              = ((DIKT_UNICODE) | (0x76)),
    DIKS_SMALL_W              = ((DIKT_UNICODE) | (0x77)),
    DIKS_SMALL_X              = ((DIKT_UNICODE) | (0x78)),
    DIKS_SMALL_Y              = ((DIKT_UNICODE) | (0x79)),
    DIKS_SMALL_Z              = ((DIKT_UNICODE) | (0x7A)),
    DIKS_CURLY_BRACKET_LEFT   = ((DIKT_UNICODE) | (0x7B)),
    DIKS_VERTICAL_BAR         = ((DIKT_UNICODE) | (0x7C)),
    DIKS_CURLY_BRACKET_RIGHT  = ((DIKT_UNICODE) | (0x7D)),
    DIKS_TILDE                = ((DIKT_UNICODE) | (0x7E)),
    DIKS_DELETE               = ((DIKT_UNICODE) | (0x7F)),

    DIKS_ENTER = DIKS_RETURN,


    DIKS_CURSOR_LEFT  = ((DIKT_SPECIAL) | (0x00)),
    DIKS_CURSOR_RIGHT = ((DIKT_SPECIAL) | (0x01)),
    DIKS_CURSOR_UP    = ((DIKT_SPECIAL) | (0x02)),
    DIKS_CURSOR_DOWN  = ((DIKT_SPECIAL) | (0x03)),
    DIKS_INSERT       = ((DIKT_SPECIAL) | (0x04)),
    DIKS_HOME         = ((DIKT_SPECIAL) | (0x05)),
    DIKS_END          = ((DIKT_SPECIAL) | (0x06)),
    DIKS_PAGE_UP      = ((DIKT_SPECIAL) | (0x07)),
    DIKS_PAGE_DOWN    = ((DIKT_SPECIAL) | (0x08)),
    DIKS_PRINT        = ((DIKT_SPECIAL) | (0x09)),
    DIKS_PAUSE        = ((DIKT_SPECIAL) | (0x0A)),
    DIKS_OK           = ((DIKT_SPECIAL) | (0x0B)),
    DIKS_SELECT       = ((DIKT_SPECIAL) | (0x0C)),
    DIKS_GOTO         = ((DIKT_SPECIAL) | (0x0D)),
    DIKS_CLEAR        = ((DIKT_SPECIAL) | (0x0E)),
    DIKS_POWER        = ((DIKT_SPECIAL) | (0x0F)),
    DIKS_POWER2       = ((DIKT_SPECIAL) | (0x10)),
    DIKS_OPTION       = ((DIKT_SPECIAL) | (0x11)),
    DIKS_MENU         = ((DIKT_SPECIAL) | (0x12)),
    DIKS_HELP         = ((DIKT_SPECIAL) | (0x13)),
    DIKS_INFO         = ((DIKT_SPECIAL) | (0x14)),
    DIKS_TIME         = ((DIKT_SPECIAL) | (0x15)),
    DIKS_VENDOR       = ((DIKT_SPECIAL) | (0x16)),

    DIKS_ARCHIVE   = ((DIKT_SPECIAL) | (0x17)),
    DIKS_PROGRAM   = ((DIKT_SPECIAL) | (0x18)),
    DIKS_CHANNEL   = ((DIKT_SPECIAL) | (0x19)),
    DIKS_FAVORITES = ((DIKT_SPECIAL) | (0x1A)),
    DIKS_EPG       = ((DIKT_SPECIAL) | (0x1B)),
    DIKS_PVR       = ((DIKT_SPECIAL) | (0x1C)),
    DIKS_MHP       = ((DIKT_SPECIAL) | (0x1D)),
    DIKS_LANGUAGE  = ((DIKT_SPECIAL) | (0x1E)),
    DIKS_TITLE     = ((DIKT_SPECIAL) | (0x1F)),
    DIKS_SUBTITLE  = ((DIKT_SPECIAL) | (0x20)),
    DIKS_ANGLE     = ((DIKT_SPECIAL) | (0x21)),
    DIKS_ZOOM      = ((DIKT_SPECIAL) | (0x22)),
    DIKS_MODE      = ((DIKT_SPECIAL) | (0x23)),
    DIKS_KEYBOARD  = ((DIKT_SPECIAL) | (0x24)),
    DIKS_PC        = ((DIKT_SPECIAL) | (0x25)),
    DIKS_SCREEN    = ((DIKT_SPECIAL) | (0x26)),

    DIKS_TV     = ((DIKT_SPECIAL) | (0x27)),
    DIKS_TV2    = ((DIKT_SPECIAL) | (0x28)),
    DIKS_VCR    = ((DIKT_SPECIAL) | (0x29)),
    DIKS_VCR2   = ((DIKT_SPECIAL) | (0x2A)),
    DIKS_SAT    = ((DIKT_SPECIAL) | (0x2B)),
    DIKS_SAT2   = ((DIKT_SPECIAL) | (0x2C)),
    DIKS_CD     = ((DIKT_SPECIAL) | (0x2D)),
    DIKS_TAPE   = ((DIKT_SPECIAL) | (0x2E)),
    DIKS_RADIO  = ((DIKT_SPECIAL) | (0x2F)),
    DIKS_TUNER  = ((DIKT_SPECIAL) | (0x30)),
    DIKS_PLAYER = ((DIKT_SPECIAL) | (0x31)),
    DIKS_TEXT   = ((DIKT_SPECIAL) | (0x32)),
    DIKS_DVD    = ((DIKT_SPECIAL) | (0x33)),
    DIKS_AUX    = ((DIKT_SPECIAL) | (0x34)),
    DIKS_MP3    = ((DIKT_SPECIAL) | (0x35)),
    DIKS_PHONE  = ((DIKT_SPECIAL) | (0x36)),
    DIKS_AUDIO  = ((DIKT_SPECIAL) | (0x37)),
    DIKS_VIDEO  = ((DIKT_SPECIAL) | (0x38)),

    DIKS_INTERNET   = ((DIKT_SPECIAL) | (0x39)),
    DIKS_MAIL       = ((DIKT_SPECIAL) | (0x3A)),
    DIKS_NEWS       = ((DIKT_SPECIAL) | (0x3B)),
    DIKS_DIRECTORY  = ((DIKT_SPECIAL) | (0x3C)),
    DIKS_LIST       = ((DIKT_SPECIAL) | (0x3D)),
    DIKS_CALCULATOR = ((DIKT_SPECIAL) | (0x3E)),
    DIKS_MEMO       = ((DIKT_SPECIAL) | (0x3F)),
    DIKS_CALENDAR   = ((DIKT_SPECIAL) | (0x40)),
    DIKS_EDITOR     = ((DIKT_SPECIAL) | (0x41)),

    DIKS_RED    = ((DIKT_SPECIAL) | (0x42)),
    DIKS_GREEN  = ((DIKT_SPECIAL) | (0x43)),
    DIKS_YELLOW = ((DIKT_SPECIAL) | (0x44)),
    DIKS_BLUE   = ((DIKT_SPECIAL) | (0x45)),

    DIKS_CHANNEL_UP   = ((DIKT_SPECIAL) | (0x46)),
    DIKS_CHANNEL_DOWN = ((DIKT_SPECIAL) | (0x47)),
    DIKS_BACK         = ((DIKT_SPECIAL) | (0x48)),
    DIKS_FORWARD      = ((DIKT_SPECIAL) | (0x49)),
    DIKS_FIRST        = ((DIKT_SPECIAL) | (0x4A)),
    DIKS_LAST         = ((DIKT_SPECIAL) | (0x4B)),
    DIKS_VOLUME_UP    = ((DIKT_SPECIAL) | (0x4C)),
    DIKS_VOLUME_DOWN  = ((DIKT_SPECIAL) | (0x4D)),
    DIKS_MUTE         = ((DIKT_SPECIAL) | (0x4E)),
    DIKS_AB           = ((DIKT_SPECIAL) | (0x4F)),
    DIKS_PLAYPAUSE    = ((DIKT_SPECIAL) | (0x50)),
    DIKS_PLAY         = ((DIKT_SPECIAL) | (0x51)),
    DIKS_STOP         = ((DIKT_SPECIAL) | (0x52)),
    DIKS_RESTART      = ((DIKT_SPECIAL) | (0x53)),
    DIKS_SLOW         = ((DIKT_SPECIAL) | (0x54)),
    DIKS_FAST         = ((DIKT_SPECIAL) | (0x55)),
    DIKS_RECORD       = ((DIKT_SPECIAL) | (0x56)),
    DIKS_EJECT        = ((DIKT_SPECIAL) | (0x57)),
    DIKS_SHUFFLE      = ((DIKT_SPECIAL) | (0x58)),
    DIKS_REWIND       = ((DIKT_SPECIAL) | (0x59)),
    DIKS_FASTFORWARD  = ((DIKT_SPECIAL) | (0x5A)),
    DIKS_PREVIOUS     = ((DIKT_SPECIAL) | (0x5B)),
    DIKS_NEXT         = ((DIKT_SPECIAL) | (0x5C)),
    DIKS_BEGIN        = ((DIKT_SPECIAL) | (0x5D)),

    DIKS_DIGITS = ((DIKT_SPECIAL) | (0x5E)),
    DIKS_TEEN   = ((DIKT_SPECIAL) | (0x5F)),
    DIKS_TWEN   = ((DIKT_SPECIAL) | (0x60)),

    DIKS_BREAK = ((DIKT_SPECIAL) | (0x61)),
    DIKS_EXIT  = ((DIKT_SPECIAL) | (0x62)),
    DIKS_SETUP = ((DIKT_SPECIAL) | (0x63)),

    DIKS_CURSOR_LEFT_UP    = ((DIKT_SPECIAL) | (0x64)),
    DIKS_CURSOR_LEFT_DOWN  = ((DIKT_SPECIAL) | (0x65)),
    DIKS_CURSOR_UP_RIGHT   = ((DIKT_SPECIAL) | (0x66)),
    DIKS_CURSOR_DOWN_RIGHT = ((DIKT_SPECIAL) | (0x67)),


    DIKS_F1  = (((DIKT_FUNCTION) | (1))),
    DIKS_F2  = (((DIKT_FUNCTION) | (2))),
    DIKS_F3  = (((DIKT_FUNCTION) | (3))),
    DIKS_F4  = (((DIKT_FUNCTION) | (4))),
    DIKS_F5  = (((DIKT_FUNCTION) | (5))),
    DIKS_F6  = (((DIKT_FUNCTION) | (6))),
    DIKS_F7  = (((DIKT_FUNCTION) | (7))),
    DIKS_F8  = (((DIKT_FUNCTION) | (8))),
    DIKS_F9  = (((DIKT_FUNCTION) | (9))),
    DIKS_F10 = (((DIKT_FUNCTION) | (10))),
    DIKS_F11 = (((DIKT_FUNCTION) | (11))),
    DIKS_F12 = (((DIKT_FUNCTION) | (12))),


    DIKS_SHIFT   = (((DIKT_MODIFIER) | ((1 << DIMKI_SHIFT)))),
    DIKS_CONTROL = (((DIKT_MODIFIER) | ((1 << DIMKI_CONTROL)))),
    DIKS_ALT     = (((DIKT_MODIFIER) | ((1 << DIMKI_ALT)))),
    DIKS_ALTGR   = (((DIKT_MODIFIER) | ((1 << DIMKI_ALTGR)))),
    DIKS_META    = (((DIKT_MODIFIER) | ((1 << DIMKI_META)))),
    DIKS_SUPER   = (((DIKT_MODIFIER) | ((1 << DIMKI_SUPER)))),
    DIKS_HYPER   = (((DIKT_MODIFIER) | ((1 << DIMKI_HYPER)))),


    DIKS_CAPS_LOCK   = ((DIKT_LOCK) | (0x00)),
    DIKS_NUM_LOCK    = ((DIKT_LOCK) | (0x01)),
    DIKS_SCROLL_LOCK = ((DIKT_LOCK) | (0x02)),


    DIKS_DEAD_ABOVEDOT         = ((DIKT_DEAD) | (0x00)),
    DIKS_DEAD_ABOVERING        = ((DIKT_DEAD) | (0x01)),
    DIKS_DEAD_ACUTE            = ((DIKT_DEAD) | (0x02)),
    DIKS_DEAD_BREVE            = ((DIKT_DEAD) | (0x03)),
    DIKS_DEAD_CARON            = ((DIKT_DEAD) | (0x04)),
    DIKS_DEAD_CEDILLA          = ((DIKT_DEAD) | (0x05)),
    DIKS_DEAD_CIRCUMFLEX       = ((DIKT_DEAD) | (0x06)),
    DIKS_DEAD_DIAERESIS        = ((DIKT_DEAD) | (0x07)),
    DIKS_DEAD_DOUBLEACUTE      = ((DIKT_DEAD) | (0x08)),
    DIKS_DEAD_GRAVE            = ((DIKT_DEAD) | (0x09)),
    DIKS_DEAD_IOTA             = ((DIKT_DEAD) | (0x0A)),
    DIKS_DEAD_MACRON           = ((DIKT_DEAD) | (0x0B)),
    DIKS_DEAD_OGONEK           = ((DIKT_DEAD) | (0x0C)),
    DIKS_DEAD_SEMIVOICED_SOUND = ((DIKT_DEAD) | (0x0D)),
    DIKS_DEAD_TILDE            = ((DIKT_DEAD) | (0x0E)),
    DIKS_DEAD_VOICED_SOUND     = ((DIKT_DEAD) | (0x0F)),


    DIKS_CUSTOM0 = (((DIKT_CUSTOM) | (0))),
    DIKS_CUSTOM1 = (((DIKT_CUSTOM) | (1))),
    DIKS_CUSTOM2 = (((DIKT_CUSTOM) | (2))),
    DIKS_CUSTOM3 = (((DIKT_CUSTOM) | (3))),
    DIKS_CUSTOM4 = (((DIKT_CUSTOM) | (4))),
    DIKS_CUSTOM5 = (((DIKT_CUSTOM) | (5))),
    DIKS_CUSTOM6 = (((DIKT_CUSTOM) | (6))),
    DIKS_CUSTOM7 = (((DIKT_CUSTOM) | (7))),
    DIKS_CUSTOM8 = (((DIKT_CUSTOM) | (8))),
    DIKS_CUSTOM9 = (((DIKT_CUSTOM) | (9)))
} DFBInputDeviceKeySymbol;


typedef enum {
    DILS_SCROLL = 0x00000001,
    DILS_NUM    = 0x00000002,
    DILS_CAPS   = 0x00000004
} DFBInputDeviceLockState;


typedef enum {
    DIKSI_BASE = 0x00,

    DIKSI_BASE_SHIFT = 0x01,

    DIKSI_ALT = 0x02,

    DIKSI_ALT_SHIFT = 0x03,


    DIKSI_LAST = DIKSI_ALT_SHIFT
} DFBInputDeviceKeymapSymbolIndex;


typedef struct {
    int code;

    DFBInputDeviceLockState locks;

    DFBInputDeviceKeyIdentifier identifier;
    DFBInputDeviceKeySymbol symbols[DIKSI_LAST + 1];
} DFBInputDeviceKeymapEntry;
    # 35 "/usr/include/directfb/directfb.h" 2
    # 68 "/usr/include/directfb/directfb.h"
extern const unsigned int directfb_major_version;
extern const unsigned int directfb_minor_version;
extern const unsigned int directfb_micro_version;
extern const unsigned int directfb_binary_age;
extern const unsigned int directfb_interface_age;


const char* DirectFBCheckVersion(unsigned int required_major,
                                 unsigned int required_minor,
                                 unsigned int required_micro);


typedef struct _IDirectFB IDirectFB;


typedef struct _IDirectFBScreen IDirectFBScreen;


typedef struct _IDirectFBDisplayLayer IDirectFBDisplayLayer;


typedef struct _IDirectFBSurface IDirectFBSurface;


typedef struct _IDirectFBPalette IDirectFBPalette;


typedef struct _IDirectFBWindow IDirectFBWindow;


typedef struct _IDirectFBInputDevice IDirectFBInputDevice;


typedef struct _IDirectFBEventBuffer IDirectFBEventBuffer;


typedef struct _IDirectFBFont IDirectFBFont;


typedef struct _IDirectFBImageProvider IDirectFBImageProvider;


typedef struct _IDirectFBVideoProvider IDirectFBVideoProvider;


typedef struct _IDirectFBDataBuffer IDirectFBDataBuffer;


typedef struct _IDirectFBGL IDirectFBGL;


typedef enum {
    DFB_OK,
    DFB_FAILURE,
    DFB_INIT,
    DFB_BUG,
    DFB_DEAD,
    DFB_UNSUPPORTED,
    DFB_UNIMPLEMENTED,
    DFB_ACCESSDENIED,
    DFB_INVARG,
    DFB_NOSYSTEMMEMORY,
    DFB_NOVIDEOMEMORY,
    DFB_LOCKED,
    DFB_BUFFEREMPTY,
    DFB_FILENOTFOUND,
    DFB_IO,
    DFB_BUSY,
    DFB_NOIMPL,
    DFB_MISSINGFONT,
    DFB_TIMEOUT,
    DFB_MISSINGIMAGE,
    DFB_THIZNULL,
    DFB_IDNOTFOUND,
    DFB_INVAREA,
    DFB_DESTROYED,
    DFB_FUSION,
    DFB_BUFFERTOOLARGE,
    DFB_INTERRUPTED,
    DFB_NOCONTEXT,
    DFB_TEMPUNAVAIL,
    DFB_LIMITEXCEEDED,
    DFB_NOSUCHMETHOD,
    DFB_NOSUCHINSTANCE,
    DFB_ITEMNOTFOUND,
    DFB_VERSIONMISMATCH,
    DFB_NOSHAREDMEMORY
} DFBResult;


typedef enum {
    DFB_FALSE = 0,
    DFB_TRUE  = !DFB_FALSE
} DFBBoolean;


typedef struct {
    int x;
    int y;
} DFBPoint;


typedef struct {
    int x;
    int w;
} DFBSpan;


typedef struct {
    int w;
    int h;
} DFBDimension;


typedef struct {
    int x;
    int y;
    int w;
    int h;
} DFBRectangle;


typedef struct {
    float x;
    float y;
    float w;
    float h;
} DFBLocation;


typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} DFBRegion;


typedef struct {
    int l;
    int t;
    int r;
    int b;
} DFBInsets;


typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
} DFBTriangle;


typedef struct {
    __u8 a;
    __u8 r;
    __u8 g;
    __u8 b;
} DFBColor;
    # 335 "/usr/include/directfb/directfb.h"
DFBResult DirectFBError(
    const char *msg,
    DFBResult result
    );


DFBResult DirectFBErrorFatal(
    const char *msg,
    DFBResult result
    );


const char* DirectFBErrorString(
    DFBResult result
    );


const char* DirectFBUsageString(void);


DFBResult DirectFBInit(
    int *argc,
    char **argv[]
    );


DFBResult DirectFBSetOption(
    const char *name,
    const char *value
    );


DFBResult DirectFBCreate(
    IDirectFB **interface

    );


typedef unsigned int DFBScreenID;
typedef unsigned int DFBDisplayLayerID;
typedef unsigned int DFBDisplayLayerSourceID;
typedef unsigned int DFBWindowID;
typedef unsigned int DFBInputDeviceID;

typedef __u32 DFBDisplayLayerIDs;
    # 428 "/usr/include/directfb/directfb.h"
typedef enum {
    DFSCL_NORMAL = 0x00000000,


    DFSCL_FULLSCREEN,


    DFSCL_EXCLUSIVE
} DFBCooperativeLevel;


typedef enum {
    DLCAPS_NONE = 0x00000000,

    DLCAPS_SURFACE = 0x00000001,


    DLCAPS_OPACITY = 0x00000002,

    DLCAPS_ALPHACHANNEL = 0x00000004,

    DLCAPS_SCREEN_LOCATION = 0x00000008,


    DLCAPS_FLICKER_FILTERING = 0x00000010,

    DLCAPS_DEINTERLACING = 0x00000020,


    DLCAPS_SRC_COLORKEY = 0x00000040,
    DLCAPS_DST_COLORKEY = 0x00000080,


    DLCAPS_BRIGHTNESS = 0x00000100,
    DLCAPS_CONTRAST   = 0x00000200,
    DLCAPS_HUE        = 0x00000400,
    DLCAPS_SATURATION = 0x00000800,
    DLCAPS_LEVELS     = 0x00001000,

    DLCAPS_FIELD_PARITY = 0x00002000,
    DLCAPS_WINDOWS      = 0x00004000,
    DLCAPS_SOURCES      = 0x00008000,
    DLCAPS_ALPHA_RAMP   = 0x00010000,


    DLCAPS_PREMULTIPLIED = 0x00020000,

    DLCAPS_SCREEN_POSITION = 0x00100000,
    DLCAPS_SCREEN_SIZE     = 0x00200000,

    DLCAPS_ALL = 0x0033FFFF
} DFBDisplayLayerCapabilities;


typedef enum {
    DSCCAPS_NONE = 0x00000000,

    DSCCAPS_VSYNC = 0x00000001,

    DSCCAPS_POWER_MANAGEMENT = 0x00000002,

    DSCCAPS_MIXERS   = 0x00000010,
    DSCCAPS_ENCODERS = 0x00000020,
    DSCCAPS_OUTPUTS  = 0x00000040,

    DSCCAPS_ALL = 0x00000073
} DFBScreenCapabilities;


typedef enum {
    DLOP_NONE         = 0x00000000,
    DLOP_ALPHACHANNEL = 0x00000001,


    DLOP_FLICKER_FILTERING = 0x00000002,
    DLOP_DEINTERLACING     = 0x00000004,

    DLOP_SRC_COLORKEY = 0x00000008,
    DLOP_DST_COLORKEY = 0x00000010,
    DLOP_OPACITY      = 0x00000020,

    DLOP_FIELD_PARITY = 0x00000040
} DFBDisplayLayerOptions;


typedef enum {
    DLBM_UNKNOWN = 0x00000000,

    DLBM_FRONTONLY  = 0x00000001,
    DLBM_BACKVIDEO  = 0x00000002,
    DLBM_BACKSYSTEM = 0x00000004,
    DLBM_TRIPLE     = 0x00000008,
    DLBM_WINDOWS    = 0x00000010
} DFBDisplayLayerBufferMode;


typedef enum {
    DSDESC_CAPS         = 0x00000001,
    DSDESC_WIDTH        = 0x00000002,
    DSDESC_HEIGHT       = 0x00000004,
    DSDESC_PIXELFORMAT  = 0x00000008,
    DSDESC_PREALLOCATED = 0x00000010,


    DSDESC_PALETTE = 0x00000020
} DFBSurfaceDescriptionFlags;


typedef enum {
    DPDESC_CAPS    = 0x00000001,
    DPDESC_SIZE    = 0x00000002,
    DPDESC_ENTRIES = 0x00000004
} DFBPaletteDescriptionFlags;


typedef enum {
    DSCAPS_NONE = 0x00000000,

    DSCAPS_PRIMARY    = 0x00000001,
    DSCAPS_SYSTEMONLY = 0x00000002,

    DSCAPS_VIDEOONLY = 0x00000004,

    DSCAPS_DOUBLE     = 0x00000010,
    DSCAPS_SUBSURFACE = 0x00000020,

    DSCAPS_INTERLACED = 0x00000040,


    DSCAPS_SEPARATED = 0x00000080,


    DSCAPS_STATIC_ALLOC = 0x00000100,


    DSCAPS_TRIPLE = 0x00000200,

    DSCAPS_PREMULTIPLIED = 0x00001000,

    DSCAPS_DEPTH = 0x00010000,

    DSCAPS_ALL = 0x000113F7,


    DSCAPS_FLIPPING = DSCAPS_DOUBLE | DSCAPS_TRIPLE
} DFBSurfaceCapabilities;


typedef enum {
    DPCAPS_NONE = 0x00000000
} DFBPaletteCapabilities;


typedef enum {
    DSDRAW_NOFX         = 0x00000000,
    DSDRAW_BLEND        = 0x00000001,
    DSDRAW_DST_COLORKEY = 0x00000002,

    DSDRAW_SRC_PREMULTIPLY = 0x00000004,

    DSDRAW_DST_PREMULTIPLY = 0x00000008,
    DSDRAW_DEMULTIPLY      = 0x00000010,

    DSDRAW_XOR = 0x00000020
} DFBSurfaceDrawingFlags;


typedef enum {
    DSBLIT_NOFX               = 0x00000000,
    DSBLIT_BLEND_ALPHACHANNEL = 0x00000001,

    DSBLIT_BLEND_COLORALPHA = 0x00000002,

    DSBLIT_COLORIZE = 0x00000004,

    DSBLIT_SRC_COLORKEY = 0x00000008,
    DSBLIT_DST_COLORKEY = 0x00000010,

    DSBLIT_SRC_PREMULTIPLY = 0x00000020,

    DSBLIT_DST_PREMULTIPLY = 0x00000040,
    DSBLIT_DEMULTIPLY      = 0x00000080,

    DSBLIT_DEINTERLACE = 0x00000100
} DFBSurfaceBlittingFlags;


typedef enum {
    DFXL_NONE = 0x00000000,

    DFXL_FILLRECTANGLE = 0x00000001,
    DFXL_DRAWRECTANGLE = 0x00000002,
    DFXL_DRAWLINE      = 0x00000004,
    DFXL_FILLTRIANGLE  = 0x00000008,

    DFXL_BLIT         = 0x00010000,
    DFXL_STRETCHBLIT  = 0x00020000,
    DFXL_TEXTRIANGLES = 0x00040000,

    DFXL_DRAWSTRING = 0x01000000,

    DFXL_ALL = 0x0107000F
} DFBAccelerationMask;
    # 699 "/usr/include/directfb/directfb.h"
typedef struct {
    DFBAccelerationMask acceleration_mask;
    DFBSurfaceDrawingFlags drawing_flags;
    DFBSurfaceBlittingFlags blitting_flags;
    unsigned int video_memory;
} DFBCardCapabilities;


typedef enum {
    DLTF_NONE = 0x00000000,

    DLTF_GRAPHICS      = 0x00000001,
    DLTF_VIDEO         = 0x00000002,
    DLTF_STILL_PICTURE = 0x00000004,
    DLTF_BACKGROUND    = 0x00000008,

    DLTF_ALL = 0x0000000F
} DFBDisplayLayerTypeFlags;


typedef enum {
    DIDTF_NONE = 0x00000000,

    DIDTF_KEYBOARD = 0x00000001,
    DIDTF_MOUSE    = 0x00000002,
    DIDTF_JOYSTICK = 0x00000004,
    DIDTF_REMOTE   = 0x00000008,
    DIDTF_VIRTUAL  = 0x00000010,

    DIDTF_ALL = 0x0000001F
} DFBInputDeviceTypeFlags;


typedef enum {
    DICAPS_KEYS    = 0x00000001,
    DICAPS_AXES    = 0x00000002,
    DICAPS_BUTTONS = 0x00000004,

    DICAPS_ALL = 0x00000007
} DFBInputDeviceCapabilities;


typedef enum {
    DIBI_LEFT   = 0x00000000,
    DIBI_RIGHT  = 0x00000001,
    DIBI_MIDDLE = 0x00000002,

    DIBI_FIRST = DIBI_LEFT,

    DIBI_LAST = 0x0000001F
} DFBInputDeviceButtonIdentifier;
    # 768 "/usr/include/directfb/directfb.h"
typedef enum {
    DIAI_X = 0x00000000,
    DIAI_Y = 0x00000001,
    DIAI_Z = 0x00000002,

    DIAI_FIRST = DIAI_X,

    DIAI_LAST = 0x0000001F
} DFBInputDeviceAxisIdentifier;


typedef enum {
    DWDESC_CAPS         = 0x00000001,
    DWDESC_WIDTH        = 0x00000002,
    DWDESC_HEIGHT       = 0x00000004,
    DWDESC_PIXELFORMAT  = 0x00000008,
    DWDESC_POSX         = 0x00000010,
    DWDESC_POSY         = 0x00000020,
    DWDESC_SURFACE_CAPS = 0x00000040
} DFBWindowDescriptionFlags;


typedef enum {
    DBDESC_FILE = 0x00000001,

    DBDESC_MEMORY = 0x00000002
} DFBDataBufferDescriptionFlags;


typedef enum {
    DWCAPS_NONE         = 0x00000000,
    DWCAPS_ALPHACHANNEL = 0x00000001,

    DWCAPS_DOUBLEBUFFER = 0x00000002,


    DWCAPS_INPUTONLY = 0x00000004,


    DWCAPS_NODECORATION = 0x00000008,
    DWCAPS_ALL          = 0x0000000F
} DFBWindowCapabilities;
    # 834 "/usr/include/directfb/directfb.h"
typedef enum {
    DFFA_NONE       = 0x00000000,
    DFFA_NOKERNING  = 0x00000001,
    DFFA_NOHINTING  = 0x00000002,
    DFFA_MONOCHROME = 0x00000004,
    DFFA_NOCHARMAP  = 0x00000008
} DFBFontAttributes;


typedef enum {
    DFDESC_ATTRIBUTES   = 0x00000001,
    DFDESC_HEIGHT       = 0x00000002,
    DFDESC_WIDTH        = 0x00000004,
    DFDESC_INDEX        = 0x00000008,
    DFDESC_FIXEDADVANCE = 0x00000010
} DFBFontDescriptionFlags;
    # 869 "/usr/include/directfb/directfb.h"
typedef struct {
    DFBFontDescriptionFlags flags;

    DFBFontAttributes attributes;
    int height;
    int width;
    unsigned int index;
    int fixed_advance;
} DFBFontDescription;
    # 916 "/usr/include/directfb/directfb.h"
typedef enum {
    DSPF_UNKNOWN = 0x00000000,


    DSPF_ARGB1555 = ( (((0) & 0x7F) ) | (((15) & 0x1F) << 7) | (((1) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((2) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_RGB16 = ( (((1) & 0x7F) ) | (((16) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((2) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_RGB24 = ( (((2) & 0x7F) ) | (((24) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((3) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_RGB32 = ( (((3) & 0x7F) ) | (((24) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((4) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_ARGB = ( (((4) & 0x7F) ) | (((24) & 0x1F) << 7) | (((8) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((4) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_A8 = ( (((5) & 0x7F) ) | (((0) & 0x1F) << 7) | (((8) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_YUY2 = ( (((6) & 0x7F) ) | (((16) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((2) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_RGB332 = ( (((7) & 0x7F) ) | (((8) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_UYVY = ( (((8) & 0x7F) ) | (((16) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((2) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_I420 = ( (((9) & 0x7F) ) | (((12) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((2) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_YV12 = ( (((10) & 0x7F) ) | (((12) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((2) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_LUT8 = ( (((11) & 0x7F) ) | (((8) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((1)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_ALUT44 = ( (((12) & 0x7F) ) | (((4) & 0x1F) << 7) | (((4) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((1)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_AiRGB = ( (((13) & 0x7F) ) | (((24) & 0x1F) << 7) | (((8) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((4) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((1)?1:0) << 31) ),


    DSPF_A1 = ( (((14) & 0x7F) ) | (((0) & 0x1F) << 7) | (((1) & 0x0F) << 12) | (((1)?1:0) << 16) | (((1) & 0x07) << 17) | (((0) & 0x07) << 20) | (((7) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_NV12 = ( (((15) & 0x7F) ) | (((12) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((2) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_NV16 = ( (((16) & 0x7F) ) | (((24) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((2) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_ARGB2554 = ( (((17) & 0x7F) ) | (((14) & 0x1F) << 7) | (((2) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((2) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_ARGB4444 = ( (((18) & 0x7F) ) | (((12) & 0x1F) << 7) | (((4) & 0x0F) << 12) | (((1)?1:0) << 16) | (((0) & 0x07) << 17) | (((2) & 0x07) << 20) | (((0) & 0x07) << 23) | (((0) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) ),


    DSPF_NV21 = ( (((19) & 0x7F) ) | (((12) & 0x1F) << 7) | (((0) & 0x0F) << 12) | (((0)?1:0) << 16) | (((0) & 0x07) << 17) | (((1) & 0x07) << 20) | (((0) & 0x07) << 23) | (((2) & 0x03) << 26) | (((0) & 0x03) << 28) | (((0)?1:0) << 30) | (((0)?1:0) << 31) )
} DFBSurfacePixelFormat;
    # 1012 "/usr/include/directfb/directfb.h"
typedef struct {
    DFBSurfaceDescriptionFlags flags;

    DFBSurfaceCapabilities caps;
    int width;
    int height;
    DFBSurfacePixelFormat pixelformat;

    struct {
        void *data;
        int pitch;
    } preallocated[2];

    struct {
        DFBColor *entries;
        unsigned int size;
    } palette;
} DFBSurfaceDescription;


typedef struct {
    DFBPaletteDescriptionFlags flags;

    DFBPaletteCapabilities caps;
    unsigned int size;
    DFBColor *entries;
} DFBPaletteDescription;


typedef struct {
    DFBDisplayLayerTypeFlags type;

    DFBDisplayLayerCapabilities caps;


    char name[32];

    int level;
    int regions;


    int sources;
} DFBDisplayLayerDescription;


typedef struct {
    DFBDisplayLayerSourceID source_id;

    char name[24];
} DFBDisplayLayerSourceDescription;


typedef struct {
    DFBScreenCapabilities caps;


    char name[32];

    int mixers;

    int encoders;

    int outputs;
} DFBScreenDescription;
    # 1104 "/usr/include/directfb/directfb.h"
typedef struct {
    DFBInputDeviceTypeFlags type;

    DFBInputDeviceCapabilities caps;


    int min_keycode;


    int max_keycode;


    DFBInputDeviceAxisIdentifier max_axis;

    DFBInputDeviceButtonIdentifier max_button;


    char name[32];

    char vendor[40];
} DFBInputDeviceDescription;


typedef struct {
    DFBWindowDescriptionFlags flags;

    DFBWindowCapabilities caps;
    int width;
    int height;
    DFBSurfacePixelFormat pixelformat;
    int posx;
    int posy;
    DFBSurfaceCapabilities surface_caps;
} DFBWindowDescription;


typedef struct {
    DFBDataBufferDescriptionFlags flags;

    const char *file;

    struct {
        const void *data;
        unsigned int length;
    } memory;
} DFBDataBufferDescription;


typedef enum {
    DFENUM_OK     = 0x00000000,
    DFENUM_CANCEL = 0x00000001
} DFBEnumerationResult;


typedef DFBEnumerationResult (*DFBVideoModeCallback)(
    int width,
    int height,
    int bpp,
    void *callbackdata
    );


typedef DFBEnumerationResult (*DFBScreenCallback)(
    DFBScreenID screen_id,
    DFBScreenDescription desc,
    void *callbackdata
    );


typedef DFBEnumerationResult (*DFBDisplayLayerCallback)(
    DFBDisplayLayerID layer_id,
    DFBDisplayLayerDescription desc,
    void *callbackdata
    );


typedef DFBEnumerationResult (*DFBInputDeviceCallback)(
    DFBInputDeviceID device_id,
    DFBInputDeviceDescription desc,
    void *callbackdata
    );


typedef int (*DFBGetDataCallback)(
    void *buffer,
    unsigned int length,
    void *callbackdata
    );


typedef enum {
    DVCAPS_BASIC      = 0x00000000,
    DVCAPS_SEEK       = 0x00000001,
    DVCAPS_SCALE      = 0x00000002,
    DVCAPS_INTERLACED = 0x00000004,
    DVCAPS_BRIGHTNESS = 0x00000010,
    DVCAPS_CONTRAST   = 0x00000020,
    DVCAPS_HUE        = 0x00000040,
    DVCAPS_SATURATION = 0x00000080
} DFBVideoProviderCapabilities;


typedef enum {
    DCAF_NONE       = 0x00000000,
    DCAF_BRIGHTNESS = 0x00000001,
    DCAF_CONTRAST   = 0x00000002,
    DCAF_HUE        = 0x00000004,
    DCAF_SATURATION = 0x00000008
} DFBColorAdjustmentFlags;


typedef struct {
    DFBColorAdjustmentFlags flags;

    __u16 brightness;
    __u16 contrast;
    __u16 hue;
    __u16 saturation;
} DFBColorAdjustment;
    # 1319 "/usr/include/directfb/directfb.h"
struct _IDirectFB { void *priv; int magic; DFBResult (*AddRef)(IDirectFB *thiz); DFBResult (*Release)(IDirectFB *thiz); DFBResult (*SetCooperativeLevel)(IDirectFB *thiz, DFBCooperativeLevel level); DFBResult (*SetVideoMode)(IDirectFB *thiz, int width, int height, int bpp); DFBResult (*GetCardCapabilities)(IDirectFB *thiz, DFBCardCapabilities *ret_caps); DFBResult (*EnumVideoModes)(IDirectFB *thiz, DFBVideoModeCallback callback, void *callbackdata); DFBResult (*CreateSurface)(IDirectFB *thiz, const DFBSurfaceDescription *desc, IDirectFBSurface **ret_interface); DFBResult (*CreatePalette)(IDirectFB *thiz, const DFBPaletteDescription *desc, IDirectFBPalette **ret_interface); DFBResult (*EnumScreens)(IDirectFB *thiz, DFBScreenCallback callback, void *callbackdata); DFBResult (*GetScreen)(IDirectFB *thiz, DFBScreenID screen_id, IDirectFBScreen **ret_interface); DFBResult (*EnumDisplayLayers)(IDirectFB *thiz, DFBDisplayLayerCallback callback, void *callbackdata); DFBResult (*GetDisplayLayer)(IDirectFB *thiz, DFBDisplayLayerID layer_id, IDirectFBDisplayLayer **ret_interface); DFBResult (*EnumInputDevices)(IDirectFB *thiz, DFBInputDeviceCallback callback, void *callbackdata); DFBResult (*GetInputDevice)(IDirectFB *thiz, DFBInputDeviceID device_id, IDirectFBInputDevice **ret_interface); DFBResult (*CreateEventBuffer)(IDirectFB *thiz, IDirectFBEventBuffer **ret_buffer); DFBResult (*CreateInputEventBuffer)(IDirectFB *thiz, DFBInputDeviceCapabilities caps, DFBBoolean global, IDirectFBEventBuffer **ret_buffer); DFBResult (*CreateImageProvider)(IDirectFB *thiz, const char *filename, IDirectFBImageProvider **ret_interface); DFBResult (*CreateVideoProvider)(IDirectFB *thiz, const char *filename, IDirectFBVideoProvider **ret_interface); DFBResult (*CreateFont)(IDirectFB *thiz, const char *filename, const DFBFontDescription *desc, IDirectFBFont **ret_interface); DFBResult (*CreateDataBuffer)(IDirectFB *thiz, const DFBDataBufferDescription *desc, IDirectFBDataBuffer **ret_interface); DFBResult (*SetClipboardData)(IDirectFB *thiz, const char *mime_type, const void *data, unsigned int size, struct timeval *ret_timestamp); DFBResult (*GetClipboardData)(IDirectFB *thiz, char **ret_mimetype, void **ret_data, unsigned int *ret_size); DFBResult (*GetClipboardTimeStamp)(IDirectFB *thiz, struct timeval *ret_timestamp); DFBResult (*Suspend)(IDirectFB *thiz); DFBResult (*Resume)(IDirectFB *thiz); DFBResult (*WaitIdle)(IDirectFB *thiz); DFBResult (*WaitForSync)(IDirectFB *thiz); DFBResult (*GetInterface)(IDirectFB *thiz, const char *type, const char *implementation, void *arg, void **ret_interface); };
    # 1681 "/usr/include/directfb/directfb.h"
typedef enum {
    DLSCL_SHARED = 0,
    DLSCL_EXCLUSIVE,

    DLSCL_ADMINISTRATIVE
} DFBDisplayLayerCooperativeLevel;


typedef enum {
    DLBM_DONTCARE = 0,

    DLBM_COLOR,

    DLBM_IMAGE,
    DLBM_TILE
} DFBDisplayLayerBackgroundMode;


typedef enum {
    DLCONF_NONE = 0x00000000,

    DLCONF_WIDTH        = 0x00000001,
    DLCONF_HEIGHT       = 0x00000002,
    DLCONF_PIXELFORMAT  = 0x00000004,
    DLCONF_BUFFERMODE   = 0x00000008,
    DLCONF_OPTIONS      = 0x00000010,
    DLCONF_SOURCE       = 0x00000020,
    DLCONF_SURFACE_CAPS = 0x00000040,

    DLCONF_ALL = 0x0000007F
} DFBDisplayLayerConfigFlags;


typedef struct {
    DFBDisplayLayerConfigFlags flags;

    int width;
    int height;
    DFBSurfacePixelFormat pixelformat;
    DFBDisplayLayerBufferMode buffermode;
    DFBDisplayLayerOptions options;
    DFBDisplayLayerSourceID source;

    DFBSurfaceCapabilities surface_caps;
} DFBDisplayLayerConfig;


typedef enum {
    DSPM_ON = 0,
    DSPM_STANDBY,
    DSPM_SUSPEND,
    DSPM_OFF
} DFBScreenPowerMode;


typedef enum {
    DSMCAPS_NONE = 0x00000000,

    DSMCAPS_FULL      = 0x00000001,
    DSMCAPS_SUB_LEVEL = 0x00000002,

    DSMCAPS_SUB_LAYERS = 0x00000004,

    DSMCAPS_BACKGROUND = 0x00000008
} DFBScreenMixerCapabilities;


typedef struct {
    DFBScreenMixerCapabilities caps;

    DFBDisplayLayerIDs layers;


    int sub_num;

    DFBDisplayLayerIDs sub_layers;


    char name[24];
} DFBScreenMixerDescription;


typedef enum {
    DSMCONF_NONE = 0x00000000,

    DSMCONF_TREE   = 0x00000001,
    DSMCONF_LEVEL  = 0x00000002,
    DSMCONF_LAYERS = 0x00000004,

    DSMCONF_BACKGROUND = 0x00000010,

    DSMCONF_ALL = 0x00000017
} DFBScreenMixerConfigFlags;


typedef enum {
    DSMT_UNKNOWN = 0x00000000,

    DSMT_FULL       = 0x00000001,
    DSMT_SUB_LEVEL  = 0x00000002,
    DSMT_SUB_LAYERS = 0x00000003
} DFBScreenMixerTree;


typedef struct {
    DFBScreenMixerConfigFlags flags;

    DFBScreenMixerTree tree;

    int level;
    DFBDisplayLayerIDs layers;

    DFBColor background;
} DFBScreenMixerConfig;


typedef enum {
    DSOCAPS_NONE = 0x00000000,

    DSOCAPS_CONNECTORS = 0x00000001,

    DSOCAPS_ENCODER_SEL   = 0x00000010,
    DSOCAPS_SIGNAL_SEL    = 0x00000020,
    DSOCAPS_CONNECTOR_SEL = 0x00000040,

    DSOCAPS_ALL = 0x00000071
} DFBScreenOutputCapabilities;


typedef enum {
    DSOC_UNKNOWN = 0x00000000,

    DSOC_VGA   = 0x00000001,
    DSOC_SCART = 0x00000002,
    DSOC_YC    = 0x00000004,
    DSOC_CVBS  = 0x00000008
} DFBScreenOutputConnectors;


typedef enum {
    DSOS_NONE = 0x00000000,

    DSOS_VGA   = 0x00000001,
    DSOS_YC    = 0x00000002,
    DSOS_CVBS  = 0x00000004,
    DSOS_RGB   = 0x00000008,
    DSOS_YCBCR = 0x00000010
} DFBScreenOutputSignals;


typedef struct {
    DFBScreenOutputCapabilities caps;

    DFBScreenOutputConnectors all_connectors;
    DFBScreenOutputSignals all_signals;

    char name[24];
} DFBScreenOutputDescription;


typedef enum {
    DSOCONF_NONE = 0x00000000,

    DSOCONF_ENCODER    = 0x00000001,
    DSOCONF_SIGNALS    = 0x00000002,
    DSOCONF_CONNECTORS = 0x00000004,

    DSOCONF_ALL = 0x00000007
} DFBScreenOutputConfigFlags;


typedef struct {
    DFBScreenOutputConfigFlags flags;

    int encoder;
    DFBScreenOutputSignals out_signals;
    DFBScreenOutputConnectors out_connectors;
} DFBScreenOutputConfig;


typedef enum {
    DSECAPS_NONE = 0x00000000,

    DSECAPS_TV_STANDARDS = 0x00000001,
    DSECAPS_TEST_PICTURE = 0x00000002,
    DSECAPS_MIXER_SEL    = 0x00000004,
    DSECAPS_OUT_SIGNALS  = 0x00000008,
    DSECAPS_SCANMODE     = 0x00000010,

    DSECAPS_BRIGHTNESS = 0x00000100,
    DSECAPS_CONTRAST   = 0x00000200,
    DSECAPS_HUE        = 0x00000400,
    DSECAPS_SATURATION = 0x00000800,

    DSECAPS_ALL = 0x00000f1f
} DFBScreenEncoderCapabilities;


typedef enum {
    DSET_UNKNOWN = 0x00000000,

    DSET_CRTC = 0x00000001,
    DSET_TV   = 0x00000002
} DFBScreenEncoderType;


typedef enum {
    DSETV_UNKNOWN = 0x00000000,

    DSETV_PAL   = 0x00000001,
    DSETV_NTSC  = 0x00000002,
    DSETV_SECAM = 0x00000004
} DFBScreenEncoderTVStandards;


typedef enum {
    DSESM_UNKNOWN = 0x00000000,

    DSESM_INTERLACED  = 0x00000001,
    DSESM_PROGRESSIVE = 0x00000002
} DFBScreenEncoderScanMode;


typedef struct {
    DFBScreenEncoderCapabilities caps;
    DFBScreenEncoderType type;

    DFBScreenEncoderTVStandards tv_standards;
    DFBScreenOutputSignals out_signals;

    char name[24];
} DFBScreenEncoderDescription;


typedef enum {
    DSECONF_NONE = 0x00000000,

    DSECONF_TV_STANDARD  = 0x00000001,
    DSECONF_TEST_PICTURE = 0x00000002,
    DSECONF_MIXER        = 0x00000004,
    DSECONF_OUT_SIGNALS  = 0x00000008,
    DSECONF_SCANMODE     = 0x00000010,
    DSECONF_TEST_COLOR   = 0x00000020,
    DSECONF_ADJUSTMENT   = 0x00000040,

    DSECONF_ALL = 0x0000007F
} DFBScreenEncoderConfigFlags;


typedef enum {
    DSETP_OFF = 0x00000000,

    DSETP_MULTI  = 0x00000001,
    DSETP_SINGLE = 0x00000002,

    DSETP_WHITE   = 0x00000010,
    DSETP_YELLOW  = 0x00000020,
    DSETP_CYAN    = 0x00000030,
    DSETP_GREEN   = 0x00000040,
    DSETP_MAGENTA = 0x00000050,
    DSETP_RED     = 0x00000060,
    DSETP_BLUE    = 0x00000070,
    DSETP_BLACK   = 0x00000080
} DFBScreenEncoderTestPicture;


typedef struct {
    DFBScreenEncoderConfigFlags flags;

    DFBScreenEncoderTVStandards tv_standard;
    DFBScreenEncoderTestPicture test_picture;
    int mixer;
    DFBScreenOutputSignals out_signals;
    DFBScreenEncoderScanMode scanmode;

    DFBColor test_color;

    DFBColorAdjustment adjustment;
} DFBScreenEncoderConfig;
    # 2030 "/usr/include/directfb/directfb.h"
struct _IDirectFBScreen { void *priv; int magic; DFBResult (*AddRef)(IDirectFBScreen *thiz); DFBResult (*Release)(IDirectFBScreen *thiz); DFBResult (*GetID)(IDirectFBScreen *thiz, DFBScreenID *ret_screen_id); DFBResult (*GetDescription)(IDirectFBScreen *thiz, DFBScreenDescription *ret_desc); DFBResult (*EnumDisplayLayers)(IDirectFBScreen *thiz, DFBDisplayLayerCallback callback, void *callbackdata); DFBResult (*SetPowerMode)(IDirectFBScreen *thiz, DFBScreenPowerMode mode); DFBResult (*WaitForSync)(IDirectFBScreen *thiz); DFBResult (*GetMixerDescriptions)(IDirectFBScreen *thiz, DFBScreenMixerDescription *ret_descriptions); DFBResult (*GetMixerConfiguration)(IDirectFBScreen *thiz, int mixer, DFBScreenMixerConfig *ret_config); DFBResult (*TestMixerConfiguration)(IDirectFBScreen *thiz, int mixer, const DFBScreenMixerConfig *config, DFBScreenMixerConfigFlags *ret_failed); DFBResult (*SetMixerConfiguration)(IDirectFBScreen *thiz, int mixer, const DFBScreenMixerConfig *config); DFBResult (*GetEncoderDescriptions)(IDirectFBScreen *thiz, DFBScreenEncoderDescription *ret_descriptions); DFBResult (*GetEncoderConfiguration)(IDirectFBScreen *thiz, int encoder, DFBScreenEncoderConfig *ret_config); DFBResult (*TestEncoderConfiguration)(IDirectFBScreen *thiz, int encoder, const DFBScreenEncoderConfig *config, DFBScreenEncoderConfigFlags *ret_failed); DFBResult (*SetEncoderConfiguration)(IDirectFBScreen *thiz, int encoder, const DFBScreenEncoderConfig *config); DFBResult (*GetOutputDescriptions)(IDirectFBScreen *thiz, DFBScreenOutputDescription *ret_descriptions); DFBResult (*GetOutputConfiguration)(IDirectFBScreen *thiz, int output, DFBScreenOutputConfig *ret_config); DFBResult (*TestOutputConfiguration)(IDirectFBScreen *thiz, int output, const DFBScreenOutputConfig *config, DFBScreenOutputConfigFlags *ret_failed); DFBResult (*SetOutputConfiguration)(IDirectFBScreen *thiz, int output, const DFBScreenOutputConfig *config); };
    # 2236 "/usr/include/directfb/directfb.h"
struct _IDirectFBDisplayLayer { void *priv; int magic; DFBResult (*AddRef)(IDirectFBDisplayLayer *thiz); DFBResult (*Release)(IDirectFBDisplayLayer *thiz); DFBResult (*GetID)(IDirectFBDisplayLayer *thiz, DFBDisplayLayerID *ret_layer_id); DFBResult (*GetDescription)(IDirectFBDisplayLayer *thiz, DFBDisplayLayerDescription *ret_desc); DFBResult (*GetSourceDescriptions)(IDirectFBDisplayLayer *thiz, DFBDisplayLayerSourceDescription *ret_descriptions); DFBResult (*GetCurrentOutputField)(IDirectFBDisplayLayer *thiz, int *ret_field); DFBResult (*GetSurface)(IDirectFBDisplayLayer *thiz, IDirectFBSurface **ret_interface); DFBResult (*GetScreen)(IDirectFBDisplayLayer *thiz, IDirectFBScreen **ret_interface); DFBResult (*SetCooperativeLevel)(IDirectFBDisplayLayer *thiz, DFBDisplayLayerCooperativeLevel level); DFBResult (*GetConfiguration)(IDirectFBDisplayLayer *thiz, DFBDisplayLayerConfig *ret_config); DFBResult (*TestConfiguration)(IDirectFBDisplayLayer *thiz, const DFBDisplayLayerConfig *config, DFBDisplayLayerConfigFlags *ret_failed); DFBResult (*SetConfiguration)(IDirectFBDisplayLayer *thiz, const DFBDisplayLayerConfig *config); DFBResult (*SetScreenLocation)(IDirectFBDisplayLayer *thiz, float x, float y, float width, float height); DFBResult (*SetScreenPosition)(IDirectFBDisplayLayer *thiz, int x, int y); DFBResult (*SetScreenRectangle)(IDirectFBDisplayLayer *thiz, int x, int y, int width, int height); DFBResult (*SetOpacity)(IDirectFBDisplayLayer *thiz, __u8 opacity); DFBResult (*SetSourceRectangle)(IDirectFBDisplayLayer *thiz, int x, int y, int width, int height); DFBResult (*SetFieldParity)(IDirectFBDisplayLayer *thiz, int field); DFBResult (*SetSrcColorKey)(IDirectFBDisplayLayer *thiz, __u8 r, __u8 g, __u8 b); DFBResult (*SetDstColorKey)(IDirectFBDisplayLayer *thiz, __u8 r, __u8 g, __u8 b); DFBResult (*GetLevel)(IDirectFBDisplayLayer *thiz, int *ret_level); DFBResult (*SetLevel)(IDirectFBDisplayLayer *thiz, int level); DFBResult (*SetBackgroundMode)(IDirectFBDisplayLayer *thiz, DFBDisplayLayerBackgroundMode mode); DFBResult (*SetBackgroundImage)(IDirectFBDisplayLayer *thiz, IDirectFBSurface *surface); DFBResult (*SetBackgroundColor)(IDirectFBDisplayLayer *thiz, __u8 r, __u8 g, __u8 b, __u8 a); DFBResult (*GetColorAdjustment)(IDirectFBDisplayLayer *thiz, DFBColorAdjustment *ret_adj); DFBResult (*SetColorAdjustment)(IDirectFBDisplayLayer *thiz, const DFBColorAdjustment *adj); DFBResult (*CreateWindow)(IDirectFBDisplayLayer *thiz, const DFBWindowDescription *desc, IDirectFBWindow **ret_interface); DFBResult (*GetWindow)(IDirectFBDisplayLayer *thiz, DFBWindowID window_id, IDirectFBWindow **ret_interface); DFBResult (*EnableCursor)(IDirectFBDisplayLayer *thiz, int enable); DFBResult (*GetCursorPosition)(IDirectFBDisplayLayer *thiz, int *ret_x, int *ret_y); DFBResult (*WarpCursor)(IDirectFBDisplayLayer *thiz, int x, int y); DFBResult (*SetCursorAcceleration)(IDirectFBDisplayLayer *thiz, int numerator, int denominator, int threshold); DFBResult (*SetCursorShape)(IDirectFBDisplayLayer *thiz, IDirectFBSurface *shape, int hot_x, int hot_y); DFBResult (*SetCursorOpacity)(IDirectFBDisplayLayer *thiz, __u8 opacity); DFBResult (*WaitForSync)(IDirectFBDisplayLayer *thiz); };
    # 2649 "/usr/include/directfb/directfb.h"
typedef enum {
    DSFLIP_NONE = 0x00000000,

    DSFLIP_WAIT = 0x00000001,

    DSFLIP_BLIT = 0x00000002,


    DSFLIP_ONSYNC = 0x00000004,


    DSFLIP_PIPELINE = 0x00000008,

    DSFLIP_WAITFORSYNC = DSFLIP_WAIT | DSFLIP_ONSYNC
} DFBSurfaceFlipFlags;


typedef enum {
    DSTF_LEFT   = 0x00000000,
    DSTF_CENTER = 0x00000001,
    DSTF_RIGHT  = 0x00000002,

    DSTF_TOP = 0x00000004,

    DSTF_BOTTOM = 0x00000008,


    DSTF_TOPLEFT   = DSTF_TOP | DSTF_LEFT,
    DSTF_TOPCENTER = DSTF_TOP | DSTF_CENTER,
    DSTF_TOPRIGHT  = DSTF_TOP | DSTF_RIGHT,

    DSTF_BOTTOMLEFT   = DSTF_BOTTOM | DSTF_LEFT,
    DSTF_BOTTOMCENTER = DSTF_BOTTOM | DSTF_CENTER,
    DSTF_BOTTOMRIGHT  = DSTF_BOTTOM | DSTF_RIGHT
} DFBSurfaceTextFlags;


typedef enum {
    DSLF_READ = 0x00000001,

    DSLF_WRITE = 0x00000002
} DFBSurfaceLockFlags;


typedef enum {
    DSPD_NONE     = 0,
    DSPD_CLEAR    = 1,
    DSPD_SRC      = 2,
    DSPD_SRC_OVER = 3,
    DSPD_DST_OVER = 4,
    DSPD_SRC_IN   = 5,
    DSPD_DST_IN   = 6,
    DSPD_SRC_OUT  = 7,
    DSPD_DST_OUT  = 8
} DFBSurfacePorterDuffRule;


typedef enum {
    DSBF_ZERO         = 1,
    DSBF_ONE          = 2,
    DSBF_SRCCOLOR     = 3,
    DSBF_INVSRCCOLOR  = 4,
    DSBF_SRCALPHA     = 5,
    DSBF_INVSRCALPHA  = 6,
    DSBF_DESTALPHA    = 7,
    DSBF_INVDESTALPHA = 8,
    DSBF_DESTCOLOR    = 9,
    DSBF_INVDESTCOLOR = 10,
    DSBF_SRCALPHASAT  = 11
} DFBSurfaceBlendFunction;


typedef struct {
    float x;
    float y;
    float z;
    float w;

    float s;
    float t;
} DFBVertex;


typedef enum {
    DTTF_LIST,
    DTTF_STRIP,
    DTTF_FAN
} DFBTriangleFormation;
    # 2763 "/usr/include/directfb/directfb.h"
struct _IDirectFBSurface { void *priv; int magic; DFBResult (*AddRef)(IDirectFBSurface *thiz); DFBResult (*Release)(IDirectFBSurface *thiz); DFBResult (*GetCapabilities)(IDirectFBSurface *thiz, DFBSurfaceCapabilities *ret_caps); DFBResult (*GetSize)(IDirectFBSurface *thiz, int *ret_width, int *ret_height); DFBResult (*GetVisibleRectangle)(IDirectFBSurface *thiz, DFBRectangle *ret_rect); DFBResult (*GetPixelFormat)(IDirectFBSurface *thiz, DFBSurfacePixelFormat *ret_format); DFBResult (*GetAccelerationMask)(IDirectFBSurface *thiz, IDirectFBSurface *source, DFBAccelerationMask *ret_mask); DFBResult (*GetPalette)(IDirectFBSurface *thiz, IDirectFBPalette **ret_interface); DFBResult (*SetPalette)(IDirectFBSurface *thiz, IDirectFBPalette *palette); DFBResult (*SetAlphaRamp)(IDirectFBSurface *thiz, __u8 a0, __u8 a1, __u8 a2, __u8 a3); DFBResult (*Lock)(IDirectFBSurface *thiz, DFBSurfaceLockFlags flags, void **ret_ptr, int *ret_pitch); DFBResult (*Unlock)(IDirectFBSurface *thiz); DFBResult (*Flip)(IDirectFBSurface *thiz, const DFBRegion *region, DFBSurfaceFlipFlags flags); DFBResult (*SetField)(IDirectFBSurface *thiz, int field); DFBResult (*Clear)(IDirectFBSurface *thiz, __u8 r, __u8 g, __u8 b, __u8 a); DFBResult (*SetClip)(IDirectFBSurface *thiz, const DFBRegion *clip); DFBResult (*SetColor)(IDirectFBSurface *thiz, __u8 r, __u8 g, __u8 b, __u8 a); DFBResult (*SetColorIndex)(IDirectFBSurface *thiz, unsigned int index); DFBResult (*SetSrcBlendFunction)(IDirectFBSurface *thiz, DFBSurfaceBlendFunction function); DFBResult (*SetDstBlendFunction)(IDirectFBSurface *thiz, DFBSurfaceBlendFunction function); DFBResult (*SetPorterDuff)(IDirectFBSurface *thiz, DFBSurfacePorterDuffRule rule); DFBResult (*SetSrcColorKey)(IDirectFBSurface *thiz, __u8 r, __u8 g, __u8 b); DFBResult (*SetSrcColorKeyIndex)(IDirectFBSurface *thiz, unsigned int index); DFBResult (*SetDstColorKey)(IDirectFBSurface *thiz, __u8 r, __u8 g, __u8 b); DFBResult (*SetDstColorKeyIndex)(IDirectFBSurface *thiz, unsigned int index); DFBResult (*SetBlittingFlags)(IDirectFBSurface *thiz, DFBSurfaceBlittingFlags flags); DFBResult (*Blit)(IDirectFBSurface *thiz, IDirectFBSurface *source, const DFBRectangle *source_rect, int x, int y); DFBResult (*TileBlit)(IDirectFBSurface *thiz, IDirectFBSurface *source, const DFBRectangle *source_rect, int x, int y); DFBResult (*BatchBlit)(IDirectFBSurface *thiz, IDirectFBSurface *source, const DFBRectangle *source_rects, const DFBPoint *dest_points, int num); DFBResult (*StretchBlit)(IDirectFBSurface *thiz, IDirectFBSurface *source, const DFBRectangle *source_rect, const DFBRectangle *destination_rect); DFBResult (*TextureTriangles)(IDirectFBSurface *thiz, IDirectFBSurface *texture, const DFBVertex *vertices, const int *indices, int num, DFBTriangleFormation formation); DFBResult (*SetDrawingFlags)(IDirectFBSurface *thiz, DFBSurfaceDrawingFlags flags); DFBResult (*FillRectangle)(IDirectFBSurface *thiz, int x, int y, int w, int h); DFBResult (*DrawRectangle)(IDirectFBSurface *thiz, int x, int y, int w, int h); DFBResult (*DrawLine)(IDirectFBSurface *thiz, int x1, int y1, int x2, int y2); DFBResult (*DrawLines)(IDirectFBSurface *thiz, const DFBRegion *lines, unsigned int num_lines); DFBResult (*FillTriangle)(IDirectFBSurface *thiz, int x1, int y1, int x2, int y2, int x3, int y3); DFBResult (*FillRectangles)(IDirectFBSurface *thiz, const DFBRectangle *rects, unsigned int num); DFBResult (*FillSpans)(IDirectFBSurface *thiz, int y, const DFBSpan *spans, unsigned int num); DFBResult (*SetFont)(IDirectFBSurface *thiz, IDirectFBFont *font); DFBResult (*GetFont)(IDirectFBSurface *thiz, IDirectFBFont **ret_font); DFBResult (*DrawString)(IDirectFBSurface *thiz, const char *text, int bytes, int x, int y, DFBSurfaceTextFlags flags); DFBResult (*DrawGlyph)(IDirectFBSurface *thiz, unsigned int index, int x, int y, DFBSurfaceTextFlags flags); DFBResult (*GetSubSurface)(IDirectFBSurface *thiz, const DFBRectangle *rect, IDirectFBSurface **ret_interface); DFBResult (*GetGL)(IDirectFBSurface *thiz, IDirectFBGL **ret_interface); DFBResult (*Dump)(IDirectFBSurface *thiz, const char *directory, const char *prefix); };
    # 3354 "/usr/include/directfb/directfb.h"
struct _IDirectFBPalette { void *priv; int magic; DFBResult (*AddRef)(IDirectFBPalette *thiz); DFBResult (*Release)(IDirectFBPalette *thiz); DFBResult (*GetCapabilities)(IDirectFBPalette *thiz, DFBPaletteCapabilities *ret_caps); DFBResult (*GetSize)(IDirectFBPalette *thiz, unsigned int *ret_size); DFBResult (*SetEntries)(IDirectFBPalette *thiz, const DFBColor *entries, unsigned int num_entries, unsigned int offset); DFBResult (*GetEntries)(IDirectFBPalette *thiz, DFBColor *ret_entries, unsigned int num_entries, unsigned int offset); DFBResult (*FindBestMatch)(IDirectFBPalette *thiz, __u8 r, __u8 g, __u8 b, __u8 a, unsigned int *ret_index); DFBResult (*CreateCopy)(IDirectFBPalette *thiz, IDirectFBPalette **ret_interface); };
    # 3433 "/usr/include/directfb/directfb.h"
typedef enum {
    DIKS_UP   = 0x00000000,
    DIKS_DOWN = 0x00000001
} DFBInputDeviceKeyState;


typedef enum {
    DIBS_UP   = 0x00000000,
    DIBS_DOWN = 0x00000001
} DFBInputDeviceButtonState;


typedef enum {
    DIBM_LEFT   = 0x00000001,
    DIBM_RIGHT  = 0x00000002,
    DIBM_MIDDLE = 0x00000004
} DFBInputDeviceButtonMask;


typedef enum {
    DIMM_SHIFT   = (1 << DIMKI_SHIFT),
    DIMM_CONTROL = (1 << DIMKI_CONTROL),
    DIMM_ALT     = (1 << DIMKI_ALT),
    DIMM_ALTGR   = (1 << DIMKI_ALTGR),
    DIMM_META    = (1 << DIMKI_META),
    DIMM_SUPER   = (1 << DIMKI_SUPER),
    DIMM_HYPER   = (1 << DIMKI_HYPER)
} DFBInputDeviceModifierMask;
    # 3476 "/usr/include/directfb/directfb.h"
struct _IDirectFBInputDevice { void *priv; int magic; DFBResult (*AddRef)(IDirectFBInputDevice *thiz); DFBResult (*Release)(IDirectFBInputDevice *thiz); DFBResult (*GetID)(IDirectFBInputDevice *thiz, DFBInputDeviceID *ret_device_id); DFBResult (*GetDescription)(IDirectFBInputDevice *thiz, DFBInputDeviceDescription *ret_desc); DFBResult (*GetKeymapEntry)(IDirectFBInputDevice *thiz, int keycode, DFBInputDeviceKeymapEntry *ret_entry); DFBResult (*CreateEventBuffer)(IDirectFBInputDevice *thiz, IDirectFBEventBuffer **ret_buffer); DFBResult (*AttachEventBuffer)(IDirectFBInputDevice *thiz, IDirectFBEventBuffer *buffer); DFBResult (*GetKeyState)(IDirectFBInputDevice *thiz, DFBInputDeviceKeyIdentifier key_id, DFBInputDeviceKeyState *ret_state); DFBResult (*GetModifiers)(IDirectFBInputDevice *thiz, DFBInputDeviceModifierMask *ret_modifiers); DFBResult (*GetLockState)(IDirectFBInputDevice *thiz, DFBInputDeviceLockState *ret_locks); DFBResult (*GetButtons)(IDirectFBInputDevice *thiz, DFBInputDeviceButtonMask *ret_buttons); DFBResult (*GetButtonState)(IDirectFBInputDevice *thiz, DFBInputDeviceButtonIdentifier button, DFBInputDeviceButtonState *ret_state); DFBResult (*GetAxis)(IDirectFBInputDevice *thiz, DFBInputDeviceAxisIdentifier axis, int *ret_pos); DFBResult (*GetXY)(IDirectFBInputDevice *thiz, int *ret_x, int *ret_y); };
    # 3605 "/usr/include/directfb/directfb.h"
typedef enum {
    DFEC_NONE   = 0x00,
    DFEC_INPUT  = 0x01,
    DFEC_WINDOW = 0x02,
    DFEC_USER   = 0x03
} DFBEventClass;


typedef enum {
    DIET_UNKNOWN = 0,
    DIET_KEYPRESS,
    DIET_KEYRELEASE,
    DIET_BUTTONPRESS,
    DIET_BUTTONRELEASE,
    DIET_AXISMOTION
} DFBInputEventType;


typedef enum {
    DIEF_NONE      = 0x000,
    DIEF_TIMESTAMP = 0x001,
    DIEF_AXISABS   = 0x002,
    DIEF_AXISREL   = 0x004,

    DIEF_KEYCODE = 0x008,

    DIEF_KEYID = 0x010,

    DIEF_KEYSYMBOL = 0x020,

    DIEF_MODIFIERS = 0x040,

    DIEF_LOCKS = 0x080,

    DIEF_BUTTONS = 0x100,

    DIEF_GLOBAL = 0x200
} DFBInputEventFlags;


typedef struct {
    DFBEventClass clazz;

    DFBInputEventType type;
    DFBInputDeviceID device_id;
    DFBInputEventFlags flags;


    struct timeval timestamp;


    int key_code;


    DFBInputDeviceKeyIdentifier key_id;

    DFBInputDeviceKeySymbol key_symbol;


    DFBInputDeviceModifierMask modifiers;

    DFBInputDeviceLockState locks;


    DFBInputDeviceButtonIdentifier button;

    DFBInputDeviceButtonMask buttons;


    DFBInputDeviceAxisIdentifier axis;


    int axisabs;

    int axisrel;
} DFBInputEvent;


typedef enum {
    DWET_NONE = 0x00000000,

    DWET_POSITION = 0x00000001,


    DWET_SIZE = 0x00000002,


    DWET_CLOSE = 0x00000004,

    DWET_DESTROYED = 0x00000008,


    DWET_GOTFOCUS  = 0x00000010,
    DWET_LOSTFOCUS = 0x00000020,

    DWET_KEYDOWN = 0x00000100,

    DWET_KEYUP = 0x00000200,


    DWET_BUTTONDOWN = 0x00010000,

    DWET_BUTTONUP = 0x00020000,

    DWET_MOTION = 0x00040000,

    DWET_ENTER = 0x00080000,

    DWET_LEAVE = 0x00100000,

    DWET_WHEEL = 0x00200000,


    DWET_POSITION_SIZE = DWET_POSITION | DWET_SIZE,


    DWET_ALL = 0x003F033F
} DFBWindowEventType;


typedef struct {
    DFBEventClass clazz;

    DFBWindowEventType type;
    DFBWindowID window_id;


    int x;


    int y;


    int cx;
    int cy;


    int step;


    int w;
    int h;


    int key_code;


    DFBInputDeviceKeyIdentifier key_id;

    DFBInputDeviceKeySymbol key_symbol;


    DFBInputDeviceModifierMask modifiers;
    DFBInputDeviceLockState locks;


    DFBInputDeviceButtonIdentifier button;


    DFBInputDeviceButtonMask buttons;


    struct timeval timestamp;
} DFBWindowEvent;


typedef struct {
    DFBEventClass clazz;

    unsigned int type;
    void *data;
} DFBUserEvent;


typedef union {
    DFBEventClass clazz;
    DFBInputEvent input;
    DFBWindowEvent window;
    DFBUserEvent user;
} DFBEvent;
    # 3827 "/usr/include/directfb/directfb.h"
struct _IDirectFBEventBuffer { void *priv; int magic; DFBResult (*AddRef)(IDirectFBEventBuffer *thiz); DFBResult (*Release)(IDirectFBEventBuffer *thiz); DFBResult (*Reset)(IDirectFBEventBuffer *thiz); DFBResult (*WaitForEvent)(IDirectFBEventBuffer *thiz); DFBResult (*WaitForEventWithTimeout)(IDirectFBEventBuffer *thiz, unsigned int seconds, unsigned int milli_seconds); DFBResult (*GetEvent)(IDirectFBEventBuffer *thiz, DFBEvent *ret_event); DFBResult (*PeekEvent)(IDirectFBEventBuffer *thiz, DFBEvent *ret_event); DFBResult (*HasEvent)(IDirectFBEventBuffer *thiz); DFBResult (*PostEvent)(IDirectFBEventBuffer *thiz, const DFBEvent *event); DFBResult (*WakeUp)(IDirectFBEventBuffer *thiz); DFBResult (*CreateFileDescriptor)(IDirectFBEventBuffer *thiz, int *ret_fd); };
    # 3939 "/usr/include/directfb/directfb.h"
typedef enum {
    DWOP_NONE         = 0x00000000,
    DWOP_COLORKEYING  = 0x00000001,
    DWOP_ALPHACHANNEL = 0x00000002,

    DWOP_OPAQUE_REGION = 0x00000004,

    DWOP_SHAPED = 0x00000008,


    DWOP_KEEP_POSITION = 0x00000010,

    DWOP_KEEP_SIZE = 0x00000020,

    DWOP_KEEP_STACKING = 0x00000040,

    DWOP_GHOST = 0x00001000,


    DWOP_INDESTRUCTIBLE = 0x00002000,

    DWOP_ALL = 0x0000307F
} DFBWindowOptions;


typedef enum {
    DWSC_MIDDLE = 0x00000000,

    DWSC_UPPER = 0x00000001,


    DWSC_LOWER = 0x00000002
} DFBWindowStackingClass;
    # 3988 "/usr/include/directfb/directfb.h"
struct _IDirectFBWindow { void *priv; int magic; DFBResult (*AddRef)(IDirectFBWindow *thiz); DFBResult (*Release)(IDirectFBWindow *thiz); DFBResult (*GetID)(IDirectFBWindow *thiz, DFBWindowID *ret_window_id); DFBResult (*GetPosition)(IDirectFBWindow *thiz, int *ret_x, int *ret_y); DFBResult (*GetSize)(IDirectFBWindow *thiz, int *ret_width, int *ret_height); DFBResult (*CreateEventBuffer)(IDirectFBWindow *thiz, IDirectFBEventBuffer **ret_buffer); DFBResult (*AttachEventBuffer)(IDirectFBWindow *thiz, IDirectFBEventBuffer *buffer); DFBResult (*EnableEvents)(IDirectFBWindow *thiz, DFBWindowEventType mask); DFBResult (*DisableEvents)(IDirectFBWindow *thiz, DFBWindowEventType mask); DFBResult (*GetSurface)(IDirectFBWindow *thiz, IDirectFBSurface **ret_surface); DFBResult (*SetOptions)(IDirectFBWindow *thiz, DFBWindowOptions options); DFBResult (*GetOptions)(IDirectFBWindow *thiz, DFBWindowOptions *ret_options); DFBResult (*SetColorKey)(IDirectFBWindow *thiz, __u8 r, __u8 g, __u8 b); DFBResult (*SetColorKeyIndex)(IDirectFBWindow *thiz, unsigned int index); DFBResult (*SetOpacity)(IDirectFBWindow *thiz, __u8 opacity); DFBResult (*SetOpaqueRegion)(IDirectFBWindow *thiz, int x1, int y1, int x2, int y2); DFBResult (*GetOpacity)(IDirectFBWindow *thiz, __u8 *ret_opacity); DFBResult (*SetCursorShape)(IDirectFBWindow *thiz, IDirectFBSurface *shape, int hot_x, int hot_y); DFBResult (*RequestFocus)(IDirectFBWindow *thiz); DFBResult (*GrabKeyboard)(IDirectFBWindow *thiz); DFBResult (*UngrabKeyboard)(IDirectFBWindow *thiz); DFBResult (*GrabPointer)(IDirectFBWindow *thiz); DFBResult (*UngrabPointer)(IDirectFBWindow *thiz); DFBResult (*GrabKey)(IDirectFBWindow *thiz, DFBInputDeviceKeySymbol symbol, DFBInputDeviceModifierMask modifiers); DFBResult (*UngrabKey)(IDirectFBWindow *thiz, DFBInputDeviceKeySymbol symbol, DFBInputDeviceModifierMask modifiers); DFBResult (*Move)(IDirectFBWindow *thiz, int dx, int dy); DFBResult (*MoveTo)(IDirectFBWindow *thiz, int x, int y); DFBResult (*Resize)(IDirectFBWindow *thiz, int width, int height); DFBResult (*SetStackingClass)(IDirectFBWindow *thiz, DFBWindowStackingClass stacking_class); DFBResult (*Raise)(IDirectFBWindow *thiz); DFBResult (*Lower)(IDirectFBWindow *thiz); DFBResult (*RaiseToTop)(IDirectFBWindow *thiz); DFBResult (*LowerToBottom)(IDirectFBWindow *thiz); DFBResult (*PutAtop)(IDirectFBWindow *thiz, IDirectFBWindow *lower); DFBResult (*PutBelow)(IDirectFBWindow *thiz, IDirectFBWindow *upper); DFBResult (*Close)(IDirectFBWindow *thiz); DFBResult (*Destroy)(IDirectFBWindow *thiz); };
    # 4356 "/usr/include/directfb/directfb.h"
struct _IDirectFBFont { void *priv; int magic; DFBResult (*AddRef)(IDirectFBFont *thiz); DFBResult (*Release)(IDirectFBFont *thiz); DFBResult (*GetAscender)(IDirectFBFont *thiz, int *ret_ascender); DFBResult (*GetDescender)(IDirectFBFont *thiz, int *ret_descender); DFBResult (*GetHeight)(IDirectFBFont *thiz, int *ret_height); DFBResult (*GetMaxAdvance)(IDirectFBFont *thiz, int *ret_maxadvance); DFBResult (*GetKerning)(IDirectFBFont *thiz, unsigned int prev_index, unsigned int current_index, int *ret_kern_x, int *ret_kern_y); DFBResult (*GetStringWidth)(IDirectFBFont *thiz, const char *text, int bytes, int *ret_width); DFBResult (*GetStringExtents)(IDirectFBFont *thiz, const char *text, int bytes, DFBRectangle *ret_logical_rect, DFBRectangle *ret_ink_rect); DFBResult (*GetGlyphExtents)(IDirectFBFont *thiz, unsigned int index, DFBRectangle *ret_rect, int *ret_advance); };
    # 4492 "/usr/include/directfb/directfb.h"
typedef enum {
    DICAPS_NONE         = 0x00000000,
    DICAPS_ALPHACHANNEL = 0x00000001,

    DICAPS_COLORKEY = 0x00000002
} DFBImageCapabilities;


typedef struct {
    DFBImageCapabilities caps;

    __u8 colorkey_r;
    __u8 colorkey_g;
    __u8 colorkey_b;
} DFBImageDescription;


typedef void (*DIRenderCallback)(DFBRectangle *rect, void *ctx);
    # 4526 "/usr/include/directfb/directfb.h"
struct _IDirectFBImageProvider { void *priv; int magic; DFBResult (*AddRef)(IDirectFBImageProvider *thiz); DFBResult (*Release)(IDirectFBImageProvider *thiz); DFBResult (*GetSurfaceDescription)(IDirectFBImageProvider *thiz, DFBSurfaceDescription *ret_dsc); DFBResult (*GetImageDescription)(IDirectFBImageProvider *thiz, DFBImageDescription *ret_dsc); DFBResult (*RenderTo)(IDirectFBImageProvider *thiz, IDirectFBSurface *destination, const DFBRectangle *destination_rect); DFBResult (*SetRenderCallback)(IDirectFBImageProvider *thiz, DIRenderCallback callback, void *callback_data); };
    # 4592 "/usr/include/directfb/directfb.h"
typedef int (*DVFrameCallback)(void *ctx);
    # 4602 "/usr/include/directfb/directfb.h"
struct _IDirectFBVideoProvider { void *priv; int magic; DFBResult (*AddRef)(IDirectFBVideoProvider *thiz); DFBResult (*Release)(IDirectFBVideoProvider *thiz); DFBResult (*GetCapabilities)(IDirectFBVideoProvider *thiz, DFBVideoProviderCapabilities *ret_caps); DFBResult (*GetSurfaceDescription)(IDirectFBVideoProvider *thiz, DFBSurfaceDescription *ret_dsc); DFBResult (*PlayTo)(IDirectFBVideoProvider *thiz, IDirectFBSurface *destination, const DFBRectangle *destination_rect, DVFrameCallback callback, void *ctx); DFBResult (*Stop)(IDirectFBVideoProvider *thiz); DFBResult (*SeekTo)(IDirectFBVideoProvider *thiz, double seconds); DFBResult (*GetPos)(IDirectFBVideoProvider *thiz, double *ret_seconds); DFBResult (*GetLength)(IDirectFBVideoProvider *thiz, double *ret_seconds); DFBResult (*GetColorAdjustment)(IDirectFBVideoProvider *thiz, DFBColorAdjustment *ret_adj); DFBResult (*SetColorAdjustment)(IDirectFBVideoProvider *thiz, const DFBColorAdjustment *adj); };
    # 4708 "/usr/include/directfb/directfb.h"
struct _IDirectFBDataBuffer { void *priv; int magic; DFBResult (*AddRef)(IDirectFBDataBuffer *thiz); DFBResult (*Release)(IDirectFBDataBuffer *thiz); DFBResult (*Flush)(IDirectFBDataBuffer *thiz); DFBResult (*SeekTo)(IDirectFBDataBuffer *thiz, unsigned int offset); DFBResult (*GetPosition)(IDirectFBDataBuffer *thiz, unsigned int *ret_offset); DFBResult (*GetLength)(IDirectFBDataBuffer *thiz, unsigned int *ret_length); DFBResult (*WaitForData)(IDirectFBDataBuffer *thiz, unsigned int length); DFBResult (*WaitForDataWithTimeout)(IDirectFBDataBuffer *thiz, unsigned int length, unsigned int seconds, unsigned int milli_seconds); DFBResult (*GetData)(IDirectFBDataBuffer *thiz, unsigned int length, void *ret_data, unsigned int *ret_read); DFBResult (*PeekData)(IDirectFBDataBuffer *thiz, unsigned int length, int offset, void *ret_data, unsigned int *ret_read); DFBResult (*HasData)(IDirectFBDataBuffer *thiz); DFBResult (*PutData)(IDirectFBDataBuffer *thiz, const void *data, unsigned int length); DFBResult (*CreateImageProvider)(IDirectFBDataBuffer *thiz, IDirectFBImageProvider **interface); };


// c/dos.c
/**
 * This is your typical header comment
 */
int foo(int bar){
    int idx;
    int res = 0;     // trailing comment
                     // that spans two lines
    for (idx = 1; idx < bar; idx++) {
        /* comment in virtual braces */
        res += idx;
    }


    res *= idx;       // some comment

    // almost continued, but a NL in between

// col1 comment in level 1
    return(res);
}

// col1 comment in level 0

/*
   Silly multiline comment.

   Oh yes.

   Really
 */


// c/doxy-comment.c
int a; // a
int a; ///a
int a; ///<a
int a; // !a
int a; // !<a


// c/else-if.c
int test (int A, int B){
    int C;

    if (A == 0) {
        if (B == 0) {
            C = 1;
        } else if (B == 1) {
            C = 2;
        } else {
            C = 3;
        }
    } else if (A == 1) {
        if (B == 0) {
            C = 4;
        } else if (B == 1) {
            C = 5;
        } else {
            C = 6;
        }
    } else if (B == 0) {
        C = 7;
    } else if (B == 1) {
        C = 8;
    } else {
        C = 9;
    }

    return C;
}

// c/empty-for.c
void foo(void){
    for (; x<2; x++) {
    }
}

// c/endif.c
int do_this
(
    int x,
    int y
){
    x++;
    #ifdef ABC
    #ifdef DEF
    x += y;
    #endif /* ifdef DEF */
    #endif /* ifdef ABC */
    a++;
    #ifdef ABC
    b++;
    #ifdef DEF
    c++;
    #ifdef HIJ
    d++;
    #endif /* ifdef HIJ */
    e++;
    #endif /* ifdef DEF */
    f++;
    #endif /* ifdef ABC */
    g++;

    return (x)
}

// c/enum-struct-init.c

enum foo_idx {
    FOO_1,
    FOO_2,
    FOO_3,
};

struct foo {
    const char *str;
    int values[8];
};

struct foo bar[] =
{
    [FOO_1] = {
        "junk",
        { 1 }
    },

    [FOO_2] = {
        "morejunk",
        {1, 2, 3}
    },

    [FOO_3] = {
        "somemore",
        {1, 2, 3, 4, 5, 6}
    },
};


// c/enum_gallery.c
enum one { liner };

enum not {
    a, one

    liner
}

enum foo { bar, baz, quux };

/*
 * In some tests, the following line remains longer than 80
 * characters. Perhaps a bug?
 */
enum longer_enum_that { will, not, all, fit, on, one, line, as, longg, as, the, cutoff, is, reasonable, because, this, is, a, very, very, wide, line };

enum q { w,
         e, r,
         t,


         y}


;

// c/fcn_indent.c
int this_is_a_function_proto(int a,
                             char *b);

int this_is_a_function_def(int a,
                           char *b){
    this_is_a_function_call(a,
                            b);

    a = another_function_call(a,
                              b);
}

typedef const char*pu8_t;

typedef short (*hello1)(char coolParam,
                        ushort*,
                        unsigned int anotherone);

typedef const unsigned char* (getfcn_t)(
    int idx, ulong op);

short (*hello2)(char coolParam,
                ulong*,
                uchar,
                unsigned int anotherone);

const unsigned char* (*getstr)(
    int idx,
    ulong op);

short hello3 (char coolParam,
              ushort*,
              unsigned int anotherone);


// c/fcn_indent_func_def_col1.c
    #if A
/* dfsdsdfd */
int X;
    #endif /* if A */

    #if A
void func1_1(void);
    #endif /* if A */

    #if A
        #if A
int X1;
void func1_1(void){
    #if A
/* ttiti */
    if (B) {
        #if A
/* dsfdf */
        a = 5;
        #endif /* if A */
    }
    #endif /* if A */
}

int Y1;

void func1_2(void){
}

int Z1;
        #endif /* if A */
    #endif /* if A */

    #if A
        #if A
int X2;
/* fsdsfd */
void func2_1(void){
    #if A
/* ttiti */
    if (B) {
        #if A
/* dsfdf */
        a = 5;
        #endif /* if A */
    }
    #endif /* if A */
}

int Y2;
        #endif /* if A */
    #endif /* if A */


// c/fcn_type.c
typedef void (*my_fcn_ptr)(char*, int);
typedef const char*(my_fcn_ptr)(char*, int);
typedef int (my_fcn_ptr)(char*, int);
typedef struct foo*(my_fcn_ptr)(char*, int);
typedef enum foo*(*my_fcn_ptr)(char*, int);
typedef const struct foo*(*my_fcn_ptr)(char*, int);
typedef BOOL (my_fcn_ptr)(char*, int);
typedef INT32 (*my_fcn_ptr)(char*, int);
typedef int INT32;
typedef struct foo {
    int a;
} fooey;

typedef struct {
    int a;
} queso;

struct myfoo {
    INT32 age;
    const struct foo* (*my_fcn_ptr)(char*, int);
    const CHAR *name;
    MYTYPE (*foo)(int, char);
    void *user;
    void (*foo)(int, char);
};

SMU foo(void){
    double AAA = 1.e-3, BBB = 0.016, CCC = 2 * DDD * sqrt(EEE);
    a = 4;
    (*ABC)();

    return SMUIFY(a);
}

typedef struct {
    void (*newObject)(const object_info *info, const IObject **interface, struct object_h *instance);
} IObjectFactory;


// c/for-space.c
void f(){
    for (; it != Values.end(); ++it) {
        BTree.insert(std::pair < int, double > (*it, double(*it) + 1.0));
    }


    for (; vIt != Values.end(); ++vIt) {
    }
    for (; vIt != Values.end(); ++vIt) {
    }

    for (;; ) {
    }
    for (int i = 0; i < 42; ) {
        i += 3;
    }

    for (int i = 0; i < 42; ++i) {
        k += 3;
    }
}

// c/freebsd.c
/* Make the structure name match the typedef. */
typedef struct bar {
    int level;
} BAR;
typedef int foo;        /* This is foo. */
typedef const long baz;     /* This is baz. */


static char* function(int _arg, const char *_arg2, struct foo *_arg3,
                      struct bar *_arg4);
static void  usage(void);

/*
 * All major routines should have a comment briefly describing what
 * they do.  The comment before the "main" routine should describe
 * what the program does.
 */
int
main(int argc, char *argv[]){
    char *ep;
    long num;
    int ch;

    while ((ch = getopt(argc, argv, "abNn:")) != -1) {
        switch (ch) {       /* Indent the switch. */
            case 'a':   /* Don't indent the case. */
                aflag = 1; /* Indent case body one tab. */

            /* FALLTHROUGH */
            case 'b':
                bflag = 1;
                break;

            case 'N':
                Nflag = 1;
                break;

            case 'n':
                num = strtol(optarg, &ep, 10);
                if (num <= 0 || *ep != '\0') {
                    warnx("illegal number, -n argument -- %s",
                          optarg);
                    usage();
                }
                break;

            case '?':
            default:
                usage();
                /* NOTREACHED */
        } /* switch */
    }
    argc -= optind;
    argv += optind;

    for (p = buf; *p != '\0'; ++p) {
        /* nothing */
    }
    for (;; ) {
        stmt;
    }
    for (;; ) {
        zed = a + really + long + statement + that + needs +
              two + lines + gets + indented + four + spaces +
              on + the + second + and + subsequent + lines;
    }
    for (;; ) {
        if (cond) {
            stmt;
        }
    }
    if (val != NULL) {
        val = realloc(val, newsize);
    }

    fcn_call(with, a, really, long, list, of, parameters,
             that, spans, two, lines);

    for (; cnt < 15; cnt++) {
        stmt1;
        stmt2;
    }

    almod = (chunk_is_single_line_comment(pc) &&
             cpd.settings[UO_indent_relative_single_line_comments].b)?
            ALMODE_KEEP_REL:ALMODE_KEEP_ABS;

    /* Indentation is an 8 character tab.  Second level indents are four spaces.
     * If you have to wrap a long statement, put the operator at the end of the
     * line.
     */

    while (cnt < 20 && this_variable_name_is_too_long &&
           ep != NULL) {
        zappy = a + really + long + statement + that + needs
                + two + lines + gets + indented + four + spaces +
                on + the + second + and + subsequent + lines;
    }

    // Do not add whitespace at the end of a line, and only use tabs followed by
    // spaces to form the indentation.  Do not use more spaces than a tab will
    // produce and do not use spaces in front of tabs.
    //
    // Closing and opening braces go on the same line as the else.  Braces that
    // are not necessary may be left out.

    if (test) {
        stmt;
    } else if (bar) {
        stmt;
        stmt;
    } else {
        stmt;
    }

    // No spaces after function names.  Commas have a space after them.  No spa-
    // ces after `(' or `[' or preceding `]' or `)' characters.

    error = function(a1, a2);
    if (error != 0) {
        exit(error);
    }

    // Unary operators do not require spaces, binary operators do.  Do not use
    // parentheses unless they are required for precedence or unless the state-
    // ment is confusing without them.  Remember that other people may confuse
    // easier than you.  Do YOU understand the following?

    a = b->c[0] + ~d == (e || f) || g && h?i:j >> 1;
    k = !(l & FLAGS);


    // Exits should be 0 on success, or 1 on failure.

    exit(0);       /*
                    * Avoid obvious comments such as
                    * "Exit 0 on success."
                    */
} /* main */

static char*
function(a1, a2, fl, a4)
int a1, a2;              /* Declare ints, too, don't default them. */
float fl;                /* Beware double vs. float prototype differences. */
int a4;                  /* List in order declared. */
{
}


// c/func_call_user.c
int func(n){
    int a     = foo ();
    char *a   = _("some text");
    char *str = N_("other text");
}

// c/func_wrap.c

void FSUB(MPI_Foo)(MPI_Fint * sendcount);


// c/funcfunc.c
int main(){
    mWriter("class Clst_"c)(cluster.getChild(HO_SHORT_NAME).getText() )(" : Cluster {"c).newline;
}

// c/function-def.c
void foo1(int param1, int param2, char *param2);

void foo2(int param1,
          int param2,
          char *param2);

void foo3(int param1,
          int param2,
          char *param2
          );

struct whoopee* foo4(int param1, int param2, char *param2);

const struct snickers*
foo5(int param1, int param2, char *param2);


void foo(int param1, int param2, char *param2){
    printf("boo!\n");
}

EXPORT int DoStuff(int Num);


// c/gh399.c


void foo(){
    for (i = 0; i *i < n; i++) {
    }
}

// c/global-vars.c

static int another_try;
struct something yup;
align_me_t please;
const char *name = "hello";
static nothing really;


// c/hello.c
    #include <stdio.h>

void HelloWorld(char *pString){
    printf("%s\n", pString);
} /* HelloWorld */

int main(){
    HelloWorld("Hello world");

    return 0;
} /* main */

// c/i2c-core.c
/* i2c-core.c - a device driver for the iic-bus interface
   ------------------------------------------------------------------------- */
/*   Copyright (C) 1995-99 Simon G. Vogl

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.            */
/* ------------------------------------------------------------------------- */

/* With some changes from Ky�sti M�lkki <kmalkki@cc.hut.fi>.
   All SMBus-related things are written by Frodo Looijaard <frodol@dds.nl>
   SMBus 2.0 support by Mark Studebaker <mdsxyz123@yahoo.com>                */

    #include <linux/module.h>
    #include <linux/kernel.h>
    #include <linux/errno.h>
    #include <linux/slab.h>
    #include <linux/i2c.h>
    #include <linux/init.h>
    #include <linux/idr.h>
    #include <linux/seq_file.h>
    #include <asm/uaccess.h>


static LIST_HEAD(adapters);
static LIST_HEAD(drivers);
static DECLARE_MUTEX(core_lists);
static DEFINE_IDR(i2c_adapter_idr);

static int i2c_device_match(struct device *dev, struct device_driver *drv){
    return 1;
}

static int i2c_bus_suspend(struct device *dev, pm_message_t state){
    int rc = 0;

    if (dev->driver && dev->driver->suspend) {
        rc = dev->driver->suspend(dev, state, 0);
    }

    return rc;
}

static int i2c_bus_resume(struct device *dev){
    int rc = 0;

    if (dev->driver && dev->driver->resume) {
        rc = dev->driver->resume(dev, 0);
    }

    return rc;
}

struct bus_type i2c_bus_type = {
    .name    = "i2c",
    .match   = i2c_device_match,
    .suspend = i2c_bus_suspend,
    .resume  = i2c_bus_resume,
};

static int i2c_device_probe(struct device *dev){
    return -ENODEV;
}

static int i2c_device_remove(struct device *dev){
    return 0;
}

void i2c_adapter_dev_release(struct device *dev){
    struct i2c_adapter *adap = dev_to_i2c_adapter(dev);
    complete(&adap->dev_released);
}

struct device_driver i2c_adapter_driver = {
    .name   = "i2c_adapter",
    .bus    = &i2c_bus_type,
    .probe  = i2c_device_probe,
    .remove = i2c_device_remove,
};

static void i2c_adapter_class_dev_release(struct class_device *dev){
    struct i2c_adapter *adap = class_dev_to_i2c_adapter(dev);
    complete(&adap->class_dev_released);
}

struct class i2c_adapter_class = {
    .name    = "i2c-adapter",
    .release = &i2c_adapter_class_dev_release,
};

static ssize_t show_adapter_name(struct device *dev, struct device_attribute *attr, char *buf){
    struct i2c_adapter *adap = dev_to_i2c_adapter(dev);

    return sprintf(buf, "%s\n", adap->name);
}

static DEVICE_ATTR(name, S_IRUGO, show_adapter_name, NULL);


static void i2c_client_release(struct device *dev){
    struct i2c_client *client = to_i2c_client(dev);
    complete(&client->released);
}

static ssize_t show_client_name(struct device *dev, struct device_attribute *attr, char *buf){
    struct i2c_client *client = to_i2c_client(dev);

    return sprintf(buf, "%s\n", client->name);
}

/*
 * We can't use the DEVICE_ATTR() macro here as we want the same filename for a
 * different type of a device.  So beware if the DEVICE_ATTR() macro ever
 * changes, this definition will also have to change.
 */
static struct device_attribute dev_attr_client_name = {
    .attr = {.name = "name", .mode = S_IRUGO, .owner = THIS_MODULE },
    .show = &show_client_name,
};


/* ---------------------------------------------------
 * registering functions
 * ---------------------------------------------------
 */

/* -----
 * i2c_add_adapter is called from within the algorithm layer,
 * when a new hw adapter registers. A new device is register to be
 * available for clients.
 */
int i2c_add_adapter(struct i2c_adapter *adap){
    int id, res = 0;
    struct list_head *item;
    struct i2c_driver *driver;

    down(&core_lists);

    if (idr_pre_get(&i2c_adapter_idr, GFP_KERNEL) == 0) {
        res = -ENOMEM;
        goto out_unlock;
    }

    res = idr_get_new(&i2c_adapter_idr, adap, &id);
    if (res < 0) {
        if (res == -EAGAIN) {
            res = -ENOMEM;
        }
        goto out_unlock;
    }

    adap->nr = id & MAX_ID_MASK;
    init_MUTEX(&adap->bus_lock);
    init_MUTEX(&adap->clist_lock);
    list_add_tail(&adap->list, &adapters);
    INIT_LIST_HEAD(&adap->clients);

    /* Add the adapter to the driver core.
     * If the parent pointer is not set up,
     * we add this adapter to the host bus.
     */
    if (adap->dev.parent == NULL) {
        adap->dev.parent = &platform_bus;
    }
    sprintf(adap->dev.bus_id, "i2c-%d", adap->nr);
    adap->dev.driver  = &i2c_adapter_driver;
    adap->dev.release = &i2c_adapter_dev_release;
    device_register(&adap->dev);
    device_create_file(&adap->dev, &dev_attr_name);

    /* Add this adapter to the i2c_adapter class */
    memset(&adap->class_dev, 0x00, sizeof(struct class_device));
    adap->class_dev.dev   = &adap->dev;
    adap->class_dev.class = &i2c_adapter_class;
    strlcpy(adap->class_dev.class_id, adap->dev.bus_id, BUS_ID_SIZE);
    class_device_register(&adap->class_dev);

    dev_dbg(&adap->dev, "adapter [%s] registered\n", adap->name);

    /* inform drivers of new adapters */
    list_for_each(item, &drivers){
        driver = list_entry(item, struct i2c_driver, list);
        if (driver->flags & I2C_DF_NOTIFY) {
            /* We ignore the return code; if it fails, too bad */
            driver->attach_adapter(adap);
        }
    }

out_unlock:
    up(&core_lists);

    return res;
} /* i2c_add_adapter */

int i2c_del_adapter(struct i2c_adapter *adap){
    struct list_head *item, *_n;
    struct i2c_adapter *adap_from_list;
    struct i2c_driver *driver;
    struct i2c_client *client;
    int res = 0;

    down(&core_lists);

    /* First make sure that this adapter was ever added */
    list_for_each_entry(adap_from_list, &adapters, list){
        if (adap_from_list == adap) {
            break;
        }
    }
    if (adap_from_list != adap) {
        pr_debug("i2c-core: attempting to delete unregistered "
                 "adapter [%s]\n", adap->name);
        res = -EINVAL;
        goto out_unlock;
    }

    list_for_each(item, &drivers){
        driver = list_entry(item, struct i2c_driver, list);
        if (driver->detach_adapter) {
            if ((res = driver->detach_adapter(adap))) {
                dev_err(&adap->dev, "detach_adapter failed "
                        "for driver [%s]\n", driver->name);
                goto out_unlock;
            }
        }
    }

    /* detach any active clients. This must be done first, because
     * it can fail; in which case we give up. */
    list_for_each_safe(item, _n, &adap->clients){
        client = list_entry(item, struct i2c_client, list);

        /* detaching devices is unconditional of the set notify
         * flag, as _all_ clients that reside on the adapter
         * must be deleted, as this would cause invalid states.
         */
        if ((res = client->driver->detach_client(client))) {
            dev_err(&adap->dev, "detach_client failed for client "
                    "[%s] at address 0x%02x\n", client->name,
                    client->addr);
            goto out_unlock;
        }
    }

    /* clean up the sysfs representation */
    init_completion(&adap->dev_released);
    init_completion(&adap->class_dev_released);
    class_device_unregister(&adap->class_dev);
    device_remove_file(&adap->dev, &dev_attr_name);
    device_unregister(&adap->dev);
    list_del(&adap->list);

    /* wait for sysfs to drop all references */
    wait_for_completion(&adap->dev_released);
    wait_for_completion(&adap->class_dev_released);

    /* free dynamically allocated bus id */
    idr_remove(&i2c_adapter_idr, adap->nr);

    dev_dbg(&adap->dev, "adapter [%s] unregistered\n", adap->name);

out_unlock:
    up(&core_lists);

    return res;
} /* i2c_del_adapter */

/* -----
 * What follows is the "upwards" interface: commands for talking to clients,
 * which implement the functions to access the physical information of the
 * chips.
 */

int i2c_add_driver(struct i2c_driver *driver){
    struct list_head *item;
    struct i2c_adapter *adapter;
    int res = 0;

    down(&core_lists);

    /* add the driver to the list of i2c drivers in the driver core */
    driver->driver.name   = driver->name;
    driver->driver.bus    = &i2c_bus_type;
    driver->driver.probe  = i2c_device_probe;
    driver->driver.remove = i2c_device_remove;

    res = driver_register(&driver->driver);
    if (res) {
        goto out_unlock;
    }

    list_add_tail(&driver->list, &drivers);
    pr_debug("i2c-core: driver [%s] registered\n", driver->name);

    /* now look for instances of driver on our adapters */
    if (driver->flags & I2C_DF_NOTIFY) {
        list_for_each(item, &adapters){
            adapter = list_entry(item, struct i2c_adapter, list);
            driver->attach_adapter(adapter);
        }
    }

out_unlock:
    up(&core_lists);

    return res;
}

int i2c_del_driver(struct i2c_driver *driver){
    struct list_head *item1, *item2, *_n;
    struct i2c_client *client;
    struct i2c_adapter *adap;

    int res = 0;

    down(&core_lists);

    /* Have a look at each adapter, if clients of this driver are still
     * attached. If so, detach them to be able to kill the driver
     * afterwards.
     *
     * Removing clients does not depend on the notify flag, else
     * invalid operation might (will!) result, when using stale client
     * pointers.
     */
    list_for_each(item1, &adapters){
        adap = list_entry(item1, struct i2c_adapter, list);
        if (driver->detach_adapter) {
            if ((res = driver->detach_adapter(adap))) {
                dev_err(&adap->dev, "detach_adapter failed "
                        "for driver [%s]\n", driver->name);
                goto out_unlock;
            }
        } else {
            list_for_each_safe(item2, _n, &adap->clients){
                client = list_entry(item2, struct i2c_client, list);
                if (client->driver != driver) {
                    continue;
                }
                dev_dbg(&adap->dev, "detaching client [%s] "
                        "at 0x%02x\n", client->name,
                        client->addr);
                if ((res = driver->detach_client(client))) {
                    dev_err(&adap->dev, "detach_client "
                            "failed for client [%s] at "
                            "0x%02x\n", client->name,
                            client->addr);
                    goto out_unlock;
                }
            }
        }
    }

    driver_unregister(&driver->driver);
    list_del(&driver->list);
    pr_debug("i2c-core: driver [%s] unregistered\n", driver->name);

out_unlock:
    up(&core_lists);

    return 0;
} /* i2c_del_driver */

static int __i2c_check_addr(struct i2c_adapter *adapter, unsigned int addr){
    struct list_head *item;
    struct i2c_client *client;

    list_for_each(item, &adapter->clients){
        client = list_entry(item, struct i2c_client, list);
        if (client->addr == addr) {
            return -EBUSY;
        }
    }

    return 0;
}

int i2c_check_addr(struct i2c_adapter *adapter, int addr){
    int rval;

    down(&adapter->clist_lock);
    rval = __i2c_check_addr(adapter, addr);
    up(&adapter->clist_lock);

    return rval;
}

int i2c_attach_client(struct i2c_client *client){
    struct i2c_adapter *adapter = client->adapter;

    down(&adapter->clist_lock);
    if (__i2c_check_addr(client->adapter, client->addr)) {
        up(&adapter->clist_lock);

        return -EBUSY;
    }
    list_add_tail(&client->list, &adapter->clients);
    up(&adapter->clist_lock);

    if (adapter->client_register) {
        if (adapter->client_register(client)) {
            dev_dbg(&adapter->dev, "client_register "
                    "failed for client [%s] at 0x%02x\n",
                    client->name, client->addr);
        }
    }

    if (client->flags & I2C_CLIENT_ALLOW_USE) {
        client->usage_count = 0;
    }

    client->dev.parent  = &client->adapter->dev;
    client->dev.driver  = &client->driver->driver;
    client->dev.bus     = &i2c_bus_type;
    client->dev.release = &i2c_client_release;

    snprintf(&client->dev.bus_id[0], sizeof(client->dev.bus_id),
             "%d-%04x", i2c_adapter_id(adapter), client->addr);
    dev_dbg(&adapter->dev, "client [%s] registered with bus id %s\n",
            client->name, client->dev.bus_id);
    device_register(&client->dev);
    device_create_file(&client->dev, &dev_attr_client_name);

    return 0;
}

int i2c_detach_client(struct i2c_client *client){
    struct i2c_adapter *adapter = client->adapter;
    int res                     = 0;

    if ((client->flags & I2C_CLIENT_ALLOW_USE)
        && (client->usage_count > 0)) {
        dev_warn(&client->dev, "Client [%s] still busy, "
                 "can't detach\n", client->name);

        return -EBUSY;
    }

    if (adapter->client_unregister) {
        res = adapter->client_unregister(client);
        if (res) {
            dev_err(&client->dev,
                    "client_unregister [%s] failed, "
                    "client not detached\n", client->name);
            goto out;
        }
    }

    down(&adapter->clist_lock);
    list_del(&client->list);
    init_completion(&client->released);
    device_remove_file(&client->dev, &dev_attr_client_name);
    device_unregister(&client->dev);
    up(&adapter->clist_lock);
    wait_for_completion(&client->released);

out:

    return res;
}

static int i2c_inc_use_client(struct i2c_client *client){
    if (!try_module_get(client->driver->owner)) {
        return -ENODEV;
    }
    if (!try_module_get(client->adapter->owner)) {
        module_put(client->driver->owner);

        return -ENODEV;
    }

    return 0;
}

static void i2c_dec_use_client(struct i2c_client *client){
    module_put(client->driver->owner);
    module_put(client->adapter->owner);
}

int i2c_use_client(struct i2c_client *client){
    int ret;

    ret = i2c_inc_use_client(client);
    if (ret) {
        return ret;
    }

    if (client->flags & I2C_CLIENT_ALLOW_USE) {
        if (client->flags & I2C_CLIENT_ALLOW_MULTIPLE_USE) {
            client->usage_count++;
        } else if (client->usage_count > 0) {
            goto busy;
        } else {
            client->usage_count++;
        }
    }

    return 0;
busy:
    i2c_dec_use_client(client);

    return -EBUSY;
}

int i2c_release_client(struct i2c_client *client){
    if (client->flags & I2C_CLIENT_ALLOW_USE) {
        if (client->usage_count>0) {
            client->usage_count--;
        } else {
            pr_debug("i2c-core: %s used one too many times\n",
                     __FUNCTION__);

            return -EPERM;
        }
    }

    i2c_dec_use_client(client);

    return 0;
}

void i2c_clients_command(struct i2c_adapter *adap, unsigned int cmd, void *arg){
    struct list_head *item;
    struct i2c_client *client;

    down(&adap->clist_lock);
    list_for_each(item, &adap->clients){
        client = list_entry(item, struct i2c_client, list);
        if (!try_module_get(client->driver->owner)) {
            continue;
        }
        if (NULL != client->driver->command) {
            up(&adap->clist_lock);
            client->driver->command(client, cmd, arg);
            down(&adap->clist_lock);
        }
        module_put(client->driver->owner);
    }
    up(&adap->clist_lock);
}

static int __init i2c_init(void){
    int retval;

    retval = bus_register(&i2c_bus_type);
    if (retval) {
        return retval;
    }
    retval = driver_register(&i2c_adapter_driver);
    if (retval) {
        return retval;
    }

    return class_register(&i2c_adapter_class);
}

static void __exit i2c_exit(void){
    class_unregister(&i2c_adapter_class);
    driver_unregister(&i2c_adapter_driver);
    bus_unregister(&i2c_bus_type);
}

subsys_initcall(i2c_init);
module_exit(i2c_exit);

/* ----------------------------------------------------
 * the functional interface to the i2c busses.
 * ----------------------------------------------------
 */

int i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num){
    int ret;

    if (adap->algo->master_xfer) {
        #ifdef DEBUG
        for (ret = 0; ret < num; ret++) {
            dev_dbg(&adap->dev, "master_xfer[%d] %c, addr=0x%02x, "
                    "len=%d\n", ret, msgs[ret].flags & I2C_M_RD?
                    'R':'W', msgs[ret].addr, msgs[ret].len);
        }
        #endif /* ifdef DEBUG */

        down(&adap->bus_lock);
        ret = adap->algo->master_xfer(adap, msgs, num);
        up(&adap->bus_lock);

        return ret;
    } else {
        dev_dbg(&adap->dev, "I2C level transfers not supported\n");

        return -ENOSYS;
    }
}

int i2c_master_send(struct i2c_client *client, const char *buf, int count){
    int ret;
    struct i2c_adapter *adap = client->adapter;
    struct i2c_msg msg;

    msg.addr  = client->addr;
    msg.flags = client->flags & I2C_M_TEN;
    msg.len   = count;
    msg.buf   = (char*)buf;

    ret = i2c_transfer(adap, &msg, 1);

    /* If everything went ok (i.e. 1 msg transmitted), return #bytes
       transmitted, else error code. */
    return (ret == 1)?count:ret;
}

int i2c_master_recv(struct i2c_client *client, char *buf, int count){
    struct i2c_adapter *adap = client->adapter;
    struct i2c_msg msg;
    int ret;

    msg.addr   = client->addr;
    msg.flags  = client->flags & I2C_M_TEN;
    msg.flags |= I2C_M_RD;
    msg.len    = count;
    msg.buf    = buf;

    ret = i2c_transfer(adap, &msg, 1);

    /* If everything went ok (i.e. 1 msg transmitted), return #bytes
       transmitted, else error code. */
    return (ret == 1)?count:ret;
}

int i2c_control(struct i2c_client *client,
                unsigned int cmd, unsigned long arg){
    int ret                  = 0;
    struct i2c_adapter *adap = client->adapter;

    dev_dbg(&client->adapter->dev, "i2c ioctl, cmd: 0x%x, arg: %#lx\n", cmd, arg);
    switch (cmd) {
        case I2C_RETRIES:
            adap->retries = arg;
            break;

        case I2C_TIMEOUT:
            adap->timeout = arg;
            break;

        default:
            if (adap->algo->algo_control!=NULL) {
                ret = adap->algo->algo_control(adap, cmd, arg);
            }
    }

    return ret;
}

/* ----------------------------------------------------
 * the i2c address scanning function
 * Will not work for 10-bit addresses!
 * ----------------------------------------------------
 */
static int i2c_probe_address(struct i2c_adapter *adapter, int addr, int kind,
                             int (*found_proc)(struct i2c_adapter*, int, int)){
    int err;

    /* Make sure the address is valid */
    if (addr < 0x03 || addr > 0x77) {
        dev_warn(&adapter->dev, "Invalid probe address 0x%02x\n",
                 addr);

        return -EINVAL;
    }

    /* Skip if already in use */
    if (i2c_check_addr(adapter, addr)) {
        return 0;
    }

    /* Make sure there is something at this address, unless forced */
    if (kind < 0) {
        if (i2c_smbus_xfer(adapter, addr, 0, 0, 0,
                           I2C_SMBUS_QUICK, NULL) < 0) {
            return 0;
        }

        /* prevent 24RF08 corruption */
        if ((addr & ~0x0f) == 0x50) {
            i2c_smbus_xfer(adapter, addr, 0, 0, 0,
                           I2C_SMBUS_QUICK, NULL);
        }
    }

    /* Finally call the custom detection function */
    err = found_proc(adapter, addr, kind);

    /* -ENODEV can be returned if there is a chip at the given address
       but it isn't supported by this chip driver. We catch it here as
       this isn't an error. */
    return (err == -ENODEV)?0:err;
}

int i2c_probe(struct i2c_adapter *adapter,
              struct i2c_client_address_data *address_data,
              int (*found_proc)(struct i2c_adapter*, int, int)){
    int i, err;
    int adap_id = i2c_adapter_id(adapter);

    /* Forget it if we can't probe using SMBUS_QUICK */
    if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_QUICK)) {
        return -1;
    }

    /* Force entries are done first, and are not affected by ignore
       entries */
    if (address_data->forces) {
        unsigned short **forces = address_data->forces;
        int kind;

        for (kind = 0; forces[kind]; kind++) {
            for (i = 0; forces[kind][i] != I2C_CLIENT_END;
                 i += 2) {
                if (forces[kind][i] == adap_id
                    || forces[kind][i] == ANY_I2C_BUS) {
                    dev_dbg(&adapter->dev, "found force "
                            "parameter for adapter %d, "
                            "addr 0x%02x, kind %d\n",
                            adap_id, forces[kind][i + 1],
                            kind);
                    err = i2c_probe_address(adapter,
                                            forces[kind][i + 1],
                                            kind, found_proc);
                    if (err) {
                        return err;
                    }
                }
            }
        }
    }

    /* Probe entries are done second, and are not affected by ignore
       entries either */
    for (i = 0; address_data->probe[i] != I2C_CLIENT_END; i += 2) {
        if (address_data->probe[i] == adap_id
            || address_data->probe[i] == ANY_I2C_BUS) {
            dev_dbg(&adapter->dev, "found probe parameter for "
                    "adapter %d, addr 0x%02x\n", adap_id,
                    address_data->probe[i + 1]);
            err = i2c_probe_address(adapter,
                                    address_data->probe[i + 1],
                                    -1, found_proc);
            if (err) {
                return err;
            }
        }
    }

    /* Normal entries are done last, unless shadowed by an ignore entry */
    for (i = 0; address_data->normal_i2c[i] != I2C_CLIENT_END; i += 1) {
        int j, ignore;

        ignore = 0;
        for (j = 0; address_data->ignore[j] != I2C_CLIENT_END;
             j += 2) {
            if ((address_data->ignore[j] == adap_id ||
                 address_data->ignore[j] == ANY_I2C_BUS)
                && address_data->ignore[j + 1]
                == address_data->normal_i2c[i]) {
                dev_dbg(&adapter->dev, "found ignore "
                        "parameter for adapter %d, "
                        "addr 0x%02x\n", adap_id,
                        address_data->ignore[j + 1]);
            }
            ignore = 1;
            break;
        }
        if (ignore) {
            continue;
        }

        dev_dbg(&adapter->dev, "found normal entry for adapter %d, "
                "addr 0x%02x\n", adap_id,
                address_data->normal_i2c[i]);
        err = i2c_probe_address(adapter, address_data->normal_i2c[i],
                                -1, found_proc);
        if (err) {
            return err;
        }
    }

    return 0;
} /* i2c_probe */

struct i2c_adapter* i2c_get_adapter(int id){
    struct i2c_adapter *adapter;

    down(&core_lists);
    adapter = (struct i2c_adapter*)idr_find(&i2c_adapter_idr, id);
    if (adapter && !try_module_get(adapter->owner)) {
        adapter = NULL;
    }

    up(&core_lists);

    return adapter;
}

void i2c_put_adapter(struct i2c_adapter *adap){
    module_put(adap->owner);
}

/* The SMBus parts */

    #define POLY (0x1070U << 3)
static u8
crc8(u16 data){
    int i;

    for (i = 0; i < 8; i++) {
        if (data & 0x8000) {
            data = data ^ POLY;
        }
        data = data << 1;
    }

    return (u8)(data >> 8);
}

/* CRC over count bytes in the first array plus the bytes in the rest
   array if it is non-null. rest[0] is the (length of rest) - 1
   and is included. */
static u8 i2c_smbus_partial_pec(u8 crc, int count, u8 *first, u8 *rest){
    int i;

    for (i = 0; i < count; i++) {
        crc = crc8((crc ^ first[i]) << 8);
    }
    if (rest != NULL) {
        for (i = 0; i <= rest[0]; i++) {
            crc = crc8((crc ^ rest[i]) << 8);
        }
    }

    return crc;
}

static u8 i2c_smbus_pec(int count, u8 *first, u8 *rest){
    return i2c_smbus_partial_pec(0, count, first, rest);
}

/* Returns new "size" (transaction type)
   Note that we convert byte to byte_data and byte_data to word_data
   rather than invent new xxx_PEC transactions. */
static int i2c_smbus_add_pec(u16 addr, u8 command, int size,
                             union i2c_smbus_data *data){
    u8 buf[3];

    buf[0] = addr << 1;
    buf[1] = command;
    switch (size) {
        case I2C_SMBUS_BYTE:
            data->byte = i2c_smbus_pec(2, buf, NULL);
            size       = I2C_SMBUS_BYTE_DATA;
            break;

        case I2C_SMBUS_BYTE_DATA:
            buf[2]     = data->byte;
            data->word = buf[2] ||
                         (i2c_smbus_pec(3, buf, NULL) << 8);
            size = I2C_SMBUS_WORD_DATA;
            break;

        case I2C_SMBUS_WORD_DATA:
            /* unsupported */
            break;

        case I2C_SMBUS_BLOCK_DATA:
            data->block[data->block[0] + 1] =
                i2c_smbus_pec(2, buf, data->block);
            size = I2C_SMBUS_BLOCK_DATA_PEC;
            break;
    } /* switch */

    return size;
}

static int i2c_smbus_check_pec(u16 addr, u8 command, int size, u8 partial,
                               union i2c_smbus_data *data){
    u8 buf[3], rpec, cpec;

    buf[1] = command;
    switch (size) {
        case I2C_SMBUS_BYTE_DATA:
            buf[0] = (addr << 1) | 1;
            cpec   = i2c_smbus_pec(2, buf, NULL);
            rpec   = data->byte;
            break;

        case I2C_SMBUS_WORD_DATA:
            buf[0] = (addr << 1) | 1;
            buf[2] = data->word & 0xff;
            cpec   = i2c_smbus_pec(3, buf, NULL);
            rpec   = data->word >> 8;
            break;

        case I2C_SMBUS_WORD_DATA_PEC:
            /* unsupported */
            cpec = rpec = 0;
            break;

        case I2C_SMBUS_PROC_CALL_PEC:
            /* unsupported */
            cpec = rpec = 0;
            break;

        case I2C_SMBUS_BLOCK_DATA_PEC:
            buf[0] = (addr << 1);
            buf[2] = (addr << 1) | 1;
            cpec   = i2c_smbus_pec(3, buf, data->block);
            rpec   = data->block[data->block[0] + 1];
            break;

        case I2C_SMBUS_BLOCK_PROC_CALL_PEC:
            buf[0] = (addr << 1) | 1;
            rpec   = i2c_smbus_partial_pec(partial, 1,
                                           buf, data->block);
            cpec = data->block[data->block[0] + 1];
            break;

        default:
            cpec = rpec = 0;
            break;
    } /* switch */
    if (rpec != cpec) {
        pr_debug("i2c-core: Bad PEC 0x%02x vs. 0x%02x\n",
                 rpec, cpec);

        return -1;
    }

    return 0;
} /* i2c_smbus_check_pec */

s32 i2c_smbus_write_quick(struct i2c_client *client, u8 value){
    return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                          value, 0, I2C_SMBUS_QUICK, NULL);
}

s32 i2c_smbus_read_byte(struct i2c_client *client){
    union i2c_smbus_data data;
    if (i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                       I2C_SMBUS_READ, 0, I2C_SMBUS_BYTE, &data)) {
        return -1;
    } else {
        return 0x0FF & data.byte;
    }
}

s32 i2c_smbus_write_byte(struct i2c_client *client, u8 value){
    union i2c_smbus_data data;  /* only for PEC */
    return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                          I2C_SMBUS_WRITE, value, I2C_SMBUS_BYTE, &data);
}

s32 i2c_smbus_read_byte_data(struct i2c_client *client, u8 command){
    union i2c_smbus_data data;
    if (i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                       I2C_SMBUS_READ, command, I2C_SMBUS_BYTE_DATA, &data)) {
        return -1;
    } else {
        return 0x0FF & data.byte;
    }
}

s32 i2c_smbus_write_byte_data(struct i2c_client *client, u8 command, u8 value){
    union i2c_smbus_data data;
    data.byte = value;

    return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                          I2C_SMBUS_WRITE, command,
                          I2C_SMBUS_BYTE_DATA, &data);
}

s32 i2c_smbus_read_word_data(struct i2c_client *client, u8 command){
    union i2c_smbus_data data;
    if (i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                       I2C_SMBUS_READ, command, I2C_SMBUS_WORD_DATA, &data)) {
        return -1;
    } else {
        return 0x0FFFF & data.word;
    }
}

s32 i2c_smbus_write_word_data(struct i2c_client *client, u8 command, u16 value){
    union i2c_smbus_data data;
    data.word = value;

    return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                          I2C_SMBUS_WRITE, command,
                          I2C_SMBUS_WORD_DATA, &data);
}

s32 i2c_smbus_write_block_data(struct i2c_client *client, u8 command,
                               u8 length, u8 *values){
    union i2c_smbus_data data;
    int i;
    if (length > I2C_SMBUS_BLOCK_MAX) {
        length = I2C_SMBUS_BLOCK_MAX;
    }
    for (i = 1; i <= length; i++) {
        data.block[i] = values[i - 1];
    }
    data.block[0] = length;

    return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                          I2C_SMBUS_WRITE, command,
                          I2C_SMBUS_BLOCK_DATA, &data);
}

/* Returns the number of read bytes */
s32 i2c_smbus_read_i2c_block_data(struct i2c_client *client, u8 command, u8 *values){
    union i2c_smbus_data data;
    int i;
    if (i2c_smbus_xfer(client->adapter, client->addr, client->flags,
                       I2C_SMBUS_READ, command,
                       I2C_SMBUS_I2C_BLOCK_DATA, &data)) {
        return -1;
    } else {
        for (i = 1; i <= data.block[0]; i++) {
            values[i - 1] = data.block[i];
        }

        return data.block[0];
    }
}

/* Simulate a SMBus command using the i2c protocol
   No checking of parameters is done!  */
static s32 i2c_smbus_xfer_emulated(struct i2c_adapter *adapter, u16 addr,
                                   unsigned short flags,
                                   char read_write, u8 command, int size,
                                   union i2c_smbus_data *data){
    /* So we need to generate a series of msgs. In the case of writing, we
       need to use only one message; when reading, we need two. We initialize
       most things with sane defaults, to keep the code below somewhat
       simpler. */
    unsigned char msgbuf0[34];
    unsigned char msgbuf1[34];
    int num               = read_write == I2C_SMBUS_READ?2:1;
    struct i2c_msg msg[2] = { { addr, flags, 1, msgbuf0 },
                              { addr, flags | I2C_M_RD, 0, msgbuf1 }};
    int i;

    msgbuf0[0] = command;
    switch (size) {
        case I2C_SMBUS_QUICK:
            msg[0].len = 0;
            /* Special case: The read/write field is used as data */
            msg[0].flags = flags | (read_write==I2C_SMBUS_READ)?I2C_M_RD:0;
            num          = 1;
            break;

        case I2C_SMBUS_BYTE:
            if (read_write == I2C_SMBUS_READ) {
                /* Special case: only a read! */
                msg[0].flags = I2C_M_RD | flags;
                num          = 1;
            }
            break;

        case I2C_SMBUS_BYTE_DATA:
            if (read_write == I2C_SMBUS_READ) {
                msg[1].len = 1;
            } else {
                msg[0].len = 2;
                msgbuf0[1] = data->byte;
            }
            break;

        case I2C_SMBUS_WORD_DATA:
            if (read_write == I2C_SMBUS_READ) {
                msg[1].len = 2;
            } else {
                msg[0].len = 3;
                msgbuf0[1] = data->word & 0xff;
                msgbuf0[2] = (data->word >> 8) & 0xff;
            }
            break;

        case I2C_SMBUS_PROC_CALL:
            num        = 2; /* Special case */
            read_write = I2C_SMBUS_READ;
            msg[0].len = 3;
            msg[1].len = 2;
            msgbuf0[1] = data->word & 0xff;
            msgbuf0[2] = (data->word >> 8) & 0xff;
            break;

        case I2C_SMBUS_BLOCK_DATA:
        case I2C_SMBUS_BLOCK_DATA_PEC:
            if (read_write == I2C_SMBUS_READ) {
                dev_err(&adapter->dev, "Block read not supported "
                        "under I2C emulation!\n");

                return -1;
            } else {
                msg[0].len = data->block[0] + 2;
                if (msg[0].len > I2C_SMBUS_BLOCK_MAX + 2) {
                    dev_err(&adapter->dev, "smbus_access called with "
                            "invalid block write size (%d)\n",
                            data->block[0]);

                    return -1;
                }
                if (size == I2C_SMBUS_BLOCK_DATA_PEC) {
                    (msg[0].len)++;
                }
                for (i = 1; i <= msg[0].len; i++) {
                    msgbuf0[i] = data->block[i - 1];
                }
            }
            break;

        case I2C_SMBUS_BLOCK_PROC_CALL:
        case I2C_SMBUS_BLOCK_PROC_CALL_PEC:
            dev_dbg(&adapter->dev, "Block process call not supported "
                    "under I2C emulation!\n");

            return -1;

        case I2C_SMBUS_I2C_BLOCK_DATA:
            if (read_write == I2C_SMBUS_READ) {
                msg[1].len = I2C_SMBUS_I2C_BLOCK_MAX;
            } else {
                msg[0].len = data->block[0] + 1;
                if (msg[0].len > I2C_SMBUS_I2C_BLOCK_MAX + 1) {
                    dev_err(&adapter->dev, "i2c_smbus_xfer_emulated called with "
                            "invalid block write size (%d)\n",
                            data->block[0]);

                    return -1;
                }
                for (i = 1; i <= data->block[0]; i++) {
                    msgbuf0[i] = data->block[i];
                }
            }
            break;

        default:
            dev_err(&adapter->dev, "smbus_access called with invalid size (%d)\n",
                    size);

            return -1;
    } /* switch */

    if (i2c_transfer(adapter, msg, num) < 0) {
        return -1;
    }

    if (read_write == I2C_SMBUS_READ) {
        switch (size) {
            case I2C_SMBUS_BYTE:
                data->byte = msgbuf0[0];
                break;

            case I2C_SMBUS_BYTE_DATA:
                data->byte = msgbuf1[0];
                break;

            case I2C_SMBUS_WORD_DATA:
            case I2C_SMBUS_PROC_CALL:
                data->word = msgbuf1[0] | (msgbuf1[1] << 8);
                break;

            case I2C_SMBUS_I2C_BLOCK_DATA:
                /* fixed at 32 for now */
                data->block[0] = I2C_SMBUS_I2C_BLOCK_MAX;
                for (i = 0; i < I2C_SMBUS_I2C_BLOCK_MAX; i++) {
                    data->block[i + 1] = msgbuf1[i];
                }
                break;
        } /* switch */
    }

    return 0;
} /* i2c_smbus_xfer_emulated */

s32 i2c_smbus_xfer(struct i2c_adapter *adapter, u16 addr, unsigned short flags,
                   char read_write, u8 command, int size,
                   union i2c_smbus_data *data){
    s32 res;
    int swpec  = 0;
    u8 partial = 0;

    flags &= I2C_M_TEN | I2C_CLIENT_PEC;
    if ((flags & I2C_CLIENT_PEC) &&
        !(i2c_check_functionality(adapter, I2C_FUNC_SMBUS_HWPEC_CALC))) {
        swpec = 1;
        if (read_write == I2C_SMBUS_READ &&
            size == I2C_SMBUS_BLOCK_DATA) {
            size = I2C_SMBUS_BLOCK_DATA_PEC;
        } else if (size == I2C_SMBUS_PROC_CALL) {
            size = I2C_SMBUS_PROC_CALL_PEC;
        } else if (size == I2C_SMBUS_BLOCK_PROC_CALL) {
            i2c_smbus_add_pec(addr, command,
                              I2C_SMBUS_BLOCK_DATA, data);
            partial = data->block[data->block[0] + 1];
            size    = I2C_SMBUS_BLOCK_PROC_CALL_PEC;
        } else if (read_write == I2C_SMBUS_WRITE &&
                   size != I2C_SMBUS_QUICK &&
                   size != I2C_SMBUS_I2C_BLOCK_DATA) {
            size = i2c_smbus_add_pec(addr, command, size, data);
        }
    }

    if (adapter->algo->smbus_xfer) {
        down(&adapter->bus_lock);
        res = adapter->algo->smbus_xfer(adapter, addr, flags, read_write,
                                        command, size, data);
        up(&adapter->bus_lock);
    } else {
        res = i2c_smbus_xfer_emulated(adapter, addr, flags, read_write,
                                      command, size, data);
    }

    if (res >= 0 && swpec &&
        size != I2C_SMBUS_QUICK && size != I2C_SMBUS_I2C_BLOCK_DATA &&
        (read_write == I2C_SMBUS_READ || size == I2C_SMBUS_PROC_CALL_PEC ||
         size == I2C_SMBUS_BLOCK_PROC_CALL_PEC)) {
        if (i2c_smbus_check_pec(addr, command, size, partial, data)) {
            return -1;
        }
    }

    return res;
} /* i2c_smbus_xfer */

/* Next four are needed by i2c-isa */
EXPORT_SYMBOL_GPL(i2c_adapter_dev_release);
EXPORT_SYMBOL_GPL(i2c_adapter_driver);
EXPORT_SYMBOL_GPL(i2c_adapter_class);
EXPORT_SYMBOL_GPL(i2c_bus_type);

EXPORT_SYMBOL(i2c_add_adapter);
EXPORT_SYMBOL(i2c_del_adapter);
EXPORT_SYMBOL(i2c_add_driver);
EXPORT_SYMBOL(i2c_del_driver);
EXPORT_SYMBOL(i2c_attach_client);
EXPORT_SYMBOL(i2c_detach_client);
EXPORT_SYMBOL(i2c_use_client);
EXPORT_SYMBOL(i2c_release_client);
EXPORT_SYMBOL(i2c_clients_command);
EXPORT_SYMBOL(i2c_check_addr);

EXPORT_SYMBOL(i2c_master_send);
EXPORT_SYMBOL(i2c_master_recv);
EXPORT_SYMBOL(i2c_control);
EXPORT_SYMBOL(i2c_transfer);
EXPORT_SYMBOL(i2c_get_adapter);
EXPORT_SYMBOL(i2c_put_adapter);
EXPORT_SYMBOL(i2c_probe);

EXPORT_SYMBOL(i2c_smbus_xfer);
EXPORT_SYMBOL(i2c_smbus_write_quick);
EXPORT_SYMBOL(i2c_smbus_read_byte);
EXPORT_SYMBOL(i2c_smbus_write_byte);
EXPORT_SYMBOL(i2c_smbus_read_byte_data);
EXPORT_SYMBOL(i2c_smbus_write_byte_data);
EXPORT_SYMBOL(i2c_smbus_read_word_data);
EXPORT_SYMBOL(i2c_smbus_write_word_data);
EXPORT_SYMBOL(i2c_smbus_write_block_data);
EXPORT_SYMBOL(i2c_smbus_read_i2c_block_data);

MODULE_AUTHOR("Simon G. Vogl <simon@tk.uni-linz.ac.at>");
MODULE_DESCRIPTION("I2C-Bus main module");
MODULE_LICENSE("GPL");


// c/if_chain.c
void foo(void){
    if (cond_a) {
        fcn_a();
        fcn_b();
    } else {
        fcn_c();
    }

    if (cond_b) {
        fcn_d();
    } else {
        fcn_e();
    }

    if (cond_c) {
        fcn_f();
        fcn_g();
    } else {
        fcn_h();
    }

    if (cond_d) {
        fcn_i();
    } else {
        fcn_j();
        fcn_k();
    }

    if (cond_e) {
        fcn_l();
    } else {
        fcn_m();
    }

    if (cond_f) {
        fcn_n();
    } else if (cond_g) {
        fcn_o();
        while (cond_g) {
            fcn_p();
        }
    } else if (cond_h) {
        while (cond_i) {
            fcn_q();
            fcn_r();
        }
    } else {
        fcn_s();
    }
} /* foo */

/* this next bit test whether vbraces can be successfully converted
 * when the closing brace is in an #ifdef.
 * Note that the author should have braced the code to begin with.
 */
void bar(void){
    if (jiffies >= hw_priv->Counter[ port ].time) {
        hw_priv->Counter[ port ].fRead = 1;
        if (port == MAIN_PORT) {
            hw_priv->Counter[ MAIN_PORT ].time = jiffies + HZ * 6;
        } else {
            hw_priv->Counter[ port ].time =

                #ifdef SOME_DEFINE
                hw_priv->Counter[ port - 1 ].time + HZ * 2;
        }

                #else /* ifdef SOME_DEFINE */
                hw_priv->Counter[ MAIN_PORT ].time + HZ * 2;
        #endif /* ifdef SOME_DEFINE */
    }
}

void funct(int v1, int v2, int v3){
    if (v1) {
        if (v2) {
            f1();
        }
    } else {
        if (v3) {
            f2();
        }
    }
}

// c/ifdef-indent.c
    #ifdef foo
        #include <foo1.h>
    #else /* ifdef foo */
        #include <foo2.h>
    #endif /* ifdef foo */

int
show_interrupts(struct seq_file *p, void *v){
    #ifndef CONFIG_SMP
    a++;
    #else /* ifndef CONFIG_SMP */
    for (b = 0; b < 9; b++) {
        if (b & 1) {
            k++;
        }
    }
    #endif /* ifndef CONFIG_SMP */

    if (v) {
        bar(v);
        #if DEBUG == 1
        printf("yup\n");
        #endif /* if DEBUG == 1 */
    }
}

void foo(){
    int i = 0;
    #if DEBUG == 1
    i--;
    #endif /* if DEBUG == 1 */
    i++;
}

// c/ifdef-nest.c

namespace MonoTests.System.IO.IsolatedStorageTest {
    public class NonAbstractIsolatedStorage: IsolatedStorage {
        public NonAbstractIsolatedStorage (){
            string s = String.Format ("{0} {1}",
                                      Environment.NewLine,
                                      #if NET_2_0
                                      String.Empty);
                                      #else /* if NET_2_0 */
                                      "            ");
            #endif /* if NET_2_0 */
        }
    }
}


// c/include_define.h
    #define MY_HEADER <foo/inc.h>

    #include MY_HEADER


// c/indent-assign.c
void foo(void){
    int a;
    junk(a = 3);
}

void f(){
    int x = size_t(1.0) +
            2;
    int y = (size_t(1.0) +
             5);
}

// c/indent-vbrace.c

void x(void){
    if (a>b) {
        b = a;
    }
}

// c/indent_first_bool_expr.c
void test(void){
    b1 = a & b||c==d;
    b2 = (a & b)||c==d;
    b3 = (a & b||c==d);


    if (a==3 && b==2 & c || d && r) {
    }


    if (/*test*/ a||b) {
    }

    if (/*test*/ a||/*truc*/ b) {
    }

    if (a /*test*/||b) {
    }

    if (a||/*test*/ b) {
    }

    a = 3; if ((aaaaaaaaaaaaaaa ==  sqddqsqsdqsdqsd)   &&   (dfdssdfsdfsdfsdfs  || (qsdfsdfsdfqsdfqsdfqsdsd == fsdqfsdfsdfsdf))) {
        a++;
    }

    while ((aaaaaaaaaaaaaaa ==  sqddqsqsdqsdqsd)   &&   (dfdssdfsdfsdfsdfs  || (qsdfsdfsdfqsdfqsdfqsdsd == fsdqfsdfsdfsdf))) {
        a++;
    }
}

// c/indent_ternary-1.c
void foo(void){
    int a = x?y:
            z,
        b = x?(y):
            (z),
        c = x?*y:
            *z,
        d = x?&y:
            &z;


    if (x?y:
        z) {
        baz;
    }
    if (x?(y):
        (z)) {
        baz;
    }
    if (x?*y:
        *z) {
        baz;
    }
    if (x?&y:
        &z) {
        baz;
    }
}

// c/indent_ternary-2.c
void foo(void){
    int a = x?y
            :z,
        b = x?(y)
            :(z),
        c = x?*y
            :*z,
        d = x?&y
            :&z;


    if (x?y
        :z) {
        baz;
    }
    if (x?(y)
        :(z)) {
        baz;
    }
    if (x?*y
        :*z) {
        baz;
    }
    if (x?&y
        :&z) {
        baz;
    }
}

// c/kw_subst.c
    #include <string>

int foo1(){
}

/** header comment */
    #if 2
int foo2(void){
}

    #endif /* if 2 */

    #if 1
void foo3(int a){
}

    #endif /* if 1 */

void* foo4(int a, int b, int c){
}

// c/lvalue.c
void foo(){
    if (c * ssize < initialCapacity) {
    }
    if (Item *item = nextItem()) {
    }
}

// c/mac.c
/**
 * This is your typical header comment
 */
int foo(int bar){
    int idx;
    int res = 0;     // trailing comment
                     // that spans two lines
    for (idx = 1; idx < bar; idx++) {
        /* comment in virtual braces */
        res += idx;
    }

    res *= idx;       // some comment

    // almost continued, but a NL in between

// col1 comment in level 1
    return(res);
}

// col1 comment in level 0


// c/minus-minus.c
int a  = 5;
int *b = &a;
int negneg(void){
    return - -a;
}

int pospos(void){
    return + +a;
}

int negpos(void){
    return - +a;
}

int posneg(void){
    return + -a;
}

    #if VERSION < -5
int negnegneg(void){
    return - - -a;
}

    #else /* if VERSION < -5 */
int negat(void){
    return -*b;
}

    #endif /* if VERSION < -5 */


// c/misc.c
/*******************
   Before Unrustify
  *******************/

    #define MACRO(cond, action) if ((cond)) (action)

void hurz(murks){
    if (murks = 4) {           // This comment belongs to (murks = 4)
        schrott();             // And this to schrott()
    }
    #ifdef SCHNIEPEL
    else if (murks = 6) {      // This comment belongs to (murks = 6)
                               // I had to write more comment than one line
                               // so I inserted some comment only blocks
        schniepel();
    }
    #endif // SCHNIEPEL
    else {
        flursen();
    }

    if (murks = 4)             // This comment belongs to (murks = 4)
    #ifdef FOO
    { foo(); }
    #else /* ifdef FOO */
    { bar(); }
    #endif /* ifdef FOO */
    if (murks = 4) {              // This comment belongs to (murks = 4)
        schrott();                // And this to schrott()
    }
} // hurz()

// c/mod-paren.c

int foo(int a, int b){
    if (!(a || b) ) {
        return (1);
    }

    return 0;
}

void fooo(){
    if (enabled) {
        value = 1;
    }

    if (enabled && value==100) {
    }

    if (value==100) {
    }

    if (value==100 && i<15 || enabled) {
    }

    if (!failed && (value==100 && i<15) || enabled) {
    }
}

void foo3(){
    if (strcmp(a, b) == 0 && total < 5) {
        add_item(a);
    }

    if (glob_add_path(gd, gd->dir, NULL,
                      (flags & GLOB_MARK) && S_ISDIR(gd->st.st_mode)) != 0) {
        bar();
    }
}

int foo1(void){
    FOO_ERROR("connect: can only connected from state CLOSED", pcb->state == CLOSED, return ERR_ISCONN);

    return ERR_OK;
}

int foo2(void){
    return (-1);
}

void foo(void){
    if (!value
        #ifdef OPTION
        || value == SOMECONST
        #endif /* comment */
        ) {
    }
}

void foo3(void){
    if (*p == '-' && p[1] != ']'?
        *text <= *++p && *text >= last:*text == *p) {
        matched = TRUE;
    }
}

// c/mod_case_brace.c
int foo(int bar){
    switch (bar) {
        case 0: {
            showit(0);
        }
            c++;
            break;

        case 1: {
            showit(bar);
            break;
        }

        case 2:
            break;

        case 3: {
            int a = bar * 3;
            showit(a);
        }
            c++;
            break;

        case 4:
            foo(bar - 1);
            {
                showit(0);
            }

        case 10:
            switch (gl_bug) {
                case 'a': {
                    gl_foo = true;
                    break;
                }

                case 'b':
                case 'c': {
                    gl_foo = false;
                    break;
                }

                default: {
                    // nothing
                }
                break;
            }
            break;

        default: {
        }
        break;
    } /* switch */

    return(-1);
} /* foo */

// c/multi.h
/*
   This is a multiline
   comment that should
   not be indented
 */
{
    /*
       No trailing spaces

       in this comment
     */
}


// c/newline_after_endif.c
int main
    (){
    #ifdef useJPLvelocity
    for (i = 0; i < x; i++) {
        y++;
    }
    #endif /* ifdef useJPLvelocity */

    return (0);
} /* main */

int main
    (){
    if (y < 3) {
        y++;
    }

    #ifdef ABC
    if (y < 3) {
        y++  // comment
    #endif /* ifdef ABC */

    if (y < 3) {
        y++;
    }

    y++;

    return (0);
} /* main */

int main
    (){
    #ifdef ABC
    if (j < y) {
        if (j < x) {
            j++;
            #ifdef XYZ
            if (j < x) {
                j++;
            }
            #endif /* ifdef XYZ */
        }
    }
    #endif /* ifdef ABC */

    return (0);
} /* main */

// c/nl-comment.c
/**
 * This is your typical header comment
 */
int foo(int bar){
    int idx;
    int res = 0;     // trailing comment
                     // that spans two lines
    /* multi-line comment
     */
    idx = 50;
    /* single line comment */
    for (idx = 1; idx < bar; idx++) {
        /* comment in virtual braces */
        res += idx;
    }

    res *= idx;       // some comment

    // almost continued, but a NL in between

    i++;
// col1 comment in level 1

// second comment
    return(res);
}

// col1 comment in level 0
// and another


// c/nl-cont.c

    #define FOO(bar) create_a_really_long_identifier name(some_function(bar1 + bar2), bar3, bar4);

    #define VNV_RECORD_CYCLES(m) \
    do { \
        uint16_t cyc_out = ((uint16_t)TMR4) - cyc_in; \
        if (cyc_out < vnv_ticks[m].min) { vnv_ticks[m].min = cyc_out; } \
        if (cyc_out > vnv_ticks[m].max) { vnv_ticks[m].max = cyc_out; } \
    } while (0)

    #define multilinemacro \
    do { (x + 5); } while (0); \
    printf("a multilinemacro"); \
    printf("a multilinemacro2");

int main(int argc, char *argv[]){
    int a, b;
    a = 1; // stupid comment \\
    b = 2;

    return(a + b);
}

// c/nl-cont2.c

    #define FOO(bar) create_a_really_long_identifier name(some_function(bar1 + bar2), bar3, bar4);

    #define multilinemacro \
    do { (x + 5); } while (0); \
    printf("a multilinemacro"); \
    printf("a multilinemacro2");

int main(int argc, char *argv[]){
    int a, b;
    a = 1; // stupid comment \
           // b = 2;

    return(a + b);
}

// c/nl-semicolon.c
void foo(void){
    a = 5; b = 3; j = 6;

    for (a = 0; a < j; a++) {
        b *= (a + b);
    }
}

struct somestruct { int a; char b; foo c; bar *d; };

struct foo { int a; char *b };

void f(){
    for (;; ) {
        nothing();
    }
    foobar();
}

// c/nl-ver-def.c
void foo(void){
    int a;
    int b;// comment

    /* comment */
    a = b;
}

// c/nl_assign.c

void foo(){
    some.really_long.variable_name
        = another.big.one[55] +
          something_else;

    some.really_long.variable_name =
        another.big.one[55] +
        something_else;

    some.really_long.variable_name = another.big.one[55] +
                                     something_else;

    a_really_long_assignment_to_test = line_breaks_around_assign_and_arith;

    a_really_long_assignment_to_test = line_breaks_around + assign_and_arith;
}

// c/nl_create_one_liner.c
void foo(){
    if (a) {
        b++;
    }
    if (a) {
        b++;
    }
    if (a) {
        if (b) {
            c++;
        }
    }

    for (i = 0; i<5; i++) {
        bar(i);
    }
    while (i>0) {
        bar(--i);
    }
}

// c/nl_ds_struct_enum.c
struct foo {
    unsigned int d_ino;
    /* Comment */
    unsigned short d_reclen;
    unsigned short d_namlen;
    /* Comment */
    char d_name[1];
};

struct foo {
    /* Comment */
    unsigned int d_ino;
    unsigned short d_reclen;
    unsigned short d_namlen;
    /* Comment */
    char d_name[1];
};

struct foo { int a; char *b };


// c/nl_endif.c
int main
    (){
    #ifdef useJPLvelocity

    for (i = 0; i < x; i++) {
        y++;
    }
    #endif /* ifdef useJPLvelocity */

    return (0);
} /* main */

// c/nl_proto_endif.c

    #include <stdio.h>

static void status_cb(status_t *status);
static int add_conn(const char *path);

    #ifdef USE_FOO_CMD
static void foo_cmd(void *user, const info_t *info);
    #endif /* ifdef USE_FOO_CMD */


// c/nl_return_expr.c

int foo1(void){
    bar();

    return NewClass(1);
}

int foo2(void){
    return NewClass(2);
}

int foo3(void){
    bar(none);

    // comment
    return(3);
}

int foo4(void){
    return(4);
}

// c/one-liner-define.c
//

    #define LOG_FMT(sev, args ...)                           \
    do { foo(); } while (0)


// c/one-liner-init.c

enum boo { FOO = 1 };

void foo(void){
    char str[123] = { 0 };

    enum hoo { NOO = 1 };

    strcat(str, "foo");
}

void f(){
    if (bar()) {
        baz(1);
    } else {
        baz(2);
    }
}

int foo(){ return 0; }

void foo(int a, int b){
    if (a == b) {
        a++;
    } else {
        b++;
    }
    if (a == b) a++; } else {
            b++;
        }
}

// c/paren-indent.c
static void* foo(int param1,
                 char *param2
                 );


static void* foo
(
    int param1,
    char *param2
){
    for (
        int i = 0;
        i< 10;
        i++
        ) {
        bar(
            arg1,
            arg2
            );
        if ( (abc < bcd)
             &&(123 < abc)
             ) {
            none(arg1,
                 arg2,
                 arg3
                 );
        }
    }
}

void CWarningAnalyzer::SetEffect(int FilterNumber
                                 , bool Exclude
                                 , int Red
                                 , int Green
                                 , int Blue
                                 , bool Italic
                                 , bool Bold
                                 , bool Underlined
                                 ){
    /* TODO */
}

// c/paren_indent.c
function1
    (something1);

function2
    (something2);

x = (float)
    (number);

x = (float)
    (number);


// c/pascal_ptr.c
foobar_t *a;
int *b;
int *c;
something no;

char* main(){
    int i = (5 * 3) + 2;
}

void foo(int *a, int *b, int *c){
}

// c/pos_compare.c
void foo(void){
    if ((a_really_long_number >
         another_really_long_number)
        ||
        (some_really_long_bool
         != another_really_long_bool)) {
        foo2();
    }
}

// c/pos_conditional.c
void foo(void){
    // conditional colon
    a = bar()?2:
        3;
    a = bar()?2
        :3;

    // conditional question
    a = bar()?
        2:3;
    a = bar()
        ?2:3;
}

// c/pp-if-indent.c
/* this is a comment */

/* should be in a H file but put in this file to avoid multiplying the number of test files */
    #ifndef COMSTACK_TYPES_H
        #define COMSTACK_TYPES_H

        #include "STD_TYPES.h"
        #ifdef COMINL_coENABLE_1
            #ifdef COMINL_coENABLE_2
                #include "def.h"
            #endif /* ifdef COMINL_coENABLE_2 */
        #endif /* ifdef COMINL_coENABLE_1 */

        #if (COMINL_coMINIMUM_DELAY_TIME_1 == COMINL_coENABLE)
            #if (COMINL_coMINIMUM_DELAY_TIME_2 == COMINL_coENABLE)
                #include "def1.h"
                #define COMINL_coMINIMUM_DELAY_TIME_1
                #include "def2.h"
            #endif /* if (COMINL_coMINIMUM_DELAY_TIME_2 == COMINL_coENABLE) */
        #endif /* if (COMINL_coMINIMUM_DELAY_TIME_1 == COMINL_coENABLE) */

/* no indentation */
        #if COMINL_coMINIMUM_DELAY_TIME == COMINL_coENABLE
            #include "MEMSRV.h"
        #endif /* if COMINL_coMINIMUM_DELAY_TIME == COMINL_coENABLE */

/* already well indented  */
        #ifndef COMINL_coAPPLI_TX_CONFIRMATION
            #error "Define COMINL_coAPPLI_TX_CONFIRMATION is undefined"
        #endif /* ifndef COMINL_coAPPLI_TX_CONFIRMATION */

/* bad indentation */
        #ifndef COMINL_coENABLE
            #error "Define COMINL_coENABLE is undefined"
        #endif /* ifndef COMINL_coENABLE */


        #ifdef COMINL_coENABLE_3
typedef enum {
    BUFREQ_OK       = 0,
    BUFREQ_E_NOT_OK = 1,
    BUFREQ_E_BUSY   = 2,
    BUFREQ_E_OVFL   = 3
}BufReq_ReturnType;
        #endif /* ifdef COMINL_coENABLE_3 */


        #if COMINL_coSTART_STOP_PERIODIC == COMINL_coENABLE
void COMINL_vidInit(void){
    uint8 u8LocalMsgIdx;

    if (COMINL_kastrVarReceiveMsg[u8LocalMsgIdx].udtDeadlineMonTimer < COMINL_udtNB_MESSAGES_RX) {
        u8LocalMsgIdx = E_OK;
    } else {
        u8LocalMsgIdx = E_NOT_OK;
    }

/* nested #if...already well indented */
    #if COMINL_coRX_MESSAGE_VAR == COMINL_coENABLE
    /*!Trace to: VEES_R_11_04044_004.01*/
    for (u8LocalMsgIdx = 0; u8LocalMsgIdx < COMINL_udtNB_MESSAGES_RX; u8LocalMsgIdx++) {
        #if COMINL_coRX_DEADLINE_MONITORING == COMINL_coENABLE
        COMINL_kastrVarReceiveMsg[u8LocalMsgIdx].udtDeadlineMonTimer = 0;
        #else /* COMINL_coRX_DEADLINE_MONITORING == COMINL_coENABLE */
        COMINL_kastrVarReceiveMsg[u8LocalMsgIdx].udtINMDeadlineMonTimer = 0;
        #endif /* COMINL_coRX_DEADLINE_MONITORING == COMINL_coENABLE */
    }
    #endif /* COMINL_coRX_MESSAGE_VAR == COMINL_coENABLE */


/* nested #if... no indentation  */
    #if COMINL_coTX_MESSAGE_VAR == COMINL_coENABLE
    /*!Trace to: VEES_R_11_04044_004.01*/
    for (u8LocalMsgIdx = 0; u8LocalMsgIdx < COMINL_udtNB_MESSAGES_TX; u8LocalMsgIdx++) {
        #if COMINL_coTX_DEADLINE_MONITORING == COMINL_coENABLE
        COMINL_kastrVarTransmitMsg[u8LocalMsgIdx].udtDeadlineMonTimer = 0;
        COMINL_kastrVarTransmitMsg[u8LocalMsgIdx].bDeadlineMonEnable  = FALSE;
        #endif /* COMINL_coTX_DEADLINE_MONITORING == COMINL_coENABLE */
        #if COMINL_coTX_INM_DEADLINE_MONITORING == COMINL_coENABLE
        COMINL_kastrVarTransmitMsg[u8LocalMsgIdx].udtINMDeadlineMonTimer = 0;
        #else /* COMINL_coTX_INM_DEADLINE_MONITORING == COMINL_coENABLE */
        COMINL_kastrVarTransmitMsg[u8LocalMsgIdx].udtMDTTimer   = 0;
        COMINL_kastrVarTransmitMsg[u8LocalMsgIdx].bMDTMsgToSend = FALSE;
        #endif /*COMINL_coMINIMUM_DELAY_TIME == COMINL_coENABLE*/
        #if COMINL_coMIXED_MODE != COMINL_coDISABLE
        COMINL_kastrVarTransmitMsg[u8LocalMsgIdx].udtPeriodicTimer = 0;
        #endif /* if COMINL_coMIXED_MODE != COMINL_coDISABLE */
    }
    #endif /* COMINL_coTX_MESSAGE_VAR == COMINL_coENABLE */
} /* COMINL_vidInit */

        #endif /* if COMINL_coSTART_STOP_PERIODIC == COMINL_coENABLE */


void myfunction(void){
    int i;
    #ifdef COMINL_coTX_MESSAGE_VAR
    #ifndef COMINL_coMIXED_MODE
    #pragma MyPragma
    int j;
    #endif /* ifndef COMINL_coMIXED_MODE */
    #endif /* ifdef COMINL_coTX_MESSAGE_VAR */
    int k;
}

    #endif /* COMSTACK_TYPES_H */

/*------------------------------- end of file --------------------------------*/


// c/pp-nest.c
    #if AA
int foo(){
    #if BB
    #else
    #if CC
    #else
    #endif
    #endif /* if BB */
}

    #endif /* if AA */

int bar(){
}

// c/pp-space.c
/**
 * Some file header comment thingy.
 */
    #ifndef SOME_H_INCLUDED
        #define SOME_H_INCLUDED

        #include "Somefile.h"

        #define SOMEMACRO (1 + 4)

        #ifdef WIN32

            #include "windows_compat.h"

        #else /* not WIN32 */

            #if defined HAVE_STDINT_H
                #include <stdint.h>
            #elif defined HAVE_INTTYPES_H
                #include <inttypes.h>
                #define YOUR_OS_SUCKS
            #else /* if defined HAVE_STDINT_H */
                #error "Don't know where int8_t is defined"
            #endif /* if defined HAVE_STDINT_H */

typedef uint32_t UINT32;

        #endif /* ifdef WIN32 */

    #endif /* SOME_H_INCLUDED */


// c/pp_concat_asn1.h
    #ifndef HEADER_ASN1_H
        #define HEADER_ASN1_H

        #define V_ASN1_UNIVERSAL        0x00
        #define V_ASN1_APPLICATION      0x40
        #define V_ASN1_CONTEXT_SPECIFIC 0x80
        #define V_ASN1_PRIVATE          0xc0

        #define V_ASN1_CONSTRUCTED   0x20
        #define V_ASN1_PRIMITIVE_TAG 0x1f
        #define V_ASN1_PRIMATIVE_TAG 0x1f

        #define V_ASN1_APP_CHOOSE -2 /* let the recipient choose */
        #define V_ASN1_OTHER      -3 /* used in ASN1_TYPE */
        #define V_ASN1_ANY        -4 /* used in ASN1 template code */

        #define V_ASN1_NEG 0x100    /* negative flag */

        #define V_ASN1_UNDEF             -1
        #define V_ASN1_EOC               0
        #define V_ASN1_BOOLEAN           1 /**/
        #define V_ASN1_INTEGER           2
        #define V_ASN1_NEG_INTEGER       (2 | V_ASN1_NEG)
        #define V_ASN1_BIT_STRING        3
        #define V_ASN1_OCTET_STRING      4
        #define V_ASN1_NULL              5
        #define V_ASN1_OBJECT            6 /* object identifier */
        #define V_ASN1_OBJECT_DESCRIPTOR 7
        #define V_ASN1_EXTERNAL          8 /* external / instance of */
        #define V_ASN1_REAL              9
        #define V_ASN1_ENUMERATED        10
        #define V_ASN1_NEG_ENUMERATED    (10 | V_ASN1_NEG)
        #define V_ASN1_EMBEDDED_PDV      11
        #define V_ASN1_UTF8STRING        12
        #define V_ASN1_SEQUENCE          16
        #define V_ASN1_SET               17
        #define V_ASN1_NUMERICSTRING     18 /**/
        #define V_ASN1_PRINTABLESTRING   19
        #define V_ASN1_T61STRING         20
        #define V_ASN1_TELETEXSTRING     20 /* alias */
        #define V_ASN1_VIDEOTEXSTRING    21 /**/
        #define V_ASN1_IA5STRING         22
        #define V_ASN1_UTCTIME           23
        #define V_ASN1_GENERALIZEDTIME   24 /**/
        #define V_ASN1_GRAPHICSTRING     25 /**/
        #define V_ASN1_ISO64STRING       26 /**/
        #define V_ASN1_VISIBLESTRING     26 /* alias */
        #define V_ASN1_GENERALSTRING     27 /**/
        #define V_ASN1_UNIVERSALSTRING   28 /**/
        #define V_ASN1_BMPSTRING         30

/* For use with d2i_ASN1_type_bytes() */
        #define B_ASN1_NUMERICSTRING   0x0001
        #define B_ASN1_PRINTABLESTRING 0x0002
        #define B_ASN1_T61STRING       0x0004
        #define B_ASN1_TELETEXSTRING   0x0004
        #define B_ASN1_VIDEOTEXSTRING  0x0008
        #define B_ASN1_IA5STRING       0x0010
        #define B_ASN1_GRAPHICSTRING   0x0020
        #define B_ASN1_ISO64STRING     0x0040
        #define B_ASN1_VISIBLESTRING   0x0040
        #define B_ASN1_GENERALSTRING   0x0080
        #define B_ASN1_UNIVERSALSTRING 0x0100
        #define B_ASN1_OCTET_STRING    0x0200
        #define B_ASN1_BIT_STRING      0x0400
        #define B_ASN1_BMPSTRING       0x0800
        #define B_ASN1_UNKNOWN         0x1000
        #define B_ASN1_UTF8STRING      0x2000
        #define B_ASN1_UTCTIME         0x4000
        #define B_ASN1_GENERALIZEDTIME 0x8000
        #define B_ASN1_SEQUENCE        0x10000

/* For use with ASN1_mbstring_copy() */
        #define MBSTRING_FLAG 0x1000
        #define MBSTRING_UTF8 (MBSTRING_FLAG)
        #define MBSTRING_ASC  (MBSTRING_FLAG | 1)
        #define MBSTRING_BMP  (MBSTRING_FLAG | 2)
        #define MBSTRING_UNIV (MBSTRING_FLAG | 4)

        #define SMIME_OLDMIME 0x400
        #define SMIME_CRLFEOL 0x800
        #define SMIME_STREAM  0x1000

struct X509_algor_st;
DECLARE_STACK_OF(X509_ALGOR);

        #define DECLARE_ASN1_SET_OF(type)   /* filled in by mkstack.pl */
        #define IMPLEMENT_ASN1_SET_OF(type) /* nothing, no longer needed */

/* We MUST make sure that, except for constness, asn1_ctx_st and
   asn1_const_ctx are exactly the same.  Fortunately, as soon as
   the old ASN1 parsing macros are gone, we can throw this away
   as well... */
typedef struct asn1_ctx_st {
    unsigned char *p;                   /* work char pointer */
    int eos;                        /* end of sequence read for indefinite encoding */
    int error;  /* error code to use when returning an error */
    int inf;    /* constructed if 0x20, indefinite is 0x21 */
    int tag;                        /* tag from last 'get object' */
    int xclass; /* class from last 'get object' */
    size_t slen;                /* length of last 'get object' */
    unsigned char *max; /* largest value of p allowed */
    unsigned char *q;/* temporary variable */
    unsigned char **pp;/* variable */
    int line;   /* used in error processing */
} ASN1_CTX;

typedef struct asn1_const_ctx_st {
    const unsigned char *p;/* work char pointer */
    int eos;                                   /* end of sequence read for indefinite encoding */
    int error;  /* error code to use when returning an error */
    int inf; /* constructed if 0x20, indefinite is 0x21 */
    int tag;                    /* tag from last 'get object' */
    int xclass;                                       /* class from last 'get object' */
    size_t slen;    /* length of last 'get object' */
    const unsigned char *max; /* largest value of p allowed */
    const unsigned char *q;/* temporary variable */
    const unsigned char **pp;/* variable */
    int line;   /* used in error processing */
} ASN1_const_CTX;

/* These are used internally in the ASN1_OBJECT to keep track of
 * whether the names and data need to be free()ed */
        #define ASN1_OBJECT_FLAG_DYNAMIC         0x01 /* internal use */
        #define ASN1_OBJECT_FLAG_CRITICAL        0x02 /* critical x509v3 object id */
        #define ASN1_OBJECT_FLAG_DYNAMIC_STRINGS 0x04 /* internal use */
        #define ASN1_OBJECT_FLAG_DYNAMIC_DATA    0x08 /* internal use */
typedef struct asn1_object_st {
    const char *sn, *ln;
    int nid;
    size_t length;
    const unsigned char *data;  /* data remains const after init */
    int flags;  /* Should we free this one */
} ASN1_OBJECT;

        #define ASN1_STRING_FLAG_BITS_LEFT 0x08 /* Set if 0x07 has bits left value */
/* This indicates that the ASN1_STRING is not a real value but just a place
 * holder for the location where indefinite length constructed data should
 * be inserted in the memory buffer
 */
        #define ASN1_STRING_FLAG_NDEF 0x010

/* This flag is used by the CMS code to indicate that a string is not
 * complete and is a place holder for content when it had all been
 * accessed. The flag will be reset when content has been written to it.
 */

        #define ASN1_STRING_FLAG_CONT 0x020

/* This is the base type that holds just about everything :-) */
typedef struct asn1_string_st {
    size_t length;
    int type;
    unsigned char *data;
    /* The value of the following field depends on the type being
     * held.  It is mostly being used for BIT_STRING so if the
     * input data has a non-zero 'unused bits' value, it will be
     * handled correctly */
    long flags;
} ASN1_STRING;

/* ASN1_ENCODING structure: this is used to save the received
 * encoding of an ASN1 type. This is useful to get round
 * problems with invalid encodings which can break signatures.
 */

typedef struct ASN1_ENCODING_st {
    unsigned char *enc; /* DER encoding */
    size_t len;     /* Length of encoding */
    int modified;        /* set to 1 if 'enc' is invalid */
} ASN1_ENCODING;

/* Used with ASN1 LONG type: if a long is set to this it is omitted */
        #define ASN1_LONG_UNDEF 0x7fffffffL

        #define STABLE_FLAGS_MALLOC 0x01
        #define STABLE_NO_MASK      0x02
        #define DIRSTRING_TYPE  \
    (B_ASN1_PRINTABLESTRING | B_ASN1_T61STRING | B_ASN1_BMPSTRING | B_ASN1_UTF8STRING)
        #define PKCS9STRING_TYPE (DIRSTRING_TYPE | B_ASN1_IA5STRING)

/* Declarations for template structures: for full definitions
 * see asn1t.h
 */
typedef struct ASN1_TEMPLATE_st ASN1_TEMPLATE;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct ASN1_TLC_st ASN1_TLC;
/* This is just an opaque pointer */
typedef struct ASN1_VALUE_st ASN1_VALUE;

/* Declare ASN1 functions: the implement macro in in asn1t.h */

        #define DECLARE_ASN1_FUNCTIONS(type) DECLARE_ASN1_FUNCTIONS_name(type, type)

        #define DECLARE_ASN1_ALLOC_FUNCTIONS(type) \
    DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, type)

        #define DECLARE_ASN1_FUNCTIONS_name(type, name) \
    DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, name); \
    DECLARE_ASN1_ENCODE_FUNCTIONS(type, name, name)

        #define DECLARE_ASN1_FUNCTIONS_fname(type, itname, name) \
    DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, name); \
    DECLARE_ASN1_ENCODE_FUNCTIONS(type, itname, name)

        #define DECLARE_ASN1_ENCODE_FUNCTIONS(type, itname, name) \
    type * d2i_##name(type * *a, const unsigned char **in, size_t len); \
    int i2d_##name(const type * a, unsigned char **out); \
    DECLARE_ASN1_ITEM(itname)

        #define DECLARE_ASN1_ENCODE_FUNCTIONS_const(type, name) \
    type * d2i_##name(type * *a, const unsigned char **in, size_t len); \
    int i2d_##name(const type * a, unsigned char **out); \
    DECLARE_ASN1_ITEM(name)

        #define DECLARE_ASN1_NDEF_FUNCTION(name) \
    int i2d_##name##_NDEF(const name * a, unsigned char **out)

        #define DECLARE_ASN1_FUNCTIONS_const(name) \
    DECLARE_ASN1_ALLOC_FUNCTIONS(name); \
    DECLARE_ASN1_ENCODE_FUNCTIONS_const(name, name)

        #define DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, name) \
    type * name##_new(void); \
    void name##_free(type * a)

        #define DECLARE_ASN1_PRINT_FUNCTION(stname) \
    DECLARE_ASN1_PRINT_FUNCTION_fname(stname, stname)

        #define DECLARE_ASN1_PRINT_FUNCTION_fname(stname, fname) \
    int fname##_print_ctx(BIO * out, const stname * x, int indent, \
                          const ASN1_PCTX * pctx)


/*
 * WARNING WARNING WARNING
 *
 * uncrustify still introduces whitespace in here at some spots, but then
 * one might ask how crazy we want to go regarding ## encumbered parsing?
 * There's always the copout of INDENT-OFF markers for files like these,
 * once you've got them 95% right through uncrustify and that extra 5%
 * by hand ;-)
 */
#define TYPEDEF_D2I_OF(type) typedef type *d2i_of_##type(type **,const unsigned char **,size_t)
#define TYPEDEF_I2D_OF(type) typedef int i2d_of_##type(type *,unsigned char **)
#define TYPEDEF_I2D_OF_CONST(type) typedef int i2d_of_const_##type(const type *,unsigned char **)    /* [i_a] */
#define TYPEDEF_D2I2D_OF(type) TYPEDEF_D2I_OF(type); TYPEDEF_I2D_OF(type); TYPEDEF_I2D_OF_CONST(type)    /* [i_a] */


/* Macro to include ASN1_ITEM pointer from base type */
#define ASN1_ITEM_ref(iptr) (&(iptr##_it))

#define ASN1_ITEM_rptr(ref) (&(ref##_it))

#define DECLARE_ASN1_ITEM(name) \
	extern const ASN1_ITEM name##_it;


#define ASN1_STRFLGS_RFC2253	(ASN1_STRFLGS_ESC_2253 | \
				ASN1_STRFLGS_ESC_CTRL | \
				ASN1_STRFLGS_ESC_MSB | \
				ASN1_STRFLGS_UTF8_CONVERT | \
				ASN1_STRFLGS_DUMP_UNKNOWN | \
				ASN1_STRFLGS_DUMP_DER)

DECLARE_STACK_OF(ASN1_INTEGER);
DECLARE_ASN1_SET_OF(ASN1_INTEGER);

DECLARE_STACK_OF(ASN1_GENERALSTRING);

typedef STACK_OF(ASN1_TYPE) ASN1_SEQUENCE_ANY;

DECLARE_ASN1_ENCODE_FUNCTIONS_const(ASN1_SEQUENCE_ANY, ASN1_SEQUENCE_ANY);
DECLARE_ASN1_ENCODE_FUNCTIONS_const(ASN1_SEQUENCE_ANY, ASN1_SET_ANY);


#define B_ASN1_DIRECTORYSTRING \
			B_ASN1_PRINTABLESTRING| \
			B_ASN1_TELETEXSTRING|\
			B_ASN1_BMPSTRING|\
			B_ASN1_UNIVERSALSTRING|\
			B_ASN1_UTF8STRING

#define B_ASN1_DISPLAYTEXT \
			B_ASN1_IA5STRING| \
			B_ASN1_VISIBLESTRING| \
			B_ASN1_BMPSTRING|\
			B_ASN1_UTF8STRING

#endif


// c/pp_ret.c
#if 0
int
#else
unsigned
#endif
f()
{
return 0;
}

#ifdef FOO
#define BAR .
#endif


// c/pragma.c

#pragma do not change anything in this pragma!

// This next bit should parse as '#', pragma, preproc-body, nl-cont,
//   preproc-body, nl-cont, preproc-body
#pragma multi \
   line \
      pragma

#pragma mark -------- Protected Member Functions ----------------

#pragma some comment follows    // comment


// c/preproc-if.c

int main()
{
int a;
#ifndef SOMEDEF
int b;
#endif /* SOMEDEF */

if (a)
{
}
#ifndef SOMEDEF
else if (b)
{
}
#endif /* SOMEDEF */

/* same thing w/o preprocs for reference */
if (a)
{
}
else if (b)
{
}

#ifdef FOO
do
{
Foo();
}
#endif
while(Loop--);
}


// c/return-multi.c

static inline long
get_tv32(struct timeval *o, struct timeval32 __user *i)
{
	return !access_ok(VERIFY_READ, i, sizeof(*i)) ||
                (__get_user(o->tv_sec, &i->tv_sec) |
		 __get_user(o->tv_usec, &i->tv_usec));
}

static inline long
get_tv32(struct timeval *o, struct timeval32 __user *i)
{
	return (!access_ok(VERIFY_READ, i, sizeof(*i)) ||
                (__get_user(o->tv_sec, &i->tv_sec) |
		 __get_user(o->tv_usec, &i->tv_usec)));
}

const char *
dcrp_license_feature(int32_t idx)
{
#define FEATURESTR(f) \
  case DCRMIB_LICENSE_##f: \
    return DCRP_LICENSE_FEATURE_##f##_STR

  switch(idx) {
    DCRP_LICENSE_FOREACH_FEATURES(FEATURESTR);
  }

  return "";

}


static int
isValidLicenseType(int32_t idx)
{
#define CHECKFEATURE(f) \
  case DCRMIB_LICENSE_##f: \
    return 1

  switch(idx) {
    DCRP_LICENSE_FOREACH_FEATURES(CHECKFEATURE);
  }

  return n * foo(5);
}


// c/semicolons.c

int foo(int bar)
{
   for (;;)
   {
      break;
   };;
   if (a)
   {
      foo();;
   };

   if (b)
      if (c)
        bar();
      else
         ;

   else
   {
      foo();;;;;
   };
   switch (a)
   {
   case 1: break;
   case 2: break;
   default: break;;
   };;
   while (b-->0)
   {
      bar();;
   };
   do
   {
      bar();
   } while (b-->0  );
};

enum FPP {
   FPP_ONE = 1,
   FPP_TWO = 2,
};;

struct narg {
   int abc;  ;  ;
   char def;  ;   ;
   ;
   ;const char *ghi;
};

void f2(void)
{
   { i++; };

   for (;;) ;

   for (;;) { ; }
}

int main(int argc, char *argv[])
{
if( argc == 1 )
{
printf("one");
};
else if( argc == 2 )
{
printf("two");
};
else
{
printf("%d", argc);
};
return 0;
}


// c/sf588.c
#define APPEND_TO_STREAM(VAR0) << #VAR0
#define APPEND_TO_STREAM(VAR0, VAR1) << #VAR0 << ", " << #VAR1


// c/sf594.c
void foo()
{
if (x < d >> 1)
{
}
}


// c/sort_include.c
// should be ddd, eee, fff
#include "ddd"
#include "fff"
#include "eee"

// should be aaa, ccc
#include "ccc"
#include "aaa"
// should be just bbb
#include "bbb"


// c/sp_after_sparen.c
// test for bug # 637
void foo(void)
{
while (1);
	while (1);
	while (1) ;
	while (1)  ;
		while (1);
	if (n) {
	while (1);
		while (1);
		while (1) ;
		while (1)  ;
			while (1);
	}
}


// c/sp_cmt_cpp_start.c

//zero
// one
//  two
//   three
void foo(void);

////four
//// five
//// six
void bar(void);


// c/sp_embed_comment.c
void f();
void g(int);
void h()
{
f(/*foo*/);
g(42/*foo*/);
g(/*foo*/42);
}


// c/string_utf8.c
char* x = "中国語 (繁体)";


// c/struct-brace.c
struct foo {
 unsigned int d_ino;
 unsigned short d_reclen;
 unsigned short d_namlen;
 char d_name[1];
};

struct foo
{
 unsigned int d_ino;
 unsigned short d_reclen;
 unsigned short d_namlen;
 char d_name[1];
};

struct foo { int a; char *b };


// c/switch-case.c

asmlinkage unsigned long
osf_setsysinfo(unsigned long op, void __user *buffer, unsigned long nbytes,
	       int __user *start, void __user *arg)
{
	switch (op) {
	case SSI_IEEE_FP_CONTROL: {
		unsigned long swcr, fpcr;
		unsigned int *state;

		/*
		 * Alpha Architecture Handbook 4.7.7.3:
		 * To be fully IEEE compiant, we must track the current IEEE
		 * exception state in software, because spurrious bits can be
		 * set in the trap shadow of a software-complete insn.
		 */

		if (get_user(swcr, (unsigned long __user *)buffer))
			return -EFAULT;
		state = &current_thread_info()->ieee_state;

		/* Update softare trap enable bits.  */
		*state = (*state & ~IEEE_SW_MASK) | (swcr & IEEE_SW_MASK);

		/* Update the real fpcr.  */
		fpcr = rdfpcr() & FPCR_DYN_MASK;
		fpcr |= ieee_swcr_to_fpcr(swcr);
		wrfpcr(fpcr);

		return 0;
	}

	case SSI_IEEE_RAISE_EXCEPTION: {
		unsigned long exc, swcr, fpcr, fex;
		unsigned int *state;

		if (get_user(exc, (unsigned long __user *)buffer))
			return -EFAULT;
		state = &current_thread_info()->ieee_state;
		exc &= IEEE_STATUS_MASK;

		/* Update softare trap enable bits.  */
 		swcr = (*state & IEEE_SW_MASK) | exc;
		*state |= exc;

		/* Update the real fpcr.  */
		fpcr = rdfpcr();
		fpcr |= ieee_swcr_to_fpcr(swcr);
		wrfpcr(fpcr);

 		/* If any exceptions set by this call, and are unmasked,
		   send a signal.  Old exceptions are not signaled.  */
		fex = (exc >> IEEE_STATUS_TO_EXCSUM_SHIFT) & swcr;
 		if (fex) {
			siginfo_t info;
			int si_code = 0;

			if (fex & IEEE_TRAP_ENABLE_DNO) si_code = FPE_FLTUND;
			if (fex & IEEE_TRAP_ENABLE_INE) si_code = FPE_FLTRES;
			if (fex & IEEE_TRAP_ENABLE_UNF) si_code = FPE_FLTUND;
			if (fex & IEEE_TRAP_ENABLE_OVF) si_code = FPE_FLTOVF;
			if (fex & IEEE_TRAP_ENABLE_DZE) si_code = FPE_FLTDIV;
			if (fex & IEEE_TRAP_ENABLE_INV) si_code = FPE_FLTINV;

			info.si_signo = SIGFPE;
			info.si_errno = 0;
			info.si_code = si_code;
			info.si_addr = NULL;  /* FIXME */
 			send_sig_info(SIGFPE, &info, current);
 		}
		return 0;
	}

	case SSI_IEEE_STATE_AT_SIGNAL:
	case SSI_IEEE_IGNORE_STATE_AT_SIGNAL:
		/*
		 * Not sure anybody will ever use this weird stuff.  These
		 * ops can be used (under OSF/1) to set the fpcr that should
		 * be used when a signal handler starts executing.
		 */
		break;

 	case SSI_NVPAIRS: {
		unsigned long v, w, i;
		unsigned int old, new;

 		for (i = 0; i < nbytes; ++i) {

 			if (get_user(v, 2*i + (unsigned int __user *)buffer))
 				return -EFAULT;
 			if (get_user(w, 2*i + 1 + (unsigned int __user *)buffer))
 				return -EFAULT;
 			switch (v) {
 			case SSIN_UACPROC:
			again:
				old = current_thread_info()->flags;
				new = old & ~(UAC_BITMASK << UAC_SHIFT);
				new = new | (w & UAC_BITMASK) << UAC_SHIFT;
				if (cmpxchg(&current_thread_info()->flags,
					    old, new) != old)
					goto again;
 				break;

 			default:
 				return -EOPNOTSUPP;
 			}
 		}
 		return 0;
	}

	default:
		break;
	}

	return -EOPNOTSUPP;
}


// c/switch.c

int foo(int op)
{
   switch (op)
   {
   case 1: {
         do_something();
         return 0;
      }

   case 2:
      do_something_else();
      return 1;

   case 3:
   case 4:
      /* don't do anything */
      break;

   case 5:
      return 3;

   default:
      break;
   }

   return -1;
}


// c/t3.in.c
extern /*@observer@*/ /*@null@*/ const dcroid_t* dcrp_oidget
(
 /*@in@*/ const char* h,
 /*@in@*/const char* t
  ) /*@ensures maxRead(result) >= 0@*/;

extern /*@observer@*/const char* dcrp_oidlabel
(
 /*@in@*/const dcroid_t* oid
 );


// c/type-cast.c

void foo(void)
{
   drab bar;
   bar = (bat) * r;
   bar = (int) * r;
   bar = (UINT8) * r;
   bar = (time_t) * r;

   a = &arg[dog * 13];
   b = arg[dog * cat];
   hc = "0123456789ABCDEF"[0xf & *val];
}


// c/type_wrap.c
void foo(void)
{
   STACK_OF(X509) * st=sk_X509_new_null();
}


// c/utf8-identifiers.c
void FooUtf8Сhar(void) // C is encoded in UTF-8
{
}

struct テスト         // Japanese 'test'
{
    void トスト() {}  // Japanese 'toast'
};

int main() {
    テスト パン;        // Japanese パン 'bread'
    パン.トスト();
}


// c/vardefcol.c
static string foo,
bar;

void f()
{
SomeNamedType *var1,
                  * var2;
}

void b()
{
AnotherType var1,
var2;
}


// c/various_colons.c
struct foo {
        unsigned int a:4;int b : 4;
};

int bar(int x)
{
        switch (x){ case 1: return 2; case 4: return 4;
                        case
                             6
                                :
                                return
                                        8;
        case 10:
                return 19;
        }return 0;

}


int main(void){bar(10);
foo: bar(-9); bar(9);baz:return 0;}


// c/vb-do.c

struct beef a =
{
   1, 2, 3
};

void get_name(void)
{
   int _ = 3;
   do
      a--;
   while (a);

   while (a) //something
      a--;

   do
      while (a) //something
         a--;
   while (b--);
}


// c/vb-pp.c

void f() {
if(0)
#pragma omp atomic
i++;
}


void f() {
if(0)
#if foo
i++;
#else
i+=2;
#endif
}

void f()
{
while(108) {
if(42)
#pragma omp critical
{ }
if(23)
#pragma omp critical
++i;
while (16)
{ }
int i = 15;
if(8)
#pragma omp atomic
i += 4;
}
}


// c/vb-while.c
unsigned long xdl_adler32(unsigned long adler, unsigned char const *buf,
                          unsigned int len)
{
   int k;
   unsigned long s1 = adler & 0xffff;
   unsigned long s2 = (adler >> 16) & 0xffff;

   if (!buf)
      return 1;

   while (len > 0)
   {
      k = len < NMAX ? len :NMAX;
      len -= k;
      while (k >= 16)
      {
         DO16(buf);
         buf += 16;
         k -= 16;
      }
      if (k != 0)
         do
         {
            s1 += *buf++;
            s2 += s1;
         } while (--k);
      s1 %= BASE;
      s2 %= BASE;
   }

   return(s2 << 16) | s1;
}

void f(){
while(1)
if(2)
3;
else
4;
}


// c/xml.c
void foo(void)
{
const char *a= "<xml>"
"<data Parent=\"%d\" Name=\"%s\">"
"<Child Id=\"%d\"/>"
"</data>"
"</xml>";
}
